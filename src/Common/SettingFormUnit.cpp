// ---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>

#pragma hdrstop

#include "SettingFormUnit.h"
#include "SimuFormUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SimuFormUnit"
#pragma resource "*.dfm"
TSettingForm *SettingForm;

// ---------------------------------------------------------------------------
__fastcall TSettingForm::TSettingForm(TComponent* Owner) : TSimuForm(Owner) {
}
// ---------------------------------------------------------------------------

void TSettingForm::Init(TBenchAdrComp* BenchAdr_i, AnsiString Section_i) {
  TSimuForm::Init(BenchAdr_i, Section_i);
  for (int i = 0; i < TStyleManager::StyleNames.Length; i++)
    cbxVclStyles->Items->Add(TStyleManager::StyleNames[i]);

  cbxVclStyles->ItemIndex = cbxVclStyles->Items->IndexOf(TStyleManager::ActiveStyle->Name);
}
// ---------------------------------------------------------------------------

void TSettingForm::setSettings(int MainScpiPort_i, bool ScpiActive_i, int HttpPort_i, bool HttpActive_i, bool SwitchActive_i, bool LockActive_i) {
  MainScpiPort_m = MainScpiPort_i;
  ScpiActive_m = ScpiActive_i;
  HttpPort_m = HttpPort_i;
  HttpActive_m = HttpActive_i;
  SwitchActive_m = SwitchActive_i;
  LockActive_m = LockActive_i;
  LockFormSwitch->OnClick = NULL;
  LockFormSwitch->State = (TToggleSwitchState)LockActive_m;
  LockFormSwitch->OnClick = LockFormSwitchClick;
}

void __fastcall TSettingForm::cbxVclStylesChange(TObject *Sender) {
  TStyleManager::SetStyle(cbxVclStyles->Text);
}
// ---------------------------------------------------------------------------

void __fastcall TSettingForm::ScpiSwitchClick(TObject *Sender) {

  if (FOnSettings)
    FOnSettings(Sender, MainScpiPort_m, ScpiActive_m, HttpPort_m, HttpActive_m, SwitchActive_m, LockActive_m);
}
// ---------------------------------------------------------------------------

void __fastcall TSettingForm::HttpSwitchClick(TObject *Sender) {

  if (FOnSettings)
    FOnSettings(Sender, MainScpiPort_m, ScpiActive_m, HttpPort_m, HttpActive_m, SwitchActive_m, LockActive_m);
}
// ---------------------------------------------------------------------------

void __fastcall TSettingForm::ChangeFormSwitchClick(TObject *Sender)
{

  if (FOnSettings)
    FOnSettings(Sender, MainScpiPort_m, ScpiActive_m, HttpPort_m, HttpActive_m, SwitchActive_m, LockActive_m);
}
//---------------------------------------------------------------------------

void __fastcall TSettingForm::LockFormSwitchClick(TObject *Sender)
{
  LockActive_m = (LockFormSwitch->State == tssOn);
  if (FOnSettings)
    FOnSettings(Sender, MainScpiPort_m, ScpiActive_m, HttpPort_m, HttpActive_m, SwitchActive_m, LockActive_m);
}
//---------------------------------------------------------------------------

void __fastcall TSettingForm::HttpPortLabelLinkClick(TObject *Sender, const UnicodeString Link, TSysLinkType LinkType)
{
  AnsiString Url_l = Link;
  ShellExecute(0, "open", Url_l.c_str(), "", "", SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

