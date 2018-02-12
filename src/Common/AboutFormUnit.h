// ----------------------------------------------------------------------------
#ifndef AboutFormUnitH
#define AboutFormUnitH
// ----------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Vcl.WinXCtrls.hpp>
#include "ChildFormUnit.h"

// ----------------------------------------------------------------------------
class TAboutForm : public TChildForm {
__published:
  TLabel *ProductNameLabel;
  TLabel *FileDescriptionLabel;
  TLabel *LegalCopyRightLabel;
  TLabel *CompanyNameLabel;
  TLabel *FileVersionLabel;
  TPanel *AdvPanel1;
  TGroupBox *AdvGroupBox1;
  TStringGrid *AboutGrid;
  TMemo *HistMemo;
  TRelativePanel *RelativePanel1;

  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);

private:
  bool GetInfo(AnsiString ModName_i, AnsiString &ProductName_o, AnsiString &FileDescription_o, AnsiString &LegalCopyRight_o, AnsiString &CompanyName_o,
  AnsiString &FileVersion_o);

public:
  virtual __fastcall TAboutForm(TComponent* AOwner);
  void DeclareDepends(TStringList* StrList);
};

// ----------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
// ----------------------------------------------------------------------------
#endif
