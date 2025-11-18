#ifndef _LISTE_PERSONNEL_H_
#define _LISTE_PERSONNEL_H_

#include "Personnel.h"

class ListePersonnel
{
private:
	Personnel** tab;
	int nb, taille;

	void doubleTableau();

public:
	ListePersonnel();
	~ListePersonnel();

	void ajoutPersonnel(Personnel* ptPersonnel);

	void afficherSalaires() const;
};

#endif

