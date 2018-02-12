// ---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "SRxFormUnit.h"
#include "UtilsString.h"
#include "SRxThread.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvSmoothLabel"
#pragma link "AdvSmoothTabPager"
#pragma link "AdvSmoothLedLabel"
#pragma resource "*.dfm"
TRxFormUnit *RxFormUnit;

using namespace Utils;

// ---------------------------------------------------------------------------
__fastcall TRxFormUnit::TRxFormUnit(TComponent* Owner) : TSimuForm(Owner) {

	AnsiString chemin = "D:\\simu_cpp.bax\\baie\\Equipment\\Eqpt_rx.ini";
	TIniFile* file = new TIniFile(chemin);
	if (!(FileExists(chemin)))
		throw Exception("Fichier '" + chemin + "' non trouvé !");
	else {
		PanelDesc->Alignment = taCenter;
		PanelDesc->Align = TAlign::alTop;

		Device = new Rx_C();

		Device->InitEqpt(file);

		SRxThread* Thread = new SRxThread(false);
		// defintion de la priorité du thread.
		Thread->Priority = tpLower;

		// Panel Parametres de configuration.

		LabelName->Caption->Text = Utils::toAnsiString("Nom Affaire : " + Device->Name);
		LabelType->Caption->Text = Utils::toAnsiString(" Type : " + Device->Type);
		LabelNbAlim->Caption->Text = " Nb Alimentation : " + (AnsiString)Device->getNb_Alim();
		LabelNbTranche->Caption->Text = " Nb Tranche :" + (AnsiString)Device->getNb_Tranche();
		LabelNbTmtc->Caption->Text = " Nb Tmtc :" + (AnsiString)Device->getNb_Tmtc();

		TensionF->Caption->Value = Device->alim_m[0].VoltageActif;
		CourantF->Caption->Value = Device->alim_m[0].CurrentActif;

		LTension->Caption = "Tension Fonctionnel :";
		TTension->Text = Device->alim_m[0].Voltage;

		LCourant->Caption = "Courant Fonctionnel :";
		TCourant->Text = Device->alim_m[0].Current;

		LPuissance->Caption = " Puissance Nominal :";
		TPuissance->Text = Device->alim_m[0].Puissance;
		TPuissance->ReadOnly = true;

		LTensionMax->Caption = "Tension Maximal :";
		TTensionMax->Text = Device->alim_m[0].ProtVoltage;
		TTensionMax->ReadOnly = true;

		LCourantMin->Caption = "Courant Min:";
		TCourantMin->Text = Device->alim_m[0].CurrentMin;
		TCourantMin->ReadOnly = true;

		LCourantMax->Caption = "Courant Max:";
		TCourantMax->Text = Device->alim_m[0].CurrentMax;
		TCourantMax->ReadOnly = true;

		LGain->Caption = "Gain:";
		TGain->Text = Device->tranche_m[0].Gain;

		LPuissanceMax->Caption = " Puissance Max :";
		TPuissanceMax->Text = Device->tranche_m[0].Power_Max;

		LFreqStart->Caption = " Frequence Start:";
		TFreqStart->Text = Device->tranche_m[0].Frequency_Start_In;

		LFreqStop->Caption = " Frequence Stop :";
		TFreqStop->Text = Device->tranche_m[0].Frequency_Stop_In;

		LFreqMin->Caption = " Frequence Minimal :";
		TFreqMin->Text = Device->tranche_m[0].Frequency_Min;

		LFreqMax->Caption = " Frequence Maximal :";
		TfreqMax->Text = Device->tranche_m[0].Frequency_Max;

		LBandwidth->Caption = " Bandwidth :";
		TBandwidth->Text = Device->tranche_m[0].Bandwidth;

		LStep->Caption = " Step :";
		Tstep->Text = Device->tranche_m[0].Step;

		LPower->Caption = " Power :";
		TPower->Text = Device->tranche_m[0].Power;

		LFreqOl->Caption = "Frequence OL :";
		TFreqOl->Text = Device->Frequency_OL;

		LpowerOl->Caption = " Power OL :";
		TpowerOl->Text = Device->Power_Ol;

		LPowerMin->Caption = " Power In :";
		TPowerMin->Text = Device->PowerIn;

		LPowerMax->Caption = " Power Out :";
		TPowerMax->Text = Device->PowerOut;

		LPowerOlMax->Caption = " Power Ol Max :";
		TPowerOlMax->Text = Device->Power_Ol_Max;

		Thread->Resume();
	}
}
void __fastcall TRxFormUnit::BitBtn1Click(TObject *Sender)
{
Application->HelpContext(0);
}
//---------------------------------------------------------------------------

