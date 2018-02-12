// ---------------------------------------------------------------------------

#pragma hdrstop

#include "GpibSubject.h"
#include "Gpib_Enum.h"
// ---------------------------------------------------------------------------

#pragma package(smart_init)

using namespace std;

namespace UtilSimu {
	GpibSubject::~GpibSubject() {
	}

	void GpibSubject::notifychangeStatus(GPIB_STATUS status) {
		for (unsigned int i = 0; i < Observers_m.size(); i++) {
			Observers_m[i]->changeStatus(status);
		}
	}

	std::string GpibSubject::notifyRecvMessage(std::string message, int adr,
		GPIB_BUSDATA* status) {
		std::string reponse;
		for (unsigned int i = 0; i < Observers_m.size(); i++) {
			return (Observers_m[i]->recvMessage(message, adr, status));
		}
	}

	void GpibSubject::notifyTimeoutRecvData(double timeout) {
		for (unsigned int i = 0; i < Observers_m.size(); i++) {
			Observers_m[i]->timeoutRecvData(timeout);
		}
	}

	void GpibSubject::notifyChangeConfiguration() {
		for (unsigned int i = 0; i < Observers_m.size(); i++) {
			Observers_m[i]->ChangeConfiguration();
		}
	}

	void GpibSubject::notifyChangeAdrPrimaire(int Adr) {
		for (unsigned int i = 0; i < Observers_m.size(); i++) {
			Observers_m[i]->ChangeAdrPrimaire(Adr);
		}
	}

	void GpibSubject::notifyChangeAdrSecondaire(int Adr) {
		for (unsigned int i = 0; i < Observers_m.size(); i++) {
			Observers_m[i]->ChangeAdrSecondaire(Adr);
		}
	}

	void GpibSubject::addObserver(GpibObserver &observer) {
		Observers_m.push_back(&observer);
	}

	void GpibSubject::removeObserver(GpibObserver &observer) {

		std::vector<GpibObserver*>observers = Observers_m;
		Observers_m.clear();
		for (unsigned int i = 0; i < observers.size(); i++) {
			if (observers[i] != &observer)
				addObserver(observer);
		}
	}
}
