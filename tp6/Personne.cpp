#include "Personne.h"

#include <iostream>

Personne::Personne(const std::string& nom, const std::string& prenom,
		   const std::string& adresse, const std::string& telephone)
: _nom(nom), _prenom(prenom), _adresse(adresse), _telephone(telephone) {}

void Personne::affiche() const
{
	std::cout << "Personne[nom=" << getNom() << ", prenom=" << getPrenom() << ", adresse=" << getAdresse() << ", telephone=" << getTelephone() << "]" << std::endl;
}

const std::string& Personne::getNom() const
{
	return _nom;
}

void Personne::setNom(const std::string& nom)
{
	_nom = nom;
}

const std::string& Personne::getPrenom() const
{
	return _prenom;
}

void Personne::setPrenom(const std::string& prenom)
{
	_prenom = prenom;
}

const std::string& Personne::getAdresse() const
{
	return _adresse;
}

void Personne::setAdresse(const std::string& adresse)
{
	_adresse = adresse;
}

const std::string& Personne::getTelephone() const
{
	return _telephone;
}

void Personne::setTelephone(const std::string& telephone)
{
	_telephone = telephone;
}

