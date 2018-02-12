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
 *   \brief definit la classe virtuelle des instruments Alimentation simulés .
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

	double voltageMax_m, // Tension maximal delivrée par l'alimentation
		currentMax_m, // Courant maximal delivrée par l'alimentation
		powerMax_m, // Puissance maximal delivrée par l'alimentation
		voltageRMS_m, // Tension RMS delivrée par l'alimentation
		voltagePeak_m, // Tension Peak to Peak delivrée par l'alimentation
		currentRMS_m; // Courant RMS delivrée par l'alimentation

	double wantingCurrent_m, // Courant desiré delivrée par l'alimentation
		wantingVoltage_m; // Tension desiré delivrée par l'alimentation

	double activeCurrent_m, // Courant instantanée delivrée par l'alimentation
		activeVoltage_m, // Tension instantanée delivrée par l'alimentation
		activeVoltageProt_m,
		// Tension de protection instantanée delivrée par l'alimentation
		activeCurrentProt_m,
		// Courant de protection instantanée delivrée par l'alimentation
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
	// Tension maximal delivrée par l'alimentation
	void setActiveVoltage(double value);
	// Courant maximal delivrée par l'alimentation
	void setpowerMax(double value);
	// Puissance maximal delivrée par l'alimentation

protected:

public:

	/**
	 *\brief propriété OverVoltage de la variable FOverVoltage.
	 */
		__property bool OverVoltage = {
		read = FOverVoltage, write = setOverVoltage};
	/**
	 *\brief propriété OverCurrent de la variable FOverCurrent.
	 */
	__property bool OverCurrent = {read = FOverCurrent, write = setOverCurrent};
	/**
	 *\brief propriété OverCurrent de la variable FOverCurrent.
	 */
	__property bool ActiveOverCurrent = {
		read = FActiveOverCurrent, write = FActiveOverCurrent};
	/**
	 *\brief propriété OverTemperature de la variable FOverTemperature.
	 */
	__property bool OverTemperature = {
		read = FOverTemperature, write = setOverTemperature};
	/**
	 *\brief propriété RemoteInhibit de la variable FRemoteInhibit.
	 */
	__property bool RemoteInhibit = {
		read = FRemoteInhibit, write = setRemoteInhibit};
	/**
	 *\brief propriété Unregulation de la variable FUnregulation.
	 */
	__property bool Unregulation = {
		read = FUnregulation, write = setUnregulation};
	/**
	 *\brief propriété VoltageMax de la variable voltageMax_m.
	 */
	__property double VoltageMax = {read = voltageMax_m, write = voltageMax_m};
	/**
	 *\brief propriété CurrentMax de la variable currentMax_m.
	 */
	__property double CurrentMax = {read = currentMax_m, write = currentMax_m};
	/**
	 *\brief propriété PowerMax de la variable powerMax_m.
	 */
	__property double PowerMax = {read = powerMax_m, write = setpowerMax};
	/**
	 *\brief propriété VoltageRMS de la variable voltageRMS_m.
	 */
	__property double VoltageRMS = {read = voltageRMS_m, write = voltageRMS_m};
	/**
	 *\brief propriété CurrentRMS de la variable currentRMS_m.
	 */
	__property double CurrentRMS = {read = currentRMS_m, write = currentRMS_m};
	/**
	 *\brief propriété VoltagePeak de la variable voltagePeak_m.
	 */
	__property double VoltagePeak = {read = voltagePeak_m, write = voltagePeak_m
	};
	/* \brief propriété ActiveCurrent de la variable activeCurrent_m.
	 */
	__property double WantingCurrent = {
		read = wantingCurrent_m, write = wantingCurrent_m};
	/**
	 *\brief propriété ActiveVoltage de la variable activeVoltage_m.
	 */
	__property double WantingVoltage = {
		read = wantingVoltage_m, write = wantingVoltage_m};

	// Propriété des variables instantannées.
	/**
	 *\brief propriété ActiveCurrent de la variable activeCurrent_m.
	 */
	__property bool Active = {read = FActive, write = setActive};
	// Propriété des variables instantannées.
	/**
	 *\brief propriété ActiveReturn de la variable FActiveReturn.
	 */
	__property bool ActiveReturn = {read = FActiveReturn, write = FActiveReturn
	};
	/**
	 *\brief propriété ActiveCurrent de la variable activeCurrent_m.
	 */
	__property double ActiveCurrent = {
		read = activeCurrent_m, write = setActiveCurrent};
	/**
	 *\brief propriété ActiveVoltage de la variable activeVoltage_m.
	 */
	__property double ActiveVoltage = {
		read = activeVoltage_m, write = setActiveVoltage};
	/**
	 *\brief propriété ActiveVoltage de la variable activeVoltage_m.
	 */
	__property double ActiveVoltageProt = {
		read = activeVoltageProt_m, write = activeVoltageProt_m};
	/**
	 *\brief propriété ActiveVoltage de la variable activeVoltage_m.
	 */
	__property double ActiveCurrentProt = {
		read = activeCurrentProt_m, write = activeCurrentProt_m};
	/**
	 *\brief propriété Channel de la variable channel_m.
	 */
	__property double Channel = {read = channel_m, write = channel_m};
	/**
	 *\brief propriété SubChannel de la variable sub_channel_m.
	 */
	__property double SubChannel = {read = sub_channel_m, write = sub_channel_m
	};
	/**
	 *\brief propriété Name de la variable Name_m.
	 */
	__property std::string Name = {read = Name_m, write = Name_m};
	/**
	 *\brief propriété Error de la variable Error_m.
	 */
	__property std::string Error = {read = error_m, write = error_m};
	/**
	 *\brief propriété VoltTrig de la variable activeVoltTrig_m.
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
	 *\brief Programme la tension de sortie désirée.
	 * \param voltLevel_V_i paramètre d'entrée définissant la tension de sortie désirée en volts.
	 */
	virtual void setVoltLevel(double voltLevel_V_i) = 0;

	/**
	 * \brief Lecture de la tension de sortie réelle.
	 * \param voltLevel_V_o pointeur sur la tension de sortie actuelle en volts.
	 */
	virtual void getVoltLevel(double *voltLevel_V_o) = 0;

	/* ----------Range----------------------------------------------------- */
	/**
	 *\brief Programme la tension de sortie désirée en mode Rampe.
	 * \param voltLevel_V_i paramètre d'entrée définissant la tension de sortie désirée en volts.
	 */
	// virtual void setVoltRange(double voltRange_V_i, int channel_i = 0,int sub_channel_i =0)=0;
	/**
	 *\brief Lecture la tension de sortie désirée en mode Rampe.
	 * \param voltLevel_V_i paramètre d'entrée définissant la tension de sortie désirée en volts.
	 */
	// virtual void getVoltRange(double *voltRange_V_o, int channel_i = 0,int sub_channel_i =0)=0;

	/* ----------Protection de surtention---------------------------------- */

	/**
	 * \brief Programe la protection en surtension de sortie à la valeur désirée.
	 * \param OVPLevel_V_i paramètre d'entrée définissant la surtension de sortie maximum désirée en volts avant protection.
	 */
	virtual void setOVProtLevel(double OVPLevel_V_i) = 0;

	/**
	 * Lecture de la valeur de surtension de sortie appliquée.
	 * @param OVPLevel_V_o pointeur sur la surtension de sortie en volts avant activation de la protection.
	 */
	virtual void getOVProtLevel(double *OVPLevel_V_o) = 0;

	/* ----------Tension de trig------------------------------------------- */

	/**
	 * \brief Programe la tension de trigger à la valeur désirée.
	 * \param voltTrig_V_i paramètre d'entrée définissant la tension de trigger désirée en volts.
	 */
	// virtual void setVoltTrig(double voltTrig_V_i, int channel_i = 0,int sub_channel_i =0)=0;

	/**
	 * \brief Lecture de la tension de trigger appliquée.
	 * \param voltTrig_V_o pointeur sur la tension de trigger en volts.
	 */
	// virtual void getVoltTrig(double *voltTrig_V_o, int channel_i = 0,int sub_channel_i =0)=0;

	/* ==================Courant=================================================== */

	/**
	 * \brief Programe le courant de sortie désiré.
	 * \param currLevel_A_i paramètre d'entrée définissant le courant de sortie désirée en ampères.
	 */
	virtual void setCurrLevel(double currLevel_A_i) = 0;

	/**
	 * \brief Lecture du courant de sortie réel.
	 * \param currLevel_A_o pointeur sur le courant de sortie actuel en ampères.
	 */
	virtual void getCurrLevel(double *currLevel_A_o) = 0;

	/* ----------Protection de surampérage--------------------------------- */

	/**
	 * \brief Programe la  protection en courant dans l'état désiré (ON ou OFF).
	 * \param state_i paramètre d'entrée définissant l'état de la protection en courant (TRUE pour ON, FALSE pour OFF), l'état ON étant sélectionné par défaut.
	 * \param ocpDelayS_i paramètre d'entrée définissant le delai de prise en compte de la protection en courant (en secondes), 0 étant sélectionné par défaut.
	 */
	virtual void setOCProtState(bool state_i = true) = 0;

	/**
	 * \brief Lecture de l'état dans lequel est la protection en courant.
	 * @param state_o pointeur sur l'état de la protection en courant (TRUE pour ON, FALSE pour OFF).
	 * @param ocpDelayS_o pointeur sur le delai de prise en compte de la protection en courant (en secondes).
	 */
	virtual void getOCProtState(bool *state_o) = 0;

	/* ----------Range----------------------------------------------------- */

	/**
	 * \brief Programme le courant
	 * \param currentRange_A_o valeur du courant.
	 * \param channel_i channel utilisé.
	 */
	// virtual void setCurrentRange(double currentRange_A_i, int channel_i = 0,int sub_channel_i =0) = 0;

	/**
	 * \brief lecture du courant
	 * \param currentRange_A_o valeur du courant.
	 * \param channel_i channel utilisé.
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
	 *\param  string message  : Message reçu.
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
