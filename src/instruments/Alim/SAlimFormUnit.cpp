// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SAlimFormUnit.h"
#include "ConstanteDefine.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma link "AdvSmoothLedLabel"
#pragma link "AdvGlassButton"
#pragma resource "*.dfm"

using namespace Utils;

TAlimFormUnit *AlimFormUnit;

void __fastcall TAlimFormUnit::FormShow(TObject *Sender, AnsiString filebaie,
	AnsiString baie, AnsiString caption) {

	// instantiation de l'objet  SAlimentaions.
	AlimDevice = new SAlimentations();
	// instantiation de l'objet TAlimThread.
	TAlimThread* Thread = new TAlimThread(true, AlimDevice);
	// defintion de la priorité du thread.
	Thread->Priority = tpLower;

	// "D:\\simu_cpp.bax\\baie\\baies.adr"
	AlimDevice->BenchAdrFile->FileName = filebaie;
	// "simu.ba1"
	AlimDevice->BenchAdrFile->Section = baie;
	// "ALIM1 #01"
	AlimDevice->Caption = caption;
	// Activation de l'objet AlimDevice.
	AlimDevice->Active = true;

	AlimDevice->Device->OverVoltage = false;
	AlimDevice->Device->OverCurrent = false;
	AlimDevice->Device->OverTemperature = false;

	// execution du Thread de mise à jour  de l'ihm;
	Thread->Resume();
	// MsgEvent(this,ALIM_MESSAGE,ALIM_TREAD_INIT);
};

// ---------------------------------------------------------------------------
__fastcall TAlimFormUnit::TAlimFormUnit(TComponent* Owner) : TSimuForm(Owner) {

	this->Caption = "Alimentation";
	this->GroupBoxAlim->Caption = "Nom de l'alimentation";
	this->FormShow(Owner, "D:\\simu_cpp.bax\\baie\\baies.adr", "simu.ba1",
		"ALIM1 #01");
}

void TAlimFormUnit::setVoltageActive(double tension) {
	VoltageLabel->Caption->Value = tension;
	// MsgEvent(this,ALIM_MESSAGE,ALIM_TENSION_ACTIVE);
};

double TAlimFormUnit::getVoltageActive() {
	return (VoltageLabel->Caption->Value);
};

void TAlimFormUnit::setCurrentActive(double courant) {
	CurrentLabel->Caption->Value = courant;
	// MsgEvent(this,ALIM_MESSAGE,ALIM_COURANT_ACTIF);
};

double TAlimFormUnit::getCurrentActive() {
	return (CurrentLabel->Caption->Value);
};

void TAlimFormUnit::setOverVoltage(bool b) {

	if (b) {
		ShapeOverVoltage->Brush->Color = clRed;
		AlimDevice->Device->OverVoltage = true;
		// MsgEvent(this,ALIM_MESSAGE,ALIM_OVERVOLTAGE);
	}
	else {
		ShapeOverVoltage->Brush->Color = clSilver;
		AlimDevice->Device->OverVoltage = false;
	}
};

bool TAlimFormUnit::getOverVoltage() {

	if (ShapeOverVoltage->Brush->Color == clLime)
		return (true);

	else
		return false;
};

void TAlimFormUnit::setOverCurrent(bool b) {

	if (b) {
		ShapeOverCurrent->Brush->Color = clRed;
		AlimDevice->Device->OverCurrent = true;
		// MsgEvent(this,ALIM_MESSAGE,ALIM_OVERCURRENT);
	}
	else {
		ShapeOverCurrent->Brush->Color = clSilver;
		AlimDevice->Device->OverCurrent = false;
	}
};

bool TAlimFormUnit::getOverCurrent() {

	if (ShapeOverVoltage->Brush->Color == clLime)
		return (true);
	else
		return false;
};

void TAlimFormUnit::setOverTemperature(bool b) {

	if (b) {
		AlimDevice->Device->OverTemperature = true;
		ShapeOverTemperature->Brush->Color = clRed;
		// MsgEvent(this,ALIM_MESSAGE,ALIM_OVERTEMPERATURE);

	}
	else {
		AlimDevice->Device->OverTemperature = false;
		ShapeOverTemperature->Brush->Color = clSilver;
	}
};

bool TAlimFormUnit::getOverTemperature() {

	if (ShapeOverTemperature->Brush->Color == clLime) {
		OverTemperature = true;
		return (true);
	}
	else {
		OverTemperature = false;
		return false;
	}

};

void TAlimFormUnit::setRemote(bool b) {

	if (b)
		ShapeRemote->Brush->Color = clLime;
	else
		ShapeRemote->Brush->Color = clSilver;
};

bool TAlimFormUnit::getRemote() {

	if (ShapeRemote->Brush->Color == clLime)
		return (true);
	else
		return false;
};

void TAlimFormUnit::setUnregulation(bool b) {

	if (b) {
		ShapeUnregulation->Brush->Color = clLime;
		// MsgEvent(this,ALIM_MESSAGE,ALIM_UNREGULATION);
	}
	else
		ShapeUnregulation->Brush->Color = clSilver;

};

bool TAlimFormUnit::getUnregulation() {

	if (ShapeUnregulation->Brush->Color == clLime)
		return (true);
	else
		return false;
};

