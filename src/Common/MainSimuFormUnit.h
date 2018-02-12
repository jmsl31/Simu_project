// ---------------------------------------------------------------------------

#ifndef MainSimuFormUnitH
#define MainSimuFormUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.ImageList.hpp>
#include <System.Actions.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.CategoryButtons.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ActnList.hpp>
#include <Graphics.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include "TVisa.h"
#include "TBenchAdr.h"
#include <IdCustomHTTPServer.hpp>
#include <IdHTTPServer.hpp>
#include "SimuFormUnit.h"
#include <IdSocketHandle.hpp>
#include <Vcl.AppEvnts.hpp>
#include "ConstanteDefine.h"
// ---------------------------------------------------------------------------



class TMainSimuForm : public TForm {
__published: // Composants gérés par l'EDI

  TRichEdit *MsgMemo;
  TPanel *MainPanel;
  TStatusBar *MainStatusBar;
  TIdTCPServer *IdTCPServer;
  TPageControl *MainPageControl;
  TSplitView *MainSplitView;
  TCategoryButtons *catMenuItems;
  TImageList *MainIcons;
  TActionList *ActionList1;
  TAction *actStatus;
  TAction *act1553;
  TAction *actPower;
  TSpeedButton *UnlockButton;
  TIdHTTPServer *IdHTTPServer;
  TApplicationEvents *ApplicationEvents1;

  void __fastcall FormShow(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall catMenuItemsCategories0Items0Click(TObject *Sender);
  void __fastcall catMenuItemsCategories0Items1Click(TObject *Sender);
  void __fastcall catMenuItemsMouseEnter(TObject *Sender);
  void __fastcall catMenuItemsMouseLeave(TObject *Sender);
  void __fastcall UnlockButtonClick(TObject *Sender);
  void __fastcall ApplicationEvents1Exception(TObject *Sender, Exception *E);

private: // Déclarations de l'utilisateur

  int log_priority_m, logMaxLine_m;
  bool AddLineProc_m, GetInfosProc_m, Init_m;
  AnsiString LastMsg_m;

  TStringList* ModuleList_m;
  TStringList* ErrorList_m;
  TStringList* ScpiPortList_m;
  TStringList* TstrCmd_m;


  TBenchAdrComp* BenchAdr_m;
  bool LockActive_m, SwitchActive_m;
  int MainScpiPort_m, HttpPort_m;
  bool ScpiActive_m, HttpActive_m;

  /**
	 *\details Methode definissant la stratégies et la hiéarchie des objets du programme.
	 *\return AnsiString : le numero d'immo.
	 */
  virtual void RegisterObserver();
  void __fastcall SettingsEvent(TObject * Sender, int MainScpiPort_i, bool ScpiActive_i, int HttpPort_i, bool HttpActive_i, bool SwitchActive_i, bool LockActive_i);
  void __fastcall RemoteEvent(TObject *Sender);

  void UpdateTmtcForm(TForm* ATmtcForm);
  void LockForms();
  void AddColoredLine(AnsiString AText, int priority, TColor AColor);


protected:
  void __fastcall RegisterDep(TObject *Sender, AnsiString ModuleName);
  void RegisterTmtcForm(TComponentClass InstanceClass, TSimuForm **ATmtcForm, AnsiString ASection);

  virtual void RegisterForms() {
  };

public: // Déclarations de l'utilisateur

  bool ScpiBin_m, LocalMode_m;
  char *ScpiBinValTab_m;
  AnsiString ScpiResult_m;
  unsigned int ScpiBinValNb_m;

  void WaitMs(int NbMsSec);
  void Shutdown(bool WithReboot);
  __fastcall TMainSimuForm(TComponent* Owner);
  void getInfos(TStringList *StrList, int *NbLine);
  void SendScpiCmd(AnsiString Cmd_i, int Port_i);
  void __fastcall MsgEvent(TObject *Sender, int priority, AnsiString Msg);



};

// ---------------------------------------------------------------------------
extern PACKAGE TMainSimuForm *MainSimuForm;
// ---------------------------------------------------------------------------
#endif
