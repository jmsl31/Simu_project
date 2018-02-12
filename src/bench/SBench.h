// ---------------------------------------------------------------------------

#ifndef SBenchH
#define SBenchH
// ---------------------------------------------------------------------------

#include <string>
#include <IniFiles.hpp>
#include "InstObserver.h"
#include "InstSubject.h"
#include "EqptSubject.h"
#include "SBenchAdr.h"
#include "CalUnit.h"
#include "MathUnit.h"
#include "ConstanteDefine.h"

#pragma link "drivers_cpp10.lib"

/** \file : Bench_C.c
 *	\class Bench_C  "bench\Bench_C.h"
 *	\version : 1.0
 *   \date : 06/04/2017
 *   \brief Definit la class d'interface Bench .
 *	\details
 */
using namespace Utils;

class SBench_C : public InstObserver, public InstSubject, public EqptObserver, public EqptSubject {
private:

	// Attribut.

	AnsiString name_m; // Nom du Banc

	AnsiString pcImmo_m; // Numero Immo du Pc de Simualtion
	TCal* Cal_in; // Objet Calibration d'entrée.
	AnsiString Chemin_CalIn; // Numero Immo du Pc de Simualtion
	TCal* Cal_out; // Objet Calibration de sortie.
	AnsiString Chemin_CalOut; // Numero Immo du Pc de Simualtion
	TCal* Cal_Spectrum; // Objet Calibration de Spectrum.
	AnsiString Chemin_CalSpectrum; // Numero Immo du Pc de Simualtion

	double resistance_cable; // Valeur de la resistivité du harnais de test.
	double Detroppage_resistance; // Valeur de la resistance de detrompage du Harnais.
	double voltage_drop; // valeur de la chute de tension du harnais.
	double cable_longuer; // longueur du harnais en metre.

	double voltage_active_m; // Valeur de la tension active sur le banc.
	double voltage_return_m, current_return_m;
	double active_Current_m; // Valeur du courrant actif sur le banc.
	double active_Power_m; // Valeur du courrant actif sur le banc.
	bool active_m, FOverVoltage, FOverCurrent, alim_Active_m; // Flag de Mise sou Tension du Banc.

	SBenchAdrComp* BenchSimu_m;

	void SetActive(bool value);
	void BenchInit(AnsiString Name_i);

protected:

public:
	/* ! \brief Constructeur de la classe.
	 */
	SBench_C();
	/* ! \brief Destructeur de la classe.
	 */
	~SBench_C();

	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property AnsiString Name = {read = name_m, write = name_m};
	// Propriété de la \a Classe Bench_C
	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property AnsiString pcImmo = {read = pcImmo_m, write = pcImmo_m};
	// Propriété de la \a Classe Bench_C
	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property AnsiString CheminCalIn = {read = Chemin_CalIn, write = Chemin_CalIn};
	// Propriété de la \a Classe Bench_C
	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property AnsiString CheminCalOut = {read = Chemin_CalOut, write = Chemin_CalOut};
	// Propriété de la \a Classe Bench_C
	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property AnsiString CheminCalSpectrum = {read = Chemin_CalSpectrum, write = Chemin_CalSpectrum};

	// Propriété de la \a Classe Bench_C
	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property double Active_Voltage = {read = voltage_active_m, write = voltage_active_m};
	// Propriété de la \a Classe Bench_C
	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property double Return_Voltage = {read = voltage_return_m, write = voltage_return_m};

	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property double Active_Current = {read = active_Current_m, write = active_Current_m};
	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property double Return_Current = {read = current_return_m, write = current_return_m};

	/* ! \brief Propriete Active_Voltage des fonctions active_Voltage_m.
	 */
	__property double Active_Power = {read = active_Power_m, write = active_Power_m};

	/* ! \brief Propriete Active des fonctions active_m.
	 */
	__property bool Active = {read = active_m, write = SetActive};
	/* ! \brief Propriete Active des fonctions active_m.
	 */
	__property bool Alim_Active = {read = alim_Active_m, write = alim_Active_m};

