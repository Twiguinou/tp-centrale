#ifndef _AGENDA_H_
#define _AGENDA_H_

#include "NoeudRDV.h"

class Agenda
{
private:
	NoeudRDV* premier;

public:
	Agenda();
	Agenda(const Agenda&);
	~Agenda();

	void ajoute(RDV& r);
	void enleve();

	void affiche() const;
};

#endif

