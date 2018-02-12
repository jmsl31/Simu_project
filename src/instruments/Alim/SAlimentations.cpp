// ---------------------------------------------------------------------------

#pragma hdrstop

#include <StrUtils.hpp>
#include "SAlimentations.h"
#include "InstSubject.h"
#include "Gpib_Enum.h"

using namespace UtilSimu;
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#define ALIM_ENUM_LENGTH        12
AnsiString SAlimEnumStr[ALIM_ENUM_LENGTH] = {
	"alDebug", "alAuto", "alDAC488", "alHP661XXA", "alHP66XXA", "alHP3640A",
	"alN67XX", "alDAQmx", "alBILT", "alBiltBE58x", "alClient", "alKiPlz"};

SAlimentations::SAlimentations() {

	FGPIB_m = new GpibInterface();

	if (FGPIB_m->get_Gpibt_T()->status != STOPPED) {
		FGPIB_m->get_Gpibt_T()->status = STOPPED;
	}

	FBenchAdrFile_m = new SBenchAdrComp();

}

SAlimentations::~SAlimentations() {
	delete FGPIB_m;
	delete FBenchAdrFile_m;
	delete FDevice;
};

void SAlimentations::ReadBenchAdrFile() {
	T1DStringArray Array_temp;
	GPIB_T structGpib_temp;

	if (BenchAdrFile != NULL && Caption != NULL) {
		BenchAdrFile->Active = true;
		// AnsiString caption_l = Caption;
		FAdresseString = BenchAdrFile->BenchAdrFile->GetDevice(Caption)
			->Address;

		Array_temp = SepareAdressGpib(FAdresseString);

		structGpib_temp.Id_Interface = StrToInt(Array_temp[0]);
		structGpib_temp.Adr_Primaire = StrToInt(Array_temp[1]);
		structGpib_temp.Adr_secondaire = StrToInt(Array_temp[2]);

		if (Array_temp[3].UpperCase() == "INTFC")
			structGpib_temp.type = SERVER;
		else
			structGpib_temp.type = CLIENT;

		GPIB->set_Gpib_T(structGpib_temp);

		structGpib_temp.status = UtilSimu::STOPPED;

		NameDevice = BenchAdrFile->BenchAdrFile->GetDevice(Caption)->DeviceType;

		if ((BenchAdrFile->BenchAdrFile->GetDevice(Caption)->InUse == 1)
			&& Device->VerifyInUse) {
			throw Exception("L'appareil '" + FNameDevice +
				"' est en cours d'utilisation !");
			BenchAdrFile->Active = false;
		}
	}
}

void SAlimentations::DescriptSimInstr(virtual_alimentation_C* alim) {

	AnsiString FileName;
	TIniFile* DescriptFile;
	TStringList* StrList = new TStringList();
	vdescription_C* description;
	try {

		for (int i = 0; i < BenchAdrFile->BenchAdrFile->AdrArray.Length; i++) {
			FileName = BenchAdrFile->BenchAdrFile->AdrArray[i].FDescription;

			DescriptFile = new TIniFile(FileName);

			DescriptFile->ReadSectionValues("Description", StrList);

			/* Renseignement des valeurs du fichier description :
			 Name
			 Reference
			 Name Option
			 */

			description = new vdescription_C(StrList->Values[StrList->Names[0]],
				StrList->Values[StrList->Names[1]],
				StrList->Values[StrList->Names[2]]);

			if (StrList->Values[StrList->Names[2]] != "") {

				// Lecture de la section des options.
				DescriptFile->ReadSectionValues(description->getnameOption(),
					StrList);

				// Ajout de la reference des Options
				description->addOption(description->getnameOption(),
					StrList->Values[StrList->Names[0]]);
				// Initialisation de la valeur de Tension Max.
				alim->VoltageMax =
					StrList->Values[StrList->Names[1]].ToDouble();
				// Initialisation de la valeur de Courant Max.
				alim->CurrentMax =
					StrList->Values[StrList->Names[2]].ToDouble();
				// Initialisation de la valeur de Puissance Max.
				alim->PowerMax = StrList->Values[StrList->Names[3]].ToDouble();
				// Initialisation de la valeur de Tension RMS Max.
				alim->VoltageRMS =
					StrList->Values[StrList->Names[4]].ToDouble();
				// Initialisation de la valeur de Tension Peak.
				alim->VoltagePeak =
					StrList->Values[StrList->Names[5]].ToDouble();
				// Initialisation de la valeur de Courant RMS.
				alim->CurrentRMS =
					StrList->Values[StrList->Names[6]].ToDouble();
			}
			else
				throw Exception
					("Erreur à l'ouverture ou la lecture du fichier " +
				FileName + "!");
			alim->setDescription(description);
		}
	}
	catch (...) {

		throw Exception("Erreur à l'ouverture ou la lecture du fichier " +
			FileName + "!");
	}
};

