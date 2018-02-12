// ---------------------------------------------------------------------------

#ifndef ChildFormUnitH
#define ChildFormUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdBaseComponent.hpp>
#include <Vcl.Graphics.hpp>
#include "CTXUnit.h"
#include <Vcl.Imaging.pngimage.hpp>
#include <string>
#include "TVisa.h"
#include "TBenchAdr.h"


// ---------------------------------------------------------------------------
typedef void __fastcall(__closure * TMsgEvent)(TObject * Sender, int priority, AnsiString msg);
typedef void __fastcall(__closure * TDepEvent)(TObject * Sender, AnsiString ModuleName);

class TChildForm : public TForm {
__published: // Composants gérés par l'EDI

  TImage *Image1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private: // Déclarations utilisateur

protected :
  bool stopTest_m;
  TMsgEvent FOnMsg;
  TDepEvent FOnDependency;
  TNotifyEvent FOnRemote, FOnQuit;
  TCTX* CTX_m;

  AnsiString Section_m;
  AnsiString PCName_m;
  bool Specimen_m;
  TDateTime T0;
  TIdTCPClient *IdTCPClient1;

  void __fastcall RegisterDep(TObject *Sender, AnsiString ModuleName);
  void __fastcall MsgEvent(TObject *Sender, int priority, AnsiString msg);
  void __fastcall WaitEvent(TObject *Sender, int delay_ms);
  void WaitMs(int NbMsSec);
  void SaveFile(bool Update_i);

public: // Déclarations utilisateur
  __fastcall TChildForm(TComponent* Owner);
  virtual void Init(TCTX* CTX_i, TIdTCPClient *IdTCPClient1);
  virtual void Execute(){};
  __property TMsgEvent OnMsg = {read = FOnMsg, write = FOnMsg};
  __property TDepEvent OnDependency = {read = FOnDependency, write = FOnDependency};
  __property TNotifyEvent OnQuit = {read = FOnQuit, write = FOnQuit};
};

// ---------------------------------------------------------------------------
extern PACKAGE TChildForm *ChildForm;
// ---------------------------------------------------------------------------
#endif
