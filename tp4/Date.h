#ifndef _DATE_H_
#define _DATE_H_

class Date
{
private:
	unsigned int _jour;
	unsigned int _mois;
	unsigned int _annee;

	static bool checkDate(unsigned int j, unsigned int m, unsigned int a);

public:
	Date(unsigned int jour=1, unsigned int mois=1, unsigned int annee=2000);

	unsigned int jour() const;

	void jour(unsigned int jour);

	unsigned int mois() const;

	void mois(unsigned int mois);

	unsigned int annee() const;

	void annee(unsigned int annee);

	void affiche() const;

	bool estEgal(const Date& d) const;

	bool estSuperieur(const Date& d) const;
};

#endif

