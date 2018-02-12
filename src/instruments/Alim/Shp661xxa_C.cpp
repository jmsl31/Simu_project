// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Shp661xxa_C.h"
#include "Gpib_Enum.h"
#include "UtilsString.h"
#include <stdio.h>
#include <string.h>
#include <iomanip> // setprecision
#include <sstream> // stringstream

// ---------------------------------------------------------------------------
#pragma package(smart_init)
using namespace Utils;

// Defintion du Thread

void Shp661xxa_C::resetInstr() {

	this->ActiveCurrent = 0.0;
	this->ActiveVoltage = 0.0;
	this->ActiveCurrentProt = 0.0;
	this->ActiveVoltageProt = 0.0;
	this->Error = "No Error";
	this->PowerMax = 0.0;
	this->OverVoltage = false;
	this->OverCurrent = false;
	this->OverTemperature = false;

};

/**
 *\brief  Reception du Message.
 *\param  string message  : Message reçu.
 */

std::string Shp661xxa_C::recvMessage(std::string message, int adr,
	GPIB_BUSDATA* status) {

	double rep;
	std::string reponse = "";

	if (message.compare("")) {
		if (strstr(message.c_str(), "?") != NULL) {
			if (strstr(message.c_str(), "SYST:ERR?") != NULL) {
				this->errorQuery(&reponse);
			}

			if (strstr(message.c_str(), "OUTP:STAT?") != NULL) {
				bool etat;
				this->getOutputState(&etat);
				reponse = Utils::toString(etat);
			}

			if (strstr(message.c_str(), "VOLT?") != NULL) {
				this->getVoltLevel(&rep);
				reponse = Utils::toString(rep, 2);
			}
			if (strstr(message.c_str(), "VOLT:PROT?") != NULL) {
				this->getOVProtLevel(&rep);
				reponse = Utils::toString(rep, 2);
			}
			if (strstr(message.c_str(), "VOLT:TRIG?") != NULL) {
				this->getVoltTrig(&rep);
				reponse = Utils::toString(rep, 2);
			}
			if (strstr(message.c_str(), "CURR?") != NULL) {
				this->getCurrLevel(&rep);
				reponse = Utils::toString(rep, 2);
			}
			if (strstr(message.c_str(), "CURR:PROT?") != NULL) {
				this->getOCProt(&rep);
				reponse = Utils::toString(rep, 2);
			}
			if (strstr(message.c_str(), "CURR:PROT?") != NULL) {
				this->getOCProt(&rep);
				reponse = Utils::toString(rep, 2);
			}
			if (strstr(message.c_str(), "CURR:PROT:STAT?") != NULL) {
				bool etat;
				this->getOCProtState(&etat);
				reponse = Utils::toString(etat);
			}
			if (strstr(message.c_str(), "MEAS:CURR?") != NULL) {
				this->getCurrLevel(&rep);
				reponse = Utils::toString(rep, 2);
			}

			if (strstr(message.c_str(), "MEAS:VOLT?") != NULL) {
				this->getVoltLevel(&rep);
				reponse = Utils::toString(rep, 2);
			}

			if (strstr(message.c_str(), "STAT:QUES:COND?") != NULL) {
				this->registreOver(&reponse);
			}
			if (strstr(message.c_str(), "TRIG:SOUR?") != NULL) {

			}
			if (strstr(message.c_str(), "TRIG:DEL?") != NULL) {

			}
			if (strstr(message.c_str(), "OUTP:TTLT?") != NULL) {

			}
			if (strstr(message.c_str(), "OUTP:TTLT:SOUR?") != NULL) {

			}
			if (strstr(message.c_str(), "TRIG:SOUR?") != NULL) {

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
				this->setOutputState(Utils::toBool(mesure));
			}
			if (strstr(message.c_str(), "VOLT") != NULL) {
				if (strstr(message.c_str(), "PROT") != NULL) {
					string mesure = RecupDataSCPI(message);
					this->setOVProtLevel(Utils::toDouble(mesure));
				}
				else {
					string mesure = RecupDataSCPI(message);
					this->setVoltLevel(Utils::toDouble(mesure));
				}
			}

			if (strstr(message.c_str(), "VOLT:TRIG") != NULL) {
				string mesure = RecupDataSCPI(message);
				this->setVoltTrig(Utils::toDouble(mesure));
			}
			if (strstr(message.c_str(), "CURR") != NULL) {
				string mesure;
				if (strstr(message.c_str(), "PROT") != NULL) {

					mesure = RecupDataSCPI(message);
					this->setOCProt(Utils::toDouble(mesure));

				}
				else {
					mesure = RecupDataSCPI(message);
					this->setCurrLevel(Utils::toDouble(mesure));
				}
			}
			if (strstr(message.c_str(), "CURR:PROT:STAT") != NULL) {
				string mesure = RecupDataSCPI(message);
				this->setOCProtState(Utils::toBool(mesure));
			}
			if (strstr(message.c_str(), "OUTP:PROT:CLE") != NULL) {
				this->ClearProtect();
			}

			if (strstr(message.c_str(), "INITIATE") != NULL) {
				this->startAlim();

			}

			if (strstr(message.c_str(), "*TRG") != NULL) {

			}

			if (strstr(message.c_str(), "TRIG") != NULL) {

			}

			if (strstr(message.c_str(), "TRIG:SOUR BUS") != NULL) {

			}
			if (strstr(message.c_str(), "TRIG:SOUR EXT") != NULL) {

			}
			if (strstr(message.c_str(), "TRIG:SOUR HOLD") != NULL) {

			}
			if (strstr(message.c_str(), "TRIG:SOUR TTLT") != NULL) {

			}
			if (strstr(message.c_str(), "TRIG:DEL") != NULL) {

			}
			if (strstr(message.c_str(), "OUTP:TTLT") != NULL) {

			}

			if (strstr(message.c_str(), "OUTP:TTLT:SOUR BUS") != NULL) {

			}
			if (strstr(message.c_str(), "OUTP:TTLT:SOUR EXT") != NULL) {

			}
			if (strstr(message.c_str(), "OUTP:TTLT:SOUR HOLD") != NULL) {

			}
			if (strstr(message.c_str(), "TRIG:DEL") != NULL) {

			}
			*status = GPIB_BUSDATA::LISTTED;
		}
	}

};

