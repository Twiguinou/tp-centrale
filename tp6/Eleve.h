#ifndef _ELEVE_H_
#define _ELEVE_H_

#include "Personne.h"

class Eleve : public Personne
{
private:
	std::string _promotion;
	std::string _groupeDeTD;
	float _GPA;

public:
	Eleve(const std::string& nom, const std::string& prenom,
	      const std::string& adresse="", const std::string& telephone="",
	      const std::string& promotion="", const std::string& groupeDeTD="", float GPA=0.0f);

	const std::string& getPromotion() const;

	void setPromotion(const std::string& promotion);

	const std::string& getGroupeDeTD() const;

	void setGroupeDeTD(const std::string& groupeDeTD);

	float getGPA() const;

	void setGPA(float GPA);

	virtual void affiche() const;
};

#endif

