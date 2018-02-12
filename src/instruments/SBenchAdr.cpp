// ---------------------------------------------------------------------------
#include <StrUtils.hpp>
#include <IniFiles.hpp>

#pragma hdrstop

#include "SBenchAdr.h"

// ---------------------------------------------------------------------------

#pragma package(smart_init)

SBenchAdrs::SBenchAdrs(AnsiString AFileName, AnsiString ASection) {
	TIniFile* BenchAdrFile = new TIniFile(AFileName);
	TStringList* StrList = new TStringList();
	try {
		if (ASection == "") {
			BenchAdrFile->ReadSections(StrList);
			ASection = StrList->Strings[0];
		}
		FSection = ASection;
		FFileName = AFileName;

		BenchAdrFile->ReadSectionValues(ASection, StrList);

		for (int i = 0; i < StrList->Count; i++) {
			T1DStringArray ArrayStr_l = SepareTab(StrList->Values[StrList->Names[i]], "\t");
			AdrArray.Length++;
			AdrArray[AdrArray.Length - 1].DeviceName = StrList->Names[i];
			AdrArray[AdrArray.Length - 1].Address = ArrayStr_l[0];
			AdrArray[AdrArray.Length - 1].Library = ArrayStr_l[1];
			AdrArray[AdrArray.Length - 1].DeviceType = ArrayStr_l[2];
			AdrArray[AdrArray.Length - 1].InUse = StrToInt(ArrayStr_l[3]);
			AdrArray[AdrArray.Length - 1].FDescription = ArrayStr_l[4];
			try {
				AdrArray[AdrArray.Length - 1].Comment = ArrayStr_l[5];
			}
			catch (...) {
				AdrArray[AdrArray.Length - 1].Comment = " ";
			}
		}
		delete StrList;
	}
	catch (...) {
		delete BenchAdrFile;
		delete StrList;
		throw Exception("Erreur à l'ouverture du fichier 'baies.adr' !");
	}
}

void SBenchAdrs::Save(void) {
	TIniFile* BenchAdrFile = new TIniFile(FFileName);
	try {
		for (int i = 0; i < AdrArray.Length; i++) {
			AnsiString AValue = "\t" + AdrArray[i].Address + "\t" + AdrArray[i].Library + "\t" + AdrArray[i].DeviceType + "\t" + IntToStr(AdrArray[i].InUse) +
			  "\t" + AdrArray[i].Comment;
			BenchAdrFile->WriteString(FSection, AdrArray[i].DeviceName, AValue);
		}
		delete BenchAdrFile;
	}
	catch (...) {
		delete BenchAdrFile;
		throw Exception("Erreur à l'enregistrement du fichier 'bair.adr' !");
	}
}

SAdrsStruct* SBenchAdrs::GetDevice(AnsiString DeviceName) {
	for (int i = 0; i < AdrArray.Length; i++) {
		if (DeviceName == AdrArray[i].DeviceName) {
			return &AdrArray[i];
		}
	}
	throw Exception("Appareil '" + DeviceName + "' non trouvé !");
}

T1DStringArray SBenchAdrs::GetDeviceAll() {
	T1DStringArray List_Device;
	List_Device.Length = 0;
	for (int i = 0; i < AdrArray.Length; i++) {
		List_Device.Length++;
		List_Device[i] = AdrArray[i].DeviceName;
	}
	return List_Device;
};

T1DStringArray SBenchAdrs::SepareTab(AnsiString Str_i, AnsiString Separateur_i) {
	T1DStringArray Array_l;
	AnsiString StrTemp_l = "";
	AnsiString Str_l = Str_i;
	while (Str_l.Pos(Separateur_i) != 0) {
		StrTemp_l = LeftStr(Str_l, Str_l.Pos(Separateur_i) - Separateur_i.Length());
		if (StrTemp_l != "") {
			Array_l.Length++;
			Array_l[Array_l.Length - 1] = StrTemp_l.Trim();
		}
		Str_l = Str_l.SubString(Str_l.Pos(Separateur_i) + Separateur_i.Length(), Str_l.Length());
	}
	if (Str_l != "") {
		Array_l.Length++;
		Array_l[Array_l.Length - 1] = Str_l.Trim();
	}
	return Array_l;
}

SBenchAdrComp::SBenchAdrComp() {
	FActive = false;
	FSection = "";
}

SBenchAdrComp::~SBenchAdrComp() {
	Active = false;
}

void __fastcall SBenchAdrComp::SetActive(bool AValue) {
	if (FActive != AValue) {
		FActive = AValue;
		if (FActive)
			try {
			SBenchAdrFile = new SBenchAdrs(FFileName, FSection);
			}
		catch (...) {
			FActive = false;
			throw;
		}
		else
			delete SBenchAdrFile;
	}
}

void __fastcall SBenchAdrComp::SetFileName(AnsiString AValue) {
	if (FFileName != AValue) {
		FFileName = AValue;
		Active = false;
	}
}

void __fastcall SBenchAdrComp::SetSection(AnsiString AValue) {
	if (FSection != AValue) {
		FSection = AValue;
		Active = false;
	}
}

T1DStringArray SBenchAdrComp::searchDevice(AnsiString Section, AnsiString searchValue, bool *valueFind) {
	bool sectionTrouvee = false;
	bool sectionSuivanteTrouvee = false;
	ifstream fichier;
	int i = 0;
	std::string contenu;
	// déclaration d'un chaine qui contiendra la ligne lue
	T1DStringArray returnValue;

	char* nom = this->FFileName.c_str(); // conversion en char
	char* searchValue2 = searchValue.c_str(); // conversion en char
	char* Section2 = Section.c_str(); // conversion en char

	fichier.open(nom, ios::in);

	try {
		if (fichier) { // si l'ouverture a réussi

			while (getline(fichier, contenu)) {
				const char* contenu2 = contenu.c_str(); // conversion en char

				if (strstr(contenu2, Section2) != NULL) {
					if (sectionTrouvee == true && strstr(contenu2, "[") != NULL) {
						sectionSuivanteTrouvee = true;
					}
					sectionTrouvee = true;

				}
				else if (sectionTrouvee == true && sectionSuivanteTrouvee == false) {
					if (strstr(contenu2, searchValue2) != NULL) {
						TStringDynArray Split_l = SplitString(contenu2, "=");
						returnValue.Length++;
						returnValue[i] = Split_l[0];
						i++;
						*valueFind = true;
					}
				}
			}
		}
	}
	catch (...) {
		fichier.close();
		throw Exception("Fichier baie.adr introuvable");
	}

	if (*valueFind != true) {
		*valueFind = false;
		returnValue.Length++;
		returnValue[0] = "Valeur non trouvée";
		return returnValue;
	}
	else {
		return returnValue;
	}
	fichier.close();
}
