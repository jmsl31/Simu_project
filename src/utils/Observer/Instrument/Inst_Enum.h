// ---------------------------------------------------------------------------

#ifndef Inst_EnumH
#define Inst_EnumH
// ---------------------------------------------------------------------------
namespace Utils {    //\namespace Utils

	enum TYPE_PARAM {  // Enumerateur TYPE_PARAM : defini l'ensemble des variables modifiables possibles dans les methose de communication des observers.

		VOLT, CURRENT, POWER,ACTIVE_POWER,VOLTAGE_RETURN,CURRENT_RETURN,


		FREQ_START_IN,FREQ_STOP_IN, FREQ_START_OUT,FREQ_STOP_OUT,BANDWIDTH,STEP, FREQ_OL, POWER_IN, POWER_OUT, POWER_OL,

		//Parametre de l'alimentation
		OVER_VOLTAGE,OVER_CURRENT,OVER_TEMPERATURE,REMOTE_INHIBIT,UNREGULATION,ACTIVE_ALIM,

	};


  }
#endif
