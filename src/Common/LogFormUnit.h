// ---------------------------------------------------------------------------

#ifndef LogFormUnitH
#define LogFormUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.CategoryButtons.hpp>
#include <Vcl.ButtonGroup.hpp>
#include <Vcl.Graphics.hpp>
#include "ChildFormUnit.h"

// ---------------------------------------------------------------------------
class TLogForm : public TChildForm {
__published: // Composants gérés par l'EDI
  TRichEdit *MsgMemo;
  TPanel *Panel1;
  TButton *ClearButton;

  void __fastcall ClearButtonClick(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private: // Déclarations utilisateur
  public : // Déclarations utilisateur
  void AddColoredLine(AnsiString AText, TColor AColor);
  __fastcall TLogForm(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TLogForm *LogForm;
// ---------------------------------------------------------------------------
#endif
