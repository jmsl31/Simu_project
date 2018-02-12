#include <DUnitX.TestFramework.hpp>
#include <stdio.h>
#include "Rx_C.h"
#include <IniFiles.hpp>


#pragma option --xrtti

class __declspec(delphirtti) TU_RX_C : public TObject {
public:
	virtual void __fastcall SetUp();
	virtual void __fastcall TearDown();

__published:
	void __fastcall TetInitEqt();

};

Rx_C* RX_eqpt;

void __fastcall TU_RX_C::SetUp() {
	RX_eqpt = new Rx_C();
	RX_eqpt->setConsEqpt(1,1,1)  ;

}

void __fastcall TU_RX_C::TearDown() {
}

void __fastcall TU_RX_C::TetInitEqt() {
	SetUp();
	TIniFile* f = new TIniFile("D:\\simu_cpp.bax\\baie\\Equipment\\RX.ini");
	RX_eqpt->InitEqpt(f);
};

static void registerTests() {
	TDUnitX::RegisterTestFixture(__classid(TU_RX_C));
}
#pragma startup registerTests 33
