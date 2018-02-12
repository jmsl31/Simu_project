// ---------------------------------------------------------------------------

#ifndef SRxFormUnitH
#define SRxFormUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "AdvSmoothLabel.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "Rx_C.h"
#include "AdvSmoothTabPager.hpp"
#include "AdvSmoothLedLabel.hpp"
#include "SimuFormUnit.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "ConstanteDefine.h"
#include "SRxThread.h"
#include <Vcl.Buttons.hpp>


/** \file : RxFormUnit.c
 *	\class TRxFormUnit
 *	\version : 1.0
 *   \date : 17/10/2017
 *   \brief Definit la class d'interface Homme/Machine de l'equipement Rx.
 *La classe herite de la classe TSimuForm.
 *	\details
 */
// ---------------------------------------------------------------------------
class TRxFormUnit : public TSimuForm {
__published: // Composants gérés par l'EDI

	TPageControl *PageControl;
	TTabSheet *PageParam;
	TPanel *PanelDesc;
	TAdvSmoothLabel *LabelCourant;
	TAdvSmoothLabel *LabelName;
	TAdvSmoothLabel *LabelNbAlim;
	TAdvSmoothLabel *LabelNbTmtc;
	TAdvSmoothLabel *LabelNbTranche;
	TAdvSmoothLabel *LabelTension;
	TAdvSmoothLabel *LabelType;
	TAdvSmoothLedLabel *TensionF;
	TAdvSmoothLedLabel *CourantF;
	TGridPanel *GridParam;
	TEdit *TTension;
	TLabel *LTension;
	TLabel *LCourant;
	TEdit *TCourant;
	TLabel *LPuissance;
	TEdit *TPuissance;
	TLabel *LTensionMax;
	TEdit *TTensionMax;
	TLabel *LCourantMin;
	TEdit *TCourantMin;
	TLabel *LPuissanceMax;
	TLabel *LGain;
	TEdit *TGain;
	TLabel *LFreqStart;
	TEdit *TFreqStart;
	TLabel *LFreqStop;
	TEdit *TFreqStop;
	TEdit *TFreqMin;
	TEdit *TfreqMax;
	TEdit *TBandwidth;
	TEdit *Tstep;
	TEdit *TPower;
	TEdit *TFreqOl;
	TEdit *TpowerOl;
	TEdit *TPowerMin;
	TEdit *TPowerMax;
	TEdit *TPowerOlMax;
	TLabel *LFreqMin;
	TLabel *LFreqMax;
	TLabel *LBandwidth;
	TLabel *LStep;
	TLabel *LPower;
	TLabel *LFreqOl;
	TLabel *LpowerOl;
	TLabel *LPowerMin;
	TLabel *LPowerMax;
	TLabel *LPowerOlMax;
	TEdit *TPuissanceMax;
	TLabel *LCourantMax;
	TEdit *TCourantMax;
	TBitBtn *BitBtn1;
	void __fastcall BitBtn1Click(TObject *Sender);

private: // Déclarations utilisateur

public : // Déclarations utilisateur

/* ! \brief Constructeur
	   */
	__fastcall TRxFormUnit(TComponent* Owner);

	/* ! \brief Defition de l'objet Thread du Banc.
	 */
	SRxThread* Thread;
/* ! \brief Defintion de l'objet Rx
	 */
	Rx_C* Device;
};

// ---------------------------------------------------------------------------
extern PACKAGE TRxFormUnit *RxFormUnit;
// ---------------------------------------------------------------------------
#endif
