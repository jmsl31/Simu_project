// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "SRxThread.h"
#include "SRxFormUnit.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------

// Important : Les méthodes et les propriétés des objets de la VCL peuvent seulement être
// utilisées dans une méthode appelée avec Synchronize, par exemple :
//
// Synchronize(&UpdateCaption);
//
// où UpdateCaption pourrait ressembler à :
//
// void __fastcall SRxThread::UpdateCaption()
// {
// Form1->Caption = "Mis à jour dans un thread";
// }
// ---------------------------------------------------------------------------

__fastcall SRxThread::SRxThread(bool CreateSuspended) : TThread(CreateSuspended) {

	this->Priority = tpIdle;
	stop_m = 0;

}

// ---------------------------------------------------------------------------
void __fastcall SRxThread::Execute() {
	NameThreadForDebugging(System::String(L"RX"));

	try {
		while (!stop_m) {
			/* Wait for 100 milliseconds. */
			Sleep(100);

			/*
			 Run the AddNewNumberToMemo procedure on the main thread.
			 This makes it safe to access GUI from this thread.
			 */
			Synchronize(UpdateIhm);
			Monitoring();

		}

	}
	catch (...) {
		throw(" Erreur de synchronisation des valeurs de IHm Instrument");
	}

	stop_m = 0;
}

void __fastcall SRxThread::UpdateIhm() {

	RxFormUnit->TensionF->Caption->Value = RxFormUnit->Device->alim_m[0].VoltageActif;
	RxFormUnit->CourantF->Caption->Value = RxFormUnit->Device->alim_m[0].CurrentActif;

};

// ---------------------------------------------------------------------------
void __fastcall SRxThread::Monitoring() {
	// Si l'equipement est actif
	if (RxFormUnit->Device->Active) {
		/* Wait for 100 milliseconds. */
		Sleep(100);
		// Surveillance du courant
		if (RxFormUnit->Device->alim_m[0].CurrentMax < RxFormUnit->Device->alim_m[0].CurrentActif) {
			RxFormUnit->Device->alim_m[0].ProtectedCurrent = true;
			RxFormUnit->Device->alim_m[0].CurrentActif = 0;
		}
		// Surveillance de la tension
		if (RxFormUnit->Device->alim_m[0].VoltageMax < RxFormUnit->Device->alim_m[0].VoltageActif) {
			RxFormUnit->Device->alim_m[0].ProtectedVoltage = true;
			RxFormUnit->Device->alim_m[0].CurrentActif = 0;
			RxFormUnit->Device->alim_m[0].VoltageActif = 0;
		}

		// Si Protection de la Tension activé alors notification de la protection en tension, de la tension et du courant.
		if (RxFormUnit->Device->alim_m[0].ProtectedVoltage) {
			RxFormUnit->Device->notifyChangeValueRising(RxFormUnit->Device->alim_m[0].ProtectedVoltage, OVER_VOLTAGE);
		}
		// Si Protection en courant activé alors notification de la protection en courant et du courant.
		if (RxFormUnit->Device->alim_m[0].ProtectedCurrent) {
			RxFormUnit->Device->notifyChangeValueRising(RxFormUnit->Device->alim_m[0].ProtectedCurrent, OVER_CURRENT);
		}
		// Notification du courant, de la tension et calcul du courant.
		RxFormUnit->Device->alim_m[0].setCurrentActifs();
		RxFormUnit->Device->notifyChangeValueRising(RxFormUnit->Device->alim_m[0].VoltageActif, VOLTAGE_RETURN);
		RxFormUnit->Device->notifyChangeValueRising(RxFormUnit->Device->alim_m[0].CurrentActif, CURRENT_RETURN);
	}
};

void __fastcall SRxThread::GentleStop() {
	/* Set the flag to 1. */
	InterlockedIncrement(&stop_m);

	/* Wait for this thread to finish executing */
	this->WaitFor();

};
