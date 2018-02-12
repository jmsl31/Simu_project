// ---------------------------------------------------------------------------

#pragma hdrstop

#include "GpibInterface.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

using namespace std;
using namespace Utils::Thread;

namespace UtilSimu {

	GpibInterface::GpibInterface() {

		Comm_gpib_m = new GPIB_T();
		Comm_gpib_m->status = STOPPED;
	};

	GpibInterface::~GpibInterface() {
	};

	void GpibInterface::set_Gpib_T(GPIB_T struct_i) {

		Comm_gpib_m->type = struct_i.type;
		Comm_gpib_m->Id_Interface = struct_i.Id_Interface;
		Comm_gpib_m->Adr_Primaire = struct_i.Adr_Primaire;
		Comm_gpib_m->Adr_secondaire = struct_i.Adr_secondaire;
		Comm_gpib_m->controler_system = struct_i.controler_system;
		Comm_gpib_m->timeout = struct_i.timeout;
		Comm_gpib_m->EOI = struct_i.EOI;
		Comm_gpib_m->status = struct_i.status;

	};

	GPIB_T* GpibInterface::get_Gpibt_T() {
		return (Comm_gpib_m);
	};

	void GpibInterface::errVisaToStr(ViStatus errVisa_i) {
		char desc_l[512];
		if (errVisa_i < VI_SUCCESS) {
			viStatusDesc(0, errVisa_i, desc_l);
			throw Exception(desc_l);
		}
	}

	bool GpibInterface::InstallGpib() {

		ViSession inst;
		ViSession def;
		AnsiString GpibCard_m;

		try {
			/* First we open a session to the VISA resource manager.  We are
			 *  returned a handle to the resource manager session that we must
			 *  use to open sessions to specific instruments.
			 */

			errVisaToStr(viOpenDefaultRM(&def));
			setDefaultSession(def);

			if (Comm_gpib_m->type == SERVER) {
				GpibCard_m = "GPIB" + IntToStr(get_Gpibt_T()->Id_Interface) +
					"::INTFC";
				Comm_gpib_m->controler_system = VI_FALSE;

			}
			else if (Comm_gpib_m->type == CLIENT) {
				GpibCard_m = "GPIB" + IntToStr(get_Gpibt_T()->Id_Interface) +
					"::INSTR";
				Comm_gpib_m->controler_system = VI_TRUE;

			}

			errVisaToStr(viOpen(getDefaultSession(), GpibCard_m.c_str(),
				VI_NULL, 1, &inst));
			setInstr(inst);

			errVisaToStr(viSetAttribute(getInstr(),
				VI_ATTR_GPIB_SYS_CNTRL_STATE, Comm_gpib_m->controler_system));

			errVisaToStr(viSetAttribute(getInstr(), VI_ATTR_TMO_VALUE,
				Comm_gpib_m->timeout));

			errVisaToStr(viSetAttribute(getInstr(), VI_ATTR_GPIB_PRIMARY_ADDR,
				Comm_gpib_m->Adr_Primaire));
			errVisaToStr(viSetAttribute(getInstr(), VI_ATTR_GPIB_SECONDARY_ADDR,
				Comm_gpib_m->Adr_secondaire));

			notifychangeStatus(GPIB_STATUS::CONNECTED);
			return 0;

		}
		catch (...) {
			notifychangeStatus(GPIB_STATUS::STOPPED);
			return 1;
		}

	};

	bool GpibInterface::UnInstallGPIB() {

		try {
			/* Obtain the information about the event and then destroy the */
			/* event. In this case, we want the status ID from the interrupt. */
			// errVisaToStr(viGetAttribute(eventData, VI_ATTR_SIGP_STATUS_ID, &statID));
			// errVisaToStr(viClose(eventData));

			/* Your code should read data from the instrument and process it. */
			errVisaToStr(viClose(getInstr()));
			errVisaToStr(viClose(getDefaultSession()));
			notifychangeStatus(GPIB_STATUS::STOPPED);
			return 0;

		}
		catch (Exception &E) {
			return 1;
		}
	};

