#ifndef _ENSEIGNANT_PERMANENT_H_
#define _ENSEIGNANT_PERMANENT_H_

#include "Personnel.h"

class EnseignantPermanent : public Personnel
{
private:
	std::string _bureau;
	int _grade;
	float _primeMensuelle;

public:
	EnseignantPermanent(const std::string& nom, const std::string& prenom, float salaire,
			    const std::string& bureau, int grade, float primeMensuelle,
			    const std::string& adresse="", const std::string& telephone="");

	virtual float calculSalaire() const;

	const std::string& getBureau() const;

	void setBureau(const std::string& bureau);

	int getGrade() const;

	void setGrade(int grade);

	float getPrimeMensuelle() const;

	void setPrimeMensuelle(float primeMensuelle);

	virtual void affiche() const;
};

#endif

