// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LogFormUnit.h"
#include "ChildFormUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ChildFormUnit"
#pragma resource "*.dfm"
TLogForm *LogForm;

// ---------------------------------------------------------------------------
__fastcall TLogForm::TLogForm(TComponent* Owner) : TChildForm(Owner) {
}
// ---------------------------------------------------------------------------

void TLogForm::AddColoredLine(AnsiString AText, TColor AColor) {
  AText = StringReplace(AText, "\n", " ", TReplaceFlags() << rfReplaceAll);
  AText = StringReplace(AText, "\r", " ", TReplaceFlags() << rfReplaceAll);
  MsgMemo->Lines->Add(AText);
  MsgMemo->SelStart = 0;
  MsgMemo->SelLength = AText.Length();
  MsgMemo->SelAttributes->Color = AColor;
  MsgMemo->SelAttributes->Size = 12;
  MsgMemo->SelAttributes->Name = "MS Sans Serif";
}

void __fastcall TLogForm::ClearButtonClick(TObject *Sender) {
  MsgMemo->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TLogForm::FormClose(TObject *Sender, TCloseAction &Action) {
  MsgMemo->PlainText = true;
  ForceDirectories(ExtractFileDir(Application->ExeName) + "\\log\\");
  MsgMemo->Lines->SaveToFile(ExtractFileDir(Application->ExeName) + "\\log\\" + ExtractFileName(Application->ExeName) + FormatDateTime("-hh-nn-ss--dd-mm-yyyy", Now()) + ".txt");
  if (!FileExists(Application->ExeName + ".log"))
    MsgMemo->Lines->SaveToFile(Application->ExeName + ".log");
}
// ---------------------------------------------------------------------------


