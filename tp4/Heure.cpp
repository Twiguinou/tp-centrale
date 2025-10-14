#include "Heure.h"

#include <iostream>

Heure::Heure(unsigned int heure, unsigned int minute)
{
	if (checkHeure(heure, minute))
	{
		_heure = heure;
		_minute = minute;
	}
	else
	{
		_heure = 0;
		_minute = 0;
	}
}

static bool _checkHeure(unsigned int heure)
{
	return 0 <= heure && heure < 24;
}

unsigned int Heure::heure() const
{
	return _heure;
}

void Heure::heure(unsigned int heure)
{
	if (_checkHeure(heure))
	{
		_heure = heure;
	}
}

static bool _checkMinute(unsigned int minute)
{
	return 0 <= minute && minute < 60;
}

unsigned int Heure::minute() const
{
	return _minute;
}

void Heure::minute(unsigned int minute)
{
	if (_checkMinute(minute))
	{
		_minute = minute;
	}
}

void Heure::affiche() const
{
	std::cout << "Heure[heure=" << _heure << ", minute=" << _minute << "]" << std::endl;
}

bool Heure::estEgal(const Heure& h) const
{
	return _heure == h._heure && _minute == h._minute;
}

bool Heure::estSuperieur(const Heure& h) const
{
	return _heure > h._heure || (_heure == h._heure && _minute >= h._minute);
}

bool Heure::checkHeure(unsigned int heure, unsigned int minute)
{
	return _checkHeure(heure) && _checkMinute(minute);
}

