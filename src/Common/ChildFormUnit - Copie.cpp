// ---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#include <IniFiles.hpp>
#pragma hdrstop

#include "ChildFormUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TChildForm *ChildForm;



// ---------------------------------------------------------------------------
__fastcall TChildForm::TChildForm(TComponent* Owner) : TForm(Owner) {
  T0 = Now();
}
// ---------------------------------------------------------------------------

void TChildForm::Init(TCTX* CTX_i, TIdTCPClient *IdTCPClient1) {
  CTX_m = CTX_i;
  // Récupération du nom du PC de la base de donnée
  PCName_m = CTX_m->PCName;
  Specimen_m = CTX_m->Specimen;
}
// ---------------------------------------------------------------------------

void __fastcall TChildForm::MsgEvent(TObject *Sender, int priority, AnsiString msg) {
  if (OnMsg)
    OnMsg(this, priority, Caption + " Module : " + msg);
}
// ---------------------------------------------------------------------------

void __fastcall TChildForm::RegisterDep(TObject *Sender, AnsiString ModuleName) {
  if (OnDependency)
    OnDependency(this, ModuleName);
}
// ---------------------------------------------------------------------------

void __fastcall TChildForm::WaitEvent(TObject *Sender, int delay_ms) {
  const TDateTime Temp = Now();
  while (MilliSecondsBetween(Temp, Now()) < delay_ms) {
    Application->ProcessMessages();
    Sleep(1);
  }
}
// ---------------------------------------------------------------------------

void TChildForm::WaitMs(int NbMsSec) {
  WaitEvent(this, NbMsSec);
}
// ---------------------------------------------------------------------------

void TChildForm::SaveFile(bool Update_i) {
  // Sauvegarde du traitement dans le fichier
  MsgEvent(this, 2, "Sauvegarde du traitement");
  CTX_m->SaveToFile();
  MsgEvent(this, 1, "Fichier sauvegardé : " + CTX_m->FileName);

  // Mise en base de donnée
  MsgEvent(this, 2, "Mise en base de données");
  WideString Str = "";
  if (Str != "")
    MsgEvent(this, 1, Str);
}
// ---------------------------------------------------------------------------

void __fastcall TChildForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  stopTest_m = true;
}
//---------------------------------------------------------------------------

