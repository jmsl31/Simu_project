// ---------------------------------------------------------------------------

#ifndef SimuFormUnitH
#define SimuFormUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <string>
#include "TVisa.h"
#include "TBenchAdr.h"
#include "SwInterfaceAbstract.h"
#include "ScpiCommand.h"
#include "ScpiResponse.h"
#include <queue>
// ---------------------------------------------------------------------------
typedef void __fastcall(__closure * TMsgEvent)(TObject * Sender, int priority, AnsiString msg);
typedef void __fastcall(__closure * TDepEvent)(TObject * Sender, AnsiString ModuleName);
typedef void __fastcall(__closure * TCmdStrEvent)(TObject * Sender, AnsiString Cmd_i);

class TSimuForm : public TForm {
__published: // Composants gérés par l'EDI

  TImage *Image1;

  void __fastcall FormDestroy(TObject *Sender);

private: // Déclarations utilisateur


protected:

  TMsgEvent FOnMsg;
  TDepEvent FOnDependency;
  TNotifyEvent FOnRemote;

  AnsiString Section_m;
  TStringList* ErrorList_m;
  std::queue<std::string> LogFiFo_m;

  void __fastcall RegisterDep(TObject *Sender, AnsiString ModuleName);
  void __fastcall MsgEvent(TObject *Sender, int priority, AnsiString msg);
  void __fastcall WaitEvent(TObject *Sender, int delay_ms);

  // Utils

public: // Déclarations utilisateur

  AnsiString ScpiResult_m;
  int ScpiPort_m;

  __fastcall TSimuForm(TComponent* Owner);
  virtual void Init(TBenchAdrComp* BenchAdr_i, AnsiString Section_i);

  void __fastcall RemoteEvent(TObject *Sender);


  __property TMsgEvent OnMsg = {read = FOnMsg, write = FOnMsg};
  __property TDepEvent OnDependency = {read = FOnDependency, write = FOnDependency};
  __property TNotifyEvent OnRemote = {read = FOnRemote, write = FOnRemote};
};

// ---------------------------------------------------------------------------
extern PACKAGE TSimuForm *SimuForm;
// ---------------------------------------------------------------------------
#endif
