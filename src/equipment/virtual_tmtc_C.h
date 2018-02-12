//---------------------------------------------------------------------------

#ifndef virtual_tmtc_CH
#define virtual_tmtc_CH
//---------------------------------------------------------------------------
#endif

/*! \class virtual_tmtc_C
\brief Classe du tmtc virtuel
*/
class virtual_tmtc_C{

private:
	///Status du tmtc
	bool tm_Status_m,
	///Etat du tmtc
	tm_ON_OFF_m;
	/*! \brief Fixe le status du tmtc
	\param bool status : status desire
	*/
	void setTm_Status(bool status);
	/*! \brief Recupere le status du tmtc
	\return Status du tmtc
	*/
	bool getTm_Status ();
	/*! \brief Fixe l'etat du tmtc
	\param bool status : status desire
	*/
	void setTm_ON_OFF(bool status);
	/*! \brief Recupere l'etat du tmtc
	\return Etat du tmtc
	*/
	bool getTm_ON_OFF ();



public:

	//Constructeur et destructeur
	 ///Constructeur de la fonction virtual_tmtc_C
	 virtual_tmtc_C();
	 ///Destructeur de la fonction virtual_tmtc_C
	~virtual_tmtc_C();
	/*! \brief Propriete Tm_Status de l'objet virtual_tmtc_C
	*/
	__property bool Tm_Status = {read = getTm_Status, write = setTm_Status};
	/*! \brief Propriete Tm_ON_OFF de l'objet virtual_tmtc_C
	*/
	__property bool Tm_ON_OFF = {read = getTm_ON_OFF, write = setTm_ON_OFF};

protected:

};
