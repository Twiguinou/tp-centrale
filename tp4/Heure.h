#ifndef _HEURE_H_
#define _HEURE_H_

class Heure
{
private:
	unsigned int _heure;
	unsigned int _minute;

	static bool checkHeure(unsigned int heure, unsigned int minute);

public:
	Heure(unsigned int heure=0, unsigned int minute=0);

	unsigned int heure() const;

	void heure(unsigned int heure);

	unsigned int minute() const;

	void minute(unsigned int minute);

	void affiche() const;
};

#endif

