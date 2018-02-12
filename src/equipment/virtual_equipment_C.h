

//---------------------------------------------------------------------------
#ifndef virtual_equipment_CH
#define virtual_equipment_CH
//---------------------------------------------------------------------------

#include <vector>
#include <IniFiles.hpp>
#include "virtual_RF_C.h"
#include "virtual_alim_C.h"
#include "virtual_tmtc_C.h"

/*! \class virtual_equipment_C
\brief Permet la representation objet d'un equipement
\author : JOHANN MEISSL
\date : 10/02/2017
\details 	Elle est composee
			d'un vecteur de Classe \a vtranche_C
			d'un vecteur de Classe \a valim_C
			d'un vecteur de Classe \a vtmtc_C
\version : 1.0.0
*/
class virtual_equipment_C {

private:
	// Parametre Privée de la \a Classe vequipment_C
	///Nom de l'equipement
	std::string	name_m;
	///Type d'equipement
	std::string Type_m;
	///Temperature equipement
	double temperature_m;
	///Variable d'activation
	bool FActive,
	///Verifie si l'equipement est active
	FVerifyInUse,
	///Variable de blocage
	FLock;

	// Méthode Privée de la \a Classe vequipment_C

	/*! \brief Recupere la tranche de l'equipement
	\return Vecteur de la tranche
	*/
	virtual std::vector<virtual_RF_C> getTranche();

	/*! \brief Recupere l'alimentation de l'equipement
	\return Vecteur de l'alimentation
	*/
	virtual std::vector<virtual_alim_C> getAlim();

	/*! \brief Recupere le tmtc de l'equipement
	\return Vecteur du tmtc
	*/
	virtual std::vector<virtual_tmtc_C> getTmtc();

	/*! \brief Recupere la temperature de l'equipement
	\return Temperature equipement
	*/
	virtual double getTemperature();
	/*! \brief Fixe la temperature de l'equipement
	\param double temp_i : temperature
	*/
	virtual void setTemperature(double temp_i);
	/*! \brief Recupere le nom de l'equipement
	\return Nom de l'equipement
	*/
	virtual std::string getName();
	/*! \brief Fixe le nom de l'equipement
	\param std::string name_i : nom de l'equipement
	*/
	virtual void setName(std::string name_i);
	/*! \brief Recupere le type d'equipement
	\return Le type d'equipement
	*/
	virtual std::string getType();
	/*! \brief Fixe le type d'equipement
	\param std::string type_i : type d'equipement
	*/
	virtual void setType(std::string type_i);

	/*! \brief Determine l'activation de l'alimentation de l'equipement
	\param bool AValue : active ou non
	*/
	virtual void SetActiveAlim(bool AValue, int Alim_actif);

	/*! \brief Determine si l'equipement est active
	\return Booleen active ou non
	*/
	virtual bool GetActive();
	/*! \brief Bloque l'equipement
	*/
	virtual void LockDevice();
	/*! \brief Debloque l'equipement
	*/
	virtual void UnlockDevice();
	/*! \brief Realise le checkup de l'equipement
	\param TObject *Sender : envoyeur
	\param virtual_equipment_C *eqpt : equipement
	*/
	virtual void check_Eqpt(TObject *Sender,virtual_equipment_C *eqpt);

public:

	//Construceur & Destructeur
	/*! \brief Constructeur de la fonction virtual_equipment_C
	*/
	 virtual_equipment_C();
	 /*! \brief Destructeur de la fonction virtual_equipment_C
	 */
	~virtual_equipment_C();
     ///Pointeur de type std::vector<virtual_RF_C>
	std::vector<virtual_RF_C> 		tranche_m;
	///Pointeur de type std::vector<virtual_alim_C>
	std::vector<virtual_alim_C> 		alim_m;
	///Pointeur de type std::vector<virtual_tmtc_C>
	std::vector<virtual_tmtc_C>     	tmtc_m;

	//Methode
	/*! \brief Fixe la tranche
	\param double fq_start_i : frequence de depart
	\param double fq_stop_i : frequence de fin
	\param double bandwidth_i : bande passante
	\param double step_i : etape
	\param double power_i : puissance
	\param double power_min : puissance minimum
	\param double power_max : puissance maximum
	\param double frequency_min : frequence minimum
	\param double frequency_max : frequence maximum
	*/
	virtual void setTranche(double fq_start_i,double fq_stop_i,double bandwidth_i,double step_i,double power_i,
								double power_min,double power_max,double frequency_min,double frequency_max,double gain_i);
	/*! \brief Fixe l'alimentation
	\param double voltage_i : voltage de l'alimentation
	\param double current_i : courant de l'alimentation
	\param double protVoltage_i : voltage de protection
	\param double protcurrent_i : courant de protection
	*/
	virtual void setAlim(double voltage_i, double current_i, double protVoltage_i, double protcurrent_i,
	double tension_max_i,double courant_min_m,double courant_max_i,double puissance_i,double puissance_max_i);
	/*! \brief Fixe le tmtc de l'equipement
	\param bool tm_status : status du tmtc
	\param bool tm_On_Off : etat du tmtc
	*/
	virtual void setTmtc(bool tm_status,bool tm_On_Off);

	// Propriété de la \a Classe vequipment_C
	/*! \brief Propriete Temperature des fonctions getTemperature et setTemperature
	*/
	__property double Temperature = {read = getTemperature, write = setTemperature};
	/*! \brief Propriete Name de l'objet virtual_equipment_C
	*/
	__property std::string Name = {read = getName, write = setName};
	/*! \brief Propriete Type de l'objet virtual_equipment_C
	*/
	__property std::string Type = {read = getType, write = setType};
	/*! \brief Propriete TrancheRF de l'objet virtual_equipment_C
	*/
	/*! \brief Propriete Active de l'objet virtual_equipment_C
	*/
	__property bool Active = {read = GetActive, write = FActive};
	/*! \brief Propriete VerifyInUse de l'objet virtual_equipment_C
	*/
	__property bool VerifyInUse = {read = FVerifyInUse, write = FVerifyInUse};
	/*! \brief Propriete Lock de l'objet virtual_equipment_C
	*/
	__property bool Lock = {read = FLock, write = FLock};

};
#endif
