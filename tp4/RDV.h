#ifndef _RDV_H_
#define _RDV_H_

#include "Date.h"
#include "Heure.h"

#include <string>

class RDV
{
private:
	Date date;
	Heure heure;
	std::string lieu;
	int nbParticipants;
	std::string* participants;

public:
	RDV();
	~RDV();

	void affiche() const;

	void saisieParticipants();

	void saisieLieu();

	void saisie();

	void setDate(const Date& dateRdv);

	void setHeure(const Heure& heureRdv);

	void setLieu(const std::string& lieuRdv);

	void setNombreDeParticipants(int nombreDeParticipants);

	void setParticipants(std::string* ps);

	void setParticipant(int i, std::string s);

	bool estCompatibleAvec(RDV r) const;

	bool estEgal(const RDV& r) const;

	bool estSuperieur(const RDV& r) const;
};

#endif

