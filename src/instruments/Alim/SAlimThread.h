﻿// ---------------------------------------------------------------------------

#ifndef SAlimThreadH
#define SAlimThreadH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
// ---------------------------------------------------------------------------

#include "SAlimFormUnit.h"
#include "SAlimentations.h"

/** \file : TAlimThread.c
 *	\class TAlimThread
 *	\version : 1.0
 *   \date : 17/10/2017
 *   \brief Definit la class du Thread de l'objet Alimentation.
 *	\details
 */
class TAlimThread : public TThread {
protected:

	long stop_m; // Drapeau d'execution du Thread

	SAlimentations* Alim; // defintion d'un objet SAlimentaion ;



	/* ! \brief Setter de l'objet Salimentaion
	 *\param Pointeur de l'objet Salimentation : Onjet Alimentation.
	 */
	void __fastcall setAlim(SAlimentations* A);
	/* ! \brief Methode d'execution du Thread.
	 */
	void __fastcall Execute();
	/* ! \brief  Methode de mise à jour de l'Ihm
	 */
	void __fastcall UpdateIhm();
	/* ! \brief Methode de gestion des interruptions du Thread dans le cas d'un Multi-Thread.
	 */
	void __fastcall GentleStop();
	/* ! \brief Methode de surveillance des variables de l'objet Banc.
	 */
	void __fastcall monitoringParam();

public:
	// Constructeur de Classe.
	__fastcall TAlimThread(bool CreateSuspended, SAlimentations* Alim);
};
// ---------------------------------------------------------------------------
#endif
