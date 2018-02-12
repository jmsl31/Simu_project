// ---------------------------------------------------------------------------

#ifndef TBenchThreadH
#define TBenchThreadH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "SBench.h"

/** \file : TBenchThread.c
 *	\class TBenchThread
 *	\version : 1.0
 *   \date : 17/10/2017
 *   \brief Definit la class du Thread de l'objet Banc.
 *	\details
 */
// ---------------------------------------------------------------------------
class TBenchThread : public TThread {
protected:

	long stop_m;		// Drapeau d'execution du Thread
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
/* ! \brief Constructeur de classe.
		 */
	__fastcall TBenchThread(bool CreateSuspended);
};
// ---------------------------------------------------------------------------
#endif
