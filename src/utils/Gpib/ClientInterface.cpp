// ---------------------------------------------------------------------------

#pragma hdrstop

#include "ClientInterface.h"
#include "stdlib.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

namespace UtilSimu {

	ClientInterface::ClientInterface() {
	};

	ClientInterface::~ClientInterface() {
	};

	void ClientInterface::changeStatus(GPIB_STATUS status) {
		setStatus(status);
	};

	void ClientInterface::recvMessage(std::string message, int adr,
		GPIB_STATUS* status) {
		setmessage(message);
	};

	void ClientInterface::ChangeConfiguration() {

	};

	void ClientInterface::ChangeAdrPrimaire(int Adr) {
		setAdrPrimarie(Adr);
	};

	void ClientInterface::ChangeAdrSecondaire(int Adr) {
		setAdrSecondaire(Adr);
	};

	void ClientInterface::timeoutRecvData(double timeout) {

	};

	GPIB_STATUS ClientInterface::getStatus() {
		return (status);
	};

	void ClientInterface::setStatus(GPIB_STATUS status) {
		status = status;
	};

	int ClientInterface::getAdrprimaire() {
		return (AdrPrimaire);
	};

	void ClientInterface::setAdrPrimarie(int adr) {
		AdrPrimaire = adr;
	};

	int ClientInterface::getAdrSecondaire() {
		return (AdrSecondaire);
	};

	void ClientInterface::setAdrSecondaire(int adr) {
		AdrSecondaire = adr;
	};

	std::string ClientInterface::getmessage() {
		return (message);
	};

	void ClientInterface::setmessage(std::string mes) {
		message = mes;
	};

}
