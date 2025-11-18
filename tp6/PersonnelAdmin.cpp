#include "PersonnelAdmin.h"

#include <iostream>

PersonnelAdmin::PersonnelAdmin(const std::string& nom, const std::string& prenom, float salaire, float taux,
			       const std::string& adresse, const std::string& telephone, int heuresSup)
: Personnel(nom, prenom, salaire, adresse, telephone), _heuresSup(heuresSup), _taux(taux) {}

float PersonnelAdmin::calculSalaire() const
{
	return getSalaire() + getTaux() * getHeuresSup();
}

int PersonnelAdmin::getHeuresSup() const
{
	return _heuresSup;
}

void PersonnelAdmin::setHeuresSup(int heuresSup)
{
	_heuresSup = heuresSup;
}

float PersonnelAdmin::getTaux() const
{
	return _taux;
}

void PersonnelAdmin::setTaux(float taux)
{
	_taux = taux;
}

void PersonnelAdmin::affiche() const
{
	std::cout << "PersonnelAdmin[" << std::endl;
	Personnel::affiche();
	std::cout << "heuresSup=" << getHeuresSup() << std::endl;
	std::cout << "taux=" << getTaux() << std::endl;
	std::cout << "]" << std::endl;
}