void Shp661xxa_C::registreOver(std::string* overflow) {
	*overflow = Utils::toString((int)Unregulation) + Utils::toString
		((int)RemoteInhibit) + Utils::toString((int)OverTemperature) +
		Utils::toString((int)OverCurrent) + Utils::toString((int)OverVoltage);
};

void Shp661xxa_C::ClearProtect() {
	OverVoltage = false;
	OverCurrent = false;
	OverTemperature = false;
};

void Shp661xxa_C::setVoltTrig(double voltTrig_V_i) {
	VoltTrig = voltTrig_V_i;
};

void Shp661xxa_C::getVoltTrig(double *voltTrig_V_o) {
	*voltTrig_V_o = VoltTrig;
};

void Shp661xxa_C::setOutputState(bool state_o) {
	if (state_o)
		Active = true;
	else
		Active = false;
};

void Shp661xxa_C::getOutputState(bool *state_o) {
	*state_o = Active;
};

void Shp661xxa_C::setOCProtState(bool ovpS_i) {
	ActiveCurrentProt = ovpS_i;
};

void Shp661xxa_C::getOCProtState(bool *ovpS_o) {
	*ovpS_o = ActiveCurrentProt;
};

void Shp661xxa_C::errorQuery(std::string *errorToTolerate_i) {
	*errorToTolerate_i = Error;
};

/* ==================Tension=================================================== */
void Shp661xxa_C::setVoltLevel(double voltLevel_V_i) {

	if (!OverVoltage || !OverCurrent || !OverTemperature) {
		WantingVoltage = voltLevel_V_i;
	}
	else {
		WantingVoltage = 0;
		throw Exception(" Alimentation en Defaut");
	}
};

void Shp661xxa_C::getVoltLevel(double *voltLevel_V_o) {
	*voltLevel_V_o = ActiveVoltage;
};

/* ==================Courant=================================================== */
void Shp661xxa_C::setCurrLevel(double currLevel_A_i) {

	if (!OverVoltage || !OverCurrent || !OverTemperature) {
		WantingCurrent = currLevel_A_i;
	}
	else {
		WantingCurrent = 0.0;
		throw Exception(" Alimentation en Defaut");
	}

};

void Shp661xxa_C::getCurrLevel(double *currLevel_A_o) {
	*currLevel_A_o = ActiveCurrent;
};

void Shp661xxa_C::setOVProtLevel(double OVPLevel_V_i) {
	ActiveVoltageProt = OVPLevel_V_i;
};

void Shp661xxa_C::getOVProtLevel(double *OVPLevel_V_o) {
	*OVPLevel_V_o = ActiveVoltageProt;
};

void Shp661xxa_C::startAlim() {

	if (!OverVoltage || !OverCurrent ||
		!OverTemperature && ActiveCurrent != 0 && ActiveVoltage != 0) {
		ActiveCurrent = WantingCurrent;
		ActiveVoltage = WantingVoltage;
		Active = true;

	}
	else {
		Active = false;
	}
};

void Shp661xxa_C::setOCProt(double ovpS_i) {
	ActiveCurrentProt = ovpS_i;
};

void Shp661xxa_C::getOCProt(double *ovpS_o) {
	*ovpS_o = ActiveCurrentProt;
};

void Shp661xxa_C::changeStatus(GPIB_STATUS status) {
};
