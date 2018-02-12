//---------------------------------------------------------------------------

#ifndef EqptObserverH
#define EqptObserverH
#include "Inst_enum.h"
#include <iostream>
//---------------------------------------------------------------------------
namespace Utils {    //\namespace Utils

class EqptObserver {

public:

	virtual void ChangeValueRising(std::string value, TYPE_PARAM type) = 0;
	virtual void ChangeValueRising(int value, TYPE_PARAM type) = 0;
	virtual void ChangeValueRising(double value, TYPE_PARAM type) = 0;
	virtual void ChangeValueRising(bool value, TYPE_PARAM type) = 0;


protected:

private:

};
}

#endif
