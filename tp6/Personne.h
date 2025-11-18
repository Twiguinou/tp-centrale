#ifndef _PERSONNE_H_
#define _PERSONNE_H_

#include <string>

class Personne
{
private:
	std::string _nom;
	std::string _prenom;
	std::string _adresse;
	std::string _telephone;

public:
	Personne(const std::string& nom, const std::string& prenom,
		 const std::string& adresse="", const std::string& telephone="");

	virtual void affiche() const;

	const std::string& getNom() const;

	void setNom(const std::string& nom);

	const std::string& getPrenom() const;

	void setPrenom(const std::string& prenom);

	const std::string& getAdresse() const;

	void setAdresse(const std::string& adresse);

	const std::string& getTelephone() const;

	void setTelephone(const std::string& telephone);
};

#endif

