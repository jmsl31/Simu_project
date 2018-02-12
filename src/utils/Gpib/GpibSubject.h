// ---------------------------------------------------------------------------

#ifndef GpibSubjectH
#define GpibSubjectH
// ---------------------------------------------------------------------------

#include <vector>
#include "GpibObserver.h"
#include "Gpib_Enum.h"

/** \file : GpibSubject.c
 *	\class GpibSubject  "utils\GPIB\GpibSubject.h"
 *	\version : 1.0
 *   \date : 29/03/2017
 *   \brief definit la classe Observable GPIB .
 *	\details
 */
namespace UtilSimu {

	class GpibSubject {

	public:
		/**
		 *\brief Destructeur de la classe.
		 */
		virtual ~GpibSubject();
		/**
		 *\brief Notifier le changement de statut.
		 *\param GPIB_STATUS status.
		 */
		void notifychangeStatus(GPIB_STATUS status);
		/**
		 *\brief Notifier la reception du message.
		 *\param std::string message.
		 *\param : int adr : adresse de l'instrument.
		 */
		virtual std::string notifyRecvMessage(std::string message, int adr,
			GPIB_BUSDATA* status);
		/**
		 *\brief Notifier le changement de Time out de reception.
		 *\param double timeout.
		 */
		void notifyTimeoutRecvData(double timeout = 0);
		/**
		 *\brief Ajout un Observateur.
		 *\param GpibObserver &obs.
		 */
		/**
		 *\brief  defini un changement de configuration.
		 *\param  double timeout : Time Out de reception.
		 */
		void notifyChangeConfiguration();
		/**
		 *\brief  defini un changement de l'adresse primaire.
		 *\param  double timeout : Time Out de reception.
		 */
		void notifyChangeAdrPrimaire(int Adr);
		/**
		 *\brief  defini un changement de l'adresse secondaire.
		 *\param  double timeout : Time Out de reception.
		 */
		void notifyChangeAdrSecondaire(int Adr);
		/**
		 *\brief Ajoute un Observateur.
		 *\param GpibObserver &obs.
		 */
		void addObserver(GpibObserver &obs);
		/**
		 *\brief Supprime un Observateur.
		 *\param GpibObserver &obs.
		 */
		void removeObserver(GpibObserver &obs);

	protected:
	private:

		std::vector<GpibObserver*>Observers_m; /* !< Liste d'Observateur. */

	};
}

#endif
