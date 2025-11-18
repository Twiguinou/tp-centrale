#include "EnseignantVacataire.h"

#include <cstdlib>

int main()
{
	EnseignantVacataire prof1("Benazha", "Hamed", "12e", 4, 200, "2 rue de la KC", "0615567890");
	prof1.affiche();

	return EXIT_SUCCESS;
}

