// ---------------------------------------------------------------------------

#ifndef virtual_multimeters_CH
#define virtual_multimeters_CH
// ---------------------------------------------------------------------------

#include <IniFiles.hpp>
#include "vsim_C.h"
#include <iostream.h>
#include <stdlib.h>

using namespace Utils;

/**
 * Classe de multimètres virtuels de base, tous les autres multimètres vont hériter de celle ci.
 * Tous les multimètres implémenterons au moins ces fonctions.
 */
class virtual_multimeters_C : public vsim_C, public GpibObserver {

private:

	int channel_m, // Channel principale du Mutimetre.
	  average_m; // Average_m  Average de Mesure.
	double dcVolt_v_m, // dcVolt_v_m Valeur de la tension en Continu.
	  acVolt_v_m, // AcVolt_v_m Valeur de la tension en Alternatif.
	  dcAmp_a_m, // dcAmp_a_m Valeur du courant en Continu.
	  acAmp_a_m, // acAmp_a_m Valeur du courant en Alternatif.
	  ohm_m, // ohm_m Valeur de résistance en Ohm.
	  freq_m, // freq_m Valeur de frequence.
	  temp_m, // temp_m Valeur de Temperature.
	  pow_dBm_m, // pow_dBm_m Valeur Puissance en dBm.
	  delta_mes_m; // delta_mes_m Delta de precision de mesure.
	bool doErrorQueryInDriver_m, // doErrorQueryInDriver_m flag d'erreur.
	  mode_Ac_m; // mode_Ac_m Mode de Mesure : 0 Ac /1 Dc.

	virtual void resetInst(int channel_i, int average_i, double dcVolt_v_i, double acVolt_v_i, double dcAmp_a_i, double acAmp_a_i, double ohm_i, double freq_i,
	  double temp_i, double pow_dBm_i, double delta_mes_i, bool doErrorQueryInDriver_i, bool mode_Ac_i);

	std::string error_m; // error

	virtual double getAverage();
	virtual void setAverage(int Average_i);
	virtual std::string getError();
	virtual void setError(std::string error_i);

public:

	virtual double createValueRand(double value_i);
	virtual double createMoyenne(double value_i);


	/**
	 *\brief propriété ErrorQueryInDriver de la variable doErrorQueryInDriver_m.
	 */
	__property bool ErrorQueryInDriver = {read = doErrorQueryInDriver_m, write = doErrorQueryInDriver_m};
	/**

	/**
	 *\brief propriété MsgError de la variable error_m.
	 */
	__property std::string MsgError = {read = error_m, write = error_m};
	/**

	/**
	 *\brief propriété ErrorQueryInDriver de la variable doErrorQueryInDriver_m.
	 */
	__property bool Mode_Ac = {read = mode_Ac_m, write = mode_Ac_m};
	/**

	/**
	 *\brief propriété Channel de la variable channel_m.
	 */
	__property int Channel = {read = channel_m, write = channel_m};
	/**

	/**
	 *\brief propriété Average de la variable average_m.
	 */
	__property int Average = {read = average_m, write = average_m};
	/**

	/**
	 *\brief propriété DcVolt de la variable dcVolt_v_m.
	 */
	__property double DcVolt = {read = dcVolt_v_m, write = dcVolt_v_m};
	/**
	/**
	 *\brief propriété DcVolt de la variable delta_mes_m.
	 */
	__property double Delta_Mes = {read = delta_mes_m, write = delta_mes_m};
	/**
	/**
	 *\brief propriété AcVolt de la variable acVolt_v_m.
	 */
	__property double AcVolt = {read = acVolt_v_m, write = acVolt_v_m};
	/**

	/**
	 *\brief propriété DcAmp de la variable dcAmp_a_m.
	 */
	__property double DcAmp = {read = dcAmp_a_m, write = dcAmp_a_m};
	/**

	/**
	 *\brief propriété AcAmp de la variable acAmp_a_m.
	 */
	__property double AcAmp = {read = acAmp_a_m, write = acAmp_a_m};
	/**

	/**
	 *\brief propriété Ohm de la variable ohm_m.
	 */
	__property double Ohm = {read = ohm_m, write = ohm_m};
	/**

	/**
	 *\brief propriété Freq de la variable freq_m.
	 */
	__property double Freq = {read = freq_m, write = freq_m};
	/**

	/**
	 *\brief propriété Temp de la variable temp_m.
	 */
	__property double Temp = {read = temp_m, write = temp_m};
	/** pow_dBm_m

	/**
	 *\brief propriété Pow_dBm de la variable pow_dBm_m.
	 */
	__property double Pow_dBm = {read = pow_dBm_m, write = pow_dBm_m};
	/**

	/**
	 * Constructeur
	 * */

	virtual_multimeters_C();

