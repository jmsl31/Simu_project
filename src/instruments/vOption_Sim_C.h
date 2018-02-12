//---------------------------------------------------------------------------

#ifndef vOption_Sim_CH
#define vOption_Sim_CH
//---------------------------------------------------------------------------
#endif
#include <string>
#include <StrUtils.hpp>

using namespace std;

namespace Utils{
/*! \class vOption_C
\brief Definit la classe option des instruments simules
*/
class vOption_C
{
private:
	///Chaine de caractere indiquant le nom
	AnsiString name_m;
	///Chaine de caractere indiquant la version
	AnsiString version_m;


public:

	///Constructeur de la classe vOption_c
	vOption_C();
	/*! \brief Constructeur surcharge de la classe vOption_C
	\param AnsiString name : Chaine de caractere indiquant le nom
	\param AnsiString version : Chaine de caractere indiquant la version
	*/
	vOption_C(AnsiString name,AnsiString version);
	 /*! \brief Recupere le nom de l'instrument
	 \return AnsiString name_m : nom de l'instrument
	 */
	AnsiString getName();
	/*! \brief Fixe le nom de l'instrument
	\param AnsiString name : Chaine de caractere indiquant le nom
	*/
	void setName(AnsiString name);
	/*! \brief Recupere la version de l'instrument
	\return AnsiString version_m : Chaine de caractere indiquant la version
	*/
	AnsiString getVersion();
	/*! \brief Fixe la version de l'instrument
	\param AnsiString version : Chaine de caractere indiquant la version
	*/
	void setVersion(AnsiString version);

protected :

};

}

