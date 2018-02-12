#include <DUnitX.TestFramework.hpp>
#include <stdio.h>

#include "virtual_alim_C.h"
#include "TU_virtual_Alim_C.h"

#pragma option --xrtti

class __declspec(delphirtti) Tu_virtual_Alim_C : public TObject {
public:
	virtual void __fastcall SetUp();
	virtual void __fastcall TearDown();

	virtual_alim_C *Alim;

__published:

	virtual void __fastcall Verif_Voltage();
	virtual void __fastcall Verif_Courant();
	virtual void __fastcall Verif_Puissance();
	virtual void __fastcall Verif_Protectiontension();
	virtual void __fastcall Verif_Protectioncourant();

};

virtual_alim_C *Alim;

double voltage_l = 100;
double current_l = 0.05;
double puissance_l = 0;

double protVoltage_l = 102;
double protcurrent_l = 0.15;
double tension_max_l = 102;
double courant_min_l = 0.02;
double courant_max_l = 0.25;
double puissance_max_l = 15;

bool StatutprotVoltage_l = false;
bool StatutprotCurrent_l = false;

void __fastcall Tu_virtual_Alim_C::SetUp() {
	Alim = new virtual_alim_C();
	Alim->initAlim(voltage_l, current_l, protVoltage_l, protcurrent_l,
		tension_max_l, courant_min_l, courant_max_l, puissance_l,
		puissance_max_l);
}

void __fastcall Tu_virtual_Alim_C::TearDown() {
	delete Alim;
}

void __fastcall Tu_virtual_Alim_C::Verif_Voltage() {

	SetUp();
	Dunitx::Testframework::Assert::IsTrue(Alim->Voltage == voltage_l);
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedVoltage == false);
	TearDown();
};

void __fastcall Tu_virtual_Alim_C::Verif_Courant() {

	SetUp();
	Dunitx::Testframework::Assert::IsTrue(Alim->Current == current_l);
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedVoltage == false);
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedCurrent == false);
	TearDown();
};

void __fastcall Tu_virtual_Alim_C::Verif_Puissance() {

	SetUp();
	double p = voltage_l * current_l;
	Alim->Puissance = voltage_l * current_l;
	Dunitx::Testframework::Assert::IsTrue(Alim->Puissance == p);
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedVoltage == false);
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedCurrent == false);
};

void __fastcall Tu_virtual_Alim_C::Verif_Protectiontension() {

	double p;
	SetUp();
	Alim->Voltage = 104;
	Alim->Puissance = 12;
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedVoltage == true);
	Dunitx::Testframework::Assert::IsTrue(Alim->PuissanceActive == 0);
	Alim->ProtectedVoltage = false;
	Alim->Voltage = 98;
	p = 98 * (Alim->Puissance / Alim->Voltage);

	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedVoltage == false);
	Dunitx::Testframework::Assert::IsTrue(Alim->PuissanceActive == p);
	Alim->Voltage = 102;
	p = 102 * (Alim->Puissance / Alim->Voltage);
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedVoltage == false);
	Dunitx::Testframework::Assert::IsTrue(Alim->PuissanceActive == p);
	Alim->Voltage = 102.2;
	p = 0;
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedVoltage == true);
	Dunitx::Testframework::Assert::IsTrue(Alim->PuissanceActive == 0);
};

void __fastcall Tu_virtual_Alim_C::Verif_Protectioncourant() {

	double p;
	SetUp();
	Alim->Current = 0.25;
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedCurrent == true);
	Dunitx::Testframework::Assert::IsTrue(Alim->PuissanceActive == 0);
	Alim->ProtectedCurrent = false;
	Alim->Puissance = 15;
	Alim->VoltageActif = voltage_l;
	Alim->setCurrentActifs();
	p = voltage_l * Alim->CurrentActif;
	Dunitx::Testframework::Assert::IsTrue(Alim->ProtectedCurrent == false);
	Dunitx::Testframework::Assert::IsTrue(Alim->PuissanceActive == p);
};

static void registerTests() {
	TDUnitX::RegisterTestFixture(__classid(Tu_virtual_Alim_C));
}
#pragma startup registerTests 33
