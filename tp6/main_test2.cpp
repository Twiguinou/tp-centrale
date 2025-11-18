#include "PersonnelAdmin.h"
#include "EnseignantPermanent.h"
#include "ListePersonnel.h"

#include <cstdlib>

int main()
{
	PersonnelAdmin admin1("Benazha", "Hamed", 2500.0f, 1.5f, "2 rue de la KC", "0615567890", 3);
	EnseignantPermanent prof1("Lacrim", "Karim", 3000.0f, "s208", 5, 100);

	ListePersonnel liste;
	liste.ajoutPersonnel(&admin1);
	liste.ajoutPersonnel(&prof1);

	liste.afficherSalaires();

	return EXIT_SUCCESS;
}

