// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Rx_C.h"
#include "UtilsString.h"
#include "ConstanteDefine.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#define num_tranche 0

using namespace Utils;

Rx_C::Rx_C() {

};

void Rx_C::InitEqpt(TIniFile *file) {

	Equipement_RX* def_Eqpt = new Equipement_RX();
	int i;

	// Initialisation des variables du fichier.
	def_Eqpt->eqpt.nb_Tranche = file->ReadInteger("Communs", "Nb Tranche", 1);
	def_Eqpt->eqpt.nb_Alim = file->ReadInteger("Communs", "Nb Alim", 1);
	def_Eqpt->eqpt.nb_Tmtc = file->ReadInteger("Communs", "Nb Tmtc", 152);
	this->Name = Utils::toString(file->ReadString("Communs", "Nom",
		"Rx_générique"));
	this->Type = Utils::toString(file->ReadString("Communs", "Type", "RX"));
	def_Eqpt->alimentation.voltage_actif_m = 0;
	def_Eqpt->alimentation.current_actif_m = 0;
	def_Eqpt->alimentation.voltage_m =
		file->ReadFloat("Alimentation", "Tension", 100);
	def_Eqpt->alimentation.current_m =
		file->ReadFloat("Alimentation", "Courant", 0.100);
	def_Eqpt->alimentation.voltageMax_m =
		file->ReadFloat("Alimentation", "Tension Max", 102);
	def_Eqpt->alimentation.courantMin_m =
		file->ReadFloat("Alimentation", "Courant Min", 0.150);
	def_Eqpt->alimentation.courantMax_m =
		file->ReadFloat("Alimentation", "Courant Max", 0.150);
	def_Eqpt->alimentation.puissance_m =
		file->ReadFloat("Alimentation", "Puissance", 0.150);
	def_Eqpt->alimentation.puissanceMax_m =
		file->ReadFloat("Alimentation", "Puissance Max", 0.150);
	def_Eqpt->frequence.frequency_Start_In =
		file->ReadFloat("RF", "Frequence Start", 11000);
	def_Eqpt->frequence.frequency_Stop_In =
		file->ReadFloat("RF", "Frequence Stop", 12000);
	def_Eqpt->frequence.bandwidth = file->ReadFloat("RF", "Bandwidth", 1000);
	def_Eqpt->frequence.step = file->ReadFloat("RF", "Step", 1);
	def_Eqpt->frequence.power_in = file->ReadFloat("RF", "Power", -45);
	def_Eqpt->frequence.frequency_Max =
		file->ReadFloat("RF", "Frequence max", 2500);
	def_Eqpt->frequence.frequency_Min =
		file->ReadFloat("RF", "Frequence min", -45);
	def_Eqpt->frequence.power_max = file->ReadFloat("RF", "Power Max", -50);
	def_Eqpt->frequence.power_min = file->ReadFloat("RF", "Power Min", 40);

	def_Eqpt->frequence.frequency_Ol =
		file->ReadFloat("RF", "Frequence Ol", 2000);
	def_Eqpt->frequence.frequencyOlMax =
		file->ReadFloat("RF", "Power Ol Max", 26000);
	def_Eqpt->frequence.frequencyOlMin =
		file->ReadFloat("RF", "Power Ol Min", -80);
	def_Eqpt->frequence.power_Ol = file->ReadFloat("RF", "Power Ol", -25);
	def_Eqpt->frequence.powerOlMax = file->ReadFloat("RF", "Power Ol Max", -25);
	def_Eqpt->frequence.powerOlMin = file->ReadFloat("RF", "Power Ol Min", -25);

	def_Eqpt->frequence.gain = file->ReadFloat("RF", "Gain", -25);

	// Initialisation des tranches Rf.

	for (i = 0; i < def_Eqpt->eqpt.nb_Tranche; i++) {

		this->setTranche(def_Eqpt->frequence.frequency_Start_In,
			def_Eqpt->frequence.frequency_Stop_In,
			def_Eqpt->frequence.bandwidth, def_Eqpt->frequence.step,
			def_Eqpt->frequence.power_in, def_Eqpt->frequence.power_min,
			def_Eqpt->frequence.power_max, def_Eqpt->frequence.frequency_Min,
			def_Eqpt->frequence.frequency_Max, def_Eqpt->frequence.gain);

	}
	// Initialisation de OL.

	Frequency_OL = def_Eqpt->frequence.frequency_Ol;
	Power_Ol = def_Eqpt->frequence.power_Ol;

	// Initialisation des Alimentations.

	for (i = 0; i < def_Eqpt->eqpt.nb_Alim; i++) {
		this->setAlim(def_Eqpt->alimentation.voltage_m,
			def_Eqpt->alimentation.current_m,
			def_Eqpt->alimentation.voltageMax_m,
			def_Eqpt->alimentation.courantMax_m,
			def_Eqpt->alimentation.voltageMax_m,
			def_Eqpt->alimentation.courantMin_m,
			def_Eqpt->alimentation.courantMax_m,
			def_Eqpt->alimentation.puissance_m,
			def_Eqpt->alimentation.puissanceMax_m);
	}

	// Initialisation Tmtc.

	for (i = 0; i < def_Eqpt->eqpt.nb_Tmtc; i++) {
		this->setTmtc(false, false);

	}
};

