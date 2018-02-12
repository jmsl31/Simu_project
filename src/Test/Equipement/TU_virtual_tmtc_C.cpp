#include <DUnitX.TestFramework.hpp>
#include <stdio.h>
#include "virtual_tmtc_C.h"

#pragma option --xrtti

class __declspec(delphirtti) TU_virtual_tmtc_C : public TObject
{
public:
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();


__published:

  virtual void __fastcall Verif_tm_Status();
  virtual void __fastcall Verif_tm_ON_OFF();

};

virtual_tmtc_C *t;

void __fastcall TU_virtual_tmtc_C::SetUp()
{
	t = new virtual_tmtc_C();
}

void __fastcall TU_virtual_tmtc_C::TearDown()
{
   delete t;
}

void __fastcall TU_virtual_tmtc_C::Verif_tm_Status()
{
	SetUp() ;
	Dunitx::Testframework::Assert::IsTrue(t->Tm_Status == false);
	t->Tm_Status = true;
	Dunitx::Testframework::Assert::IsTrue(t->Tm_Status == true);
	TearDown();
}

void __fastcall TU_virtual_tmtc_C::Verif_tm_ON_OFF()
{
	SetUp() ;
	Dunitx::Testframework::Assert::IsTrue(t->Tm_ON_OFF == false);
	t->Tm_ON_OFF = true;
	Dunitx::Testframework::Assert::IsTrue(t->Tm_ON_OFF == true);
	TearDown();

}

static void registerTests()
{
  TDUnitX::RegisterTestFixture(__classid(TU_virtual_tmtc_C));
}
#pragma startup registerTests 33