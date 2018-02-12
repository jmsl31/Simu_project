// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "SAlimThread.h"

#pragma package(smart_init)
// ---------------------------------------------------------------------------

// Important : Les méthodes et les propriétés des objets de la VCL peuvent seulement être
// utilisées dans une méthode appelée avec Synchronize, par exemple :
//
// Synchronize(&UpdateCaption);
//
// où UpdateCaption pourrait ressembler à :
//
// void __fastcall TAlimThread::UpdateCaption()
// {
// Form1->Caption = "Mis à jour dans un thread";
// }
// ---------------------------------------------------------------------------

__fastcall TAlimThread::TAlimThread(bool CreateSuspended, SAlimentations* Alim)
	: TThread(CreateSuspended) {

	this->Priority = tpIdle;
	stop_m = 0;
	this->setAlim(Alim);
}

// ---------------------------------------------------------------------------
void __fastcall TAlimThread::Execute() {
	NameThreadForDebugging(System::String(L"AlimThread"));

	try {
		while (!stop_m) {
			/* Wait for 100 milliseconds. */
			Sleep(100);

			/*
			 Run the AddNewNumberToMemo procedure on the main thread.
			 This makes it safe to access GUI from this thread.
			 */
			Synchronize(UpdateIhm);
			this->monitoringParam();

		}

	}
	catch (...) {
		throw(" Erreur de synchronisation des valeurs de IHm Instrument");
	}

	stop_m = 0;
}

// ---------------------------------------------------------------------------
void __fastcall TAlimThread::UpdateIhm() {

	// Panel Vue
	if (Alim->Device->Active && Alim->Device->ActiveReturn) {
		Alim->Device->ActiveVoltage = Alim->Device->WantingVoltage;
		AlimFormUnit->VoltageLabel->Caption->Value =
			Alim->Device->WantingVoltage;
		AlimFormUnit->CurrentLabel->Caption->Value =
			Alim->Device->WantingCurrent;
		AlimFormUnit->OverCurrent = Alim->Device->OverCurrent;
		AlimFormUnit->OverVoltage = Alim->Device->OverVoltage;
		AlimFormUnit->OverTemperature = Alim->Device->OverTemperature;
	}
	AlimFormUnit->VoltageProgLabel->Caption->Value =
		Alim->Device->WantingVoltage;
	AlimFormUnit->VoltageProtLabel->Caption->Value =
		Alim->Device->ActiveVoltageProt;
	AlimFormUnit->CurrentProtLabel->Caption->Value =
		Alim->Device->ActiveCurrentProt;

	AlimFormUnit->OverVoltage = Alim->Device->OverVoltage;
	AlimFormUnit->OverCurrent = Alim->Device->OverCurrent;
	AlimFormUnit->OverTemperature = Alim->Device->OverTemperature;
	AlimFormUnit->Active = Alim->Device->Active;

	// Panel Parametre

	AlimFormUnit->TextTensionMax->Text = Alim->Device->VoltageMax;
	AlimFormUnit->TextPowerMax->Text = Alim->Device->PowerMax;
	AlimFormUnit->TextTensionpeak->Text = Alim->Device->VoltagePeak;
	AlimFormUnit->TextTensionRMS->Text = Alim->Device->VoltageRMS;
	AlimFormUnit->TextCourantMax->Text = Alim->Device->CurrentMax;
	AlimFormUnit->TextCourantRMS->Text = Alim->Device->CurrentRMS;
}

void __fastcall TAlimThread::setAlim(SAlimentations* A) {
	Alim = A;
};

void __fastcall TAlimThread::GentleStop() {
	/* Set the flag to 1. */
	InterlockedIncrement(&stop_m);

	/* Wait for this thread to finish executing */
	this->WaitFor();

};

void __fastcall TAlimThread::monitoringParam() {

	if (Alim->Device->ActiveVoltageProt < Alim->Device->ActiveVoltage) {
		Alim->Device->OverVoltage = True;
		Alim->Device->Error = " OverVoltage";
	}

	if (Alim->Device->ActiveCurrentProt < Alim->Device->ActiveCurrent) {
		Alim->Device->OverCurrent = True;
		Alim->Device->Error = " OverCurrent";
	}
	if (Alim->Device->Active && Alim->Device->ActiveReturn) {
		Alim->Device->ActiveVoltage = Alim->Device->WantingVoltage;
		Alim->Device->ActiveCurrent = Alim->Device->WantingCurrent;
		Alim->Device->notifyChangeValueDown
			(Alim->Device->WantingVoltage*Alim->Device->WantingCurrent, POWER);
	}
};
