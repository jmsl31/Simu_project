// ---------------------------------------------------------------------------

#ifndef EqptSubjectH
#define EqptSubjectH
// ---------------------------------------------------------------------------
#include <vector>
#include "EqptObserver.h"
#include "Inst_Enum.h"

namespace Utils { // \namespace Utils

	class EqptSubject {

	public:
		/**
		 *\brief Methode de communication de l'observer montante permettant la propagation de l'inforamtion entre les objets.
		 *\param std::string value : parametres a transmettre.
		 *\param TYPE_PARAM type : Type de parametres transmis
		 */

		void notifyChangeValueRising(std::string value, TYPE_PARAM type);
		void notifyChangeValueRising(double value, TYPE_PARAM type);
		void notifyChangeValueRising(int value, TYPE_PARAM type);
		void notifyChangeValueRising(bool value, TYPE_PARAM type);
		/**
		 *\brief Ajout dans la pile d'un objet EqptObserver
		 *\param EqptObserver obs : Objet EqptObserver.
		 */
		void addObserverRising(EqptObserver* obs);
		/**
		 *\brief Supprime un Observateur.
		 *\param EqptObserver &obs.
		 */
		void removeObserverRising(EqptObserver* obs);

	protected:

	private:

		std::vector<EqptObserver*>ObserversRising_m;
		// Pile d'objets EqptObserver.
	};
}
#endif
