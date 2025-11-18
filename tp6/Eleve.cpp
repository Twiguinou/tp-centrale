#include "Eleve.h"

#include <iostream>

Eleve::Eleve(const std::string& nom, const std::string& prenom,
	     const std::string& adresse, const std::string& telephone,
	     const std::string& promotion, const std::string& groupeDeTD, float GPA)
: Personne(nom, prenom, adresse, telephone), _promotion(promotion), _groupeDeTD(groupeDeTD), _GPA(GPA) {}

const std::string& Eleve::getPromotion() const
{
	return _promotion;
}

void Eleve::setPromotion(const std::string& promotion)
{
	_promotion = promotion;
}

const std::string& Eleve::getGroupeDeTD() const
{
	return _groupeDeTD;
}

void Eleve::setGroupeDeTD(const std::string& groupeDeTD)
{
	_groupeDeTD = groupeDeTD;
}

float Eleve::getGPA() const
{
	return _GPA;
}

void Eleve::setGPA(float GPA)
{
	_GPA = GPA;
}

void Eleve::affiche() const
{
	std::cout << "Eleve[" << std::endl;
	Personne::affiche();
	std::cout << "promotion=" << getPromotion() << std::endl;
	std::cout << "groupeDeTD=" << getGroupeDeTD() << std::endl;
	std::cout << ", GPA=" << getGPA() << std::endl;
	std::cout << "]" << std::endl;
}

