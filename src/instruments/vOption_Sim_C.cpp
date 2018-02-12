//---------------------------------------------------------------------------

#pragma hdrstop

#include "vOption_Sim_C.h"
#include <StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)


namespace Utils{
	vOption_C::vOption_C()
	{
		name_m ="";
		version_m="";
	};

	vOption_C::vOption_C(AnsiString name,AnsiString version)
	{
		name_m =name;
		version_m=version;
	};
	AnsiString vOption_C::getName(){
			return(name_m);
	};

	void vOption_C::setName(AnsiString name){
			name_m = name;
	};

	AnsiString vOption_C::getVersion(){
			return(version_m);
	};

	void vOption_C::setVersion(AnsiString version){
			version_m = version;
	};

}