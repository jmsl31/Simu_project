//---------------------------------------------------------------------------

#pragma hdrstop

#include "virtual_RF_C.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//*******************************************************************************************************************
//							Implementation Vtranche_C
//*******************************************************************************************************************
virtual_RF_C::virtual_RF_C()
{
};
/*  __fastcall vtranche_C::~vtranche_C(){
};      */

void virtual_RF_C::initTranche(double fq_start_i,double fq_stop_i,double bandwidth_i,double step_i,double power_i,
						double power_min,double power_max,double frequency_min,double frequency_max,double gain_i){
  Power_Min = power_min;
  Power_Max = power_max;
  Frequency_Min = frequency_min;
  Frequency_Max = frequency_max;
  Frequency_Start_In =fq_start_i;
  Frequency_Stop_In = fq_stop_i;
  Bandwidth = bandwidth_i;
  Power = power_i;
  Step = step_i;
  Gain = gain_i;

 }
 ;

double virtual_RF_C::getFrequency_Start_In(){
	return( frequency_Start_In_m );
};
void virtual_RF_C::setFrequency_Start_In(double fq_start_i){

	if (fq_start_i ==0 || Frequency_Max<=fq_start_i  && fq_start_i < Frequency_Min ) {
		FActiveRF = false;
	}else
	{
		frequency_Start_In_m = fq_start_i;
		FActiveRF = true;
	}

};
double virtual_RF_C::getFrequency_Stop_In(){

	return( frequency_Stop_In_m );
};
void virtual_RF_C::setFrequency_Stop_In(double fq_stop_i){

	if (fq_stop_i ==0 || Frequency_Max<= fq_stop_i || fq_stop_i <= Frequency_Min ) {
		FActiveRF =false;
	}else
	 {
		frequency_Stop_In_m = fq_stop_i;
		FActiveRF =true;
	 }
};
double virtual_RF_C::getFrequency_Start_Out(){
		return( frequency_Start_Out_m );
};

void virtual_RF_C::setFrequency_Start_Out(double fq_start_i){

	if (fq_start_i ==0 || Frequency_Max<= fq_start_i || fq_start_i <= Frequency_Min ) {
		FActiveRF =false;
	}else
	 {
		frequency_Start_Out_m = fq_start_i;
		FActiveRF =true;
	 }

};
double virtual_RF_C::getFrequency_Stop_Out(){

	return( frequency_Stop_Out_m );
};


void virtual_RF_C::setFrequency_Stop_Out(double fq_stop_i){


	if (fq_stop_i ==0 || Frequency_Max<= fq_stop_i || fq_stop_i <= Frequency_Min ) {
		FActiveRF =false;
	}else
	 {
		frequency_Stop_Out_m = fq_stop_i;
		FActiveRF =true;
	 }

};

double virtual_RF_C::getbandwidth(){
	return(bandwidth_m);
};
void virtual_RF_C::setbandwidth(double bandwidth_i){

		// Si la bande correspond a la bande de l'equipement.
	if (Frequency_Stop_In- Frequency_Start_In == bandwidth_i ) {
			bandwidth_m=bandwidth_i;
	}else
	{
		double Start_temp = Frequency_Start_In;
		// Calculer des nouvelles frequences de Debut et Fin de Bande.
		Frequency_Start_In = ((Frequency_Stop_In+ Frequency_Start_In)/2)- bandwidth_i/2;
		Frequency_Stop_In  = ((Frequency_Stop_In+ Start_temp)/2)+ bandwidth_i/2;
		bandwidth_m=bandwidth_i;
    }

};
double virtual_RF_C::getstep(){
   return(step_m);
};
void virtual_RF_C::setstep(double step_i){
	step_m=step_i;
};
double virtual_RF_C::getGain(){
   return(gain_m);
};
void virtual_RF_C::setGain(double gain_i){
	gain_m=gain_i;
};
double virtual_RF_C::getPower(){
   return(power_m);
};
void virtual_RF_C::setPower(double power_i){
	if (  Power_Max < power_i || power_i < Power_Min) {
		Overload = true;
		ActivePower =false;
		power_m=-120;
	}else
	{
		power_m = power_i;
		Overload = false;
		ActivePower = true;
	}
};
double virtual_RF_C::getPower_Min(){
	return(power_min);
};

void virtual_RF_C::setPower_Min(double power_min_i){
	power_min = power_min_i;
};

double virtual_RF_C::getPower_Max(){
	return(power_max);
};

void virtual_RF_C::setPower_Max(double power_max_i){
	power_max = power_max_i;
};
double virtual_RF_C::getFrequency_Min(){
	return( frequency_Min );
};
void virtual_RF_C::setFrequency_Min(double fq_min_i){
	 frequency_Min = fq_min_i ;
};
double virtual_RF_C::getFrequency_Max(){
		 return(frequency_Max);
};
void virtual_RF_C::setFrequency_Max(double fq_max_i){
		frequency_Max = fq_max_i;
};