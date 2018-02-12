// ---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#include <IniFiles.hpp>
#pragma hdrstop
#include "FormatException.h"
#include "SimuFormUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSimuForm *SimuForm;

using namespace Utils;
using namespace std;

// ---------------------------------------------------------------------------
__fastcall TSimuForm::TSimuForm(TComponent* Owner) : TForm(Owner) {
  ScpiPort_m = 0;
  ErrorList_m = new TStringList();
}
// ---------------------------------------------------------------------------
void TSimuForm::Init(TBenchAdrComp* BenchAdr_i, AnsiString Section_i) {
  Section_m = Section_i;

  Section_m = Section_i;
  if (Section_i == "")
	return;
}
// ---------------------------------------------------------------------------
void __fastcall TSimuForm::MsgEvent(TObject *Sender, int priority, AnsiString msg) {
  LogFiFo_m.push(Utils::toString(priority) + "," + Utils::toString(msg));
  if (OnMsg)
    OnMsg(this, priority, "[" + Section_m + "] " + msg);
}
// ---------------------------------------------------------------------------
void __fastcall TSimuForm::RegisterDep(TObject *Sender, AnsiString ModuleName) {
  if (OnDependency)
    OnDependency(this, ModuleName);
}

// ---------------------------------------------------------------------------
void __fastcall TSimuForm::WaitEvent(TObject *Sender, int delay_ms) {
  const TDateTime Temp = Now();
  while (MilliSecondsBetween(Temp, Now()) < delay_ms) {
    Application->ProcessMessages();
    Sleep(1);
  }
}
// ---------------------------------------------------------------------------
void __fastcall TSimuForm::RemoteEvent(TObject *Sender) {
  if (OnRemote)
    OnRemote(this);
}

// ---------------------------------------------------------------------------
void __fastcall TSimuForm::FormDestroy(TObject *Sender) {
  delete ErrorList_m;
}
// ---------------------------------------------------------------------------
