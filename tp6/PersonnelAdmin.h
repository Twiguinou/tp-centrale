#ifndef _PERSONNEL_ADMIN_H_
#define _PERSONNEL_ADMIN_H_

#include "Personnel.h"

class PersonnelAdmin : public Personnel
{
private:
	int _heuresSup;
	float _taux;

public:
	PersonnelAdmin(const std::string& nom, const std::string& prenom, float salaire, float taux,
		       const std::string& adresse="", const std::string& telephone="", int heuresSup=0);

	virtual float calculSalaire() const;

	int getHeuresSup() const;

	void setHeuresSup(int heuresSup);

	float getTaux() const;

	void setTaux(float taux);

	virtual void affiche() const;
};

#endif

