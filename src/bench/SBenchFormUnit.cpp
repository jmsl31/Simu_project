// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SBenchFormUnit.h"
#include "TBenchThread.h"
#include "HtmlHelpViewer.hpp"
// ---------------------------------------------------------------------------
#include "Vcl.HTMLHelpViewer.hpp"
#pragma package(smart_init)
#pragma link "Vcl.HTMLHelpViewer"
#pragma link "AdvSmoothLedLabel"
#pragma resource "*.dfm"
TBenchFormUnit* BenchFormUnit;


#define file " D:\\Doc.chm"
// ---------------------------------------------------------------------------
__fastcall TBenchFormUnit::TBenchFormUnit(TComponent* Owner) : TSimuForm(Owner) {
	// instantiation de l'objet Device.

	Device = new SBench_C();
	// instantiation de l'objet Thread.
	TBenchThread* Thread = new TBenchThread(false);
	// defintion de la priorité du thread.
	Thread->Priority = tpLower;
	// creation de la liason des messages d'informations de l'Objet SBench.

	Device->BenchSimu->FileName = "D:\\simu_cpp.bax\\baie\\baies.adr";
	Device->BenchSimu->Section = "simu.ba1";
	Device->Active = true;

	TextName->Text = Device->Name;
	TextImmo->Text = Device->pcImmo;
	this->getListDevice();

	this->TextTension->Caption->Value = this->Device->Active_Voltage;
	this->TextCourant->Caption->Value = this->Device->Active_Current;
	this->TextPower->Caption->Value = this->Device->Active_Power;

	//lancement du Thread de mise à jour de l'Ihm.
	Thread->Resume();
}

void TBenchFormUnit::getListDevice() {

	for (int i = 0; i < Device->BenchSimu->BenchAdrFile->GetDeviceAll().Length; i++) {

		ListView1->Items->Add()->Caption = Device->BenchSimu->BenchAdrFile->GetDeviceAll()[i];
	}

};
void TBenchFormUnit::OpenLocalFile(UnicodeString Path) {
  //  if (FileExists(Path)) {
//	  TShellExecuteInfo SEInfo = { 0 };
//	  SEInfo.cbSize = sizeof(TShellExecuteInfo);
//	  SEInfo.hwnd = 0;
//	  SEInfo.lpFile = Path.w_str();
//	  SEInfo.lpParameters = NULL;
//	  SEInfo.nShow = SW_SHOWDEFAULT;
//	  SEInfo.lpVerb = L"open";
//	  SEInfo.lpDirectory = ExtractFileDir(Path).w_str();
//      ShellExecuteExW(&SEInfo);
   // }

  }

void __fastcall TBenchFormUnit::BitBtn1Click(TObject *Sender)
{
    Application->HelpContext(0);
}
//---------------------------------------------------------------------------

