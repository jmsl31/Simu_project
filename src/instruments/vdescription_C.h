//---------------------------------------------------------------------------

#ifndef vdescription_CH
#define vdescription_CH
//---------------------------------------------------------------------------
#endif

#include "vOption_Sim_C.h"
#include <stdio.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

/**
 * Classe de la description de l'appareil de mesure.
 */
using namespace std;

namespace Utils{
/*! \class vdescription_C
\brief Classe de la description de l'appareil de mesure.
*/
class vdescription_C
{
private:
	///Chaine de caractere indiquant le nom
	AnsiString name_m;
	///Chaine de caractere indiquant la reference
	AnsiString reference_m;
	///Chaine de caractere indiquant le nom de l'option
	AnsiString nameOption_m;
	///Pointeur de type std::vector<vOption_C>
	std::vector<vOption_C*> option_m;

public:
	///Constructeur de la classe vdescription_C
	vdescription_C();
	/*! \brief Constructeur surcharge de la classe vdescription_C
	\param AnsiString name : chaine de caractere indiquant le nom
	\param AnsiString ref : chaine de caractere indiquant la reference
	\param AnsiString option : chaine de caractere indiquant l'option
	*/
	vdescription_C(AnsiString name, AnsiString ref,AnsiString option);
	/*! \brief Fixe le nom de l'appareil
	\param AnsiString name : chaine de caractere indiquant le nom
	*/
	void setName(AnsiString name);
	/*! \brief Recupere le nom de l'appareil
	\return  AnsiString name_m : chaine de caractere indiquant le nom
	*/
	AnsiString getName();
	/*! \brief Fixe la reference de l'appareil
	\param AnsiString reference : chaine de caractere indiquant la reference
	*/
	void setReference( AnsiString reference);
	/*! \brief Recupere la reference de l'appareil
	\return AnsiString reference_m : chaine de caractere indiquant la reference
	*/
	AnsiString getReference();
	/*! \brief Fixe le nom de l'option
	\param AnsiString nameOption : chaine de caractere indiquant le nom de l'option
	*/
	void setnameOption(AnsiString nameOption);
	/*! \brief Recupere le nom de l'option
	\return AnsiString nameOption_m : chaine de caractere indiquant le nom de l'option
	*/
	AnsiString getnameOption();
	/*! \brief Ajoute une option
	\param AnsiString name : chaine de caractere indiquant le nom
	\param AnsiString version : chaine de caractere indiquant la version
	*/
	void addOption(AnsiString name,AnsiString version);

protected :

};
}
