// ---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.CategoryButtons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.WinXCtrls.hpp>
#include "MainSimuFormUnit.h"
#include "SAlimFormUnit.h"
#include "SRXFormUnit.h"
#include "SBenchFormUnit.h"
// ---------------------------------------------------------------------------
class TMainForm : public TMainSimuForm {
__published: // Composants gérés par l'EDI
  void __fastcall FormShow(TObject *Sender);

protected:
  virtual void RegisterForms();
  virtual void RegisterObserver();

private: // Déclarations utilisateur
  public : // Déclarations utilisateur
  __fastcall TMainForm(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif
