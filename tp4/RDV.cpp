#include "RDV.h"

#include <iostream>

RDV::RDV(): nbParticipants(0), participants(new std::string[10]) {}

RDV::~RDV()
{
	delete[] participants;
}

void RDV::affiche() const
{
	std::cout << "RDV[" << std::endl;

	std::cout << "date=";
	date.affiche();

	std::cout << "heure=";
	heure.affiche();

	std::cout << "lieu=" << lieu << std::endl;
	std::cout << "nombreDeParticipants=" << nbParticipants << std::endl;

	std::cout << "participants={";
	for (int i = 0; i < nbParticipants; i++)
	{
		std::cout << std::endl << " " << participants[i];
	}
	std::cout << std::endl << "}" << std::endl;

	std::cout << std::endl;
}

void RDV::saisieParticipants()
{
	int nb;
	std::cout << "Nombre de participants: ";
	std::cin >> nb;
	if (nb < 0)
	{
		std::cout << "Le nombre de participants doit être positif." << std::endl;
		return;
	}

	if (nb > nbParticipants)
	{
		delete[] participants;
		participants = new std::string[nb];
	}

	nbParticipants = nb;
	for (int i = 0; i < nbParticipants; i++)
	{
		std::cout << "Participant n°" << (i + 1) << ": ";
		std::cin >> participants[i];
	}
}

void RDV::saisieLieu()
{
	std::cout << "Lieu: ";
	std::cin >> lieu;
}

void RDV::saisie()
{
	int jour, mois, annee;
	std::cout << "Date: ";
	std::cin >> jour >> mois >> annee;
	date = Date(jour, mois, annee);

	int h, m;
	std::cout << "Heure: ";
	std::cin >> h >> m;
	heure = Heure(h, m);

	saisieLieu();
	saisieParticipants();
}

void RDV::setDate(const Date& dateRdv)
{
	date = dateRdv;
}

void RDV::setHeure(const Heure& heureRdv)
{
	heure = heureRdv;
}

void RDV::setLieu(const std::string& lieuRdv)
{
	lieu = lieuRdv;
}

void RDV::setNombreDeParticipants(int nombreDeParticipants)
{
	if (nombreDeParticipants >= 0 && nombreDeParticipants <= nbParticipants)
	{
		nbParticipants = nombreDeParticipants;
	}
}

void RDV::setParticipants(std::string* ps)
{
	delete[] participants;
	participants = ps;
}

void RDV::setParticipant(int i, std::string s)
{
	if (i >= 0 && i < nbParticipants)
	{
		participants[i] = s;
	}
}

bool RDV::estCompatibleAvec(RDV r) const
{
	return !date.estEgal(r.date) || !heure.estEgal(r.heure);
}

bool RDV::estEgal(const RDV& r) const
{
	return date.estEgal(r.date) && heure.estEgal(r.heure);
}

bool RDV::estSuperieur(const RDV& r) const
{
	return date.estSuperieur(r.date) && (!date.estEgal(r.date) || heure.estSuperieur(r.heure));
}



