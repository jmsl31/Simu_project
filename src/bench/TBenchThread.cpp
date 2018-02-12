// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "TBenchThread.h"
#include "SBenchFormUnit.h"
#include "SBench.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------

// Important : Les m�thodes et les propri�t�s des objets de la VCL peuvent seulement �tre
// utilis�es dans une m�thode appel�e avec Synchronize, par exemple :
//
// Synchronize(&UpdateCaption);
//
// o� UpdateCaption pourrait ressembler � :
//
// void __fastcall TBenchThread::UpdateCaption()
// {
// Form1->Caption = "Mis � jour dans un thread";
// }
// ---------------------------------------------------------------------------
__fastcall TBenchThread::TBenchThread(bool CreateSuspended) : TThread(CreateSuspended) {

	this->Priority = tpIdle;
	stop_m = 0;
}

// ---------------------------------------------------------------------------
void __fastcall TBenchThread::Execute() {
	NameThreadForDebugging(System::String(L"Bench"));

	try {
		while (!stop_m) {
			/* Wait for 100 milliseconds. */
			Sleep(100);
			/*
			 Run the AddNewNumberToMemo procedure on the main thread.
			 This makes it safe to access GUI from this thread.
			 */
			Synchronize(UpdateIhm);
            monitoringParam();
		}

	}
	catch (...) {
		throw(" Erreur de synchronisation des valeurs de IHm Instrument");
	}

	stop_m = 0;
}

void __fastcall TBenchThread::UpdateIhm() {

	BenchFormUnit->TextTension->Caption->Value = BenchFormUnit->Device->Return_Voltage;
	BenchFormUnit->TextCourant->Caption->Value = BenchFormUnit->Device->Return_Current;
	BenchFormUnit->TextPower->Caption->Value = BenchFormUnit->Device->Active_Power;
};
// ---------------------------------------------------------------------------

void __fastcall TBenchThread::GentleStop() {
	/* Set the flag to 1. */
	InterlockedIncrement(&stop_m);

	/* Wait for this thread to finish executing */
	this->WaitFor();

};


void __fastcall TBenchThread::monitoringParam() {

	BenchFormUnit->Device->Active_Power = BenchFormUnit->Device->Active_Voltage*BenchFormUnit->Device->Active_Current;
	BenchFormUnit->Device->Active_Voltage = BenchFormUnit->Device->Return_Voltage;
	BenchFormUnit->Device->Active_Current = BenchFormUnit->Device->Return_Current;

};
