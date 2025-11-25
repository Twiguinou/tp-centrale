#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <cstdint>

class Vector
{
private:
	double* elements;
	int _taille;

public:
	Vector(int taille=0);
	Vector(double x);
	Vector(double x, double y);
	Vector(double x, double y, double z);
	Vector(double x, double y, double z, double w);
	~Vector();

	friend std::ostream& operator<<(std::ostream& os, const Vector& v);

	friend Vector* operator+(const Vector& v1, const Vector& v2);

	Vector& operator=(const Vector& v);

	friend double operator*(const Vector& v1, const Vector& v2);

	friend Vector* operator*(const Vector& v, double s);

	friend Vector* operator*(double s, const Vector& v);

	Vector& operator+=(const Vector& v);

	bool operator==(const Vector& v) const;

	bool operator!=(const Vector& v) const;

	static uint64_t getInstanceCount();
};

#endif

