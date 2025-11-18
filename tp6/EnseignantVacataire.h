#ifndef _ENSEIGNANT_VACATAIRE_H_
#define _ENSEIGNANT_VACATAIRE_H_

#include "Personne.h"

class EnseignantVacataire : public Personne
{
private:
	std::string _casier;
	int _nbreHeures;
	float _taux;

public:
	EnseignantVacataire(const std::string& nom, const std::string& prenom,
			    const std::string& casier, int nbreHeures, float taux,
			    const std::string& adresse="", const std::string& telephone="");

	virtual float calculSalaire() const;

	const std::string& getCasier() const;

	void setCasier(const std::string& casier);

	int getNbreHeures() const;

	void setNbreHeures(int nbreHeures);

	float getTaux() const;

	void setTaux(float taux);

	virtual void affiche() const;
};

#endif

