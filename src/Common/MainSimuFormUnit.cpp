// ---------------------------------------------------------------------------

#include <vcl.h>
#include <SysUtils.hpp>
#include <DateUtils.hpp>
#include <IniFiles.hpp>

#pragma hdrstop

#include "MainSimuFormUnit.h"
#include "SimuFormUnit.h"
#include "AboutFormUnit.h"
#include "LogFormUnit.h"
#include "SAlimFormUnit.h"
#include "SRXFormUnit.h"
#include "SBenchFormUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainSimuForm *MainSimuForm;

__fastcall TMainSimuForm::TMainSimuForm(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::FormCreate(TObject *Sender) {
	FormatSettings.DecimalSeparator = '.';

	AddLineProc_m = false;
	GetInfosProc_m = false;
	LastMsg_m = "";
	ModuleList_m = new TStringList();
	ErrorList_m = new TStringList();
	ScpiPortList_m = new TStringList();
	Init_m = false;
	log_priority_m = 5;
	logMaxLine_m = 50;
}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::FormShow(TObject *Sender) {
	if (Init_m)
		return;

	RegisterTmtcForm(__classid(TLogForm), (TSimuForm**)&LogForm, "LOG");
	RegisterTmtcForm(__classid(TAboutForm), (TSimuForm**)&AboutForm, "ABOUT");
	RegisterTmtcForm(__classid(TAlimFormUnit), (TSimuForm**)&AlimFormUnit, "ALIM_FORM");
	MsgEvent(this, MEMO_ALIM_MESSAGE, INIT_ALIM);

	RegisterTmtcForm(__classid(TBenchFormUnit), (TSimuForm**)&BenchFormUnit, "BENCH FORM");
	MsgEvent(this, MEMO_BENCH_MESSAGE, INIT_BENCH);

	RegisterTmtcForm(__classid(TRxFormUnit), (TSimuForm**)&RxFormUnit, "EQUIPEMENT FORM");
	MsgEvent(this, MEMO_EQPT_MESSAGE, INIT_EQPT);

	RegisterObserver();
	RegisterForms();

	for (int i = 0; i < MainPageControl->PageCount; i++)
		MainPageControl->Pages[i]->TabVisible = false;

	MainSplitView->Close();

	MainPageControl->ActivePageIndex = 1;
	AboutForm->DeclareDepends(ModuleList_m);
	SettingsEvent(this, MainScpiPort_m, ScpiActive_m, HttpPort_m, HttpActive_m, SwitchActive_m, LockActive_m);
	Init_m = true;
}
// ---------------------------------------------------------------------------
void TMainSimuForm::RegisterObserver() {

	// Liaison entre les objects descendant.

	// Liaison entre l'instrument et le banc.
	MsgEvent(this, MEMO_OBSERVER_MESSAGE, INIT_OBSERVER_DOWN);
	AlimFormUnit->AlimDevice->Device->addObserverDown(BenchFormUnit->Device);

	// Liaison entre le banc et l'equipement.

	BenchFormUnit->Device->addObserverDown(RxFormUnit->Device);

	// Liaison entre les objects montant.

	// Liaison entre l'equipement et le banc
	MsgEvent(this, MEMO_OBSERVER_MESSAGE, INIT_OBSERVER_RISING);
	RxFormUnit->Device->addObserverRising(BenchFormUnit->Device);

	// Liaison entre le banc et l'instrument

	BenchFormUnit->Device->addObserverRising(AlimFormUnit->AlimDevice->Device);

};
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::SettingsEvent(TObject * Sender, int MainScpiPort_i, bool ScpiActive_i, int HttpPort_i, bool HttpActive_i, bool SwitchActive_i,
  bool LockActive_i) {
	try {
		MainScpiPort_m = MainScpiPort_i;
		ScpiActive_m = ScpiActive_i;
		HttpPort_m = HttpPort_i;
		HttpActive_m = HttpActive_i;
		SwitchActive_m = SwitchActive_i;
		LockActive_m = LockActive_i;
	}
	catch (Exception &E) {
		MsgEvent(this, 0, "ERROR : " + E.Message);
	}
}

void TMainSimuForm::UpdateTmtcForm(TForm* ASimuForm) {
	// Ajout de la fiche au PageControl
	TTabSheet * newTabSheet = new TTabSheet(this);
	newTabSheet->Parent = MainPageControl;
	newTabSheet->PageControl = MainPageControl;
	ASimuForm->ManualDock(newTabSheet);
	ASimuForm->Tag = MainPageControl->PageCount - 1;
	// Création du bouton dans MainForm
	TButtonItem* myButtonItem = new TButtonItem(catMenuItems->Categories->Items[0]->Items);
	TAction* myAction = new TAction(ActionList1);
	myAction->Caption = " " + ASimuForm->Caption;
	myAction->Tag = MainPageControl->PageCount - 1;
	myAction->OnExecute = catMenuItemsCategories0Items1Click;
	myAction->ImageIndex = MainPageControl->PageCount;
	myButtonItem->Action = myAction;
}

void TMainSimuForm::RegisterTmtcForm(TComponentClass InstanceClass, TSimuForm **ASimuForm, AnsiString ASection) {
	// Création de la fiche
   //	Application->CreateForm(InstanceClass, ASimuForm);
	// Initialisation de la fiche
	UpdateTmtcForm(*ASimuForm);
	(*ASimuForm)->Show();
	(*ASimuForm)->OnMsg = MsgEvent;
	(*ASimuForm)->OnRemote = RemoteEvent;
	(*ASimuForm)->OnDependency = RegisterDep;
	// (*ASimuForm)->Init(BenchAdr_m, ASection);

	// Récupération de l'icone
	TBitmap* myBitmap = new TBitmap();
	myBitmap->Width = (*ASimuForm)->Image1->Width;
	myBitmap->Height = (*ASimuForm)->Image1->Height;
	myBitmap->Canvas->Draw(0, 0, (*ASimuForm)->Image1->Picture->Graphic);
	MainIcons->AddMasked(myBitmap, myBitmap->TransparentColor);
}

// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::FormClose(TObject *Sender, TCloseAction &Action) {
	MsgEvent(this, 1, "Close application received...");

	TIniFile *ConfFile_l = new TIniFile(ChangeFileExt(Application->ExeName, ".ini"));
	try {
		ConfFile_l->WriteInteger("IHM SIMULATEUR", "SCPI_PORT", MainScpiPort_m);
		ConfFile_l->WriteInteger("IHM SIMULATEUR", "HTTP_PORT", HttpPort_m);
		ConfFile_l->WriteBool("IHM SIMULATEUR", "SCPI_ACTIVE", ScpiActive_m);
		ConfFile_l->WriteBool("IHM SIMULATEUR", "LOCK_ACTIVE", LockActive_m);
		ConfFile_l->WriteBool("IHM SIMULATEUR", "SWITCH_ACTIVE", SwitchActive_m);
		ConfFile_l->UpdateFile();
	}
	__finally {
		delete ConfFile_l;
	}
	for (int i = 0; i < MainPageControl->PageCount; i++) {
		((TForm*) MainPageControl->Pages[i]->Controls[0])->Close();
	}

	delete ModuleList_m;
	delete ErrorList_m;
	delete ScpiPortList_m;
}
// ---------------------------------------------------------------------------

