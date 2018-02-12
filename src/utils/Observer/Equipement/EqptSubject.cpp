//---------------------------------------------------------------------------

#pragma hdrstop

#include "EqptSubject.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



using namespace std;

namespace Utils {


	void EqptSubject::notifyChangeValueRising(std::string value, TYPE_PARAM type) {

		for (unsigned int i = 0; i < ObserversRising_m.size(); i++) {
			ObserversRising_m[i]->ChangeValueRising(value, type);
		}
	};

	void EqptSubject::notifyChangeValueRising(int value, TYPE_PARAM type) {

		for (unsigned int i = 0; i < ObserversRising_m.size(); i++) {
			ObserversRising_m[i]->ChangeValueRising(value, type);
		}
	};

	void EqptSubject::notifyChangeValueRising(double value, TYPE_PARAM type) {

		for (unsigned int i = 0; i < ObserversRising_m.size(); i++) {
			ObserversRising_m[i]->ChangeValueRising(value, type);
		}
	};

	void EqptSubject::notifyChangeValueRising(bool value, TYPE_PARAM type) {

		for (unsigned int i = 0; i < ObserversRising_m.size(); i++) {
			ObserversRising_m[i]->ChangeValueRising(value, type);
		}
	};

	void EqptSubject::addObserverRising(EqptObserver* obs) {
		ObserversRising_m.push_back(obs);
	};

	void EqptSubject::removeObserverRising(EqptObserver* observer) {

		std::vector<EqptObserver*>observers = ObserversRising_m;
		ObserversRising_m.clear();
		for (unsigned int i = 0; i < ObserversRising_m.size(); i++) {
			if (observers[i] != &observer)
				addObserverRising(observer);
		}
	};

}

