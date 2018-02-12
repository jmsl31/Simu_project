// ---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdContext.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.CategoryButtons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.WinXCtrls.hpp>
#include "MainSimuFormUnit.h"
#include "SAlimFormUnit.h"
#include "SRXFormUnit.h"
#include "SBenchFormUnit.h"

/** \file : MainUnit.c
 *	\class TMainUnit
 *	\version : 1.0
 *   \date : 17/10/2017
 *   \brief Definit la class pricipale du programme.
 *	\details
 */
// ---------------------------------------------------------------------------
class TMainForm : public TMainSimuForm {
__published: // Composants g�r�s par l'EDI
	void __fastcall FormShow(TObject *Sender);

protected:
	// Methodes
	/**
	 *\details Methode enregistre les fentres Enfants du programme.
	 *\return AnsiString : le numero d'immo.
	 */

	virtual void RegisterForms();
	/**
	 *\details Methode definissant la strat�gies et la hi�archie des objets du programme.
	 *\return AnsiString : le numero d'immo.
	 */
	virtual void RegisterObserver();

private: // D�clarations utilisateur
	  public : // D�clarations utilisateur
	__fastcall TMainForm(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif
