// ---------------------------------------------------------------------------

#ifndef Shp34970a_CH
#define Shp34970a_CH
// ---------------------------------------------------------------------------

#define HP34970A_BUFFER_LENGTH      1024
#define HP34970A_MESSAGE_LENGTH     256
#define HP34970A_IDENT              "HEWLETT-PACKARD,34970A"
#define HP34972A_IDENT              "Agilent Technologies,34972A"
#define HP34970A_NOERROR            "+0,"

// ---------------------------------------------------------------------------

#include "virtual_multimeters_C.h"

class Shp34970a_C : public virtual_multimeters_C {
private:


	virtual void resetInstr();
	virtual std::string identInstr();

public:

	Shp34970a_C() : virtual_multimeters_C() {
		this->resetInstr();
	};
	virtual void errorQuery(long *errorToTolerate_i = NULL, int nbError_i = 0);

	/* ==================Méthodes de la classe virtual_multimeters_C=============== */
	virtual double getDcVolt();
	virtual double getAcVolt();
	virtual double getDcAmp();
	virtual double getAcAmp();
	virtual double getOhm();
	virtual double getOhm_FourWire();
	virtual double getFreq();
	virtual double getFreqMon();
	virtual double getTemp();
	virtual double getPower();
	virtual double getAverage();
	virtual std::string getError();

	virtual double setDcVolt(double DcVolt_i);
	virtual double setAcVolt(double AcVolt_i);
	virtual double setDcAmp(double DcAmp_i);
	virtual double setAcAmp(double AcAmp_i);
	virtual double setOhm(double Ohm_i);
	virtual double setOhm_FourWire(double Ohm_i);
	virtual double setFreq(double Freq_i);
	virtual double setFreqMon(double Freq_i);
	virtual double setTemp(double Temp_i);
	virtual double setPower(double Power_dbm_i);
	virtual void setAverage(int Average_i);
	virtual void setError(std::string error_i);
	/**
	 *\brief  Reception du Message. Fonction virtualle abstraite.
	 *\param  string message  : Message reçu.
	 *\param  int adr : Adresse du l'instrument.
	 *\param  GPIB_STATUS* status : pointeur Status de l'interface GPIB.
	 */ std::string recvMessage(std::string message, int adr, GPIB_BUSDATA * status);
	/**
	 *\brief  defini un changement de configuration.
	 *\param  double timeout : Time Out de reception.
	 */ void ChangeConfiguration();
	/**
	 *\brief  defini un changement de l'adresse primaire.
	 *\param  double timeout : Time Out de reception.
	 */ void ChangeAdrPrimaire(int Adr);
	/**
	 *\brief  defini un changement de l'adresse secondaire.
	 *\param  double timeout : Time Out de reception.
	 */ void ChangeAdrSecondaire(int Adr);
	/**
	 *\brief  defini le time Out du Reception.
	 *\param  double timeout : Time Out de reception.
	 */ void timeoutRecvData(double timeout = 0);
};

#endif
