#include <DUnitX.TestFramework.hpp>
#include <stdio.h>
#include <stdio.h>
#include <StrUtils.hpp>
#include "vcl.h"
#include "SBench.h"
#include "SAlimentations.h"
#include <string>
//#pragma link "drivers_cpp10.lib"
#pragma link "simu_cpp10.lib"
#pragma option --xrtti

using namespace Utils;

class __declspec(delphirtti) TU_Bench : public TObject {
public:
	virtual void __fastcall SetUp();
	virtual void __fastcall TearDown();

__published:
	void __fastcall TU_BenchConfig();
	void __fastcall TU_VariableBench();
};

SBench_C *B;
SAlimentations *A;

void __fastcall TU_Bench::SetUp() {
	B = new SBench_C();
	A = new SAlimentations();
	A->BenchAdrFile->FileName = "D:\\simu_cpp.bax\\baie\\baies.adr";
	A->BenchAdrFile->Section = "simu.ba1";
	A->Caption = "ALIM1 #01";
	A->Active = true;
	A->Device->OverVoltage = false;
	A->Device->OverCurrent = false;
	A->Device->OverTemperature = false;

}

void __fastcall TU_Bench::TearDown() {
}

void __fastcall TU_Bench::TU_BenchConfig() {

	SetUp();
	B->BenchSimu->FileName = "D:\\simu_cpp.bax\\baie\\baies.adr";
	B->BenchSimu->Section = "simu.ba1";
	B->Active = true;

	A->Device->addObserverDown(B);

};

void __fastcall TU_Bench::TU_VariableBench() {

	A->Device->OverVoltage = false;
	A->Device->OverCurrent = false;
	A->Device->OverTemperature = false;
	A->Device->RemoteInhibit = false;
	A->Device->Unregulation = false;

	A->Device->ActiveVoltageProt = 102;
	A->Device->ActiveCurrentProt = 0.025;
	A->Device->ActiveCurrent = 0.012;
	A->Device->ActiveVoltage = 100;
	// Test validite des parametres de l'alimentation.

	Dunitx::Testframework::Assert::IsTrue(A->Device->OverVoltage == false);
	Dunitx::Testframework::Assert::IsTrue(A->Device->OverCurrent == false);
	Dunitx::Testframework::Assert::IsTrue(A->Device->OverTemperature == false);
	Dunitx::Testframework::Assert::IsTrue(A->Active == true);
	Dunitx::Testframework::Assert::IsTrue(A->Caption == "ALIM1 #01");
	Dunitx::Testframework::Assert::IsTrue(A->NameDevice == "alHP661xxA");
	Dunitx::Testframework::Assert::IsTrue(A->AdresseString == "GPIB0::2::0::INTFC");
	Dunitx::Testframework::Assert::IsTrue(A->BenchAdrFile->Section == "simu.ba1");
	Dunitx::Testframework::Assert::IsTrue(A->BenchAdrFile->FileName == "D:\\simu_cpp.bax\\baie\\baies.adr");

	// Test des variables Adresse GPIB du fichiers de baie.adr
	Dunitx::Testframework::Assert::IsTrue(A->GPIB->get_Gpibt_T()->type == SERVER);
	Dunitx::Testframework::Assert::IsTrue(A->GPIB->get_Gpibt_T()->Id_Interface == 0);
	Dunitx::Testframework::Assert::IsTrue(A->GPIB->get_Gpibt_T()->Adr_Primaire == 2);
	Dunitx::Testframework::Assert::IsTrue(A->GPIB->get_Gpibt_T()->Adr_secondaire == 0);
	Dunitx::Testframework::Assert::IsTrue(A->GPIB->get_Gpibt_T()->controler_system == false);

	// Test des variables Options du fichiers de configuration de l'alimentation.


	Dunitx::Testframework::Assert::IsTrue(A->Device->ActiveCurrent == 0.012);
	Dunitx::Testframework::Assert::IsTrue(A->Device->ActiveVoltage == 100);
	Dunitx::Testframework::Assert::IsTrue(A->Device->ActiveVoltageProt == 102);
	Dunitx::Testframework::Assert::IsTrue(A->Device->ActiveVoltageProt == 102);
	Dunitx::Testframework::Assert::IsTrue(A->Device->ActiveCurrentProt == 0.025);
    A->Device->Active = true;
	Dunitx::Testframework::Assert::IsTrue(B->Active_Current == 0.012);
	Dunitx::Testframework::Assert::IsTrue(B->Active_Voltage == 100);
	Dunitx::Testframework::Assert::IsTrue(B->Active_Power == 100 * 0.012);


};

static void registerTests() {
	TDUnitX::RegisterTestFixture(__classid(TU_Bench));
}
#pragma startup registerTests 33
