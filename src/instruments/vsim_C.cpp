// ---------------------------------------------------------------------------
#include "errorInfo.h"
#include "math.h"
#include <stdio.h>
#include <io.h>
#include <StrUtils.hpp>
#include <IniFiles.hpp>
#include "vsim_C.h"


#ifndef linux
#pragma hdrstop
#endif


// ---------------------------------------------------------------------------

#ifndef linux
#pragma package(smart_init)
#endif

		/* ==================Constructeur=============================================== */
		vsim_C::vsim_C() {

			Description_m = new vdescription_C();

		}
		void vsim_C::setDescription(vdescription_C* Description){
			  Description_m = Description;
		};

		vdescription_C* vsim_C::getDescription(){
			return (Description_m);
		};

		void vsim_C::setAdr(AnsiString Adr){
			Adr_m =Adr;
		};

		AnsiString vsim_C::getAdr(){
			return(Adr_m);
		};

		void vsim_C::setAdrPrimaire(int adr){
			AdrPrimaire_m = adr;
		};

		int vsim_C::getAdrPrimaire(){

			return(AdrPrimaire_m);
		};

		void vsim_C::setAdrSecondaire(int Adr){
			AdrSecondaire_m = Adr;
		};

		int vsim_C::getAdrSecondaire(){
			return(AdrSecondaire_m);
		};

		void vsim_C::setName_Device(AnsiString Name){
			Name_Device_m = Name;
		};

		AnsiString vsim_C::getName_Device(){
			return (Name_Device_m);
		};

		void vsim_C::setTimeout(double time){
			Timeout_m = time;
		};

		double vsim_C::getTimeout(){
			return(Timeout_m);
		};

		void vsim_C::setCaption(AnsiString Caption){
			Caption_m = Caption;
		};

		AnsiString vsim_C::getCaption(){
			return(Caption_m);
		};

		std::string vsim_C::RecupDataSCPI(std::string mes){

			string rep = mes.substr(mes.find(" ")+1,mes.size());;
			rep.resize(rep.size()-1);

			return(rep);
		};


