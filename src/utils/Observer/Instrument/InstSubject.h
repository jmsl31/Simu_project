// ---------------------------------------------------------------------------

#ifndef InstSubjectH
#define InstSubjectH
// ---------------------------------------------------------------------------

#include <vector>
#include "InstObserver.h"
#include "Inst_Enum.h"

namespace Utils { // \namespace Utils
	class InstSubject {

	public:
		/**
		 *\brief Methode de communication de l'observer descendant permettant la propagation de l'inforamtion entre les objets.
		 *\param std::string value : parametres a transmettre.
		 *\param TYPE_PARAM type : Type de parametres transmis
		 */
		void notifyChangeValueDown(std::string value, TYPE_PARAM type);
		void notifyChangeValueDown(double value, TYPE_PARAM type);
		void notifyChangeValueDown(int value, TYPE_PARAM type);
		void notifyChangeValueDown(bool value, TYPE_PARAM type);
		/**
		 *\brief Ajout dans la pile d'un objet InstObserver
		 *\param InstObserver obs : Objet InstObserver.
		 */
		void addObserverDown(InstObserver* obs);
		/**
		 *\brief Supprime un Observateur.
		 *\param InstObserver &obs.
		 */
		void removeObserverDown(InstObserver* obs);

	protected:

	private:

		std::vector<InstObserver*>ObserversDown_m;
		// Pile d'objets EqptObserver.
	};
}
#endif
