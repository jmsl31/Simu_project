// ---------------------------------------------------------------------------

#pragma hdrstop

#include "virtual_alim_C.h"
#include "ConstanteDefine.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

// *******************************************************************************************************************
// Implementation VAlim_C
// *******************************************************************************************************************
virtual_alim_C::virtual_alim_C() {
};

void virtual_alim_C::initAlim(double voltage_i, double current_i,
	double protVoltage_i, double protcurrent_i, double tension_max_i,
	double courant_min_i, double courant_max_i, double puissance_i,
	double puissance_max_i) {

	FProtectedCurrent = false;
	FProtectedVoltage = false;
	this->setProtCurrent(protcurrent_i);
	this->setProtVoltage(protVoltage_i);
	this->setVoltage(voltage_i);
	this->setCurrent(current_i);
	this->setPuissanceMax(puissance_max_i);
	this->setCurrentMin(courant_min_i);
	this->setCurrentMax(courant_max_i);
	this->setVoltageMax(tension_max_i);
	this->setPuissance(puissance_i);
	this->setVoltageActifs(0);
	current_actif_m = 0;
	FActive = false;

};

virtual_alim_C::~virtual_alim_C() {
};

double virtual_alim_C::getVoltage() {
	if (voltage_m > protVoltage_m) {
		voltage_m = 0;
		current_m = 0;
		FProtectedVoltage = true;
	}
	else
		return (voltage_m);

};

void virtual_alim_C::setVoltage(double voltage_i) {

	if (voltage_i > protVoltage_m || ProtectedVoltage) {
		voltage_m = 0;
		FProtectedVoltage = true;
		setPuissanceActive();
	}
	else {
		voltage_m = voltage_i;
		FProtectedVoltage = false;
		setPuissanceActive();
	}

};

double virtual_alim_C::getPuissance() {

	return (puissance_m);
};

void virtual_alim_C::setPuissance(double value) {

	if (ProtectedVoltage || ProtectedCurrent) {
		puissance_m = 0;
	}
	else
		puissance_m = value;
};


double virtual_alim_C::getPuissanceActive() {

	return (puissance_m);
};

void virtual_alim_C::setPuissanceActive() {

	if (ProtectedVoltage || ProtectedCurrent) {
		puissance_active_m = 0;
	}
	else
		puissance_active_m = puissance_m;

};

double virtual_alim_C::getCurrent() {

	if (current_m > protcurrent_m) {
		return (0);
		FProtectedCurrent = true;
	}
	else
		return (current_m);
};

void virtual_alim_C::setCurrent(double current_i) {

	if (current_i >= protcurrent_m || ProtectedCurrent || ProtectedVoltage) {
		current_m = 0;
		FProtectedCurrent = true;
		setPuissanceActive();
	}
	else {
		current_m = current_i;
		FProtectedCurrent = false;
		setPuissanceActive();
	}
};

double virtual_alim_C::getProtVoltage() {
	return (protVoltage_m);
};

void virtual_alim_C::setProtVoltage(double ProtVoltage_i) {

	protVoltage_m = ProtVoltage_i;
};

double virtual_alim_C::getVoltageActifs() {
	return (voltage_actif_m);
};

void virtual_alim_C::setVoltageActifs(double Voltage_i) {
	if (this->Active || !this->ProtectedCurrent || !this->ProtectedVoltage) {

		if (Voltage_i < VoltageMax) {
			voltage_actif_m = Voltage_i;
			FProtectedVoltage = false;
		}
		else {
			voltage_actif_m = 0;
			CurrentActif = 0;
			FProtectedVoltage = true;
		}
	}
};

double virtual_alim_C::getCurrentActifs() {

	return (current_actif_m);
};

void virtual_alim_C::setCurrentActifs() {

	if (this->Active || !this->ProtectedCurrent || !this->ProtectedVoltage) {

		if (this->getVoltageActifs() != 0) {
			current_actif_m = this->getPuissance() / this->getVoltageActifs();
		}

		if (current_actif_m >= CurrentMax) {
			FProtectedCurrent = true;
			current_actif_m = 0;
		}
		else
			FProtectedCurrent = false;

		if (voltage_actif_m >= VoltageMax) {
			voltage_actif_m = 0;
			FProtectedVoltage = true;
		}
		else
			FProtectedVoltage = false;
	}
	else if (this->Active || this->getVoltageActifs() != 0 && this->ProtectedCurrent) {
		current_actif_m = 0;
		puissance_active_m = 0;
	}
	else if (this->Active || this->getVoltageActifs() != 0 && this->ProtectedVoltage) {
		current_actif_m = 0;
		voltage_actif_m = 0;
		puissance_active_m = 0;
	}
	else {
		current_actif_m = 0;
		voltage_actif_m = 0;
		puissance_active_m = 0;
		this->ProtCurrent = true;
	}
}

double virtual_alim_C::getProtCurrent() {
	return (protcurrent_m);
};

void virtual_alim_C::setProtCurrent(double ProtCurrent_i) {
	protcurrent_m = ProtCurrent_i;
}

double virtual_alim_C::getVoltageMax() {
	return (tension_max_m);
};

void virtual_alim_C::setVoltageMax(double voltage_i) {
	tension_max_m = voltage_i;
};

double virtual_alim_C::getCurrentMin() {
	return (courant_min_m);
};

void virtual_alim_C::setCurrentMin(double current_i) {
	courant_min_m = current_i;
};

double virtual_alim_C::getCurrentMax() {
	return (courant_max_m);
};

void virtual_alim_C::setCurrentMax(double current_i) {
	courant_max_m = current_i;
};

double virtual_alim_C::getPuissanceMax() {
	return (puissance_max_m);
};

void virtual_alim_C::setPuissanceMax(double puissance_i) {
	puissance_max_m = puissance_i;
};