#include "EnseignantPermanent.h"

#include <iostream>

EnseignantPermanent::EnseignantPermanent(const std::string& nom, const std::string& prenom, float salaire,
			    		 const std::string& bureau, int grade, float primeMensuelle,
			    		 const std::string& adresse, const std::string& telephone)
: Personnel(nom, prenom, salaire, adresse, telephone), _bureau(bureau), _grade(grade), _primeMensuelle(primeMensuelle) {}

float EnseignantPermanent::calculSalaire() const
{
	return getSalaire() + getGrade() * getPrimeMensuelle() / 100;
}

const std::string& EnseignantPermanent::getBureau() const
{
	return _bureau;
}

void EnseignantPermanent::setBureau(const std::string& bureau)
{
	_bureau = bureau;
}

int EnseignantPermanent::getGrade() const
{
	return _grade;
}

void EnseignantPermanent::setGrade(int grade)
{
	_grade = grade;
}

float EnseignantPermanent::getPrimeMensuelle() const
{
	return _primeMensuelle;
}

void EnseignantPermanent::setPrimeMensuelle(float primeMensuelle)
{
	_primeMensuelle = primeMensuelle;
}

void EnseignantPermanent::affiche() const
{
	std::cout << "EnseignantPermanent[" << std::endl;
	Personnel::affiche();
	std::cout << "bureau=" << getBureau() << std::endl;
	std::cout << "grade=" << getGrade() << std::endl;
	std::cout << "primeMensuelle=" << getPrimeMensuelle() << std::endl;
	std::cout << "]" << std::endl;
}

