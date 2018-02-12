// ---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include <iostream>
#pragma hdrstop

#include "MainUnit.h"
#include "Constantedefine.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "drivers_cpp10.lib"
#pragma link "smtlib_cpp10.lib"
// #pragma link "simu_cpp.lib"
#pragma link "Tee.lib"

TMainForm *MainForm;
// ---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner) : TMainSimuForm(Owner) {
	MainSimuForm = this;
	Caption = "IHM SIMULATEUR";

}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender) {
	TMainSimuForm::FormShow(Sender);

}
// ---------------------------------------------------------------------------

void TMainForm::RegisterForms() {

	RegisterTmtcForm(__classid(TAlimFormUnit), (TSimuForm**)&AlimFormUnit, "ALIM_FORM");
	MsgEvent(this, MEMO_ALIM_MESSAGE, INIT_ALIM);

	RegisterTmtcForm(__classid(TBenchFormUnit), (TSimuForm**)&BenchFormUnit, "BENCH FORM");
	MsgEvent(this, MEMO_BENCH_MESSAGE, INIT_BENCH);

	RegisterTmtcForm(__classid(TRxFormUnit), (TSimuForm**)&RxFormUnit, "EQUIPEMENT FORM");
	MsgEvent(this, MEMO_EQPT_MESSAGE, INIT_EQPT);

	RegisterObserver();
}

// ---------------------------------------------------------------------------
void TMainForm::RegisterObserver() {

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

// Fonction qui permet au lieur de fonctionner avec drivers_cpp avec l'option "Lier avec la RTL dynamique" à FALSE (Exe standalone)
void ResolveUnresolvedSTDExternals() {
	string dummy1;
	dummy1.find("");
	fstream dummy2;
	std::char_traits<char>::eq('a', 'b');
	cout.flags();
	dummy2.fail();
	dummy2.good();

	locale loc;
	std::ostream st;
	st.exceptions(2);
	st.precision(1);
	st.setf(std::ios::showbase, std::ios::showbase);
	st.eof();
	st.bad();
	st.operator void *();
	st.operator !();
	st << use_facet<codecvt<wchar_t, char, mbstate_t> >(loc).max_length();

	char_traits<wchar_t>::char_type str1[25] = L"The Hell Boy";
	char_traits<wchar_t>::char_type str2[25] = L"Something To ponder";
	char_traits<wchar_t>::move(str2, str1, 10);
	char_traits<wchar_t>::copy(str1, str2, 2);
	char_traits<wchar_t>::assign(*str1, *str2);
	char_traits<wchar_t>::assign(str1, 2, *str2);
	char_traits<char>::compare("test", "test", 2);
	char_traits<char>::find("test", 2, '2');
}
