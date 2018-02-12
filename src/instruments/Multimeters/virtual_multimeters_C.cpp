// ---------------------------------------------------------------------------

#pragma hdrstop

#include "virtual_multimeters_C.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

virtual_multimeters_C::virtual_multimeters_C() {

	this->ErrorQueryInDriver = false;
	this->Mode_Ac = false;
	this->Channel = 0;
	this->Average = 0;
	this->DcVolt = 0;
	this->AcVolt = 0;
	this->DcAmp = 0;
	this->AcAmp = 0;
	this->Ohm = 0;
	this->Freq = 0;
	this->Pow_dBm = 0;
	this->delta_mes_m = 0;
	this->MsgError = "NO ERROR";

}

void virtual_multimeters_C::resetInst(int channel_i, int average_i, double dcVolt_v_i, double acVolt_v_i, double dcAmp_a_i, double acAmp_a_i, double ohm_i,
  double freq_i, double temp_i, double pow_dBm_i, double delta_mes_i, bool doErrorQueryInDriver_i, bool mode_Ac_i) {
	this->ErrorQueryInDriver = doErrorQueryInDriver_i;
	this->Mode_Ac = mode_Ac_i;
	this->Channel = channel_i;
	this->Average = average_i;
	this->DcVolt = dcVolt_v_i;
	this->AcVolt = acVolt_v_i;
	this->DcAmp = dcAmp_a_i;
	this->AcAmp = acAmp_a_i;
	this->Ohm = ohm_i;
	this->Freq = freq_i;
	this->Temp = temp_i;
	this->Pow_dBm = pow_dBm_i;
	this->Delta_Mes = delta_mes_i;

};

double virtual_multimeters_C::createMoyenne(double value_i) {
	vector<double>tableau;
	double moyenne = 0;
	if (Average == 0)
			Average = 1;

	for (int i = 0; i < Average; i++) {
		tableau[i] = createValueRand(value_i);
		moyenne += tableau[i];
	}

	return moyenne /= tableau.size();
};

double virtual_multimeters_C::createValueRand(double value_i) {

	double vMax_l, vMin_l;
	double r;
	if (Delta_Mes != 0) {
		vMax_l = value_i + Delta_Mes/2;
		vMin_l = value_i - Delta_Mes/2;
	}

	r = (double)rand() / (double)RAND_MAX;

	return (r * (vMax_l - vMin_l) + vMin_l);

};



void virtual_multimeters_C::ChangeConfiguration() {
};

void virtual_multimeters_C::ChangeAdrPrimaire(int Adr) {
};

void virtual_multimeters_C::ChangeAdrSecondaire(int Adr) {
};

void virtual_multimeters_C::timeoutRecvData(double timeout) {
};

std::string virtual_multimeters_C::recvMessage(std::string message, int adr, GPIB_BUSDATA* status){
};
