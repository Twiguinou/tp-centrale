#include "Personnel.h"

#include <iostream>

Personnel::Personnel(const std::string& nom, const std::string& prenom, float salaire,
		     const std::string& adresse, const std::string& telephone)
: Personne(nom, prenom, adresse, telephone), _salaire(salaire) {}

float Personnel::getSalaire() const
{
	return _salaire;
}

void Personnel::setSalaire(float salaire)
{
	_salaire = salaire;
}

void Personnel::affiche() const
{
	std::cout << "Personnel[" << std::endl;
	Personne::affiche();
	std::cout << "salaire=" << getSalaire() << std::endl;
	std::cout << "salaireTotal=" << calculSalaire() << std::endl;
	std::cout << "]" << std::endl;
}