void TMainSimuForm::AddColoredLine(AnsiString AText, int priority, TColor AColor) {
	if (MsgMemo == NULL)
		return; // Message du IdTCPServer à la fermeture
	while (GetInfosProc_m)
		WaitMs(1);
	AddLineProc_m = true;
	try {
		if ((LastMsg_m != AText) && (priority <= log_priority_m)) {
			MsgMemo->SelAttributes->Color = AColor;
			std::string str = Utils::toString(AText);
			int c = MsgMemo->Lines->Count;
			MsgMemo->Lines->Add(AText);
			SendMessage(MsgMemo->Handle, WM_VSCROLL, SB_LINEDOWN, 0);
			LastMsg_m = AText;
		}
		if (LogForm != NULL)
			LogForm->AddColoredLine(AText, AColor);
		if (MsgMemo->Lines->Count > logMaxLine_m)
			MsgMemo->Lines->Delete(0);
	}
	catch (...) {
	}
	AddLineProc_m = false;
}

void __fastcall TMainSimuForm::MsgEvent(TObject *Sender, int priority, AnsiString Msg) {
	// Emergence des messages et passage au moniteur selon prioritée
	Msg = StringReplace(Msg, "\n", " ", TReplaceFlags() << rfReplaceAll);
	Msg = StringReplace(Msg, "\r", " ", TReplaceFlags() << rfReplaceAll);

	switch (priority)

	{
	case MEMO_ERROR_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " ERROR : " + Msg, priority, clRed);
		break;
	case MEMO_INFO_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " INFO : " + Msg, priority, clBlack);
		break;
	case MEMO_ALIM_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " ALIMENTATION : " + Msg, priority, clBlue);
		break;
	case MEMO_EQPT_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " EQUIPEMENT : " + Msg, priority, clGreen);
		break;
	case MEMO_BENCH_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " BANC : " + Msg, priority, clGray);
		break;
	case MEMO_OBSERVER_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " BANC : " + Msg, priority, clMaroon);
		break;
	case LOG_ERROR_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " ERROR : " + Msg, priority, clRed);
		break;
	case LOG_INFO_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " INFO : " + Msg, priority, clBlack);
		break;
	case LOG_ALIM_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " ALIMENTATION : " + Msg, priority, clBlue);
		break;
	case LOG_EQPT_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " EQUIPEMENT : " + Msg, priority, clGreen);
		break;
	case LOG_BENCH_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " BANC : " + Msg, priority, clGray);
		break;
	case LOG_OBSERVER_MESSAGE:
		AddColoredLine(FormatDateTime("hh:nn:ss:zzz", Now()) + " BANC : " + Msg, priority, clMaroon);
		break;
		WaitMs(1);
		break;

	default: ;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::RegisterDep(TObject *Sender, AnsiString ModuleName) {
	ModuleList_m->Add(ModuleName);
}

