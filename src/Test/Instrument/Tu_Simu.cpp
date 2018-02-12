#include <DUnitX.TestFramework.hpp>
#include <stdio.h>
#include "SAlimFormUnit.h"
#include "SimuFormUnit.h"
#include <StrUtils.hpp>

#pragma option --xrtti

class __declspec(delphirtti) TU_IHM : public TObject
{
public:
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();

__published:

void __fastcall TU_TestIHM();
};

TAlimFormUnit* IHM;

TIniFile* File;
TStringList* StrList ;

AnsiString nom_i,ref_i,option_i,Version_i;
	double 	Voltage_Max_i,
			Current_Max_i,
			Power_Max_i,
			Voltage_RMS_i,
			Voltage_Peak_i,
			Current_RMS_i;


void __fastcall TU_IHM::SetUp()
{
	StrList = new TStringList();
}

void __fastcall TU_IHM::TearDown()
{
}

void __fastcall TU_IHM::TU_TestIHM()
{
   SetUp();
}


static void registerTests()
{
  TDUnitX::RegisterTestFixture(__classid(TU_IHM));
}
#pragma startup registerTests 33