	// Defintion du Thread

	DWORD WINAPI RecvProcessing(LPVOID arg) {

		GpibInterface* Gpib = (GpibInterface*) arg;
		std::string message, reponse;
		while (Gpib->getRecvStatus() == THEARD_STATUS::RUNNING) {
			message = Gpib->threadRecv();
			Gpib->get_Gpibt_T()->Status_bus = GPIB_BUSDATA::REQUEST;
			reponse = Gpib->notifyRecvMessage(message,
				Gpib->get_Gpibt_T()->Adr_Primaire,
				&Gpib->get_Gpibt_T()->Status_bus);
			if (strstr(message.c_str(), "?") != NULL && Gpib->get_Gpibt_T()
				->Status_bus == GPIB_BUSDATA::REPLY) {

				Gpib->threadSend(reponse);
			}
			Gpib->get_Gpibt_T()->Status_bus == GPIB_BUSDATA::LISTTED;
		}
		// Gpib->setRecvStatus(THEARD_STATUS::STOP);
		return 0;
	}

	void GpibInterface::threadSend(std::string reponse) {

		unsigned long ret = 0;
		ViStatus status;

		try {
			Comm_gpib_m->Status_bus = GPIB_BUSDATA::WRITTED;
			status = viWrite(SessionInstrument, reponse.c_str(), 100, &ret);
			std::cout << "Envoyer" << std::endl;
			Comm_gpib_m->Status_bus = GPIB_BUSDATA::REPLY;
		}
		catch (Exception &E) {
			// LastError_m = E.Message;     // POURQUOI TIMEOUT ?
			// MsgEvent(this, 0, "GPIB ERROR : " + LastError_m);
			std::cout << "Probleme" << std::endl;
		}

	};

	std::string GpibInterface::threadRecv() {
		unsigned long ret = 0;
		char buffer[512];
		ViStatus status;

		Comm_gpib_m->Status_bus = GPIB_BUSDATA::LISTTED;

		do {
			status = viRead(getInstr(), buffer, 100, &ret);
			buffer[ret] = 0;
			Sleep(100);
		}
		while ((ret == 0) && getRecvStatus()
			== THEARD_STATUS::RUNNING && Comm_gpib_m->Status_bus == GPIB_BUSDATA::LISTTED);

		std::cout << "Recu" << std::endl;
		return (buffer);

	}

	void GpibInterface::setInstr(ViSession instr) {
		SessionInstrument = instr;
	};

	ViSession GpibInterface::getInstr() {
		return (SessionInstrument);
	};

	void GpibInterface::setDefaultSession(ViSession instr) {
		defaultRM = instr;
	};

	ViSession GpibInterface::getDefaultSession() {
		return (defaultRM);
	};

	GPIB_STATUS GpibInterface::getStatus() {
		return (Comm_gpib_m->status);
	};

	void GpibInterface::setStatus(GPIB_STATUS status) {
		Comm_gpib_m->status = status;
	};

	TYPE_GPIB GpibInterface::getType() {
		return (Comm_gpib_m->type);
	};

	void GpibInterface::setType(TYPE_GPIB t) {
		Comm_gpib_m->type = t;
	};

	Utils::Thread::THEARD_STATUS GpibInterface::getRecvStatus() {
		return (RecvStatus_m);
	};

	/**
	 *\details Renseigne le status du le Thread.
	 *\param  THEARD_STATUS : Status du Thread.
	 */

	void GpibInterface::setRecvStatus(Utils::Thread::THEARD_STATUS status) {
		RecvStatus_m = status;
	};

	void GpibInterface::Start() {

		RecvStatus_m = THEARD_STATUS::RUNNING;
		DWORD threadID;
		CreateThread(NULL, 0, RecvProcessing, this, 0, &threadID);

	}

	void GpibInterface::Stop() {
		if (RecvStatus_m == Utils::Thread::STOP) {
			return;
		}
		RecvStatus_m = Utils::Thread::STOPPING;

		while (RecvStatus_m != Utils::Thread::STOP) {
			Sleep(10);
		}
	}
}
