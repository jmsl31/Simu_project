// ---------------------------------------------------------------------------

#ifndef Shp661xxa_CH
#define Shp661xxa_CH
// ---------------------------------------------------------------------------

#include "virtual_alimentation_C.h"

namespace Utils { // \namespace Utils

	/** \file : Shp661xxa_C.c
	 *	\class Shp661xxa_C
	 *	\version : 1.0
	 *   \date : 17/10/2017
	 *   \brief Definit la class du Shp661xxa_C. Classe d'heritage de virtual_alimentation_C.
	 *	\details
	 */

	class Shp661xxa_C : public virtual_alimentation_C {

	private:

		/**
		 *\brief  Reset l'instrument.
		 */
		virtual void resetInstr();

		// brief Déclenche alim
		virtual void startAlim();

		// brief   Retire toutes les protections
		virtual void ClearProtect();

		/* /brief   defini le registre OverFlow.Concatene l'ensemble des flags.
		 * \param  std::string* overflow : Registre des flags.
		 */
		virtual void registreOver(std::string* overflow);

		// ==================Gestion d'erreurs========================================= */
		/* /brief   Retourne l'erreur de l'alimentation
		 * \param  std::string* errorToTolerate_i : Message d'erreur.
		 */
		virtual void errorQuery(std::string *errorToTolerate_i = NULL);

		/* ==================Sortie on/off============================================= */
		/* /brief   Setter d'activation de l'alimentation
		 * \param  bool state_o : etat d'activation de l'alimentation.
		 */
		virtual void setOutputState(bool state_o);
		/* /brief   Getter d'activation de l'alimentation
		 * \return  bool state_o : etat d'activation de l'alimentation.
		 */
		virtual void getOutputState(bool *state_o);

		/* ==================Tension=================================================== */
		/* /brief   Setter de la tension applicable d'alimentation
		 * \param  double voltLevel_V_i : tension applicable.
		 */
		void setVoltLevel(double voltLevel_V_i);
		/* /brief   Getter de la tension applicable d'alimentation
		 * \return  double voltLevel_V_i : tension applicable.
		 */
		void getVoltLevel(double *voltLevel_V_o);

		/* ----------Protection de surtention---------------------------------- */
		/* /brief   Setter de la tension de Protection d'alimentation
		 * \param  double voltLevel_V_i : tension de Protection.
		 */
		void setOVProtLevel(double OVPLevel_V_i);
		/* /brief   Getter de la tension de Protection d'alimentation
		 * \return  double voltLevel_V_i : tension de Protection.
		 */
		void getOVProtLevel(double *OVPLevel_V_o);

		/* ----------Tension de trig------------------------------------------- */
		/* /brief   Setter de la tension du Trigger d'alimentation
		 * \param  double voltLevel_V_i : tension du Trigger.
		 */
		virtual void setVoltTrig(double voltTrig_V_i);
		/* /brief   Getter de la tension du Trigger d'alimentation
		 * \return  double voltLevel_V_i : tension du Trigger.
		 */
		virtual void getVoltTrig(double *voltTrig_V_o);

		/* ==================Courant=================================================== */
		/* /brief   Setter du courant applicable d'alimentation
		 * \param  double currLevel_A_o : courant applicable.
		 */
		void setCurrLevel(double currLevel_A_i);
		/* /brief   Getter du courant applicable d'alimentation
		 * \return  double currLevel_A_o : courant applicable
		 */
		void getCurrLevel(double *currLevel_A_o);

		// ----------Protection de surampérage---------------------------------
		/* /brief   Setter du Courant de Protection d'alimentation
		 * \param  double currLevel_A_o : Courant de Protection.
		 */
		void setOCProt(double ovpS_i = 0);
		/* /brief   Getter du Courant de Protection d'alimentation
		 * \return  double currLevel_A_o : Courant de Protection
		 */
		void getOCProt(double *ovpS_o);
		/* /brief   Setter de l'etat de la Protection en Courant d'alimentation
		 * \param  bool ovpS_i : etat de la Protection en Courant.
		 */
		void setOCProtState(bool ovpS_i = 0);
		/* /brief   Getter de l'etat de la Protection en Courant d'alimentation
		 * \return  bool ovpS_i: etat de la Protection en Courant.
		 */
		void getOCProtState(bool *ovpS_o);

		/********************************* Variable ****************************************** */

	protected:

	public:

		/* /brief   Constructeur de Classe */
		Shp661xxa_C() : virtual_alimentation_C() {
			this->resetInstr();
		};

		/**
		 *\brief  Reception du Message. Fonction virtualle abstraite.
		 *\param  string message  : Message reçu.
		 *\param  int adr : Adresse du l'instrument.
		 *\param  GPIB_STATUS* status : pointeur Status de l'interface GPIB.
		 */
		std::string recvMessage(std::string message, int adr,
			GPIB_BUSDATA* status);
		/**
		 *\brief  Reception du Message. Fonction virtualle abstraite.
		 *\param  string message  : Message reçu.
		 *\param  int adr : Adresse du l'instrument.
		 *\param  GPIB_STATUS* status : pointeur Status de l'interface GPIB.
		 */
		void changeStatus(GPIB_STATUS status);

	};
}
#endif
