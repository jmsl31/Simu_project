// ---------------------------------------------------------------------------

#ifndef SBenchFormUnitH
#define SBenchFormUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "SimuFormUnit.h"
#include "SBench.h"
#include "InstObserver.h"
#include <Vcl.Imaging.pngimage.hpp>
#include "ConstanteDefine.h"
#include "AdvSmoothLedLabel.hpp"
#include <Vcl.Buttons.hpp>

/** \file : BenchFormUnit.c
 *	\class TBenchFormUnit
 *	\version : 1.0
 *   \date : 17/10/2017
 *   \brief Definit la class d'interface Homme/Machine du Bench .
 *    \La classe herite de la classe TSimuForm.
 *	\details
 */
// ---------------------------------------------------------------------------
class TBenchFormUnit : public TSimuForm {
__published: // Composants gérés par l'EDI

	TPanel *Panel1;
	TEdit *TextName;
	TEdit *TextImmo;
	TLabel *LabelImmo;
	TLabel *LabelName;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TGroupBox *GroupBox2;
	TLabel *Label4;
	TListView *ListView1;
	TLabel *Label5;
	TEdit *TCal_In;
	TEdit *TCal_Out;
	TLabel *Label6;
	TEdit *TCal_Spectrum;
	TLabel *Label7;
	TAdvSmoothLedLabel *TextTension;
	TAdvSmoothLedLabel *TextCourant;
	TAdvSmoothLedLabel *TextPower;
	TBitBtn *BitBtn1;
	void __fastcall BitBtn1Click(TObject *Sender);


private: // Déclarations utilisateur

	T1DStringArray DeviceList;  // Liste des appareils de mesures à afficher

public: // Déclarations utilisateur

	SBench_C* Device_m;    // Defintion de l'objet Bench
	void startUpdateIHM();
	/* ! \brief Propriete Device de l'objet Bench.
	 */
	__property SBench_C* Device = {read = Device_m, write = Device_m};
		/* ! \brief Methode affichant la liste des appareils de mesures du banc.
		 */
		void getListDevice();
    	/* ! \brief Constructeur
		 */
		__fastcall TBenchFormUnit(TComponent* Owner);

     void OpenLocalFile(UnicodeString Path) ;
};

// ---------------------------------------------------------------------------
extern PACKAGE TBenchFormUnit *BenchFormUnit;
// ---------------------------------------------------------------------------

#endif
