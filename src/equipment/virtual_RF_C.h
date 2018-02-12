//---------------------------------------------------------------------------

#ifndef virtual_RF_CH
#define virtual_RF_CH
//---------------------------------------------------------------------------
#endif


/*! \class virtual_RF_C
\brief Classe du RF virtuel
*/
class virtual_RF_C{

private:
	// Parametre Privée de la \a Classe vtranche_C
	///Frequence de depart en entree
	double 	frequency_Start_In_m,
	///Frequence de fin en entree
	frequency_Stop_In_m,
	///Bande passante
	bandwidth_m,
	///Etape
	step_m,
	///Puissance
	power_m,
	///Frequence minimum
	frequency_Min,
	///Frequence maximum
	frequency_Max,
	///Frequence de depart en sortie
	frequency_Start_Out_m,
	///Frequence de fin en sortie
	frequency_Stop_Out_m,
	///Puissance minimum
	power_min,
	///Puissance maximum
	power_max,
	// Gain de la tranche
	gain_m;

	///Etat RF
	bool FActiveRF,
	///Etat puissance RF
	FActivePower,
	///Etat de surcharge
	FOverload;


	// methode Privée de la \a Classe vtranche_C
	/*! \brief Recupere la frequence de depart en entree
	\return Frequence de depart en entree
	*/
	virtual double getFrequency_Start_In();
	/*! \brief Fixe la frequence de depart en entree
	\param fq_start_i : frequence desiree
	*/
	virtual void setFrequency_Start_In(double fq_start_i);
	/*! \brief Recupere la frequence de fin en entree
	\return Frequence de fin en entree
	*/
	virtual double getFrequency_Stop_In();
	/*! \brief Fixe la frequence de fin en entree
	\param fq_stop_i : Ffrequence desiree
	*/
	virtual void setFrequency_Stop_In(double fq_stop_i);
	/*! \brief Recupere la frequence de depart en sortie
	\return Frequence de depart en sortie
	*/
	virtual double getFrequency_Start_Out();
	/*! \brief Fixe la frequence de depart en sortie
	\param fq_start_i : frequence desiree
	*/
	virtual void setFrequency_Start_Out(double fq_start_i);
	/*! \brief Recupere la frequence de fin en sortie
	\return Frequence de fin en sortie
	*/
	virtual double getFrequency_Stop_Out();
	/*! \brief Fixe la frequence de fin en sortie
	\param fq_stop_i : frequence desiree
	*/
	virtual void setFrequency_Stop_Out(double fq_stop_i);

	/*! \brief Recupere la frequence minimum
	\return Frequence minimum
	*/
	virtual double getFrequency_Min();
	/*! \brief Fixe la frequence minimum
	\param fq_min_i : frequence desiree
	*/
	virtual void setFrequency_Min(double fq_min_i);
	/*! \brief Recupere la frequence maximum
	\return Frequence maximum
	*/
	virtual double getFrequency_Max();
	/*! \brief Fixe la frequence maximum
	\param Frequence desiree
	*/
	virtual void setFrequency_Max(double fq_max_i);

	/*! \brief Recupere la bande passante
	\return Bande passante
	*/
	virtual double getbandwidth();
	/*! \brief Fixe la bande passante
	\param bandwith_i : bande passante desiree
	*/
	virtual void setbandwidth(double bandwidth_i);
	/*! \brief Recupere l'etape en cours
	\return Etape en cours
	*/
	virtual double getstep();
	/*! \brief Fixe l'etape en cours
	\param step_i : etape desiree
	*/
	virtual void setstep(double step_i);

