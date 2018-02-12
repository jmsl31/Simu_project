// ---------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#include <Inifiles.hpp>
#pragma hdrstop

#include "AboutFormUnit.h"
// ---------------------------------------------------------------------
#pragma link "ChildFormUnit"
#pragma resource "*.dfm"
TAboutForm *AboutForm;

// ---------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* AOwner) : TChildForm(AOwner) {

}
// ---------------------------------------------------------------------

bool TAboutForm::GetInfo(AnsiString ModName_i, AnsiString &ProductName_o,
	AnsiString &FileDescription_o, AnsiString &LegalCopyRight_o,
	AnsiString &CompanyName_o, AnsiString &FileVersion_o) {
	DWORD VersionHandle;
	DWORD VersionSize;
	bool error = false;
	char *pBuffer;
	char * ExeName_l = ModName_i.c_str();
	// Il faut d'abord transformer UnicodeString en AnsiString pour que c_str() renvoie un char * !!!!
	VersionSize = GetFileVersionInfoSize(ExeName_l, &VersionHandle);
	if (VersionSize) {
		pBuffer = new char[VersionSize];
		if (GetFileVersionInfo(ExeName_l, VersionHandle, VersionSize, pBuffer))
		{
			char *b;
			UINT buflen;
			DWORD hVersion;
			DWORD vis = GetFileVersionInfoSize(ExeName_l, &hVersion);
			if (vis == 0)
				return false;
			void *vData;
			vData = (void *)new char[(UINT)vis];
			if (!GetFileVersionInfo(ExeName_l, hVersion, vis, vData)) {
				delete vData;
				return false;
			}
			char vn[100];
			strcpy(vn, "\\VarFileInfo\\Translation");
			LPVOID transblock;
			UINT vsize;
			BOOL res = VerQueryValue(vData, vn, &transblock, &vsize);
			if (!res) {
				delete vData;
				return false;
			}
			DWORD *dw = (DWORD*)transblock;
			DWORD dwhi = HIWORD(*dw);
			DWORD dwlo = LOWORD(*dw);
			*dw = dwhi | (dwlo << 16);
			char *info;
			info = "ProductName";
			wsprintf(vn, "\\StringFileInfo\\%08lx\\%s",
				*(DWORD *)transblock, info);
			if (VerQueryValue(pBuffer, TEXT(vn), (void**)&b, &buflen))
				ProductName_o = b;
			else
				error = true;
			info = "FileDescription";
			wsprintf(vn, "\\StringFileInfo\\%08lx\\%s",
				*(DWORD *)transblock, info);
			if (VerQueryValue(pBuffer, TEXT(vn), (void**)&b, &buflen))
				FileDescription_o = b;
			else
				error = true;
			info = "LegalCopyRight";
			wsprintf(vn, "\\StringFileInfo\\%08lx\\%s",
				*(DWORD *)transblock, info);
			if (VerQueryValue(pBuffer, TEXT(vn), (void**)&b, &buflen))
				LegalCopyRight_o = b;
			else
				error = true;
			info = "CompanyName";
			wsprintf(vn, "\\StringFileInfo\\%08lx\\%s",
				*(DWORD *)transblock, info);
			if (VerQueryValue(pBuffer, TEXT(vn), (void**)&b, &buflen))
				CompanyName_o = b;
			else
				error = true;
			info = "FileVersion";
			wsprintf(vn, "\\StringFileInfo\\%08lx\\%s",
				*(DWORD *)transblock, info);
			if (VerQueryValue(pBuffer, TEXT(vn), (void**)&b, &buflen))
				FileVersion_o = b;
			else
				error = true;
		}
		else
			error = true;
	}
	else
		error = true;

	delete [] pBuffer;
	return !error;
}

void __fastcall TAboutForm::FormShow(TObject *Sender) {
	AnsiString ModName_l = Application->ExeName;
	AnsiString ProductName_l, FileDescription_l, LegalCopyRight_l,
		CompanyName_l, FileVersion_l;
	GetInfo(ModName_l, ProductName_l, FileDescription_l, LegalCopyRight_l,
		CompanyName_l, FileVersion_l);

	UnicodeString DateStr;
	TDateTime Date_l;
	FileAge(Application->ExeName, Date_l);
	DateTimeToString(DateStr, "mmmm yyyy", Date_l);
	ProductNameLabel->Caption = ProductName_l;
	FileDescriptionLabel->Caption = FileDescription_l;
	LegalCopyRightLabel->Caption = LegalCopyRight_l;
	CompanyNameLabel->Caption = CompanyName_l;
	FileVersionLabel->Caption = FileVersion_l;
	FileVersionLabel->Caption = "Version " + FileVersionLabel->Caption + " / " +
		DateStr;

	AboutGrid->Cells[0][0] = "File Name";
	AboutGrid->Cells[1][0] = "Date";
	AboutGrid->Cells[2][0] = "Product Name";
	AboutGrid->Cells[3][0] = "Description";
	AboutGrid->Cells[4][0] = "Copyright";
	AboutGrid->Cells[5][0] = "Company";
	AboutGrid->Cells[6][0] = "Version";

	if (FileExists(ChangeFileExt(Application->ExeName, ".txt")))
		HistMemo->Lines->LoadFromFile(ChangeFileExt(Application->ExeName,
		".txt"));
}
// ---------------------------------------------------------------------------

void __fastcall TAboutForm::FormResize(TObject *Sender) {
	AboutGrid->DefaultColWidth = floor((float)AboutGrid->Width / 7) - 1;
	AboutForm->FormShow(this);
}
// ---------------------------------------------------------------------------

void TAboutForm::DeclareDepends(TStringList* StrList) {
	AnsiString ProductName_l, FileDescription_l, LegalCopyRight_l,
		CompanyName_l, FileVersion_l;
	TDateTime Date_l;
	try {
		AboutGrid->RowCount = StrList->Count + 1;
		for (int i = 0; i < StrList->Count; i++) {
			AboutGrid->Cells[0][i + 1] = ExtractFileName(StrList->Strings[i]);
			FileAge(StrList->Strings[i], Date_l);
			AboutGrid->Cells[1][i + 1] = DateToStr(Date_l);
			ProductName_l = "";
			FileDescription_l = "";
			LegalCopyRight_l = "";
			CompanyName_l = "";
			FileVersion_l = "";
			GetInfo(StrList->Strings[i], ProductName_l, FileDescription_l,
				LegalCopyRight_l, CompanyName_l, FileVersion_l);
			AboutGrid->Cells[2][i + 1] = ProductName_l;
			AboutGrid->Cells[3][i + 1] = FileDescription_l;
			AboutGrid->Cells[4][i + 1] = LegalCopyRight_l;
			AboutGrid->Cells[5][i + 1] = CompanyName_l;
			AboutGrid->Cells[6][i + 1] = FileVersion_l;
		}
	}
	catch (...) {
	}
}
// ---------------------------------------------------------------------------
