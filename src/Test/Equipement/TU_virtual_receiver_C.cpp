#include <DUnitX.TestFramework.hpp>
#include <stdio.h>
#include "virtual_receiver_C.h"
#include <time.h>

#pragma option --xrtti

class __declspec(delphirtti) TU_virtual_receiver_C : public TObject
{
public:

	virtual void __fastcall SetUp();
	virtual void __fastcall TearDown();




__published:

	virtual void __fastcall Verif_Composition_Equipement();
	virtual void __fastcall Verif_DeviceType();
	virtual void __fastcall Verif_FrequencyOl();
	virtual void __fastcall Verif_interval_Fq_Ol();
	virtual void __fastcall Verif_power_Ol_min();
	virtual void __fastcall Verif_power_Ol_max();
	virtual void __fastcall Verif_power_Ol();
	virtual void __fastcall Verif_Gain();
	virtual void __fastcall Verif_power_in();
	virtual void __fastcall Verif_power_out();
};

 virtual_receiver_C *Equipement;

void __fastcall TU_virtual_receiver_C::SetUp()
{
   Equipement = new virtual_receiver_C();

}

void __fastcall TU_virtual_receiver_C::TearDown()
{
	delete Equipement;
}

double time_clock = CLOCKS_PER_SEC;

void __fastcall TU_virtual_receiver_C::Verif_Composition_Equipement(){

	SetUp();
	int nb_Tranche = 1;
	int nb_Alim = 1;
	int nb_Tmtc = 1;

	Equipement->setConsEqpt(nb_Tranche,nb_Alim,nb_Tmtc);

	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Tranche == nb_Tranche);
	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Alim == nb_Alim);
	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Tmtc == nb_Tmtc);


	nb_Tranche = 1;
	nb_Alim = 2;
	nb_Tmtc = 3;

	Equipement->setConsEqpt(nb_Tranche,nb_Alim,nb_Tmtc);

	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Tranche == nb_Tranche);
	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Alim == nb_Alim);
	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Tmtc == nb_Tmtc);

	nb_Tranche = 1;
	nb_Alim = 2;
	nb_Tmtc = 6;

	Equipement->setConsEqpt(nb_Tranche,nb_Alim,nb_Tmtc);

	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Tranche == nb_Tranche);
	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Alim == nb_Alim);
	Dunitx::Testframework::Assert::IsTrue(Equipement->getConsEqpt().nb_Tmtc == nb_Tmtc);

};

void __fastcall TU_virtual_receiver_C::Verif_DeviceType(){

	equipmentEnum Name = RX;

	Equipement->SetDeviceType(Name);

	Dunitx::Testframework::Assert::IsTrue(Equipement->DeviceType == Name);

	Name = DUAL;

	Equipement->SetDeviceType(Name);

	Dunitx::Testframework::Assert::IsTrue(Equipement->DeviceType == Name);

	Name = DOCON;

	Equipement->SetDeviceType(Name);

	Dunitx::Testframework::Assert::IsTrue(Equipement->DeviceType == Name);

	Name = UPCON;

	Equipement->SetDeviceType(Name);

	Dunitx::Testframework::Assert::IsTrue(Equipement->DeviceType == Name);


};

void __fastcall TU_virtual_receiver_C::Verif_FrequencyOl(){

	 double Frequency = 1250.5;
	 Equipement->TimeHot = 10;
	 Equipement->Frequency_OL = Frequency;

	 Dunitx::Testframework::Assert::IsTrue(Equipement->Frequency_OL == Frequency);
	 Dunitx::Testframework::Assert::IsTrue(Equipement->OlActive == false);
	 Dunitx::Testframework::Assert::IsTrue(Equipement->TimeHot == 10* time_clock);

	 //  A modifier pour valdiation du temps de chauffe de OL.
};

void __fastcall  TU_virtual_receiver_C::Verif_interval_Fq_Ol(){

		double interval = 100;

		Equipement->Interval_Fq_OL = interval;
		Dunitx::Testframework::Assert::IsTrue(Equipement->Interval_Fq_OL == interval);
};

void __fastcall TU_virtual_receiver_C::Verif_power_Ol_min(){

		double min = -65;

		Equipement->Power_Ol_Min = min;
		Dunitx::Testframework::Assert::IsTrue(Equipement->Power_Ol_Min == min);
};
void __fastcall TU_virtual_receiver_C::Verif_power_Ol_max(){

		double max = -5;

		Equipement->Power_Ol_Max = max;
		Dunitx::Testframework::Assert::IsTrue(Equipement->Power_Ol_Max == max);
};
void __fastcall TU_virtual_receiver_C::Verif_power_Ol(){

		double power = -10;

		Equipement->Power_Ol = power;
		Dunitx::Testframework::Assert::IsTrue(Equipement->Power_Ol == power);
		Dunitx::Testframework::Assert::IsTrue(Equipement->OlOverload == false);

		Equipement->OlOverload = true;
		Dunitx::Testframework::Assert::IsTrue(Equipement->Power_Ol == -140);
		Dunitx::Testframework::Assert::IsTrue(Equipement->OlOverload == true);

		Equipement->OlOverload = false;
		Equipement->Power_Ol = -2;

		Dunitx::Testframework::Assert::IsTrue(Equipement->Power_Ol == -140);
		Dunitx::Testframework::Assert::IsTrue(Equipement->OlOverload == true);

		Equipement->OlOverload = false;
		Equipement->Power_Ol = -20;

		Dunitx::Testframework::Assert::IsTrue(Equipement->Power_Ol == -20);
		Dunitx::Testframework::Assert::IsTrue(Equipement->OlOverload == false);

		Equipement->OlOverload = false;
		Equipement->Power_Ol = -140;

		Dunitx::Testframework::Assert::IsTrue(Equipement->Power_Ol == -140);
		Dunitx::Testframework::Assert::IsTrue(Equipement->OlOverload == true);

};
void __fastcall TU_virtual_receiver_C::Verif_Gain(){

		double g = 40 ;

		Equipement->Gain = g;

		Dunitx::Testframework::Assert::IsTrue(Equipement->Gain == g);

};
void __fastcall TU_virtual_receiver_C::Verif_power_in(){

		double in = -35 ;

		Equipement->PowerIn = in;

		Dunitx::Testframework::Assert::IsTrue(Equipement->PowerIn == in);

};
void __fastcall TU_virtual_receiver_C::Verif_power_out(){

		double in = -35 ;
		double g = 40 ;

		Equipement->Gain = g;
		Equipement->PowerIn = in;

		Dunitx::Testframework::Assert::IsTrue(Equipement->PowerOut == Equipement->Gain+Equipement->PowerIn);

		Equipement->Gain = 25;

		Dunitx::Testframework::Assert::IsTrue(Equipement->PowerOut == Equipement->Gain+Equipement->PowerIn);

		Equipement->PowerIn = -15;

		Dunitx::Testframework::Assert::IsTrue(Equipement->PowerOut == Equipement->Gain+Equipement->PowerIn);

};

static void registerTests()
{
  TDUnitX::RegisterTestFixture(__classid(TU_virtual_receiver_C));
}
#pragma startup registerTests 33