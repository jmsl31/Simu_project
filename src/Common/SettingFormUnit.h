// ---------------------------------------------------------------------------

#ifndef SettingFormUnitH
#define SettingFormUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.WinXCtrls.hpp>
#include "SimuFormUnit.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include "SimuFormUnit.h"

// ---------------------------------------------------------------------------
typedef void __fastcall(__closure * TSettingsEvent)(TObject * Sender, int MainScpiPort_i, bool ScpiActive_i, int HttpPort_i, bool HttpActive_i, bool SwitchActive_i, bool LockActive_i);

class TSettingForm : public TSimuForm {
__published: // Composants gérés par l'EDI

  TLabel *lblVclStyle;
  TComboBox *cbxVclStyles;
  TToggleSwitch *LockFormSwitch;
  void __fastcall cbxVclStylesChange(TObject *Sender);
  void __fastcall ScpiSwitchClick(TObject *Sender);
  void __fastcall HttpSwitchClick(TObject *Sender);
  void __fastcall HttpPortLabelLinkClick(TObject *Sender, const UnicodeString Link, TSysLinkType LinkType);
  void __fastcall ChangeFormSwitchClick(TObject *Sender);
  void __fastcall LockFormSwitchClick(TObject *Sender);

private: // Déclarations utilisateur
  TSettingsEvent FOnSettings;
  bool LockActive_m, SwitchActive_m;
  int MainScpiPort_m, HttpPort_m;
  bool ScpiActive_m, HttpActive_m;

public: // Déclarations utilisateur

  __fastcall TSettingForm(TComponent* Owner);
  virtual void Init(TBenchAdrComp* BenchAdr_i, AnsiString Section_i);
  void setSettings(int MainScpiPort_i, bool ScpiActive_i, int HttpPort_i, bool HttpActive_i, bool SwitchActive_i, bool LockActive_i);
  __property TSettingsEvent OnSettings = {read = FOnSettings, write = FOnSettings};
};

// ---------------------------------------------------------------------------
extern PACKAGE TSettingForm *SettingForm;
// ---------------------------------------------------------------------------
#endif
