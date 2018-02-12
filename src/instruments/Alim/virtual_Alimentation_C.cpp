// ---------------------------------------------------------------------------

#pragma hdrstop

#include "virtual_Alimentation_C.h"
#include "Shp661xxa_C.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#define ALIM_ENUM_LENGTH        12

virtual_alimentation_C::virtual_alimentation_C() {

	ActiveCurrent = 0;
	ActiveVoltage = 0;

	WantingVoltage = 0;
	WantingCurrent = 0;
	Channel = 0;
	SubChannel = 0;
	VoltageMax = 0;
	CurrentMax = 0;
	PowerMax = 0;
	VoltageRMS = 0;
	CurrentRMS = 0;
	VoltagePeak = 0;
	Name = "";
	Error = "No Error";
	Active = false;
	VoltTrig = 0;
	PowerMax = 0;

	ActiveOverCurrent = false;
	OverVoltage = false;
	OverCurrent = false;
	OverTemperature = false;
	RemoteInhibit = false;
	Unregulation = false;

};

void virtual_alimentation_C::setOverVoltage(bool etat) {
	FOverVoltage = etat;
	this->notifyChangeValueDown(etat, TYPE_PARAM::OVER_VOLTAGE);
};

void virtual_alimentation_C::setOverCurrent(bool etat) {
	FOverCurrent = etat;
	this->notifyChangeValueDown(etat, TYPE_PARAM::OVER_CURRENT);
};

void virtual_alimentation_C::setOverTemperature(bool etat) {
	FOverTemperature = etat;
	this->notifyChangeValueDown(etat, TYPE_PARAM::OVER_TEMPERATURE);
};

void virtual_alimentation_C::setRemoteInhibit(bool etat) {
	FRemoteInhibit = etat;
	this->notifyChangeValueDown(etat, TYPE_PARAM::REMOTE_INHIBIT);
};

void virtual_alimentation_C::setUnregulation(bool etat) {
	FUnregulation = etat;
	this->notifyChangeValueDown(etat, TYPE_PARAM::UNREGULATION);
};

void virtual_alimentation_C::setActive(bool etat) {
	FActive = etat;
	this->notifyChangeValueDown(etat, TYPE_PARAM::ACTIVE_ALIM);
	this->notifyChangeValueDown(this->ActiveVoltage, VOLT);
	setpowerMax(this->ActiveCurrent * this->ActiveVoltage);
};

void virtual_alimentation_C::setActiveCurrent(double value) {
	activeCurrent_m = value;
	this->notifyChangeValueDown(value, TYPE_PARAM::CURRENT);
	setpowerMax(this->ActiveCurrent * this->ActiveVoltage);
};

void virtual_alimentation_C::setActiveVoltage(double value) {
	activeVoltage_m = value;
	this->notifyChangeValueDown(value, TYPE_PARAM::VOLT);
};

void virtual_alimentation_C::setpowerMax(double value) {
	powerMax_m = value;
	this->notifyChangeValueDown(value, TYPE_PARAM::POWER);
};

void virtual_alimentation_C::ChangeValueRising(std::string value,
	TYPE_PARAM type) {

	switch (type) {
	case VOLT:
		break;
	case CURRENT:
		break;
	case POWER:
		break;
	case ACTIVE_POWER:
		break;
	case FREQ_START_IN:
		break;
	case FREQ_STOP_IN:
		break;
	case FREQ_START_OUT:
		break;
	case FREQ_STOP_OUT:
		break;
	case BANDWIDTH:
		break;
	case STEP:
		break;
	case FREQ_OL:
		break;
	case POWER_IN:
		break;
	case POWER_OUT:
		break;
	case POWER_OL:
		break;
	case OVER_VOLTAGE:
		break;
	case OVER_CURRENT:
		break;
	case OVER_TEMPERATURE:
		break;
	case REMOTE_INHIBIT:
		break;
	case UNREGULATION:
		break;
	case ACTIVE_ALIM:
		break;
	default: ;
	}
};