	/*! \brief Recupere le gain
	\return Gain de la tranche
	*/
	virtual double getGain();
	/*! \brief Fixe le gain
	\param gain_i : gain desiree
	*/
	virtual void setGain(double gain_i);
	/*! \brief Recupere la puissance
	\return Puissance du RF
	*/
	virtual double getPower();
	/*! \brief Fixe la puissance
	\param power_i : puisance desiree
	*/
	virtual void setPower(double power_i);
	/*! \brief Recupere la puissance minimum
	\return Puissance minimum du RF
	*/
	virtual double getPower_Min();
	/*! \brief Fixe la puissance minimum
	\param power_min_i : puissance desiree
	*/
	virtual void setPower_Min(double power_min_i);
	/*! \brief Recupere la puisasnce maximum
	\return Puissance maximum du RF
	*/
	virtual double getPower_Max();
	/*! \brief Fixe la puissance maximum
	\param power_max_i : puissance desiree
	*/
	virtual void setPower_Max(double power_max_i);


public:
	// Parametre Public  de la \a Classe vtranche_C

	// methode Public de la \a Classe vtranche_C

		//Construceur & Destructeur

	 ///Constructeur de la fonction virtual_RF_C
	 virtual_RF_C();

	 //	 virtual __fastcall ~vtranche_C();


	 /*! \brief Initialise la tranche
	 \param double fq_start_i : frequence de depart
	 \param double fq_stop_i : frequence de fin
	 \param double bandwidth_i : bande passante
	 \param double step_i : etape
	 \param double power_i : puissance
	 \param double power_min : puissance minimum
	 \param double power_max : puissance maximum
	 \param double frequency_min : frequence minimum
	 \param double frequency_max : frequence maximum
	 */
	 virtual void initTranche(double fq_start_i,double fq_stop_i,double bandwidth_i,double step_i,double power_i,
				double power_min,double power_max,double frequency_min,double frequency_max,double gain_i);


	// Propriété de la \a Classe vtranche_C
	/*! \brief Propriete Frequency_Start_In de l'objet virtual_RF_C
	*/
	__property double Frequency_Start_In = {read = getFrequency_Start_In, write = setFrequency_Start_In};
	/*! \brief Propriete Frequency_Stop_In de l'objet virtual_RF_C
	*/
	__property double Frequency_Stop_In = {read = getFrequency_Stop_In, write = setFrequency_Stop_In};
	/*! \brief Propriete Frequency_Stop_In de l'objet virtual_RF_C
	*/
	__property double Gain = {read = getGain, write = setGain};

	/*! \brief Propriete Frequency_Start_Out de l'objet virtual_RF_C
	*/
	__property double Frequency_Start_Out = {read = getFrequency_Start_Out, write = setFrequency_Start_Out};
	/*! \brief Propriete Frequency_Stop_Out de l'objet virtual_RF_C
	*/
	__property double Frequency_Stop_Out = {read = getFrequency_Stop_Out, write = setFrequency_Stop_Out};
	/*! \brief Propriete Frequency_Min de l'objet virtual_RF_C
	*/
	__property double Frequency_Min = {read = getFrequency_Min, write = setFrequency_Min};
	/*! \brief Propriete Frequency_Max de l'objet virtual_RF_C
	*/
	__property double Frequency_Max = {read = getFrequency_Max, write = setFrequency_Max};
	/*! \brief Propriete Bandwidth de l'objet virtual_RF_C
	*/
	__property double Bandwidth = {read = getbandwidth, write = setbandwidth};
	/*! \brief Propriete Step de l'objet virtual_RF_C
	*/
	__property double Step = {read = getstep, write = setstep};
	/*! \brief Propriete Power de l'objet virtual_RF_C
	*/
	__property double Power = {read = getPower, write = setPower};
	/*! \brief Propriete Power_Max de l'objet virtual_RF_C
	*/
	__property double Power_Max = {read = getPower_Max, write = setPower_Max};
	/*! \brief Propriete Power_Minde l'objet virtual_RF_C
	*/
	__property double Power_Min = {read = getPower_Min, write = setPower_Min};
	/*! \brief Propriete ActiveRF de l'objet virtual_RF_C
	*/
	__property bool ActiveRF = {read = FActiveRF, write = FActiveRF};
	/*! \brief Propriete ActivePower de l'objet virtual_RF_C
	*/
	__property bool ActivePower = {read = FActivePower, write = FActivePower};
    /*! \brief Propriete Overload de l'objet virtual_RF_C
	*/
	__property bool Overload = {read = FOverload, write = FOverload};


protected:

};

