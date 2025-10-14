#include "Agenda.h"

#include <iostream>

Agenda::Agenda(): premier(nullptr) {}

Agenda::Agenda(const Agenda& agenda)
{
	if (!agenda.premier)
	{
		return;
	}

	premier = new NoeudRDV(agenda.premier->getRDV(), nullptr);
	NoeudRDV* rsv = premier;
	NoeudRDV* noeud = agenda.premier->getSuivant();
	while (noeud)
	{
		rsv->setSuivant(new NoeudRDV(noeud->getRDV(), nullptr));
		rsv = rsv->getSuivant();
		noeud = noeud->getSuivant();
	}
}

Agenda::~Agenda()
{
	NoeudRDV* noeud = premier;
	while (noeud)
	{
		NoeudRDV* tmp = noeud;
		noeud = noeud->getSuivant();
		delete tmp;
	}
}

void Agenda::ajoute(RDV& r)
{
	if (!premier || !r.estSuperieur(premier->getRDV()))
	{
		premier = new NoeudRDV(r, premier);
		return;
	}

	NoeudRDV* p = premier;
	while (p->getSuivant() && r.estSuperieur(p->getSuivant()->getRDV()))
	{
		p = p->getSuivant();
	}

	p->setSuivant(new NoeudRDV(r, p->getSuivant()));
}

void Agenda::enleve()
{
	NoeudRDV* tmp = premier;
	premier = tmp->getSuivant();
	delete tmp;
}

void Agenda::affiche() const
{
	std::cout << "Agenda[" << std::endl;
	NoeudRDV* noeud = premier;
	while (noeud)
	{
		noeud->getRDV().affiche();
		noeud = noeud->getSuivant();
	}

	std::cout << "]" << std::endl;
}

