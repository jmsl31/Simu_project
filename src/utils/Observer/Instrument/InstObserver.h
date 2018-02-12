// ---------------------------------------------------------------------------

#ifndef InstObserverH
#define InstObserverH

// ---------------------------------------------------------------------------
#include <iostream>
#include "Inst_Enum.h"
namespace Utils {    //\namespace Utils

class InstObserver {

public:

	virtual void ChangeValueDown(std::string value, TYPE_PARAM type) = 0;
	virtual void ChangeValueDown(int value, TYPE_PARAM type) = 0;
	virtual void ChangeValueDown(double value, TYPE_PARAM type) = 0;
	virtual void ChangeValueDown(bool value, TYPE_PARAM type) = 0;


protected:

private:

};
}

#endif
