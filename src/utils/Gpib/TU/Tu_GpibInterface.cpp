#include <DUnitX.TestFramework.hpp>
#include <stdio.h>
#include "GpibInterface.h"
#include "GpibObserver.h"

#pragma option --xrtti

class __declspec(delphirtti) TU_GpibInterface : public TObject
{
public:
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();

 __published:

  // Methode de base
  virtual void __fastcall Test_set_Gpib_T();
  virtual void __fastcall Test_get_Gpib_T();
  /*virtual void __fastcall InstallGpib();
  virtual void __fastcall UnInstallGPIB();
  virtual void __fastcall getStatus();
  virtual void __fastcall setStatus();
  virtual void __fastcall getType();
  virtual void __fastcall setType();
  virtual void __fastcall setInstr();
  virtual void __fastcall getInstr();
  virtual void __fastcall setDefaultSession();
  virtual void __fastcall getDefaultSession();        */

  //Methode de test des fonctionnalités de l'objet.

  //virtual void __fastcall Test_Connection();

};

using namespace std;
using namespace Utils;


 GpibInterface	*Interface;
 GPIB_T  *Struct_Gpib;
 GpibObserver   *Bench ;

void __fastcall TU_GpibInterface::SetUp()
{
	 Struct_Gpib = new GPIB_T();

}

void __fastcall TU_GpibInterface::TearDown()
{
	delete Struct_Gpib;
}

void __fastcall TU_GpibInterface::Test_set_Gpib_T(){

	 Struct_Gpib->type = SERVER;
	 Struct_Gpib->Id_Interface = 0;
	 Struct_Gpib->Adr_Primaire = 2;
	 Struct_Gpib->Adr_secondaire =0;
	 Struct_Gpib->controler_system = false;
	 Struct_Gpib->timeout = 200;
	 Struct_Gpib->EOI = true;
	 Struct_Gpib->status = STOPPED;

	 Interface->set_Gpib_T(*Struct_Gpib);

	 Dunitx::Testframework::Assert::IsTrue(Interface->get_Gpibt_T()->type == SERVER);
	 Dunitx::Testframework::Assert::IsTrue(Interface->get_Gpibt_T()->Id_Interface == 0);
	 Dunitx::Testframework::Assert::IsTrue(Interface->get_Gpibt_T()->Adr_Primaire == 2);
	 Dunitx::Testframework::Assert::IsTrue(Interface->get_Gpibt_T()->Adr_secondaire == 0);
	 Dunitx::Testframework::Assert::IsTrue(Interface->get_Gpibt_T()->controler_system == false);
	 Dunitx::Testframework::Assert::IsTrue(Interface->get_Gpibt_T()->timeout == 200);
	 Dunitx::Testframework::Assert::IsTrue(Interface->get_Gpibt_T()->EOI == true);
	 Dunitx::Testframework::Assert::IsTrue(Interface->get_Gpibt_T()->status == STOPPED);



};

void __fastcall TU_GpibInterface::Test_get_Gpib_T(){

	 GPIB_T *Struct_Gpib_test = new GPIB_T();


	 Struct_Gpib_test = Interface->get_Gpibt_T();

	 Dunitx::Testframework::Assert::IsTrue( Struct_Gpib_test->type == Interface->get_Gpibt_T()->type);
	 Dunitx::Testframework::Assert::IsTrue( Struct_Gpib_test->Id_Interface == Interface->get_Gpibt_T()->Id_Interface);
	 Dunitx::Testframework::Assert::IsTrue( Struct_Gpib_test->Adr_Primaire == Interface->get_Gpibt_T()->Adr_Primaire);
	 Dunitx::Testframework::Assert::IsTrue( Struct_Gpib_test->Adr_secondaire == Interface->get_Gpibt_T()->Adr_secondaire);
	 Dunitx::Testframework::Assert::IsTrue( Struct_Gpib_test->controler_system == Interface->get_Gpibt_T()->controler_system);
	 Dunitx::Testframework::Assert::IsTrue( Struct_Gpib_test->timeout == Interface->get_Gpibt_T()->timeout);
	 Dunitx::Testframework::Assert::IsTrue( Struct_Gpib_test->EOI == Interface->get_Gpibt_T()->EOI);
	 Dunitx::Testframework::Assert::IsTrue( Struct_Gpib_test->status == Interface->get_Gpibt_T()->status);


};

static void registerTests()
{
  TDUnitX::RegisterTestFixture(__classid(TU_GpibInterface));
}
#pragma startup registerTests 33