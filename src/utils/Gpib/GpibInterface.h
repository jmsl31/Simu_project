// ---------------------------------------------------------------------------

#ifndef GpibInterfaceH
#define GpibInterfaceH
// ---------------------------------------------------------------------------

#include "GpibSubject.h"
#include <IniFiles.hpp>
#include <DateUtils.hpp>
#include "UtilsThread.h"
#include "visa.h"
#include "visa_C.h"
#include <visatype.h>
#include "Gpib_Enum.h"
#pragma link "visa32.lib"

namespace UtilSimu { // \namespace Utils

	/** \file : GpibInterface.c
	 *	\class GpibInterface  "utils\GPIB\GpibInterface.h"
	 *	\version : 1.0
	 *   \date : 29/03/2017
	 *   \brief definit la classe d'Interface GPIB .
	 *	\details
	 */

	class GpibInterface : public GpibSubject {

	public:

		/**
		 *\details Constructeur de la classe.
		 *\param \e TYPE_GPIB : Enumeration des types de Connection Manager du protocole GPIB
		 */

		GpibInterface();

		/**
		 *\details Destructeur de la classe.
		 *\param \e TYPE_GPIB : Enumeration des types de Connection Manager du protocole GPIB
		 */
		~GpibInterface();
		/**
		 *\details Initialisation l'objet de configuration Gpib de la classe
		 * \param GPIB_T : Objet regroupant la configuration de la communication GPIB
		 */
		void set_Gpib_T(GPIB_T struct_i);
		/**
		/**
		 *\details Recupere l'objet de configuration Gpib de la classe
		 * \return GPIB_T : Objet regroupant la configuration de la communication GPIB
		 */
		GPIB_T* get_Gpibt_T();

		/**
		 *\details Initialisation et ouvre la communication du Protocole GPIB de la classe avec le numero de la carte et l'adresse de l'instrument.
		 *\param \e TYPE_GPIB : Enumeration des types de Connection Manager du protocole GPIB
		 *\param \e GpibCard_i : Numero de la carte GPIB utilisée.
		 *\param \e GpibAdr_i : Adresse de la carte GPIB utilisée.
		 */

		bool InstallGpib();
		/**
		 *\details Ferme la communication du Protocole GPIB.
		 */
		bool UnInstallGPIB();

		/**
		 *\details Retourne l'etat de la communication du protocole GPIB.
		 */
		GPIB_STATUS getStatus();

		/**
		 *\details Initialise l'etat de la communication du protocole GPIB.
		 */
		void setStatus(GPIB_STATUS status);

		/**
		 *\details Retourne le type de communication du protocole GPIB.
		 *\valeur Server ou Client.
		 */
		TYPE_GPIB getType();
		/**
		 *\details Initialise le type de communication du protocole GPIB.
		 *\valeur Server ou Client.
		 */
		void setType(TYPE_GPIB t);

		/**
		 *\details Initialise la session de communication de l'instrument GPIB.
		 */
		void setInstr(ViSession instr);

		/**
		 *\details Retourne la session de communication de l'instrument GPIB.
		 *\return \e  ViSession
		 */
		ViSession getInstr();
		/**
		 *\details Initialise la session par defaut  de communication de l'instrument GPIB.
		 */
		void setDefaultSession(ViSession instr);
		/**
		 *\details Retourne la session par defaut de communication de l'instrument GPIB.
		 *\return \e  ViSession
		 */
		ViSession getDefaultSession();
		/**
		 *\details Traite l'erreur de communication de l'instrument GPIB.
		 *\param \e  ViStatus errVisa_i : erreur Ni_visa.
		 */
		void errVisaToStr(ViStatus errVisa_i);

		/**
		 *\details Lance le Thread de communication de l'instrument GPIB.
		 */
		void Start();
		/**
		 *\details Stop le Thread de communication de l'instrument GPIB.
		 */
		void Stop();

		/**
		 *\details return le status du le Thread.
		 *\return  THEARD_STATUS : Status du Thread.
		 */

		Utils::Thread::THEARD_STATUS getRecvStatus();

		/**
		 *\details Renseigne le status du le Thread.
		 *\param  THEARD_STATUS : Status du Thread.
		 */

		void setRecvStatus(Utils::Thread::THEARD_STATUS status);

		/**
		 *\details Fonction execute l'ecoute du port de communication GPIB.
		 *\return String Message reçu.
		 */
		std::string threadRecv();

		/**
		 *\details Fonction execute l'envoi de la reponse sur le port de communication GPIB.
		 *\param String Message reçu.
		 */
		void threadSend(std::string reponse);

	protected:

	private:

		ViSession defaultRM; /* !<  Session par Default du protocole GPIB */
		ViSession SessionInstrument;
		/* !<   Session de l'instance de l'instrument du protocole GPIB */

		GPIB_T* Comm_gpib_m; /* !< Objet de configuration Gpib de la classe. */

		Utils::Thread::THEARD_STATUS RecvStatus_m;
		/* !<  Status du Thread de Reception de l'instrument du protocole GPIB */
	};

}

#endif
