// ---------------------------------------------------------------------------

#ifndef SAlimentationsH
#define SAlimentationsH
// ---------------------------------------------------------------------------

#include "virtual_alimentation_C.h"
#include "Shp661xxa_C.h"
#include "GpibInterface.h"
#include "SBenchAdr.h"
#include "ConstanteDefine.h"

/* \enum AlimEnum
 *\brief Liste des instruments d'alimentation possible de simul�s
 */

enum SAlimEnum {
	alDebug, alAuto, alDAC488, alHP661XXA, alHP66XXA, alHP3640A, alN67XX, alDAQmx, alBILT, alBiltBE58x, alClient, alKiPlz
};

/* \typedef T1DStringArray
 *\brief Definition d'un tableau 1D de string.
 */
typedef DynamicArray<AnsiString>T1DStringArray;

/** \file : SAlimentations.c
 *	\class vsim_C  "instruments\Alim\SAlimentations.h"
 *	\version : 1.0
 *   \date : 13/04/2017
 *   \brief definit la classe virtuelle des instruments Alimentation simul�s .
 *	\details
 */

class SAlimentations {
protected:
	virtual_alimentation_C* FDevice; // Objet Appareils virtual_alimentations
	GpibInterface* FGPIB_m; // Objet GpibInterface.
	SAlimEnum FDeviceType;  // Enumerateur des drivers implement�s.
	AnsiString FDeviceStr, // Type de drivers simul� .
	  FCaption, // Alias du driver dans le fichier Baie.adr
	  FAdresseString, // Adresse GPIB Complete Exemple : GPIB0::2::0::INTFC
	  FNameDevice; // Nom de l'appareils de mesure
	SBenchAdrComp* FBenchAdrFile_m; // Objet permettant la lecture et initalisation du materiels de la Baie.

	/**
	 *\brief Active ou Deactive le composant SAlimentation.
	 \param bool AValue : Boolean activation ou non du composant.
	 */
	void SetActive(bool AValue);
	/**
	 *\brief Recherche et Inialisation du type de driver simul�.
	 \param AnsiString AValue : Nom du driver simul� recherch�.
	 */
	void SetDeviceFind(AnsiString AValue);
	/**
	 *\brief Recherche et Initialisation du type de driver simul� en fonction de la Liste des instruments d'alimentation possible de simul�s
	 \param SAlimEnum AValue : Liste des instruments d'alimentation possible de simul�s.
	 */
	void SetDeviceType(SAlimEnum AValue);
	/**
	 *\brief Renseigne le Alias du driver simul�.
	 \param AnsiString AValue : Alias du drievr simul�.
	 */
	void setCaption(AnsiString AValue);
	/**
	 *\brief .Retourne l'Alias du driver simul�.
	 \return AnsiString AValue : Alias du drievr simul�.
	 */
	AnsiString getCaption();
	/**
	 *\brief .Renseigne la chaine complete de l'adresse du driver simul�.
	 \param AnsiString AValue : chaine complete de l'adresse du driver simul�.
	 */
	void setAdresseString(AnsiString AValue);
	/**
	 *\brief .Retourne  la chaine complete de l'adresse du driver simul�.
	 /\return AnsiString AValue : chaine complete de l'adresse du driver simul�.
	 */
	AnsiString getAdresseString();
	/**
	 *\brief Retourne le Nom du Driver simul�.
	 \return AnsiString AValue : le Nom du Driver simul�.
	 */
	AnsiString getNameDevice();
	/**
	 *\brief Renseigne les differents parametres de l'adresse GPIB
	 /\param AnsiString Str_i : chaine complete de l'adresse du driver simul�.
	 */
	T1DStringArray SepareAdressGpib(AnsiString Str_i);

	bool FActive; // Registre d'activation ,deactviation du Composant.

public:

	/**
	 *\brief Constructeur de la classe SAlimentations.
	 */
	SAlimentations();
	   	/**
	 *\brief Destructeur de la classe SAlimentations.
	 */
	~SAlimentations();
	/**
	 *\brief Separation de la chaine de caractere en fonction du separateur souhait�.
	 \param AnsiString Str_i : Chaine de caractere.
	 \param AnsiString Separateur_i : separateur souhait�.
	 \return  T1DStringArray : Tableau de String. Chaque chaine de caractere s�par� est stock� dans un emplacement memoire du tableau.
	 */
	T1DStringArray SepareTab(AnsiString Str_i, AnsiString Separateur_i);
	/**
	 *\brief Lecture de la configuration de l'instrument dans le ficheir de configuration.
	 */
	void ReadBenchAdrFile();

	/**
	 *\brief Description de l'Alimentation .
	 */
	void DescriptSimInstr(virtual_alimentation_C* alim);
	/**
	 *\brief propri�t� Active de la variable FActive.
	 */
	__property bool Active = {read = FActive, write = SetActive};
	/**
	 *\brief propri�t� Caption de la variable FCaption.
	 */
	__property AnsiString Caption = {read = getCaption, write = setCaption};
	/**
	 *\brief propri�t� NameDevice de la variable NameDevice.
	 */
	__property AnsiString NameDevice = {read = FNameDevice, write = SetDeviceFind};
	/**
	/**
	 *\brief propri�t� AdresseString de la variable FAdresseString.
	 */
	__property AnsiString AdresseString = {read = FAdresseString, write = FAdresseString};
	/**
	 *\brief propri�t� Device de la variable FDevice.
	 */
	__property virtual_alimentation_C* Device = {read = FDevice, write = FDevice};
	/**
	 *\brief propri�t� DeviceType de la variable FDeviceType.
	 */
	__property SAlimEnum DeviceType = {read = FDeviceType, write = SetDeviceType};
	/**
	 *\brief propri�t� BenchAdrFile de la variable FBenchAdrFile_m.
	 */
	__property SBenchAdrComp* BenchAdrFile = {read = FBenchAdrFile_m, write = FBenchAdrFile_m};
	/**
	 *\brief propri�t� GPIB de la variable FGPIB_m.
	 */
	__property GpibInterface* GPIB = {read = FGPIB_m, write = FGPIB_m};

};

#endif