void virtual_alimentation_C::ChangeValueRising(int value, TYPE_PARAM type) {
	switch (type) {
	case VOLT:
		break;
	case CURRENT:
		break;
	case POWER:
		break;
	case ACTIVE_POWER:
		break;
	case FREQ_START_IN:
		break;
	case FREQ_STOP_IN:
		break;
	case FREQ_START_OUT:
		break;
	case FREQ_STOP_OUT:
		break;
	case BANDWIDTH:
		break;
	case STEP:
		break;
	case FREQ_OL:
		break;
	case POWER_IN:
		break;
	case POWER_OUT:
		break;
	case POWER_OL:
		break;
	case OVER_VOLTAGE:
		break;
	case OVER_CURRENT:
		break;
	case OVER_TEMPERATURE:
		break;
	case REMOTE_INHIBIT:
		break;
	case UNREGULATION:
		break;
	case ACTIVE_ALIM:
		break;
	default: ;
	}
};

void virtual_alimentation_C::ChangeValueRising(double value, TYPE_PARAM type) {
	switch (type) {
	case VOLT:
		this->ActiveVoltage = value;
		break;
	case VOLTAGE_RETURN:
		this->WantingVoltage = value;
		if (WantingVoltage >= VoltageMax) {
			WantingVoltage = 0;
			WantingCurrent = 0;
			this->notifyChangeValueDown(WantingVoltage, VOLT);
			this->notifyChangeValueDown(WantingCurrent, CURRENT);
			this->notifyChangeValueDown(WantingVoltage* WantingCurrent, POWER);
			this->FOverVoltage = true;
			this->notifyChangeValueDown(FOverVoltage, OVER_VOLTAGE);
		}
		break;
	case CURRENT_RETURN:
		this->WantingCurrent = value;
		if (WantingCurrent >= CurrentMax) {
			WantingCurrent = 0;
			this->notifyChangeValueDown(WantingCurrent, CURRENT);
			this->FOverCurrent = true;
			this->notifyChangeValueDown(FOverCurrent, OVER_CURRENT);
		}
		break;
	case CURRENT:
		this->ActiveCurrent = value;
		break;
	case POWER:
		break;
	case ACTIVE_POWER:
		break;
	case FREQ_START_IN:
		break;
	case FREQ_STOP_IN:
		break;
	case FREQ_START_OUT:
		break;
	case FREQ_STOP_OUT:
		break;
	case BANDWIDTH:
		break;
	case STEP:
		break;
	case FREQ_OL:
		break;
	case POWER_IN:
		break;
	case POWER_OUT:
		break;
	case POWER_OL:
		break;
	case OVER_VOLTAGE:
		break;
	case OVER_CURRENT:
		break;
	case OVER_TEMPERATURE:
		break;
	case REMOTE_INHIBIT:
		break;
	case UNREGULATION:
		break;
	case ACTIVE_ALIM:
		break;
	default: ;
	}
};

void virtual_alimentation_C::ChangeValueRising(bool value, TYPE_PARAM type) {
	switch (type) {
	case VOLT:
		this->FOverVoltage = value;
		break;
	case CURRENT:
		this->FOverCurrent = value;
		break;
	case POWER:
		break;
	case ACTIVE_POWER:
		break;
	case FREQ_START_IN:
		break;
	case FREQ_STOP_IN:
		break;
	case FREQ_START_OUT:
		break;
	case FREQ_STOP_OUT:
		break;
	case BANDWIDTH:
		break;
	case STEP:
		break;
	case FREQ_OL:
		break;
	case POWER_IN:
		break;
	case POWER_OUT:
		break;
	case POWER_OL:
		break;
	case OVER_VOLTAGE:
		break;
	case OVER_CURRENT:
		break;
	case OVER_TEMPERATURE:
		break;
	case REMOTE_INHIBIT:
		break;
	case UNREGULATION:
		break;
	case ACTIVE_ALIM:
		this->FActiveReturn = value;
		break;
	default: ;
	}
};

void virtual_alimentation_C::changeStatus(GPIB_STATUS status) {
};

std::string virtual_alimentation_C::recvMessage(std::string message, int adr,
	GPIB_BUSDATA* status) {
};

void virtual_alimentation_C::ChangeConfiguration() {
};

void virtual_alimentation_C::ChangeAdrPrimaire(int Adr) {
};

void virtual_alimentation_C::ChangeAdrSecondaire(int Adr) {
};

void virtual_alimentation_C::timeoutRecvData(double timeout) {
};
