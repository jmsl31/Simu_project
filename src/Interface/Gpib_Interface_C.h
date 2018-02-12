//---------------------------------------------------------------------------

#ifndef Gpib_Interface_CH
#define Gpib_Interface_CH
//---------------------------------------------------------------------------
#include "visa.h"
#include "visa_C.h"
#include <visatype.h>
#include "GpibInterface.h"


//#pragma link "drivers_cpp10.lib"


namespace UtilSimu{            // \namespace Utils

	/** \file : Gpib_Interface_C.c
	*	\class Interface  "bench\Gpib_Interface_C.h"
	*	\version : 1.0
	*   \date : 06/04/2017
	*   \brief Definit la class d'interface materiel Gpib .
	*	\details
	*/
class Gpib_Interface_C : public GpibInterface{

   public:
	/**
	*\details Constructeur de la classe.
	*/
   Gpib_Interface_C();


   protected:


   private :



};

}
#endif
