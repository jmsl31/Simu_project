//---------------------------------------------------------------------------

#pragma hdrstop

#include <StrUtils.hpp>
#include "vdescription_C.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


namespace Utils{

	vdescription_C::vdescription_C(){};

	vdescription_C::vdescription_C(AnsiString name, AnsiString ref,AnsiString option){

		setName(name);
		setReference(ref);
		setnameOption(option);
	};

	void vdescription_C::setName( AnsiString name){
		name_m = name;
	};

	AnsiString vdescription_C::getName(){
			return(name_m);
	};

	void vdescription_C::setReference( AnsiString reference){
			reference_m = reference;
	};

	AnsiString vdescription_C::getReference(){
			return(reference_m);
	};

	void vdescription_C::setnameOption(AnsiString nameOption){
		 nameOption_m = nameOption;
	};

	AnsiString vdescription_C::getnameOption(){
		return(nameOption_m);
	};



	void vdescription_C::addOption(AnsiString name,AnsiString version){

	vOption_C* opt = new vOption_C(name,version);

	option_m.push_back(opt);

	};
}
