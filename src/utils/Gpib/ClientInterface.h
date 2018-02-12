// ---------------------------------------------------------------------------

#ifndef ClientInterfaceH
#define ClientInterfaceH
// ---------------------------------------------------------------------------

#include "GpibInterface.h"
#include "GpibObserver.h"

namespace UtilSimu { // \namespace Utils

	class ClientInterface : public GpibObserver {

	public:

		/**
		 *\details Constructeur de la classe.
		 */
		ClientInterface();

		/**
		 *\details Destructeur de la classe.
		 */
		~ClientInterface();
		/**
		 *\brief  Change le Status du GPIB.
		 *\param  status : Statut du GPIB.
		 */
		void changeStatus(GPIB_STATUS status);
		/**
		 *\brief  Reception du Message.
		 *\param  string message  : Message reçu.
		 */
		void recvMessage(std::string message, int adr, GPIB_STATUS* status);
		/**
		 *\brief  defini un changement de configuration.
		 *\param  double timeout : Time Out de reception.
		 */
		void ChangeConfiguration();
		/**
		 *\brief  defini un changement de l'adresse primaire.
		 *\param  double timeout : Time Out de reception.
		 */
		void ChangeAdrPrimaire(int Adr);
		/**
		 *\brief  defini un changement de l'adresse secondaire.
		 *\param  double timeout : Time Out de reception.
		 */
		void ChangeAdrSecondaire(int Adr);
		/**
		 *\brief  defini le time Out du Reception.
		 *\param  double timeout : Time Out de reception.
		 */
		void timeoutRecvData(double timeout = 0);

		GPIB_STATUS getStatus();
		void setStatus(GPIB_STATUS status);

		int getAdrprimaire();
		void setAdrPrimarie(int adr);

		int getAdrSecondaire();
		void setAdrSecondaire(int adr);

		std::string getmessage();
		void setmessage(std::string mes);

	protected:

	private:

		GPIB_STATUS status;
		int AdrPrimaire;
		int AdrSecondaire;
		double timeout;

		std::string message;

	};
}
#endif
