#ifndef _PERSONNEL_H_
#define _PERSONNEL_H_

#include "Personne.h"

class Personnel : public Personne
{
private:
	float _salaire;

public:
	Personnel(const std::string& nom, const std::string& prenom, float salaire,
		  const std::string& adresse="", const std::string& telephone="");

	virtual float calculSalaire() const = 0;
	
	float getSalaire() const;

	void setSalaire(float salaire);

	virtual void affiche() const;
};

#endif

