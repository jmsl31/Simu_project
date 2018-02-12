// ---------------------------------------------------------------------------

#pragma hdrstop

#include "InstSubject.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;

namespace Utils {


	void InstSubject::notifyChangeValueDown(std::string value, TYPE_PARAM type) {

		for (unsigned int i = 0; i < ObserversDown_m.size(); i++) {
			ObserversDown_m[i]->ChangeValueDown(value, type);
		}
	};

	void InstSubject::notifyChangeValueDown(int value, TYPE_PARAM type) {

		for (unsigned int i = 0; i < ObserversDown_m.size(); i++) {
			ObserversDown_m[i]->ChangeValueDown(value, type);
		}
	};

	void InstSubject::notifyChangeValueDown(double value, TYPE_PARAM type) {

		for (unsigned int i = 0; i < ObserversDown_m.size(); i++) {
			ObserversDown_m[i]->ChangeValueDown(value, type);
		}
	};

	void InstSubject::notifyChangeValueDown(bool value, TYPE_PARAM type) {

		for (unsigned int i = 0; i < ObserversDown_m.size(); i++) {
			ObserversDown_m[i]->ChangeValueDown(value, type);
		}
	};

	void InstSubject::addObserverDown(InstObserver* obs) {
		ObserversDown_m.push_back(obs);
	};

	void InstSubject::removeObserverDown(InstObserver* observer) {

		std::vector<InstObserver*>observers = ObserversDown_m;
		ObserversDown_m.clear();
		for (unsigned int i = 0; i < ObserversDown_m.size(); i++) {
			if (observers[i] != &observer)
				addObserverDown(observer);
		}
	};

}
