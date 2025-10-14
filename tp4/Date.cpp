#include "Date.h"

#include <iostream>

Date::Date(unsigned int jour, unsigned int mois, unsigned int annee)
{
	if (checkDate(jour, mois, annee))
	{
		_jour = jour;
		_mois = mois;
		_annee = annee;
	}
	else
	{
		_jour = 1;
		_mois = 1;
		_annee = 2000;
	}
}

unsigned int Date::jour() const
{
	return _jour;
}

void Date::jour(unsigned int jour)
{
	if (1 <= jour && jour <= 31)
	{
		_jour = jour;
	}
}

unsigned int Date::mois() const
{
	return _mois;
}

void Date::mois(unsigned int mois)
{
	if (1 <= mois && mois <= 12)
	{
		_mois = mois;
	}
}

unsigned int Date::annee() const
{
	return _annee;
}

void Date::annee(unsigned int annee)
{
	if (2000 <= annee && annee <= 2050)
	{
		_annee = annee;
	}
}

void Date::affiche() const
{
	std::cout << "Date[jour=" << _jour << ", mois=" << _mois << ", annee=" << _annee << "]" << std::endl;
}

bool Date::estEgal(const Date& d) const
{
	return _jour == d._jour && _mois == d._mois && _annee == d._annee;
}

bool Date::estSuperieur(const Date& d) const
{
	return _annee > d._annee || (_annee == d._annee && (_mois > d._mois || (_mois == d._mois && _jour >= d._jour)));
}

bool Date::checkDate(unsigned int jour, unsigned int mois, unsigned int annee)
{
	return 1 <= jour && jour <= 31 && 1 <= mois && mois <= 12 && 2000 <= annee && annee <= 2050;
}

