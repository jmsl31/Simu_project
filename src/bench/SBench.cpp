// ---------------------------------------------------------------------------

#pragma hdrstop

#include "SBench.h"
#include "Inst_Enum.h"
#include <string>

// ---------------------------------------------------------------------------

#pragma package(smart_init)

SBench_C::SBench_C() : InstObserver() {
	BenchSimu = new SBenchAdrComp();
	BenchSimu->FileName = "D:\\simu_cpp.bax\\baie\\baies.adr";
	BenchSimu->Section = "simu.ba1";
	this->Active = true;

	Name = "";
	pcImmo = "";

	Active_Voltage = 0;
	Active_Current = 0;
	Active_Power = 0;
	resistance_cable = 0;
	Detroppage_resistance = 0;
	voltage_drop = 0;
	Return_Voltage = 0;
	Return_Current = 0;
	cable_longuer = 0;
	Active = false;
	Alim_Active = false;
	OverVoltage = false;
	OverCurrent = false;

};

SBench_C::~SBench_C() {
	delete BenchSimu;
};

AnsiString SBench_C::getPcImmo() {
	return (pcImmo_m);
};

void SBench_C::setPcImmo(AnsiString immo) {
	pcImmo_m = immo;

};

TCal SBench_C::getCalIn() {
	return (*Cal_in);

};

void SBench_C::setCalIn(TCal Cal) {
	*Cal_in = Cal;
};

TCal SBench_C::getCalOut() {
	return (*Cal_out);
};

void SBench_C::setCalOut(TCal Cal) {
	*Cal_out = Cal;
};

TCal SBench_C::getCalSpectrum() {
	return (*Cal_Spectrum);
};

void SBench_C::setCalSpectrum(TCal Cal) {
	*Cal_Spectrum = Cal;
};

void SBench_C::SetActive(bool value) {

	if (BenchSimu->FileName != "" & BenchSimu->Section != "") {

		if (value)
			try {

			BenchSimu->Active = true;
			BenchInit("D:\\simu_cpp.bax\\baie\\Bench\\Bench.ini");
			}
		catch (...) {
			Active = false;
			throw;
		}
	}

};

void SBench_C::BenchInit(AnsiString Name_i) {
	if (!(FileExists(Name_i)))
		throw Exception("Fichier '" + Name_i + "' non trouvé !");
	try {
		TIniFile* BenchFile = new TIniFile(Name_i);
		this->Name = BenchFile->ReadString("Communs", "Nom", "");
		this->pcImmo = BenchFile->ReadString("Communs", "Pc Immo", "");

	}
	catch (...) {
		throw("Erreur Init bench");
	}

	if (Active)
		try {

		if (strstr(Name_i.c_str(), "#ALIM")) {

		}

		}
	catch (...) {
	};
}

void SBench_C::ChangeValueDown(std::string value, TYPE_PARAM type) {
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

void SBench_C::ChangeValueDown(int value, TYPE_PARAM type) {
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

void SBench_C::ChangeValueDown(double value, TYPE_PARAM type) {

	switch (type) {
	case VOLT:
		this->Active_Voltage = value;
		this->notifyChangeValueDown(this->Active_Voltage, VOLT);
		break;
	case CURRENT:
		this->Active_Current = value;
		this->notifyChangeValueDown(value, CURRENT);
		break;
	case POWER:
		this->Active_Power = this->Active_Voltage*this->Active_Current;
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

void SBench_C::ChangeValueDown(bool value, TYPE_PARAM type) {

	switch (type) {
	case VOLT:
		break;
	case CURRENT:
		break;
	case POWER:
		break;
	case ACTIVE_POWER:
		this->Active = value;
		this->notifyChangeValueDown(value, ACTIVE_POWER);
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
		this->OverVoltage = value;
		this->notifyChangeValueDown(this->OverVoltage, OVER_VOLTAGE);
		break;
	case OVER_CURRENT:
		this->OverCurrent = value;
		this->notifyChangeValueDown(this->OverCurrent, OVER_CURRENT);
		break;
	case OVER_TEMPERATURE:
		break;
	case REMOTE_INHIBIT:
		break;
	case UNREGULATION:
		break;
	case ACTIVE_ALIM:
		this->notifyChangeValueDown(value, ACTIVE_ALIM);
		break;

	default: ;
	}
};

void SBench_C::ChangeValueRising(std::string value, TYPE_PARAM type) {

};

void SBench_C::ChangeValueRising(int value, TYPE_PARAM type) {

};

void SBench_C::ChangeValueRising(double value, TYPE_PARAM type) {
	switch (type) {
	case VOLT:
		this->Active_Voltage = value;
		this->notifyChangeValueRising(this->Active_Voltage, VOLT);
		break;
	case VOLTAGE_RETURN:
		this->Return_Voltage = value;
		this->notifyChangeValueRising(this->Return_Voltage, VOLTAGE_RETURN);

		break;
	case CURRENT:
		this->Active_Current = value;
		this->notifyChangeValueRising(this->Active_Current, CURRENT);
		break;

	case CURRENT_RETURN:
		this->Return_Current = value;
		this->notifyChangeValueRising(this->Return_Current, CURRENT_RETURN);
		break;

	case POWER:
		break;
	case ACTIVE_POWER:
		this->Active_Power = value;
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

void SBench_C::ChangeValueRising(bool value, TYPE_PARAM type) {
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
		this->OverVoltage = value;
		this->notifyChangeValueRising(this->OverVoltage, VOLT);
		break;
	case OVER_CURRENT:
		this->OverCurrent = value;
		this->notifyChangeValueRising(this->OverCurrent, CURRENT);
		break;
	case OVER_TEMPERATURE:
		break;
	case REMOTE_INHIBIT:
		break;
	case UNREGULATION:
		break;
	case ACTIVE_ALIM:
		this->Alim_Active = value;
		this->notifyChangeValueRising(this->Alim_Active, ACTIVE_ALIM);
		break;
	default: ;
	}
};
