#include "EnseignantVacataire.h"

#include <iostream>

EnseignantVacataire::EnseignantVacataire(const std::string& nom, const std::string& prenom,
			    		 const std::string& casier, int nbreHeures, float taux,
			    		 const std::string& adresse, const std::string& telephone)
: Personne(nom, prenom, adresse, telephone), _casier(casier), _nbreHeures(nbreHeures), _taux(taux) {}

float EnseignantVacataire::calculSalaire() const
{
	return getTaux() * getNbreHeures();
}

const std::string& EnseignantVacataire::getCasier() const
{
	return _casier;
}

void EnseignantVacataire::setCasier(const std::string& casier)
{
	_casier = casier;
}

int EnseignantVacataire::getNbreHeures() const
{
	return _nbreHeures;
}

void EnseignantVacataire::setNbreHeures(int nbreHeures)
{
	_nbreHeures = nbreHeures;
}

float EnseignantVacataire::getTaux() const
{
	return _taux;
}

void EnseignantVacataire::setTaux(float taux)
{
	_taux = taux;
}

void EnseignantVacataire::affiche() const
{
	std::cout << "EnseignantVacataire[" << std::endl;
	Personne::affiche();
	std::cout << "casier=" << getCasier() << std::endl;
	std::cout << "nbreHeures=" << getNbreHeures() << std::endl;
	std::cout << "taux=" << getTaux() << std::endl;
	std::cout << "salaire=" << calculSalaire() << std::endl;
	std::cout << "]" << std::endl;
}