void TAlimFormUnit::setActive(bool b) {

	setRemote(true);
	if (b) {
		ShapeActive->Brush->Color = clLime;
		// MsgEvent(this,ALIM_MESSAGE,ALIM_ACTIVE);
	}
	else
		ShapeActive->Brush->Color = clSilver;
};

bool TAlimFormUnit::getActive() {

	if (ShapeActive->Brush->Color == clLime)
		return (true);
	else
		return false;
};

void TAlimFormUnit::setTensionMax(double t) {
	TextTensionMax->Text = t;
};

double TAlimFormUnit::getTensionMax() {

	return (TextTensionMax->Text.ToDouble());
};

void TAlimFormUnit::setCourantMax(double t) {
	TextCourantMax->Text = t;
};

double TAlimFormUnit::getCourantMax() {
	return (TextCourantMax->Text.ToDouble());
};

void TAlimFormUnit::setPowerMax(double t) {
	TextPowerMax->Text = t;
};

double TAlimFormUnit::getPowerMax() {
	return (TextPowerMax->Text.ToDouble());
};

void TAlimFormUnit::setTensionRMS(double t) {
	TextTensionRMS->Text = t;
};

double TAlimFormUnit::getTensionRMS() {
	return (TextTensionRMS->Text.ToDouble());
};

void TAlimFormUnit::setTensionpeak(double t) {
	TextTensionpeak->Text = t;
};

double TAlimFormUnit::getTensionpeak() {
	return (TextTensionpeak->Text.ToDouble());
};

void TAlimFormUnit::setCourantRMS(double t) {
	TextCourantRMS->Text = t;
};

double TAlimFormUnit::getCourantRMS() {
	return (TextCourantRMS->Text.ToDouble());
};

void TAlimFormUnit::setTensionApp(double t) {

	if (this->AlimDevice->Device->Active) {
		this->AlimDevice->Device->WantingVoltage = t;
	}
	else {
		this->AlimDevice->Device->ActiveVoltage = t;
	}
};

double TAlimFormUnit::getTensionApp() {
	return (ActionTensionText->Text.ToDouble());
};

void TAlimFormUnit::setCourantApp(double t) {

	if (this->AlimDevice->Device->Active) {
		this->AlimDevice->Device->WantingCurrent = t;
	}
	else {
		this->AlimDevice->Device->ActiveCurrent = t;
	}
};

double TAlimFormUnit::getCourantApp() {
	return (ActionCourantText->Text.ToDouble());
};

void TAlimFormUnit::setOVoltage() {

	BOverVoltage = true;
};

void TAlimFormUnit::setOTemperature() {
	AlimDevice->Device->OverTemperature = true;
};

void TAlimFormUnit::setUregulation() {
	BUnRegulation = true;

};

void TAlimFormUnit::SetInit() {
	BOverVoltage = false;
	BOverTemperature = false;
	BUnRegulation = false;
	AlimDevice->Device->OverCurrent = false;
	AlimDevice->Device->OverVoltage = false;
	AlimDevice->Device->OverTemperature = false;
	// MsgEvent(this,ALIM_MESSAGE,INIT_ALIM);
};

void __fastcall TAlimFormUnit::ButTensionparamClick(TObject *Sender) {
	setTensionApp(this->ActionTensionText->Text.ToDouble());
	MsgEvent(this, LOG_ALIM_MESSAGE,
		ALIM_BT_VOLTAGE_USER +this->ActionTensionText->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TAlimFormUnit::ButCourantAppClick(TObject *Sender) {
	setCourantApp(this->ActionCourantText->Text.ToDouble());
	// MsgEvent(this,ALIM_MESSAGE,ALIM_BT_CURRENT_USER);
}
// ---------------------------------------------------------------------------

void __fastcall TAlimFormUnit::AdvGlassButton1Click(TObject *Sender) {
	this->SetInit();
	// MsgEvent(this,ALIM_MESSAGE,ALIM_BT_RESET);
	if (this->AlimDevice->Device->Active) {
		this->AlimDevice->Device->WantingVoltage = 0.0;
		this->AlimDevice->Device->WantingCurrent = 0.0;
	}
	else {
		this->AlimDevice->Device->ActiveVoltage = 0.0;
		this->AlimDevice->Device->ActiveCurrent = 0.0;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TAlimFormUnit::ButDisjonctionAppClick(TObject *Sender) {
	if (this->AlimDevice->Device->Active) {
		this->AlimDevice->Device->WantingCurrent = 0.0;
	}
	else {
		this->AlimDevice->Device->ActiveCurrent = 0.0;
	}
	// MsgEvent(this,ALIM_MESSAGE,ALIM_BT_OVERCURRENT);
}
// ---------------------------------------------------------------------------

void __fastcall TAlimFormUnit::ButSurchauffeAppClick(TObject *Sender) {

	if (this->AlimDevice->Device->Active) {
		this->AlimDevice->Device->WantingVoltage = 0.0;
		this->AlimDevice->Device->WantingCurrent = 0.0;
	}
	else {
		this->AlimDevice->Device->ActiveVoltage = 0.0;
		this->AlimDevice->Device->ActiveCurrent = 0.0;
	}
	this->OverTemperature = true;
}

void __fastcall TAlimFormUnit::ButHelpAlimClick(TObject *Sender) {
	Application->HelpContext(0);
}
// ---------------------------------------------------------------------------
