#include <DUnitX.TestFramework.hpp>
#include <stdio.h>
#include <StrUtils.hpp>
#include "vcl.h"
#include "SAlimentations.h"
#include <visa.h>
#include <visatype.h>

//#pragma link "drivers_cpp10.lib"
#pragma option --xrtti

class __declspec(delphirtti) TU_Hp661xxa : public TObject
{
public:


  virtual void __fastcall SetUp();

  virtual void __fastcall TearDown();

__published:
  void __fastcall TU_Variable();
  void __fastcall TU_Commande();


};

SAlimentations* Alim;

TIniFile* File;
TStringList* StrList ;

AnsiString nom_i,ref_i,option_i,Version_i;
	double 	Voltage_Max_i,
			Current_Max_i,
			Power_Max_i,
			Voltage_RMS_i,
			Voltage_Peak_i,
			Current_RMS_i;

void __fastcall TU_Hp661xxa::SetUp()
{
	Alim = new  SAlimentations();
	StrList = new TStringList();


	Alim->BenchAdrFile->FileName = "D:\\simu_cpp.bax\\baie\\baies.adr" ;
	Alim->BenchAdrFile->Section = "simu.ba1";
	Alim->Caption = "ALIM1 #01";
	Alim->Active = true;
	Alim->Device->OverVoltage = false;
	Alim->Device->OverCurrent = false;
	Alim->Device->OverTemperature = false;

	File = new TIniFile(Alim->BenchAdrFile->BenchAdrFile->AdrArray[0].FDescription);

	File->ReadSectionValues("Description",StrList);

	nom_i = StrList->Values[StrList->Names[0]];
	ref_i = StrList->Values[StrList->Names[1]];
	option_i = StrList->Values[StrList->Names[2]];

	File->ReadSectionValues(option_i,StrList);

	Version_i =  StrList->Values[StrList->Names[0]];
	Voltage_Max_i = StrList->Values[StrList->Names[1]].ToDouble() ;
	Current_Max_i = StrList->Values[StrList->Names[2]].ToDouble() ;
	Power_Max_i =  StrList->Values[StrList->Names[3]].ToDouble() ;
	Voltage_RMS_i =  StrList->Values[StrList->Names[4]].ToDouble() ;
	Voltage_Peak_i = StrList->Values[StrList->Names[5]].ToDouble() ;
	Current_RMS_i =  StrList->Values[StrList->Names[6]].ToDouble() ;



}

void __fastcall TU_Hp661xxa::TearDown()
{
	delete Alim;
	delete StrList;
	delete File;
}

void __fastcall TU_Hp661xxa::TU_Variable()
{
  SetUp();
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->OverVoltage == false);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->OverCurrent == false);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->OverTemperature == false);
  Dunitx::Testframework::Assert::IsTrue(Alim->Active == true);
  Dunitx::Testframework::Assert::IsTrue(Alim->Caption == "ALIM1 #01");
  Dunitx::Testframework::Assert::IsTrue(Alim->NameDevice == "alHP661xxA");
  Dunitx::Testframework::Assert::IsTrue(Alim->AdresseString == "GPIB0::2::0::INTFC");
  Dunitx::Testframework::Assert::IsTrue(Alim->BenchAdrFile->Section == "simu.ba1");
  Dunitx::Testframework::Assert::IsTrue(Alim->BenchAdrFile->FileName == "D:\\simu_cpp.bax\\baie\\baies.adr");

   // Test des variables Adresse GPIB du fichiers de baie.adr
  Dunitx::Testframework::Assert::IsTrue(Alim->GPIB->get_Gpibt_T()->type ==SERVER);
  Dunitx::Testframework::Assert::IsTrue(Alim->GPIB->get_Gpibt_T()->Id_Interface == 0);
  Dunitx::Testframework::Assert::IsTrue(Alim->GPIB->get_Gpibt_T()->Adr_Primaire == 2);
  Dunitx::Testframework::Assert::IsTrue(Alim->GPIB->get_Gpibt_T()->Adr_secondaire == 0);
  Dunitx::Testframework::Assert::IsTrue(Alim->GPIB->get_Gpibt_T()->controler_system == false);

  // Test des variables Options du fichiers de configuration de l'alimentation.
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->VoltageMax ==Voltage_Max_i);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->CurrentMax ==Current_Max_i);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->PowerMax ==Power_Max_i);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->VoltageRMS ==Voltage_RMS_i);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->VoltagePeak ==Voltage_Peak_i);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->CurrentRMS ==Current_RMS_i);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->getDescription()->getName() == nom_i);
  Dunitx::Testframework::Assert::IsTrue(Alim->Device->getDescription()->getReference() == ref_i);

}

void __fastcall TU_Hp661xxa::TU_Commande()
{
	int j =0;


	while( j< 3 )
	{
			std::cout << "Attente" << std::endl;
			j++;
			Sleep(1000);
	}

  TearDown();

};

static void registerTests()
{
  TDUnitX::RegisterTestFixture(__classid(TU_Hp661xxa));
}
#pragma startup registerTests 33