void SAlimentations::SetActive(bool AValue) {

	if (FActive != AValue) {
		FActive = AValue;
		if (AValue) {
			try {
				ReadBenchAdrFile();

				if ((DeviceType == alHP661XXA) || (DeviceType == alAuto)) {
					// Initialisation & creation du Driver
					try {
						FDevice = new Shp661xxa_C();
					}
					catch (...) {
						delete FDevice;
						throw Exception("Probleme d'initialisation du Driver " +
							AValue);
					}
					// Defintion des caracteristiques de configurations.

					DescriptSimInstr(FDevice);

					// Initialisation & creation de l'interface GPIB
					try {
							this->GPIB->InstallGpib();
							this->GPIB->addObserver(*FDevice);
							this->GPIB->Start();
						}
					catch (...) {
						this->GPIB->removeObserver(*FDevice);
						this->GPIB->get_Gpibt_T()->status = UtilSimu::UNDEFINED;
						this->GPIB->Stop();
						this->GPIB->UnInstallGPIB();
						throw Exception
							("Probleme d'initialisation du Protocole de communication GPIB '" +
							GPIB->get_Gpibt_T()->Id_Interface);
					}

					return;
				}
			}
			catch (...) {
				FActive = false;

				throw Exception("Probleme Driver '" + AValue);
			}
		}
		else {

			delete FDevice;
		}
	}

}

void SAlimentations::SetDeviceFind(AnsiString AValue) {
	bool FindStr = false;
	if (FDeviceStr != AValue) {
		for (int i = 0; i < ALIM_ENUM_LENGTH; i++)
			if (Trim(UpperCase(AValue)) == UpperCase(SAlimEnumStr[i])) {
				FindStr = true;
				FDeviceType = (SAlimEnum)i;
			}
		if (!FindStr)
			throw Exception("Driver '" + AValue + "' non trouvé");
		// Active = false;
		FNameDevice = AValue;
	}

}

void SAlimentations::setCaption(AnsiString AValue) {
	FCaption = AValue;
};

AnsiString SAlimentations::getCaption() {
	return (FCaption);
};

void SAlimentations::setAdresseString(AnsiString AValue) {
	FAdresseString = AValue;
};

AnsiString SAlimentations::getAdresseString() {
	return (FAdresseString);
};

void SAlimentations::SetDeviceType(SAlimEnum AValue) {
	if (FDeviceType != AValue) {
		Active = false;
		FDeviceType = AValue;
	}
}

T1DStringArray SAlimentations::SepareAdressGpib(AnsiString Str_i) {
	T1DStringArray Array_l;
	AnsiString StrTemp_l = "";
	AnsiString Str_l = Str_i;
	while (Str_l.Pos("::") != 0) {
		StrTemp_l = LeftStr(Str_l, Str_l.Pos("::") - 1);
		if (StrTemp_l.Pos("GPIB")) {
			StrTemp_l = StrTemp_l.SubString(Str_l.Pos("GPIB") + 4,
				Str_l.Length());
		}
		if (StrTemp_l != "") {
			Array_l.Length++;
			Array_l[Array_l.Length - 1] = StrTemp_l.Trim();
		}
		Str_l = Str_l.SubString(Str_l.Pos("::") + 2, Str_l.Length());
	}
	if (Str_l != "") {
		Array_l.Length++;
		Array_l[Array_l.Length - 1] = Str_l.Trim();
	}
	return Array_l;
}

T1DStringArray SAlimentations::SepareTab(AnsiString Str_i,
	AnsiString Separateur_i) {
	T1DStringArray Array_l;
	AnsiString StrTemp_l = "";
	AnsiString Str_l = Str_i;
	while (Str_l.Pos(Separateur_i) != 0) {
		StrTemp_l =
			LeftStr(Str_l, Str_l.Pos(Separateur_i) - Separateur_i.Length());
		if (StrTemp_l != "") {
			Array_l.Length++;
			Array_l[Array_l.Length - 1] = StrTemp_l.Trim();
		}
		Str_l = Str_l.SubString(Str_l.Pos(Separateur_i) + Separateur_i.Length(),
			Str_l.Length());
	}
	if (Str_l != "") {
		Array_l.Length++;
		Array_l[Array_l.Length - 1] = Str_l.Trim();
	}
	return Array_l;
}