double Rx_C::getNb_Tranche() {
	return (tranche_m.size());
};

double Rx_C::getNb_Alim() {
	return (alim_m.size());
};

double Rx_C::getNb_Tmtc() {
	return (tmtc_m.size());
};

double Rx_C::getFrequency_Start_Out(int Num_Tranche) {

	int i = 0;

	for (i = 0; i < tranche_m.size(); i++) {
		tranche_m[i].Frequency_Start_Out = tranche_m[i].Frequency_Start_In -
			Frequency_OL;
	}
	return (tranche_m[Num_Tranche].Frequency_Start_Out);
};

void Rx_C::setFrequency_Start_Out(int Num_Tranche, double fq_out_start_i) {
	tranche_m[Num_Tranche].Frequency_Start_Out;
};

double Rx_C::getFrequency_Stop_Out(int Num_Tranche) {
	int i = 0;

	for (i = 0; i < tranche_m.size(); i++) {
		tranche_m[i].Frequency_Stop_Out = tranche_m[i].Frequency_Stop_In -
			Frequency_OL;
	}
	return (tranche_m[Num_Tranche].Frequency_Stop_Out);
};

void Rx_C::setFrequency_Stop_Out(int Num_Tranche, double fq_out_stop_i) {
	tranche_m[Num_Tranche].Frequency_Stop_Out;
};

void Rx_C::setActive() {

	if (this->Active) {
		if (this->alim_m[num_tranche].VoltageMax <
			this->alim_m[num_tranche].VoltageActif) {

			this->alim_m[num_tranche].ProtectedVoltage = true;
			this->alim_m[num_tranche].VoltageActif = 0;
			this->alim_m[num_tranche].CurrentActif = 0;
		}

		if (this->alim_m[num_tranche].CurrentMax <
			this->alim_m[num_tranche].CurrentActif) {

			this->alim_m[num_tranche].ProtectedCurrent = true;
			this->alim_m[num_tranche].Current = 0;
		}

		this->alim_m[num_tranche].setCurrentActifs();
		this->notifyChangeValueRising(this->alim_m[num_tranche].VoltageActif,
			VOLTAGE_RETURN);
		this->notifyChangeValueRising(this->alim_m[num_tranche].CurrentActif,
			CURRENT_RETURN);
		this->notifyChangeValueRising(this->alim_m[num_tranche].Puissance,
			ACTIVE_POWER);

	}
};

void Rx_C::ChangeValueDown(std::string value, TYPE_PARAM type) {

};

