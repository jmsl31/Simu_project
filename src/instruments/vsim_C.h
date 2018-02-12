// ---------------------------------------------------------------------------

#ifndef vsim_CH
#define vsim_CH
// ---------------------------------------------------------------------------


#include "TBenchAdr.h"
#include "GpibObserver.h"
#include "vdescription_C.h"
#include <vector>
#include <IniFiles.hpp>

#pragma link "drivers_cpp10.lib"

// Valeur par defaut du masque de l'ESR
// Bits actifs : query error, device dependant error, execution error, command error
#define VINST_DEFAULT_ESR_MASK			0x3C

using namespace Utils;

/*!  \brief Tableau dynamique ansistring a 1D
*/
typedef DynamicArray < AnsiString > T1DStringArray;

	/*!
	\class vsim_C
	\version : 1.0
	\date : 29/03/2017
	\brief Definit la classe virtuelle des instruments simules.
	*/
class vsim_C{

private:
   ///Pointeur vdescription_C
   vdescription_C* Description_m;


   /// Adresse de l'instrument dans le fichier.
   AnsiString Adr_m;
   /// Adresse Primaire de l'instrument.
   int AdrPrimaire_m;
   /// Adresse Secondaire de l'instrument.
   int AdrSecondaire_m;
   /// Nom du drivers de l'instrument.
   AnsiString Name_Device_m;
   /// Timeout de fin de reception.
   double Timeout_m;
   /// Verification de l'utilisation de l'appareils.
   bool FVerfiyUse_m;
   /// Alias Instrument
   AnsiString Caption_m;
   /// Etat de l'instrument.
   bool FLockStateDevice ;



	/**
	*\brief Initialiser de la variable Adr_m. Represente l'adresse complet de l'instrument
	*\param AnsiString Adr : variable de type AnsiString.
	*/
   void setAdr(AnsiString Adr);
	/**
	*\brief Recuperer la variable Adr_m.
	*\return AnsiString Adr : variable de type AnsiString.
	*/
   AnsiString getAdr();
	/**
	*\brief Initialiser de la variable Adr_Primaire_m.
	*\param int Adr : variable de type entier
	*/
   void setAdrPrimaire(int adr);
   /**
	*\brief Recuperer la variable Adr_Primaire_m.
	*\return int Adr_Primaire_m : variable de type int.
	*/
	int getAdrPrimaire();
   /**
	*\brief Initialiser de la variable Adr_Secondaire_m.
	*\param int Adr : variable de type int.
	*/
   void setAdrSecondaire(int Adr);
	/**
	*\brief Recuperer la variable Adr_Secondaire_m.
	*\return int Adr_Secondaire_m : variable de type int.
	*/
	int getAdrSecondaire();
	/**
	*\brief Initialiser de la variable Name_Device_m.Represente l'Alias de l'instrument.
	*\param AnsiString Name : variable de type AnsiString.
	*/
	  void setName_Device(AnsiString Name);
   /**
	*\brief Recuperer la variable Name_Device_m.
	*\return AnsiString Name_Device_m : variable de type AnsiString.
	*/
	AnsiString getName_Device();

	 /**
	*\brief Initialiser de la variable timeOut_m.
	*\param double time: variable de type double.
	*/
   void setTimeout(double time);
   /**
	*\brief Recuperer la variable timeOut_m.
	*\return double timeOut: variable de type double.
	*/
	double getTimeout();
   /**
	*\brief Initialiser de la variable caption_m.
	*\param AnsiString Caption: variable de type AnsiString.
	*/
   void setCaption(AnsiString Caption);
   /**
	*\brief Recuperer la variable caption_m.
	*\return AnsiString Caption_m: variable de type AnsiString.
	*/
   AnsiString getCaption();


protected:


public:
  /*!   \brief Contructeur de la classe.
  */
  vsim_C();

	/**
	*\brief Initialiser de la variable Description_m.
	*\details Represente la description de l'instrument.
	*\param vdescription_C Description : variable de type vdescription_C.
	*/
   void setDescription(vdescription_C* Description);
     /**
	*\brief Recuperer la variable Description_m.
	*\return vdescription_C : variable de type vdescription_C.
	*/
   vdescription_C* getDescription();

    /**
	*\brief Recupere la valeur passee dans la commande scpi.
	*\return std::string : la valeur en chaine de caractere.
	*/
	std::string RecupDataSCPI(std::string mes);

	/**
	*\brief propriete VerifyInUse de la variable FVerfiyUse_m.
	*/
  __property bool VerifyInUse = {read = FVerfiyUse_m, write = FVerfiyUse_m};
  /**
	*\brief propriete LockStateDevice de la variable FLockStateDevice.
	*/
  __property bool LockStateDevice = {read = FLockStateDevice, write = FLockStateDevice};
  /**
	*\brief propriete LockStateDevice de la variable FLockStateDevice.
	*/
  __property AnsiString NameDevice = {read = getName_Device, write = setName_Device};
  /**
	*\brief propriete AdresseString de la variable Adr_m.
	*/
  __property AnsiString AdresseString = {read = getAdr, write = setAdr};
  /**
	*\brief propriete AdrPrimaire de la variable AdrPrimaire_m.
	*/
  __property int AdrPrimaire = {read = getAdrPrimaire, write = setAdrPrimaire};
  /**
	*\brief propriete AdrSecondaire de la variable AdrSecondaire_m.
	*/
  __property int AdrSecondaire = {read = getAdrSecondaire, write = setAdrSecondaire};

  /**
	*\brief propriete AdrSecondaire de la varible AdrSecondaire_m.
	*/
  __property double Timeout = {read = getTimeout, write = setTimeout};
  /**
	*\brief propriete AdrSecondaire de la varible AdrSecondaire_m.
	*/
  __property AnsiString Caption = {read = getCaption, write = setCaption};


};


#endif
