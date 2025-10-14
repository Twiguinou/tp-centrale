#include "NoeudRDV.h"

NoeudRDV::NoeudRDV(RDV& info, NoeudRDV* s): rdv(info), suivant(s) {}

RDV& NoeudRDV::getRDV()
{
	return rdv;
}

void NoeudRDV::setRDV(RDV& info)
{
	rdv = info;
}

NoeudRDV* NoeudRDV::getSuivant() const
{
	return suivant;
}

void NoeudRDV::setSuivant(NoeudRDV* s)
{
	suivant = s;
}

