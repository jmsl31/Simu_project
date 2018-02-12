// ---------------------------------------------------------------------------

#ifndef Gpib_EnumH
#define Gpib_EnumH
// ---------------------------------------------------------------------------

#include <iostream>

namespace UtilSimu { // \namespace Utils

	// \enum  TYPE_GPIB
	// \details Enumeration des types de connection possible.
	enum TYPE_GPIB {
		SERVER, /* !< Enum de Type Server. */
			CLIENT /* !< Enum de Type Client. */
	};

	/* \enum GPIB_Status
	 *	  \brief Status de la connection GPIB.
	 */
	enum GPIB_STATUS {
		STOPPED, // STOP
			CONNECTED, // CONNECTE
			UNDEFINED, // NON DEFINI.
		};

	/* \enum BUSDATA
	 *	  \brief Status DU BUS DATA.
	 */
	enum GPIB_BUSDATA {
		LISTTED, // Ecoute
			WRITTED, // Ecriture
			REQUEST, // Demadne
			REPLY, // Reponse.
			UNDEF
	};

	/* \struct  GPIB_T : Objet regroupant la configuration de la communication GPIB
	 */
	struct GPIB_T {

		TYPE_GPIB type; // Type de communication
		int Id_Interface; // Numero de l'index de l'interface.
		int Adr_Primaire; // Adresse primaire de l'objet.
		int Adr_secondaire; // Adresse secondaire de l'objet
		bool controler_system; // Parametre Controle system
		int timeout; // Timeout de fin de reception.
		bool EOI; // EOI
		GPIB_STATUS status; // Etat du status de communication.
		GPIB_BUSDATA Status_bus;
	};

	/* \fn   GPIB_STATUS toGpibStatus(std::string status)
	 * \brief Defini l'etat du statut du GPIB.
	 *\return GPIB_STATUS.
	 */
	GPIB_STATUS toGpibStatus(std::string status);

	GPIB_STATUS toGpibStatus(std::string status) {
		if (status.c_str() == "STOPPED")
			return STOPPED;
		if (status.c_str() == "CONNECTED")
			return CONNECTED;
		return UNDEFINED;
	};

	GPIB_BUSDATA toGpibBusData(std::string statusBus) {
		if (statusBus.c_str() == "LISTTED")
			return LISTTED;
		if (statusBus.c_str() == "WRITTED")
			return WRITTED;
		if (statusBus.c_str() == "REQUEST")
			return REQUEST;
		if (statusBus.c_str() == "REPLY")
			return REPLY;
		return UNDEF;
	};
}
#endif
