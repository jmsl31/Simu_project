// ---------------------------------------------------------------------------

#ifndef SBenchAdrH
#define SBenchAdrH
#include <Classes.hpp>
#include <stdio.h>
#include <io.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

// ---------------------------------------------------------------------------
/* ! \struct SAdrsStruct
 \brief Structure des adresses
 */
typedef struct {
	///Chaine de caracteres contenant : Nom de l'instrument
	AnsiString DeviceName,
	///Chaine de caracteres contenant : Adresse de l'instrument
	Address,
	///Chaine de caracteres contenant : Librairie utilisee
	Library,
	///Chaine de caracteres contenant : Type d'instrument
	DeviceType,
	///Chaine de caracteres contenant : Description de l'instrument
	FDescription,
	///Chaine de caracteres contenant : Commentaire(s)
	Comment;
	///Variable de type int : utilisation des instruments
	int InUse;
} SAdrsStruct;

/* ! \brief Definition tableau 1D de la structure des adresses d'instruments
 */
typedef DynamicArray<SAdrsStruct>SAdrsArray;
/* ! \brief Definition tableau 1 dimension de string
 */
typedef DynamicArray<AnsiString>T1DStringArray;

/* ! \class SBenchAdrs
 \brief Classe des adresses de bancs
 */
class SBenchAdrs {
private:
	///Nom de la section
	AnsiString FSection,

	///Nom du fichier
	FFileName;

public:
	///Chaine de caracteres contenant : Titre
	AnsiString Title;
	///Chaine de caracteres contenant : Tableau d'adresse
	SAdrsArray AdrArray;

	/* ! \brief Recherche l'appareil dans la structure
	 \param AnsiString DeviceName :nom de l'appareil
	 \return SAdrsStruct* : pointeur de SAdrsStruct
	 */
	SAdrsStruct* GetDevice(AnsiString DeviceName);
	/* ! \brief Return la liste des appareils du Banc

	 \return T1DStringArray : Liste des appareils
	 */
	T1DStringArray GetDeviceAll();
	/* ! \brief Constructeur de la classe
	 \param AnsiString AFileName : nom du fichier
	 \param AnsiString ASection : nom de la section
	 */
	SBenchAdrs(AnsiString AFileName, AnsiString ASection = "");
	/* ! \brief Fonction de sauvegarde
	 */
	void Save(void);
	/* ! \brief Cree un tableau de caractere separes par un separateur
	 \param AnsiString Str_i : chaine de caractere
	 \param AnsiString Separateur_i : separateur souhaite
	 */
	T1DStringArray SepareTab(AnsiString Str_i, AnsiString Separateur_i);
};

/* ! \class SBenchAdrComp
 \brief Classe des complements d'adresse des bancs
 */
class SBenchAdrComp {
private:
	///Chaine de caracteres contenant : Section
	AnsiString FSection;
	///Pointeur de type SBenchAdrs
	SBenchAdrs* SBenchAdrFile;

protected:
	///Variable de type bool caracterisant l'etat
	bool FActive;
	///Chaine de caracteres contenant : nom du fichier
	AnsiString FFileName;
	///Chaine de caracteres contenant : legende
	AnsiString FCaption;

	/* ! \brief Fixe l'activation de l'instrument
	 \param bool AValue : etat de l'equipement
	 */
	virtual void __fastcall SetActive(bool AValue);
	/* ! \brief Fixe le nom du fichier
	 \param AnsiString AValue : nom du fichier souhaite
	 */
	virtual void __fastcall SetFileName(AnsiString AValue);
	/* ! \brief Fixe la section de l'instrument
	 \param AnsiString AValue : nom de la section souhaite
	 */
	virtual void __fastcall SetSection(AnsiString AValue);

public:
	///Constructeur de la classe
	SBenchAdrComp();
	///Destructeur de la classe
	~SBenchAdrComp();

	/* ! \brief Methode qui permet de chercher dans le fichier baie.adr la liste des Devices associes a un type
	 \details (par exemple : tmAlis, tmDebug, etc...)
	 */
	T1DStringArray searchDevice(AnsiString Section, AnsiString searchValue, bool *valueFind);
	/* !
	 \brief Propriete BenchAdrFile identifiant  SBenchAdrFile.
	 */
	__property SBenchAdrs* BenchAdrFile = {read = SBenchAdrFile};
	/* ! \brief Propriete Active identifiant l'activation de l'equipement
	 */
	__property bool Active = {read = FActive, write = SetActive /* , default=false */ };
	/* !
	 \brief Propriete FileName identifiant le fichier.
	 */
	__property AnsiString FileName = {read = FFileName, write = SetFileName};
	/* !
	 \brief Propriete Section identifiant la rubrique du fichier.
	 */
	__property AnsiString Section = {read = FSection, write = SetSection};
};
#endif
