// ---------------------------------------------------------------------------

#ifndef virtual_Alimentation_CH
#define virtual_Alimentation_CH
// --------------------------------------------------------------------------
#include <IniFiles.hpp>
#include "vsim_C.h"
#include "InstSubject.h"
#include "EqptObserver.h"
#include "GpibObserver.h"

using namespace UtilSimu;

/** \file : virtual_alimentation_C.c
 *	\class vsim_C  "instruments\Alim\virtual_alimentation_C.h"
 *	\version : 1.0
 *   \date : 6/04/2017
 *   \brief definit la classe virtuelle des instruments Alimentation simul�s .
 *	\details
 */
class virtual_alimentation_C : public vsim_C, public GpibObserver,
	public InstSubject, public EqptObserver {

private:

	bool FOverVoltage, // Registre d'etat de Over Voltage
		FOverCurrent, // Registre d'etat de Over Courant
		FOverTemperature, // Regisre d'etat de Over Temperature
		FRemoteInhibit, // Registre d'etat de Remote
		FUnregulation, // Registre d'etat de regulation
		FActive, // Registre Activation
		FActiveReturn, // Registre Activation  de la reponse
		FActiveOverCurrent; // Registre activation Over Current

	double voltageMax_m, // Tension maximal delivr�e par l'alimentation
		currentMax_m, // Courant maximal delivr�e par l'alimentation
		powerMax_m, // Puissance maximal delivr�e par l'alimentation
		voltageRMS_m, // Tension RMS delivr�e par l'alimentation
		voltagePeak_m, // Tension Peak to Peak delivr�e par l'alimentation
		currentRMS_m; // Courant RMS delivr�e par l'alimentation

	double wantingCurrent_m, // Courant desir� delivr�e par l'alimentation
		wantingVoltage_m; // Tension desir� delivr�e par l'alimentation

	double activeCurrent_m, // Courant instantan�e delivr�e par l'alimentation
		activeVoltage_m, // Tension instantan�e delivr�e par l'alimentation
		activeVoltageProt_m,
		// Tension de protection instantan�e delivr�e par l'alimentation
		activeCurrentProt_m,
		// Courant de protection instantan�e delivr�e par l'alimentation
		activeVoltTrig_m; // Tension du Trigger de l'alimentation.

	double channel_m, // Channel principale de l'alimentation.
		sub_channel_m; // Channel secondaire de l'alimentation.

	std::string Name_m; // Nom de l'alimentation.
	std::string error_m; // message d'erreur

	void setOverVoltage(bool etat);
	void setOverCurrent(bool etat);
	void setOverTemperature(bool etat);
	void setRemoteInhibit(bool etat);
	void setUnregulation(bool etat);
	void setActive(bool etat);

	void setActiveCurrent(double value);
	// Tension maximal delivr�e par l'alimentation
	void setActiveVoltage(double value);
	// Courant maximal delivr�e par l'alimentation
	void setpowerMax(double value);
	// Puissance maximal delivr�e par l'alimentation

protected:

public:

	/**
	 *\brief propri�t� OverVoltage de la variable FOverVoltage.
	 */
		__property bool OverVoltage = {
		read = FOverVoltage, write = setOverVoltage};
	/**
	 *\brief propri�t� OverCurrent de la variable FOverCurrent.
	 */
	__property bool OverCurrent = {read = FOverCurrent, write = setOverCurrent};
	/**
	 *\brief propri�t� OverCurrent de la variable FOverCurrent.
	 */
	__property bool ActiveOverCurrent = {
		read = FActiveOverCurrent, write = FActiveOverCurrent};
	/**
	 *\brief propri�t� OverTemperature de la variable FOverTemperature.
	 */
	__property bool OverTemperature = {
		read = FOverTemperature, write = setOverTemperature};
	/**
	 *\brief propri�t� RemoteInhibit de la variable FRemoteInhibit.
	 */
	__property bool RemoteInhibit = {
		read = FRemoteInhibit, write = setRemoteInhibit};
	/**
	 *\brief propri�t� Unregulation de la variable FUnregulation.
	 */
	__property bool Unregulation = {
		read = FUnregulation, write = setUnregulation};
	/**
	 *\brief propri�t� VoltageMax de la variable voltageMax_m.
	 */
	__property double VoltageMax = {read = voltageMax_m, write = voltageMax_m};
	/**
	 *\brief propri�t� CurrentMax de la variable currentMax_m.
	 */
	__property double CurrentMax = {read = currentMax_m, write = currentMax_m};
	/**
	 *\brief propri�t� PowerMax de la variable powerMax_m.
	 */
	__property double PowerMax = {read = powerMax_m, write = setpowerMax};
	/**
	 *\brief propri�t� VoltageRMS de la variable voltageRMS_m.
	 */
	__property double VoltageRMS = {read = voltageRMS_m, write = voltageRMS_m};
	/**
	 *\brief propri�t� CurrentRMS de la variable currentRMS_m.
	 */
	__property double CurrentRMS = {read = currentRMS_m, write = currentRMS_m};
	/**
	 *\brief propri�t� VoltagePeak de la variable voltagePeak_m.
	 */
	__property double VoltagePeak = {read = voltagePeak_m, write = voltagePeak_m
	};
	/* \brief propri�t� ActiveCurrent de la variable activeCurrent_m.
	 */
	__property double WantingCurrent = {
		read = wantingCurrent_m, write = wantingCurrent_m};
	/**
	 *\brief propri�t� ActiveVoltage de la variable activeVoltage_m.
	 */
	__property double WantingVoltage = {
		read = wantingVoltage_m, write = wantingVoltage_m};

	// Propri�t� des variables instantann�es.
	/**
	 *\brief propri�t� ActiveCurrent de la variable activeCurrent_m.
	 */
	__property bool Active = {read = FActive, write = setActive};
	// Propri�t� des variables instantann�es.
	/**
	 *\brief propri�t� ActiveReturn de la variable FActiveReturn.
	 */
	__property bool ActiveReturn = {read = FActiveReturn, write = FActiveReturn
	};
	/**
	 *\brief propri�t� ActiveCurrent de la variable activeCurrent_m.
	 */
	__property double ActiveCurrent = {
		read = activeCurrent_m, write = setActiveCurrent};
	/**
	 *\brief propri�t� ActiveVoltage de la variable activeVoltage_m.
	 */
	__property double ActiveVoltage = {
		read = activeVoltage_m, write = setActiveVoltage};
	/**
	 *\brief propri�t� ActiveVoltage de la variable activeVoltage_m.
	 */
	__property double ActiveVoltageProt = {
		read = activeVoltageProt_m, write = activeVoltageProt_m};
	/**
	 *\brief propri�t� ActiveVoltage de la variable activeVoltage_m.
	 */
	__property double ActiveCurrentProt = {
		read = activeCurrentProt_m, write = activeCurrentProt_m};
	/**
	 *\brief propri�t� Channel de la variable channel_m.
	 */
	__property double Channel = {read = channel_m, write = channel_m};
	/**
	 *\brief propri�t� SubChannel de la variable sub_channel_m.
	 */
	__property double SubChannel = {read = sub_channel_m, write = sub_channel_m
	};
	/**
	 *\brief propri�t� Name de la variable Name_m.
	 */
	__property std::string Name = {read = Name_m, write = Name_m};
	/**
	 *\brief propri�t� Error de la variable Error_m.
	 */
	__property std::string Error = {read = error_m, write = error_m};
	/**
	 *\brief propri�t� VoltTrig de la variable activeVoltTrig_m.
	 */
	__property double VoltTrig = {
		read = activeVoltTrig_m, write = activeVoltTrig_m};

	/**
	 *\brief Constructeur de la classe
	 */
	virtual_alimentation_C();
	/*
	 *\brief  Reset l'instrument. */
	virtual void resetInstr() = 0;

	virtual void ClearProtect() = 0;

	/* ==================Tension=================================================== */

	/**
	 *\brief Programme la tension de sortie d�sir�e.
	 * \param voltLevel_V_i param�tre d'entr�e d�finissant la tension de sortie d�sir�e en volts.
	 */
	virtual void setVoltLevel(double voltLevel_V_i) = 0;

	/**
	 * \brief Lecture de la tension de sortie r�elle.
	 * \param voltLevel_V_o pointeur sur la tension de sortie actuelle en volts.
	 */
	virtual void getVoltLevel(double *voltLevel_V_o) = 0;

	/* ----------Range----------------------------------------------------- */
	/**
	 *\brief Programme la tension de sortie d�sir�e en mode Rampe.
	 * \param voltLevel_V_i param�tre d'entr�e d�finissant la tension de sortie d�sir�e en volts.
	 */
	// virtual void setVoltRange(double voltRange_V_i, int channel_i = 0,int sub_channel_i =0)=0;
	/**
	 *\brief Lecture la tension de sortie d�sir�e en mode Rampe.
	 * \param voltLevel_V_i param�tre d'entr�e d�finissant la tension de sortie d�sir�e en volts.
	 */
	// virtual void getVoltRange(double *voltRange_V_o, int channel_i = 0,int sub_channel_i =0)=0;

	/* ----------Protection de surtention---------------------------------- */

	/**
	 * \brief Programe la protection en surtension de sortie � la valeur d�sir�e.
	 * \param OVPLevel_V_i param�tre d'entr�e d�finissant la surtension de sortie maximum d�sir�e en volts avant protection.
	 */
	virtual void setOVProtLevel(double OVPLevel_V_i) = 0;

	/**
	 * Lecture de la valeur de surtension de sortie appliqu�e.
	 * @param OVPLevel_V_o pointeur sur la surtension de sortie en volts avant activation de la protection.
	 */
	virtual void getOVProtLevel(double *OVPLevel_V_o) = 0;

	/* ----------Tension de trig------------------------------------------- */

	/**
	 * \brief Programe la tension de trigger � la valeur d�sir�e.
	 * \param voltTrig_V_i param�tre d'entr�e d�finissant la tension de trigger d�sir�e en volts.
	 */
	// virtual void setVoltTrig(double voltTrig_V_i, int channel_i = 0,int sub_channel_i =0)=0;

	/**
	 * \brief Lecture de la tension de trigger appliqu�e.
	 * \param voltTrig_V_o pointeur sur la tension de trigger en volts.
	 */
	// virtual void getVoltTrig(double *voltTrig_V_o, int channel_i = 0,int sub_channel_i =0)=0;

	/* ==================Courant=================================================== */

	/**
	 * \brief Programe le courant de sortie d�sir�.
	 * \param currLevel_A_i param�tre d'entr�e d�finissant le courant de sortie d�sir�e en amp�res.
	 */
	virtual void setCurrLevel(double currLevel_A_i) = 0;

	/**
	 * \brief Lecture du courant de sortie r�el.
	 * \param currLevel_A_o pointeur sur le courant de sortie actuel en amp�res.
	 */
	virtual void getCurrLevel(double *currLevel_A_o) = 0;

	/* ----------Protection de suramp�rage--------------------------------- */

	/**
	 * \brief Programe la  protection en courant dans l'�tat d�sir� (ON ou OFF).
	 * \param state_i param�tre d'entr�e d�finissant l'�tat de la protection en courant (TRUE pour ON, FALSE pour OFF), l'�tat ON �tant s�lectionn� par d�faut.
	 * \param ocpDelayS_i param�tre d'entr�e d�finissant le delai de prise en compte de la protection en courant (en secondes), 0 �tant s�lectionn� par d�faut.
	 */
	virtual void setOCProtState(bool state_i = true) = 0;

	/**
	 * \brief Lecture de l'�tat dans lequel est la protection en courant.
	 * @param state_o pointeur sur l'�tat de la protection en courant (TRUE pour ON, FALSE pour OFF).
	 * @param ocpDelayS_o pointeur sur le delai de prise en compte de la protection en courant (en secondes).
	 */
	virtual void getOCProtState(bool *state_o) = 0;

	/* ----------Range----------------------------------------------------- */

	/**
	 * \brief Programme le courant
	 * \param currentRange_A_o valeur du courant.
	 * \param channel_i channel utilis�.
	 */
	// virtual void setCurrentRange(double currentRange_A_i, int channel_i = 0,int sub_channel_i =0) = 0;

	/**
	 * \brief lecture du courant
	 * \param currentRange_A_o valeur du courant.
	 * \param channel_i channel utilis�.
	 */

	// virtual void getCurrentRange(double *currentRange_A_o, int channel_i = 0,int sub_channel_i =0) = 0;

	/**
	 *\details Methode de communication de l'observer montante permettant la propagation de l'inforamtion entre les objets.
	 *\param std::string value : parametres a transmettre.
	 *\param TYPE_PARAM type : Type de parametres transmis
	 */
	/**
	 *\brief  Change le Status du GPIB.
	 *\param  status : Statut du GPIB.
	 */
	virtual void changeStatus(GPIB_STATUS status);
	/**
	 *\brief  Reception du Message.
	 *\param  string message  : Message re�u.
	 */
	virtual std::string recvMessage(std::string message, int adr,
		GPIB_BUSDATA* status);
	/**
	 *\brief  defini un changement de configuration.
	 *\param  double timeout : Time Out de reception.
	 */
	virtual void ChangeConfiguration();
	/**
	 *\brief  defini un changement de l'adresse primaire.
	 *\param  double timeout : Time Out de reception.
	 */
	virtual void ChangeAdrPrimaire(int Adr);
	/**
	 *\brief  defini un changement de l'adresse secondaire.
	 *\param  double timeout : Time Out de reception.
	 */
	virtual void ChangeAdrSecondaire(int Adr);
	/**
	 *\brief  defini le time Out du Reception.
	 *\param  double timeout : Time Out de reception.
	 */
	virtual void timeoutRecvData(double timeout = 0);

	virtual void ChangeValueRising(std::string value, TYPE_PARAM type);
	virtual void ChangeValueRising(int value, TYPE_PARAM type);
	virtual void ChangeValueRising(double value, TYPE_PARAM type);
	virtual void ChangeValueRising(bool value, TYPE_PARAM type);
};

#endif
