// ---------------------------------------------------------------------------

#ifndef Rx_CH
#define Rx_CH
// ---------------------------------------------------------------------------

#include <IniFiles.hpp>
#include "virtual_receiver_C.h"
#include <vector>
#include "ConstanteDefine.h"
#include "InstObserver.h"
#include "InstSubject.h"

#define num_tranche 0

using namespace Utils;
/* ! \struct Alimentation
 \brief Structure de definition de l'alimentation
 */
typedef struct {
	///voltage_m : voltage desire
	double voltage_m;
	///voltage_actif_m : voltage actif
	double voltage_actif_m;
	///current_m : courant desire
	double current_m;
	///current_actif_m : courant actif
	double current_actif_m;
	///voltageMax_m : Tension Max autorisée
	double voltageMax_m;
	///voltageMin_m : Tension Min autorisée
	double courantMin_m;
	///voltageMin_m : Tension Min autorisée
	double courantMax_m;
	///voltageMin_m : Tension Min autorisée
	double puissance_m;
	///puissanceMax_m : puissance Maximal autorisée
	double puissanceMax_m;

} Alimentation;
/* ! \struct Frequency
 \brief Structure de definition des frequences
 */
typedef struct {
	///Frequence de depart entrante
	double frequency_Start_In,
	///Frequence de fin entrante
	frequency_Stop_In,
	///Bande passante
	bandwidth,
	///Etape
	step,
	///Frequence minimum
	frequency_Min,
	///Frequence maximum
	frequency_Max,
	///Frequence oscillateur local
	frequency_Ol,
	///Frequence oscillateur local
	frequencyOlMax,
	///Frequence oscillateur local
	frequencyOlMin,
	///Puissance oscillateur local
	power_Ol,
	///Puissance oscillateur local
	powerOlMax,
	///Puissance oscillateur local
	powerOlMin,
	///Puissance minimum
	power_min,
	///Puissance maximum
	power_max,
	///Puissance entrante
	power_in,
	///Puissance de sortie
	power_out,
	///Gain obtenu
	gain;
} Frequency;

/* ! \struct Equipement_RX
 \brief Structure de definition de l'equipement RX
 */
typedef struct {
	///Structure de l'objet de type TCompEqpt
	TCompEqpt eqpt;
	///Type d'alimentation
	Alimentation alimentation;
	///Type de frequence
	Frequency frequence;
} Equipement_RX;

/* ! \class Rx_C
 \brief Classe publique du recepteur virtuel.
 */
class Rx_C : public virtual_receiver_C, public InstObserver, public EqptSubject
{

private:

	/* ! \brief *file : pointeur de type TIniFile
	 */
	TIniFile *file;

protected:

public:

	Rx_C();

	/** ! \brief Recupere le nombre de tranche
	 \return Nombre de tranche
	 */
	double getNb_Tranche();
	/* ! \brief Recupere le nombre d'alimentation
	 \return Nombre d'alimentations
	 */
	double getNb_Alim();
	/* ! \brief Recupere le nombre de tmtc
	 \return Nombre de tmtc
	 */
	double getNb_Tmtc();
	/* ! \brief Initialise l'equipement
	 \param *file : pointeur de type TIniFile
	 */
	/* ! \brief Recupere la frequence de depart en sortie de l'appareil
	 \param int Num_Tranche : numero de la tranche
	 \return Frequence de la tranche
	 */
	double getFrequency_Start_Out(int Num_Tranche);
	/* ! \brief Fixe la frequence de depart en sortie de l'appareil
	 \param int Num_Tranche : numero de la tranche
	 \param double fq_out_start_i : valeur de la fréquence de depart
	 */
	void setFrequency_Start_Out(int Num_Tranche, double fq_out_start_i);
	/* ! \brief Recupere la frequence de fin en sorite de l'appareil
	 \param int Num_Tranche : numero de tranche
	 \return Frequence de la tranche
	 */
	double getFrequency_Stop_Out(int Num_Tranche);
	/* ! \brief Fixe la fréquence de fin en sortie de l'appareil
	 \param int Num_Tranche : numero de la tranche
	 \param double fq_out_stop_i : valeur de la frequence de fin
	 */
	void setFrequency_Stop_Out(int Num_Tranche, double fq_out_stop_i);
	/* ! \brief Recupere la puissance de sortie de l'appareil
	 \param int Num_Tranche : numero de la tranche
	 \param double Pin : puissance en entrée de l'appareil
	 \return Puissance de l'appareil
	 */
	double getPout(int Num_Tranche, double Pin);

	/* ! \brief Transmets les valeurs des variables au objet Client(Observer)
	 \param double Voltage : Tension de l'equipement
	 \param double Current : Courant de l'equipement
	 \param bool overvoltage : Flag de l'overvoltage
	 \param bool overcurrent : Flag de l'overcurrent
	 \param bool active_power : Flag de l'activation de la puissance RF
	 \param bool active_alim : Flag de l'activation de la puissance d'alimentation
	 \param double power : puissance de l'equipement
	 */
	void ReturnValue(double Voltage, double Current, bool overvoltage,
		bool overcurrent, bool active_power, bool active_alim, double power);

	void setActive();
	/* ! \brief Methode permettant la configuration de l'equipement virtual partir d'un fichier INI
	 */
	void InitEqpt(TIniFile *file);
	/**
	 *\details Methode de communication de l'observer descendant permettant la propagation de l'inforamtion entre les objets.
	 *\param std::string value : parametres a transmettre.
	 *\param TYPE_PARAM type : Type de parametres transmis
	 */
	virtual void ChangeValueDown(std::string value, TYPE_PARAM type);
	virtual void ChangeValueDown(int value, TYPE_PARAM type);
	virtual void ChangeValueDown(double value, TYPE_PARAM type);
	virtual void ChangeValueDown(bool value, TYPE_PARAM type);

};

#endif
