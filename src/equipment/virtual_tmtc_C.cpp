//---------------------------------------------------------------------------

#pragma hdrstop

#include "virtual_tmtc_C.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//*******************************************************************************************************************
//							Implementation VTmtc_C
//*******************************************************************************************************************

virtual_tmtc_C::virtual_tmtc_C(){

	Tm_ON_OFF =false;
	Tm_Status = false;
};
virtual_tmtc_C::~virtual_tmtc_C(){};

void virtual_tmtc_C::setTm_Status(bool status){
	 tm_Status_m = status ;
};

bool virtual_tmtc_C::getTm_Status(){
	return(tm_Status_m);
};

void virtual_tmtc_C::setTm_ON_OFF(bool status){
	tm_ON_OFF_m = status;
};

bool virtual_tmtc_C::getTm_ON_OFF (){
	return(tm_ON_OFF_m);
};