	/* ! \brief Propriete OverVoltage des fonctions FOverVoltage.
	 */
	__property bool OverVoltage = {read = FOverVoltage, write = FOverVoltage};
	/* ! \brief Propriete OverVoltage des fonctions FOverVoltage.
	 */
	__property bool OverCurrent = {read = FOverCurrent, write = FOverCurrent};

	/* ! \brief Propriete Active des fonctions active_m.
	 */
	__property SBenchAdrComp* BenchSimu = {read = BenchSimu_m, write = BenchSimu_m};

	/**
	 *\details Recupere l'objet de BenchAdrSimu.
	 *\return TBenchAdrComp : Objet regroupant l'ensemble des appareils de mesures du Bench de simulation.
	 */

	SBenchAdrComp* getBenchAdrSimu();
	/**
	 *\details Initialise l'objet de BenchAdrSimu.
	 *\param TBenchAdrComp : Objet regroupant l'ensemble des appareils de mesures du Bench de simulation.
	 */
	void SetBenchAdrSimu(SBenchAdrComp* AppSimu);

	/**
	 *\details Recupere le Numero Immo du Pc.
	 *\return AnsiString : le numero d'immo.
	 */

	AnsiString getPcImmo();

	/**
	 *\details Initialise le numero d'Immo du pc.
	 *\param AnsiString : le numero d'immo.
	 */

	void setPcImmo(AnsiString immo);

	/**
	 *\details Recupere Les calibrations d'entrées simulées du Banc de Simulation
	 *\return TCal : Objet regroupant Les calibrations d'entrées simulées du Banc de Simulation
	 */

	TCal getCalIn();
	/**
	 *\details Initialise Les calibrations d'entrées simulées du Banc de Simulation.
	 *\param TCal Cal_in : Objet regroupant les calibrations d'entrées simulées du Banc de Simulation
	 */

	void setCalIn(TCal Cal);
	/**
	 *\details Recupere Les calibrations de sorties simulées du Banc de Simulation
	 *\return TCal : Objet regroupant Les calibrations de sorties simulées du Banc de Simulation
	 */

	TCal getCalOut();
	/**
	 *\details Initialise Les calibrations de sorties simulées du Banc de Simulation.
	 *\param TCal Cal_out : Objet regroupant les calibrations de sorties simulées du Banc de Simulation
	 */

	void setCalOut(TCal Cal);
	/**
	 *\details Recupere Les calibrations de spectrum simulées du Banc de Simulation
	 *\return TCal : Objet regroupant Les calibrations de Spectrum simulées du Banc de Simulation
	 */

	TCal getCalSpectrum();
	/**
	 *\details Initialise Les calibrations de Spectrum simulées du Banc de Simulation.
	 *\param TCal Cal_Spectrum : Objet regroupant les calibrations de Spectrum simulées du Banc de Simulation
	 */

	void setCalSpectrum(TCal Cal);
	/**
	 *\details Methode de communication de l'observer descendant permettant la propagation de l'inforamtion entre les objets.
	 *\param std::string value : parametres a transmettre.
	 *\param TYPE_PARAM type : Type de parametres transmis
	 */
	virtual void ChangeValueDown(std::string value, TYPE_PARAM type);
	virtual void ChangeValueDown(int value, TYPE_PARAM type);
	virtual void ChangeValueDown(double value, TYPE_PARAM type);
	virtual void ChangeValueDown(bool value, TYPE_PARAM type);

	/**
	 *\details Methode de communication de l'observer montant permettant la propagation de l'inforamtion entre les objets.
	 *\param std::string value : parametres a transmettre.
	 *\param TYPE_PARAM type : Type de parametres transmis
	 */
	virtual void ChangeValueRising(std::string value, TYPE_PARAM type);
	virtual void ChangeValueRising(int value, TYPE_PARAM type);
	virtual void ChangeValueRising(double value, TYPE_PARAM type);
	virtual void ChangeValueRising(bool value, TYPE_PARAM type);

};

#endif
