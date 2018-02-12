// ---------------------------------------------------------------------------

#ifndef GpibObserverH
#define GpibObserverH
// ---------------------------------------------------------------------------

#include <iostream>

#include "Gpib_Enum.h"

/** \file : GpibObserver.c
 *	\class GpibObserver  "utils\GPIB\GpibObserver.h"
 *	\version : 1.0
 *   \date : 29/03/2017
 *   \brief definit la classe Observer GPIB .
 *	\details
 */
namespace UtilSimu {
	class GpibObserver {

	public:
		/**
		 *\details Destructeur de la classe.
		 */
		virtual ~GpibObserver();
		/**
		 *\brief  Change le Status du GPIB.
		 *\param  status : Statut du GPIB.
		 */
		virtual void changeStatus(GPIB_STATUS status) = 0;
		/**
		 *\brief  Reception du Message.
		 *\param  string message  : Message reçu.
		 */
		virtual std::string recvMessage(std::string message, int adr,
			GPIB_BUSDATA* status) = 0;
		/**
		 *\brief  defini un changement de configuration.
		 *\param  double timeout : Time Out de reception.
		 */
		virtual void ChangeConfiguration() = 0;
		/**
		 *\brief  defini un changement de l'adresse primaire.
		 *\param  double timeout : Time Out de reception.
		 */
		virtual void ChangeAdrPrimaire(int Adr) = 0;
		/**
		 *\brief  defini un changement de l'adresse secondaire.
		 *\param  double timeout : Time Out de reception.
		 */
		virtual void ChangeAdrSecondaire(int Adr) = 0;
		/**
		 *\brief  defini le time Out du Reception.
		 *\param  double timeout : Time Out de reception.
		 */
		virtual void timeoutRecvData(double timeout = 0) = 0;

	protected:

	private:

	};
}

#endif
