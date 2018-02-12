
//---------------------------------------------------------------------------

#ifndef virtual_receiver_CH
#define virtual_receiver_CH
//---------------------------------------------------------------------------

#include "virtual_equipment_C.h"
#include <IniFiles.hpp>
#include <time.h>
#include "EqptSubject.h"


/*! \enum equipmentEnum
\brief Enumeration de l'equipement
*/
enum equipmentEnum {RX,DOCON,UPCON,DUAL};

/*! \struct TCompEqpt
\brief Structure de l'equipement
*/
typedef struct {
	/// nb_Tranche : nombre de tranche
	int nb_Tranche;
	///nb_Alim : nombre d'alimentation
	int nb_Alim;
	///nb_Tmtc : nombre de tmtc
	int nb_Tmtc;
}TCompEqpt;

/*! \class virtual_receiver_C
\brief Classe du recepteur virtuel
*/
class virtual_receiver_C : public virtual_equipment_C
{
private :
	///Frequence de l'oscillateur local
	double frequency_Ol_m;
	///Intervalle de frequence de l'oscillateur local
	double interval_Fq_OL;
	///Puissance de l'oscillateur local
	double power_Ol_m;
	///Puissance minimale de l'oscillateur local
	double power_Ol_min_m;
	///Puissance maximale de l'oscillateur local
	double power_Ol_max_m;
	///Gain obtenu
	double gain_m;
	///Puissance d'entree
	double power_in_m;
	///Puissance de sortie
	double power_out_m;
	///FDeviceType : variable de type equipmentEnum
	equipmentEnum FDeviceType;
	///*CompositionEqpt : pointeur de type TCompEqpt
	TCompEqpt *CompositionEqpt;

	///Variable d'activation de l'oscillateur local
	bool FOl_Active;
	///Variable de surcharge de l'oscillateur local
	bool FOL_Overload;
	///Temps de chauffe de l'oscillateur local
	double time_Hot;

	/*! \brief Recupere le temps de chauffe de l'oscillateur local
	*/
	virtual double getTime_Hot();
	/*! \brief Fixe le temps de chauffe de l'oscillateur local
	\param double time : temps
	*/
	virtual void setTime_Hot(double time);
	/*! \brief Recupere la frequence emise par l'oscillateur local
	\return Frequence de l'oscillateur local
	*/
	virtual double getFrequency_Ol();
	/*! \brief  Fixe la frequence de l'oscillateur local
	\param double freqOl_i : frequence souhaitee
	*/
	virtual void setFrequency_Ol(double freqOl_i);
	/*! \brief Recupere la puissance 01
	\return Puissance 01
	*/
	virtual double getPower_Ol();
	/*! \brief Fixe la puisance 01
	\param double powerOl_i : Puissance souhaitee
	*/
	virtual void setPower_Ol(double powerOl_i);
	/*! \brief Recupere la puissance 01 minimale
	\return Puissance 01 minimale
	*/
	virtual double getPower_Ol_min();
	/*! \brief Fixe la puissance 01 minimale
	\param double power01_i : Puissance souhaitee
	*/
	virtual void setPower_Ol_min(double powerOl_i);
	/*! \brief Recupere la puissance 01 maximale
	\return Puissance maximale
	*/
	virtual double getPower_Ol_max();
	/*! \brief Fixe la puissance 01 maximale
	\param double power01_i : puissance souhaitee
	*/
	virtual void setPower_Ol_max(double powerOl_i);
	/*! \brief Recupere le gain obtenu
	\return Gain obtenu
	*/
	virtual double getGain();
	/*! \brief Fixe le gain souhaite
	\param double gain : gain souhaite
	*/
	virtual void setGain(double gain);
	/*! \brief Recupere la puissance entrante
	\return Puissance entrante
	*/
	virtual double getPowerIn();
	/*! \brief Fixe la puissance entrante
	\param double p_in : puissance souhaitee
	*/
	virtual void setPowerIn(double p_in);
	/*! \brief Recupere la puissance en sortie
	\return Puissance en sortie
	*/
	virtual double getPowerOut();
	/*! \brief Attend la frequence 01 à la chauffe
	*/
	virtual void waitHotFrequencyOl();
	/*! \brief Recupere la surcharge 01
	\return Variable booleenne de surcharge
	*/
	virtual bool getOl_overload();
	/*! \brief Fixe la surcharge 01
	\param b : booleen determinant la surcharge
	*/
	virtual void setOl_overload(bool b);

public:


	//Construction & Destructeur.
	/*! \brief Constructeur de la fonction virtual_receiver_C
	*/
	virtual_receiver_C();
	/*! \brief Destructeur de la fonction virtual_receiver_C
	*/
	~virtual_receiver_C();

	/*! \brief Fixe les constantes de l'equipement
	\param int nb_tranche_m : nombre de tranche
	\param int nb_alim_m : nombre d'alim
	\param int nb_tmtc_m
	*/
	virtual void setConsEqpt(int nb_tranche_m,int nb_alim_m,int nb_tmtc_m);

	/*! \brief Recupere les constantes de l'equipement
	\return Variable TCompEqpt
	*/
	virtual TCompEqpt getConsEqpt();

	/*! \brief Propriete DeviceType de la variable FDeviceType en lecture et SetDeviceType en ecriture
	*/
	__property equipmentEnum DeviceType = {read=FDeviceType, write=SetDeviceType};
	/*! \brief Propriete Frequency_OL des fonctions getFrequency_Ol et setFrequency_Ol
	*/
	__property double Frequency_OL = {read=getFrequency_Ol, write=setFrequency_Ol};
	/*! \brief Propriete Interval_Fq_OL de la variable interval_Fq_OL
	*/
	__property double Interval_Fq_OL = {read=interval_Fq_OL, write=interval_Fq_OL};
	/*! \brief Propriete Power_Ol des fonctions getPower_Ol et setPower_Ol
	*/
	__property double Power_Ol = {read=getPower_Ol, write=setPower_Ol};
	/*! \brief Propriete Power_Ol_Min des fonctions getPower_Ol_Min et setPower_Ol_Min
	*/
	__property double Power_Ol_Min = {read=getPower_Ol_min, write=setPower_Ol_min};
	/*! \brief Propriete Power_Ol_Max des fonctions getPower_Ol_Max et setPower_Ol_Max
	*/
	__property double Power_Ol_Max = {read=getPower_Ol_max, write=setPower_Ol_max};
	/*! \brief Propriete Gain des fonctions getGain et setGain
	*/
	__property double Gain = {read=getGain, write=setGain};
	/*! \brief Propriete PowerIn des fonctions getPowerIn et setPowerIn
	*/
	__property double PowerIn = {read=getPowerIn,write=setPowerIn};
	/*! \brief Propriete PowerOut de la fonction getPowerOut en lecture
	*/
	__property double PowerOut = {read=getPowerOut};
	/*! \brief Propriete OlActive des fonctions FOl_Active et FOl_Active
	*/
	__property bool OlActive = {read=FOl_Active, write=FOl_Active};
	/*! \brief Propriete OlOverload des fonctions getOl_overload et setOl_overload
	*/
	__property bool OlOverload = {read=getOl_overload, write=setOl_overload};
	/*! \brief Propriete TimeHot des fonctions getTime_Hot et setTime_Hot
	*/
	__property double TimeHot = {read=getTime_Hot,write=setTime_Hot};
	/*! \brief Fixe le type d'equipement utilise
	\param equipmentEnum AValue : variable de type AValue
	*/
	virtual void SetDeviceType(equipmentEnum AValue);

protected:

};
#endif
