//---------------------------------------------------------------------------

#pragma hdrstop

#include "virtual_receiver_C.h"
#include "SRxthread.h"
#include <stdlib.h>


//---------------------------------------------------------------------------
#pragma package(smart_init)

/********************************************************************************************************************
/*								Implementation virtual_receiver_C
/*****************************************************************************************************************/


virtual_receiver_C::virtual_receiver_C(){

	CompositionEqpt = new TCompEqpt();

	frequency_Ol_m = 0;
	power_Ol_m = 0;
	power_Ol_min_m = 0;
	power_Ol_max_m = 0;
	gain_m = 0;
	power_in_m = 0;
	power_out_m = 0;
	time_Hot = 0;
	interval_Fq_OL = 0;
	FOl_Active = false;
	FOL_Overload =false;

};

virtual_receiver_C::~virtual_receiver_C(){};


double virtual_receiver_C::getFrequency_Ol(){
	return(frequency_Ol_m);
};

void virtual_receiver_C::setFrequency_Ol(double freqOl_i){

	if (freqOl_i != 0) {
	   frequency_Ol_m=freqOl_i;
	   FOl_Active = false;
	}

};

double virtual_receiver_C::getPower_Ol(){
	return(power_Ol_m) ;
};

void virtual_receiver_C::setPower_Ol(double powerOl_i){

	if (powerOl_i !=0 && powerOl_i < power_Ol_max_m &&  power_Ol_min_m < powerOl_i && OlOverload ==false)
	{
		power_Ol_m = powerOl_i;
		OlOverload = false;
	}
	else
	{       power_Ol_m = -140;
			OlOverload = true;
    }
};

double virtual_receiver_C::getPower_Ol_min(){
	 return(power_Ol_min_m);
};
void virtual_receiver_C::setPower_Ol_min(double powerOl_i){
	power_Ol_min_m = powerOl_i;
};
double virtual_receiver_C::getPower_Ol_max(){
	 return(power_Ol_max_m);
};
void virtual_receiver_C::setPower_Ol_max(double powerOl_i){
	 power_Ol_max_m = powerOl_i;
};


double virtual_receiver_C::getGain(){
	return(gain_m);

};
void virtual_receiver_C::setGain(double gain){
	gain_m = gain;

};
double virtual_receiver_C::getPowerOut(){

	if(this->power_in_m != 999)
	return( getPowerIn() + getGain());

};
double virtual_receiver_C::getPowerIn(){
	 return( power_in_m );
};

void virtual_receiver_C::setPowerIn(double p_in){
	power_in_m = p_in;
};
void virtual_receiver_C::setConsEqpt(int nb_tranche_m,int nb_alim_m,int nb_tmtc_m){

	CompositionEqpt->nb_Tranche = nb_tranche_m;
	CompositionEqpt->nb_Alim = nb_alim_m;
	CompositionEqpt->nb_Tmtc = nb_tmtc_m;
};

TCompEqpt virtual_receiver_C::getConsEqpt(){
		return(*CompositionEqpt);
};

void virtual_receiver_C::SetDeviceType(equipmentEnum AValue){
		FDeviceType = AValue;
};

double virtual_receiver_C::getTime_Hot(){
	   return( time_Hot);
};
void virtual_receiver_C::setTime_Hot(double time){

		time_Hot = time * CLOCKS_PER_SEC;
};

void virtual_receiver_C::waitHotFrequencyOl(){

		double temp_fq_Ol = Frequency_OL;
		clock_t timing = clock() + time_Hot;

		while (clock() >= timing )
		{
			OlActive = false;

			frequency_Ol_m = frequency_Ol_m +-  (std::rand() % (int)interval_Fq_OL) - (double)interval_Fq_OL;
		}

		OlActive = true;
};


bool virtual_receiver_C::getOl_overload(){
	return(FOL_Overload);
};
void virtual_receiver_C::setOl_overload(bool b){

	if (b) {
		FOL_Overload= b;
		power_Ol_m =-140;
		FOl_Active = false;
	}
	else
	{
		FOL_Overload= b;
	};
}


