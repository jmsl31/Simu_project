// ---------------------------------------------------------------------------

#pragma hdrstop

#include "virtual_equipment_C.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// *******************************************************************************************************************
// Implementation vequipment_c
// *******************************************************************************************************************
virtual_equipment_C::virtual_equipment_C() {

	name_m = "";
	Type_m = "";
	temperature_m = 20;
	FActive = false;
	FVerifyInUse = false;
	FLock = false;
	int i;
  /*	tranche_m = new std::vector<virtual_RF_C>;
	alim_m = new std::vector<virtual_alim_C>;
	tmtc_m = new std::vector<virtual_tmtc_C>;  */

};

virtual_equipment_C::~virtual_equipment_C() {
};

void virtual_equipment_C::setTranche(double fq_start_i, double fq_stop_i, double bandwidth_i, double step_i, double power_i, double power_min, double power_max,
  double frequency_min, double frequency_max,double gain_i) {
	virtual_RF_C tranche_temp;
	tranche_temp.initTranche(fq_start_i, fq_stop_i, bandwidth_i, step_i, power_i, power_min, power_max, frequency_min, frequency_max,gain_i);
	tranche_m.push_back(tranche_temp);

};

std::vector<virtual_RF_C> virtual_equipment_C::getTranche() {

	return (tranche_m);
}

void virtual_equipment_C::setAlim(double voltage_i, double current_i, double protVoltage_i, double protcurrent_i,
	double tension_max_i,double courant_min_m,double courant_max_i,double puissance_i,double puissance_max_i) {

	virtual_alim_C alim_temp;

	alim_temp.initAlim(voltage_i, current_i, protVoltage_i, protcurrent_i,tension_max_i,courant_min_m,courant_max_i,
		puissance_i,puissance_max_i);

	alim_m.push_back(alim_temp);
};

std::vector<virtual_alim_C>virtual_equipment_C::getAlim() {

	return (alim_m);
}

double virtual_equipment_C::getTemperature() {
	return (temperature_m);
};

void virtual_equipment_C::setTemperature(double temp_i) {
	temperature_m = temp_i;
};

std::string virtual_equipment_C::getName() {
	return (name_m);
};

void virtual_equipment_C::setName(std::string name_i) {
	name_m = name_i;
};

std::string virtual_equipment_C::getType() {
	return (Type_m);
};

void virtual_equipment_C::setType(std::string type_i) {
	Type_m = type_i;
};

void virtual_equipment_C::SetActiveAlim(bool AValue, int Alim_actif) {

	if (AValue != Active && Alim_actif <= this->alim_m.size()) {

		this->alim_m[Alim_actif].setCurrentActifs();
	}
	else
		throw("Probleme d'activation de l'alimentation");
};

bool virtual_equipment_C::GetActive() {
	return (FActive);
};

void virtual_equipment_C::check_Eqpt(TObject *Sender, virtual_equipment_C *eqpt) {

	int i = 0;

	if (!FActive) {
		for (i = 0; i < eqpt->tranche_m.size(); i++) {

			if (eqpt->tranche_m[i].Overload)
				FActive = false;
		}

		for (i = 0; i < eqpt->alim_m.size(); i++) {

			if (eqpt->alim_m[i].ProtectedVoltage || eqpt->alim_m[i].ProtectedCurrent) {
				FActive = false;
			}

		}
	}
};

void virtual_equipment_C::LockDevice() {
	FLock = true;
};

void virtual_equipment_C::UnlockDevice() {
	FLock = false;
};

void virtual_equipment_C::setTmtc(bool tm_status, bool tm_On_Off) {

	virtual_tmtc_C tmtc_l;

	tmtc_l.Tm_Status = tm_status;
	tmtc_l.Tm_ON_OFF = tm_On_Off;

	tmtc_m.push_back(tmtc_l);
};

std::vector<virtual_tmtc_C>virtual_equipment_C::getTmtc() {
	return (tmtc_m);
};