void Rx_C::ChangeValueDown(int value, TYPE_PARAM type) {
};

void Rx_C::ChangeValueDown(double value, TYPE_PARAM type) {

	switch (type) {
	case VOLT:
		if (this->alim_m[num_tranche].Active) {

			this->alim_m[num_tranche].VoltageActif = value;
			if (this->alim_m[num_tranche].VoltageActif != 0) {
				this->alim_m[num_tranche].setCurrentActifs();
				this->alim_m[num_tranche].setPuissanceActive();
				this->ReturnValue(this->alim_m[num_tranche].VoltageActif,
					this->alim_m[num_tranche].CurrentActif,
					this->alim_m[num_tranche].ProtectedVoltage,
					this->alim_m[num_tranche].ProtectedCurrent, true, true,
					this->alim_m[num_tranche].Puissance);
			}
			else {
				this->ReturnValue(0, 0, true, false, false, false, 0);

			}
		}

		break;
	case POWER:
		this->alim_m[num_tranche].PuissanceActive = value;
		break;
	case ACTIVE_POWER:
		break;
	case FREQ_START_IN:
		this->tranche_m[num_tranche].Frequency_Start_In = value;
		break;
	case FREQ_STOP_IN:
		this->tranche_m[num_tranche].Frequency_Start_Out = value;
		break;
	case FREQ_START_OUT:
		this->tranche_m[num_tranche].Frequency_Start_Out = value;
		break;
	case FREQ_STOP_OUT:
		this->tranche_m[num_tranche].Frequency_Stop_Out = value;
		break;
	case BANDWIDTH:
		this->tranche_m[num_tranche].Bandwidth = value;
		break;
	case STEP:
		this->tranche_m[num_tranche].Step = value;
		break;
	case FREQ_OL:
		this->Frequency_OL = value;
		break;
	case POWER_IN:
		this->PowerIn = value;
		break;
	case POWER_OUT:

		break;
	case POWER_OL:
		this->Power_Ol = value;
		break;
	default: ;
	}

};

void Rx_C::ChangeValueDown(bool value, TYPE_PARAM type) {

	switch (type) {
	case OVER_VOLTAGE:
		this->alim_m[num_tranche].ProtectedVoltage = value;
		this->notifyChangeValueRising
			(this->alim_m[num_tranche].ProtectedVoltage, OVER_VOLTAGE);
		break;
	case OVER_CURRENT:
		this->alim_m[num_tranche].ProtectedCurrent = value;
		this->notifyChangeValueRising
			(this->alim_m[num_tranche].ProtectedCurrent, OVER_CURRENT);
		break;
	case OVER_TEMPERATURE:
		break;
	case REMOTE_INHIBIT:
		break;
	case UNREGULATION:
		break;
	case ACTIVE_POWER:
		this->Active = value;
		break;
	case ACTIVE_ALIM:
		this->Active = value;
		this->alim_m[num_tranche].Active = value;
		this->setActive();
		this->notifyChangeValueRising(this->alim_m[num_tranche].VoltageActif,
			VOLTAGE_RETURN);
		this->notifyChangeValueRising(this->alim_m[num_tranche].CurrentActif,
			CURRENT_RETURN);
		break;
	default:

		;
	}
};

void Rx_C::ReturnValue(double Voltage, double Current, bool overvoltage,
	bool overcurrent, bool active_power, bool active_alim, double power) {
this->notifyChangeValueRising(Voltage, VOLTAGE_RETURN);
this->notifyChangeValueRising(Current, CURRENT_RETURN);
this->notifyChangeValueRising(overcurrent, OVER_CURRENT);
this->notifyChangeValueRising(overvoltage, OVER_VOLTAGE);
this->notifyChangeValueRising(active_power, ACTIVE_POWER);
this->notifyChangeValueRising(active_alim, ACTIVE_ALIM);
this->notifyChangeValueRising(active_power, POWER);

};
