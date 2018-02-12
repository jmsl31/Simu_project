// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
// ---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
#include "MainUnit.h"

// USEFORM("..\..\instruments\Alim\SAlimFormUnit.cpp", AlimForm);
// USEFORM("..\Common\MainSimuFormUnit.cpp", MainSimuForm);
// ---------------------------------------------------------------------------
USEFORM("..\..\Common\LogFormUnit.cpp", LogForm);
USEFORM("..\..\Common\MainSimuFormUnit.cpp", MainSimuForm);
USEFORM("..\..\bench\SBenchFormUnit.cpp", BenchFormUnit);
USEFORM("..\..\Common\ChildFormUnit.cpp", ChildForm);
USEFORM("..\..\Common\AboutFormUnit.cpp", AboutForm);
USEFORM("..\..\instruments\Alim\SAlimFormUnit.cpp", AlimFormUnit);
USEFORM("..\..\equipment\Recepteur\SRxFormUnit.cpp", RxFormUnit);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	try {
		Application->Initialize();
		TStyleManager::TrySetStyle("Windows10 Dark");
		Application->Title = "Le Simulateur test";
		Application->HelpFile = "Doc.chm";
		Application->CreateForm(__classid(TMainSimuForm), &MainSimuForm);
		Application->CreateForm(__classid(TChildForm), &ChildForm);
		Application->CreateForm(__classid(TLogForm), &LogForm);
		Application->CreateForm(__classid(TBenchFormUnit), &BenchFormUnit);
		Application->CreateForm(__classid(TRxFormUnit), &RxFormUnit);
		Application->CreateForm(__classid(TAlimFormUnit), &AlimFormUnit);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TAboutForm), &AboutForm);
		Application->Run();
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}
	return 0;
}
// ---------------------------------------------------------------------------
