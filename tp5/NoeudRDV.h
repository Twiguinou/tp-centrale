#ifndef _NOEUD_RDV_H_
#define _NOEUD_RDV_H_

#include <RDV.h>

class NoeudRDV
{
private:
	RDV& rdv;
	NoeudRDV* suivant;

public:
	NoeudRDV(RDV& info, NoeudRDV* s=nullptr);

	RDV& getRDV();

	void setRDV(RDV& info);

	NoeudRDV* getSuivant() const;

	void setSuivant(NoeudRDV* s);
};

#endif

