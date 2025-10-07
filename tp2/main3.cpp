#include "ArrayOfInteger.h"

#include <cstdlib>

int main()
{
	ArrayOfInteger a;
	a.ajouter(3);
	a.ajouter(2);
	a.ajouter(54);
	a.ajouter(23);
	a.ajouter(2);
	a.retirer(3);
	a.afficher();

	return EXIT_SUCCESS;
}

