#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdint>

class Vector
{
private:
	double* elements;
	int dimension;

public:
	Vector(int elementCount, double value=0.0);
	Vector();
	Vector(const Vector& v);
	~Vector();

	double getCoordinates(int index) const;
	void setCoordinates(int index, double value);

	void afficher() const;

	double norme() const;

	bool equals(const Vector& v) const;

	double dot(const Vector& v) const;

	void multiplier(double s);

	void ajouter(const Vector& v);

	static uint64_t getInstanceCount();
};

#endif