void TMainSimuForm::WaitMs(int NbMsSec) {
	// Attente en millisecondes
	const TDateTime Temp = Now();
	while (MilliSecondsBetween(Temp, Now()) < NbMsSec) {
		Application->ProcessMessages();
		Sleep(1);
	}
}
// ---------------------------------------------------------------------------

void TMainSimuForm::Shutdown(bool WithReboot) {
	PostMessage(Handle, WM_CLOSE, 0, 0);
	TOKEN_PRIVILEGES wTokenIn, wTokenOut;
	DWORD wLength;
	HANDLE wCurrentProcess, wToken;
	_LUID wLuid;
	OSVERSIONINFO wOsVer;
	try {
		wCurrentProcess = GetCurrentProcess();
		OpenProcessToken(wCurrentProcess, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &wToken);
		LookupPrivilegeValue(NULL, "SeShutdownPrivilege", &wLuid);
		wTokenIn.PrivilegeCount = 1;
		wTokenIn.Privileges[0].Luid = wLuid;
		wTokenIn.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(wToken, FALSE, &wTokenIn, sizeof(TOKEN_PRIVILEGES), &wTokenOut, &wLength);
		CloseHandle(wToken);
	}
	__finally {
		Application->ProcessMessages();
		if (WithReboot)
			ExitWindowsEx(EWX_REBOOT | EWX_FORCEIFHUNG, 0);
		else {
			wOsVer.dwOSVersionInfoSize = sizeof(wOsVer);
			GetVersionEx(&wOsVer);
			if (wOsVer.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
				ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCEIFHUNG, 0);
			else
				ExitWindowsEx(EWX_POWEROFF | EWX_FORCEIFHUNG, 0);
		}
	}
}
// ---------------------------------------------------------------------------

void TMainSimuForm::getInfos(TStringList *StrList, int *NbLine) {
	while (AddLineProc_m)
		WaitMs(1);
	GetInfosProc_m = true;
	if (*NbLine >= MsgMemo->Lines->Count) {
		StrList->Assign(MsgMemo->Lines);
		*NbLine = StrList->Count;
		// MsgMemo->Lines->Clear();
		for (int i = 0; i < *NbLine; i++)
			MsgMemo->Lines->Delete(MsgMemo->Lines->Count - 1);
	}
	else
		for (int i = 0; i < *NbLine; i++) {
			StrList->Insert(0, MsgMemo->Lines->Strings[MsgMemo->Lines->Count - 1]);
			MsgMemo->Lines->Delete(MsgMemo->Lines->Count - 1);
		}
	GetInfosProc_m = false;
}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::catMenuItemsCategories0Items0Click(TObject *Sender) {
	if (MainSplitView->Opened)
		MainSplitView->Close();
	else
		MainSplitView->Open();
}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::catMenuItemsCategories0Items1Click(TObject *Sender) {
	MainSplitView->Close();
	MainPageControl->ActivePageIndex = ((TAction*)Sender)->Tag;
}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::catMenuItemsMouseEnter(TObject *Sender) {
	MainSplitView->Open();
}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::catMenuItemsMouseLeave(TObject *Sender) {
	MainSplitView->Close();
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::UnlockButtonClick(TObject *Sender) {
	for (int i = 0; i < MainPageControl->PageCount; i++)
		((TForm*) MainPageControl->Pages[i]->Controls[0])->Enabled = true;
}
// ---------------------------------------------------------------------------

void TMainSimuForm::LockForms() {
	for (int i = 0; i < MainPageControl->PageCount; i++)
		((TForm*) MainPageControl->Pages[i]->Controls[0])->Enabled = false;
}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::RemoteEvent(TObject *Sender) {
	if (LockActive_m)
		LockForms();
	if (SwitchActive_m)
		MainPageControl->ActivePageIndex = ((TForm*)Sender)->Tag;
}
// ---------------------------------------------------------------------------

void __fastcall TMainSimuForm::ApplicationEvents1Exception(TObject *Sender, Exception *E) {
	MsgEvent(this, 0, "ERROR : " + E->Message);
}
// ---------------------------------------------------------------------------
