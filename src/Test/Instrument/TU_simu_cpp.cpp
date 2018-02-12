#include <System.Sysutils.hpp>
#include <DUnitX.Loggers.Console.hpp>
#include <DUnitX.Loggers.Xml.NUnit.hpp>
#include <DUnitX.TestFramework.hpp>


#include <stdio.h>
#pragma package(smart_init)
//#pragma link "drivers_cpp10.lib"
#pragma link "visa32.lib"
#include <vcl.h>

USEFORM("..\..\bench\SBenchFormUnit.cpp", BenchFormUnit);
USEFORM("..\..\equipment\Recepteur\SRxFormUnit.cpp", RxFormUnit);
USEFORM("..\..\instruments\Alim\SAlimFormUnit.cpp", AlimFormUnit);
//---------------------------------------------------------------------------
int main()
{
  try
  {
    TDUnitX::CheckCommandLine();
	_di_ITestRunner runner = TDUnitX::CreateRunner();
    _di_ITestLogger logger(*new TDUnitXConsoleLogger(true));
    runner->AddLogger(logger);

    _di_ITestLogger nunitLogger(*new TDUnitXXMLNUnitFileLogger(TDUnitX::Options->XMLOutputFile));
    runner->AddLogger(nunitLogger);

    _di_IRunResults results = runner->Execute();

#if !defined(CI)
    if (TDUnitX::Options->ExitBehavior == TDUnitXExitBehavior::Pause)
    {
      printf("Done.. press <Enter> key to quit.");
      getchar();
    }
#endif

    return results->AllPassed ? EXIT_SUCCESS : EXIT_FAILURE;
  }
  catch(System::Sysutils::Exception& Ex)
  {
    printf("Exception: ''Project1''\n", AnsiString(Ex.Message).c_str());
  }
  return EXIT_FAILURE;
}