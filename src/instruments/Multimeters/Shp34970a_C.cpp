// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Shp34970a_C.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <vector> //Ne pas oublier !

double Shp34970a_C::getDcVolt() {
	return createMoyenne(DcVolt);
};

double Shp34970a_C::getAcVolt() {
	return createMoyenne(AcVolt);
};

double Shp34970a_C::getDcAmp() {
	return createMoyenne(DcAmp);
};

double Shp34970a_C::getAcAmp() {
	return createMoyenne(AcAmp);
};

double Shp34970a_C::getOhm() {
	return createMoyenne(Ohm);
};

double Shp34970a_C::getOhm_FourWire() {
	return createMoyenne(Ohm);
};

double Shp34970a_C::getFreq() {
	return createMoyenne(Freq);
};

double Shp34970a_C::getFreqMon() {
	return createMoyenne(Freq);
};

double Shp34970a_C::getTemp() {
	return createMoyenne(Temp);
};

double Shp34970a_C::getPower() {
	return createMoyenne(Pow_dBm);
};

double Shp34970a_C::setDcVolt(double DcVolt_i) {
	DcVolt = DcVolt_i;
};

double Shp34970a_C::setAcVolt(double AcVolt_i) {
	AcVolt = AcVolt_i;
};

double Shp34970a_C::setDcAmp(double DcAmp_i) {
	DcAmp = DcAmp_i;
};

double Shp34970a_C::setAcAmp(double AcAmp_i) {
};

double Shp34970a_C::setOhm(double Ohm_i) {
	Ohm = Ohm_i;
};

double Shp34970a_C::setOhm_FourWire(double Ohm_i) {
	Ohm = Ohm_i;
};

double Shp34970a_C::setFreq(double Freq_i) {
	Freq = Freq_i;
};

double Shp34970a_C::setFreqMon(double Freq_i) {
	Freq = Freq_i;
};

double Shp34970a_C::setTemp(double Temp_i) {
	Temp = Temp_i;
};

double Shp34970a_C::setPower(double Power_dbm_i) {
	Pow_dBm = Power_dbm_i;
};

double Shp34970a_C::getAverage() {
	return Average;
};

void Shp34970a_C::setAverage(int Average_i) {
	Average = Average_i;
};

void Shp34970a_C::setError(std::string error_i) {
		MsgError = error_i;
};

std::string Shp34970a_C::getError() {
	return MsgError;
};

std::string Shp34970a_C::recvMessage(std::string message, int adr, GPIB_BUSDATA * status) {
	double rep;
	std::string reponse = "";

	if (message.compare("")) {
		if (strstr(message.c_str(), "?") != NULL) {

			if (strstr(message.c_str(), "SYST:ERR?") != NULL) {
				reponse = getError();
			}

			if (strstr(message.c_str(), "*IDN?") != NULL) {
				AnsiString rep;
				rep = this->getDescription()->getName();
				reponse = Utils::toString(rep);
			}

			*status = GPIB_BUSDATA::REPLY;
			return (reponse.c_str());
		}
		else {
			if (strstr(message.c_str(), "*CLS") != NULL) {
				this->resetInstr();
			}
			if (strstr(message.c_str(), "*RST") != NULL) {
				this->resetInstr();
			}

			if (strstr(message.c_str(), "OUTP:STAT") != NULL) {
				string mesure = RecupDataSCPI(message);
				// this->setOutputState(Utils::toBool(mesure));
			}
			*status = GPIB_BUSDATA::LISTTED;
		}
	}
};
