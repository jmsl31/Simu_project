// ---------------------------------------------------------------------------

#ifndef SRxThreadH
#define SRxThreadH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "Rx_C.h"


/** \file : RxThread.c
 *	\class TBenchThread
 *	\version : SRxThread.0
 *   \date : 17/10/2017
 *   \brief Definit la class du Thread de l'objet Rcepteur.
 *	\details
 */
// ---------------------------------------------------------------------------
class SRxThread : public TThread {
protected:

	long stop_m;// Drapeau d'execution du Thread

/* ! \brief Methode d'execution du Thread.
	 */
	void __fastcall Execute();
/* ! \brief  Methode de mise à jour de l'Ihm
	 */
	void __fastcall UpdateIhm();
/* ! \brief Methode de surveillance des variables de l'objet Banc.
	 */
	void __fastcall Monitoring();
	/* ! \brief Methode de gestion des interruptions du Thread dans le cas d'un Multi-Thread.
	 */
	void __fastcall GentleStop();

public:

	__fastcall SRxThread(bool CreateSuspended);





};
// ---------------------------------------------------------------------------
#endif
