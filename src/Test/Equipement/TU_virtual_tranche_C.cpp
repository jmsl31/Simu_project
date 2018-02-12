#include <DUnitX.TestFramework.hpp>
#include <stdio.h>
#include "virtual_RF_C.h"
#include "TU_virtual_tranche_C.h"

#pragma option --xrtti

class __declspec(delphirtti) TU_virtual_tranche_C : public TObject
{
public:
  virtual void __fastcall SetUp();
  virtual void __fastcall SetUpBande();
  virtual void __fastcall TearDown();
  virtual void __fastcall ChangeUp(double start,double stop,double bande,double step,
						double power,double powerMin,double powerMax,double FreqMin,double FreqMax);


  virtual_RF_C *tranche;

__published:

  virtual void __fastcall Verif_Frequency_Start_In();
  virtual void __fastcall Verif_Frequency_Stop_In();
  virtual void __fastcall Verif_Frequency_Start_Out();
  virtual void __fastcall Verif_Frequency_Stop_Out();
  virtual void __fastcall Verif_Frequency_min();
  virtual void __fastcall Verif_Frequency_max();
  virtual void __fastcall Verif_Bandwidth();
  virtual void __fastcall Verif_Step();
  virtual void __fastcall Verif_Power();
  virtual void __fastcall Verif_Power_min();
  virtual void __fastcall Verif_Power_max();

  virtual void __fastcall Verif_Freq_bandwitdh_Diff();


  virtual void __fastcall Verif_FActiveRf() ;
  virtual void __fastcall Verif_FActivePower() ;
  virtual void __fastcall Verif_FActiveOverload() ;
};

virtual_RF_C *t;

		double start = 13000;
		double stop = 13500;
		double bande = 500;
		double bande2 = 250;
		double step = 1;
		double power = -42;
		double powerMin = -85;
		double powerMax = -20;
		double FreqMin = 2000;
		double FreqMax = 26000;
		double start_out = 13000;
		double stop_out = 13500;
		double Freq_Start_out = 11500;
		double Freq_Stop_out = 12000;
		double Gain = 35;

void __fastcall TU_virtual_tranche_C::SetUp()
{
	   t = new virtual_RF_C();
	   t->initTranche(start,stop,bande,step,power,powerMin,powerMax,FreqMin,FreqMax,Gain);
	   t->Frequency_Start_Out = Freq_Start_out;
	   t->Frequency_Stop_Out = Freq_Stop_out;
}

void __fastcall TU_virtual_tranche_C::SetUpBande()
{
	   t = new virtual_RF_C();
	   t->initTranche(start,stop,bande2,step,power,powerMin,powerMax,FreqMin,FreqMax,Gain);
	   t->Frequency_Start_Out = Freq_Start_out;
	   t->Frequency_Stop_Out = Freq_Stop_out;
}

void __fastcall TU_virtual_tranche_C::ChangeUp(double start,double stop,double bande,double step,
												double power,double powerMin,double powerMax,double FreqMin,double FreqMax)
{      t = new virtual_RF_C();
	   t->initTranche(start,stop,bande,step,power,powerMin,powerMax,FreqMin,FreqMax,Gain);
}

void __fastcall TU_virtual_tranche_C::TearDown()
{
	delete tranche;
}

/////////////////////////// TESTS UNITAIRES vTranche_C	//////////////////////////////////////////////////////////

void __fastcall TU_virtual_tranche_C::Verif_Frequency_Start_In()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Frequency_Start_In == start);
	TearDown();
}


void __fastcall TU_virtual_tranche_C::Verif_Frequency_Stop_In()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Frequency_Stop_In == stop);
	TearDown();
}

void __fastcall TU_virtual_tranche_C::Verif_Frequency_min()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Frequency_Min == FreqMin);
	TearDown();
}

void __fastcall TU_virtual_tranche_C::Verif_Frequency_max()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Frequency_Max == FreqMax);
	TearDown();
}

void __fastcall TU_virtual_tranche_C::Verif_Frequency_Start_Out()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Frequency_Start_Out == Freq_Start_out);
	TearDown();
}

void __fastcall TU_virtual_tranche_C::Verif_Frequency_Stop_Out()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Frequency_Stop_Out == Freq_Stop_out);
	TearDown();
}

void __fastcall TU_virtual_tranche_C::Verif_Bandwidth()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Bandwidth == bande);
	TearDown();
}

void __fastcall TU_virtual_tranche_C::Verif_Step()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Step == step);
	TearDown();
}
void __fastcall TU_virtual_tranche_C::Verif_Power()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Power == power);
	TearDown();
}
void __fastcall TU_virtual_tranche_C::Verif_Power_min()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Power_Min == powerMin);
	TearDown();
}

void __fastcall TU_virtual_tranche_C::Verif_Power_max()
{
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Frequency_Max == FreqMax);
	TearDown();
}

void __fastcall TU_virtual_tranche_C::Verif_Freq_bandwitdh_Diff()
{

   SetUpBande();

   double resultin =  (start+stop)/2 - (t->Bandwidth/2);
   double resultout =  (start+stop)/2 +(t->Bandwidth/2);

   Dunitx::Testframework::Assert::IsTrue(t->Frequency_Start_In == resultin);
   Dunitx::Testframework::Assert::IsTrue(t->Frequency_Stop_In == resultout);

   TearDown();

};

void __fastcall TU_virtual_tranche_C::Verif_FActiveRf()
{
	t->ActiveRF = false ;
	Dunitx::Testframework::Assert::IsTrue(t->ActiveRF == false);
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->ActiveRF == true);

};

void __fastcall TU_virtual_tranche_C::Verif_FActivePower()
{
	t->ActivePower = false ;
	Dunitx::Testframework::Assert::IsTrue(t->ActivePower == false);
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->ActivePower == true);
	t->Power = -140;
	Dunitx::Testframework::Assert::IsTrue(t->ActivePower == false);
	t->ActivePower = true;
	t->Power = 35;
	Dunitx::Testframework::Assert::IsTrue(t->ActivePower == false);


} ;
void __fastcall TU_virtual_tranche_C::Verif_FActiveOverload()
{
	t->Overload = false ;
	Dunitx::Testframework::Assert::IsTrue(t->Overload == false);
	SetUp();
	Dunitx::Testframework::Assert::IsTrue(t->Overload == false);
	t->Power = -140;
	Dunitx::Testframework::Assert::IsTrue(t->Overload == true);
	t->Overload = false;
	t->Power = 35;
	Dunitx::Testframework::Assert::IsTrue(t->Overload == true);
} ;

static void registerTests()
{
  TDUnitX::RegisterTestFixture(__classid(TU_virtual_tranche_C));
}
#pragma startup registerTests 33