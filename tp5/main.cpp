#include "Agenda.h"

#include <cstdlib>

int main()
{
	RDV rdv1;
	rdv1.saisie();

	RDV rdv2;
	rdv2.saisie();

	Agenda agenda;
	agenda.ajoute(rdv1);
	agenda.ajoute(rdv2);
	agenda.affiche();

	return EXIT_SUCCESS;
}

