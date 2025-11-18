#include "ListePersonnel.h"

#include <iostream>

ListePersonnel::ListePersonnel() : tab(nullptr), nb(0), taille(0) {}

ListePersonnel::~ListePersonnel()
{
	delete[] tab;
}

void ListePersonnel::ajoutPersonnel(Personnel* ptPersonnel)
{
	if (nb == taille)
	{
		doubleTableau();
	}

	tab[nb++] = ptPersonnel;
}

void ListePersonnel::afficherSalaires() const
{
	for (int i = 0; i < nb; i++)
	{
		std::cout << "Salaire n°" << (i+1) << ": " << tab[i]->calculSalaire() << "€" << std::endl;
	}
}

void ListePersonnel::doubleTableau()
{
	int nouvelleTaille = taille == 0 ? 1 : taille * 2;
	Personnel** nouveauTab = new Personnel*[nouvelleTaille];
	for (int i = 0; i < taille; i++)
	{
		nouveauTab[i] = tab[i];
	}

	delete[] tab;
	tab = nouveauTab;
	taille = nouvelleTaille;
}