	/**
	 * Mesure en mode voltmètre continu.
	 * @param dcVolt_v_o pointeur sur la tension mesurée en volts.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant le canal sur lequel effectuer la mesure.
	 * @param range_i range de mesure.
	 * @param integTimePlcOrS_i resolution de la mesure.
	 */
	virtual double getDcVolt() = 0;

	/**
	 * Mesure en mode voltmètre alternatif.
	 * @param acVolt_v_o pointeur sur la tension mesurée en volts.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant le canal sur lequel effectuer la mesure.
	 * @param range_i range de mesure.
	 * @param integTimePlcOrS_i resolution de la mesure.
	 */
	virtual double getAcVolt() = 0;

	/**
	 * Mesure en mode ampèremètre continu.
	 * @param dcAmp_a_o pointeur sur le courant mesuré en ampères.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant le canal sur lequel effectuer la mesure.
	 * @param range_i range de mesure.
	 * @param integTimePlcOrS_i resolution de la mesure.
	 */
	virtual double getDcAmp() = 0;

	/**
	 * Mesure en mode ampèremètre alternatif.
	 * @param acAmp_a_o pointeur sur le courant mesuré en ampères.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant le canal sur lequel effectuer la mesure.
	 * @param range_i range de mesure.
	 * @param integTimePlcOrS_i resolution de la mesure.
	 */
	virtual double getAcAmp() = 0;

	/**
	 * Mesure en mode ohm-mètre.
	 * @param ohm_o pointeur sur la résistance mesurée en ohms.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant le canal sur lequel effectuer la mesure.
	 * @param range_i range de mesure.
	 * @param integTimePlcOrS_i resolution de la mesure.
	 */ virtual double getOhm() = 0;

	/**
	 * Mesure en mode ohm-mètre, en mode 4 fils.
	 * @param ohm_o pointeur sur la résistance mesurée en ohms.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant les canaux sur lesquels effectuer la mesure.
	 * @param range_i range de mesure.
	 * @param integTimePlcOrS_i resolution de la mesure.
	 */ virtual double getOhm_FourWire() = 0;

	/**
	 * Mesure en mode fréquence-mètre.
	 * @param freq_o pointeur sur la fréquence mesurée en Hz.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant les canaux sur lesquels effectuer la mesure.
	 */ virtual double getFreq() = 0;

	/**
	 * Mesure en mode fréquence-mètre pour un monitoring.
	 * @param freq_o pointeur sur la fréquence mesurée en Hz.
	 */ virtual double getFreqMon() = 0;

	/**
	 * Mesure en mode thermocouple K.
	 * @param temp_o pointeur sur la température mesurée en °C.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant les canaux sur lesquels effectuer la mesure.
	 */ virtual double getTemp() = 0;

	/**
	 * Mesure en mode power-mètre.
	 * @param pow_dBm_o pointeur sur la puissance mesurée en dBm.
	 * @param average_i paramètre d'entrée désignant le nombre de mesures entrants dans la moyenne.
	 * @param channel_i paramètre d'entrée désignant les canaux sur lesquels effectuer la mesure.
	 */ virtual double getPower() = 0;

	virtual double setDcVolt(double DcVolt_i);
	virtual double setAcVolt(double AcVolt_i);
	virtual double setDcAmp(double DcAmp_i);
	virtual double setAcAmp(double AcAmp_i);
	virtual double setOhm(double Ohm_i);
	virtual double setOhm_FourWire(double Ohm_i);
	virtual double setFreq(double Freq_i);
	virtual double setFreqMon(double Freq_i);
	virtual double setTemp(double Temp_i);
	virtual double setPower(double Power_dbm_i);

	/**
	 * Permet de desaciver les errorQuery dans le driver
	 * @param doErrorQueryInDriver_i : bool activer / desactiver les errorQuery
	 */ virtual void setDoErrorQueryInDriver(bool doErrorQueryInDriver_i);

	/**
	 *\brief  Reception du Message. Fonction virtualle abstraite.
	 *\param  string message  : Message reçu.
	 *\param  int adr : Adresse du l'instrument.
	 *\param  GPIB_STATUS* status : pointeur Status de l'interface GPIB.
	 */ std::string recvMessage(std::string message, int adr, GPIB_BUSDATA * status);
	/**
	 *\brief  defini un changement de configuration.
	 *\param  double timeout : Time Out de reception.
	 */ void ChangeConfiguration();
	/**
	 *\brief  defini un changement de l'adresse primaire.
	 *\param  double timeout : Time Out de reception.
	 */ void ChangeAdrPrimaire(int Adr);
	/**
	 *\brief  defini un changement de l'adresse secondaire.
	 *\param  double timeout : Time Out de reception.
	 */ void ChangeAdrSecondaire(int Adr);
	/**
	 *\brief  defini le time Out du Reception.
	 *\param  double timeout : Time Out de reception.
	 */ void timeoutRecvData(double timeout = 0);

};

#endif
