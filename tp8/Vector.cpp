#include "Vector.h"

static uint64_t instanceCount = 0;

Vector::Vector(int taille)
: elements(new double[taille]), _taille(taille)
{
	++instanceCount;
}

Vector::Vector(double x)
: elements(new double[1] {x}), _taille(1)
{
	++instanceCount;
}

Vector::Vector(double x, double y)
: elements(new double[2] {x, y}), _taille(2)
{
	++instanceCount;
}

Vector::Vector(double x, double y, double z)
: elements(new double[3] {x, y, z}), _taille(3)
{
	++instanceCount;
}

Vector::Vector(double x, double y, double z, double w)
: elements(new double[4] {x, y, z, w}), _taille(4)
{
	++instanceCount;
}

Vector::~Vector()
{
	delete[] elements;
	--instanceCount;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "Vector[" << std::endl;
	for (int i = 0; i < v._taille; i++)
	{
		os << "x" << i << "=" << v.elements[i] << std::endl;
	}

	os << "]";
	return os;
}

Vector* operator+(const Vector& v1, const Vector& v2)
{
	Vector* r = new Vector(v1._taille);
	for (int i = 0; i < r->_taille; i++)
	{
		r->elements[i] = v1.elements[i] + v2.elements[i];
	}

	return r;
}

Vector& Vector::operator=(const Vector& v)
{
	if (_taille != v._taille)
	{
		delete[] elements;
		elements = new double[v._taille];
		_taille = v._taille;
	}

	for (int i = 0; i < _taille; i++)
	{
		elements[i] = v.elements[i];
	}

	return *this;
}

double operator*(const Vector& v1, const Vector& v2)
{
	double s = 0.0;
	for (int i = 0; i < v1._taille; i++)
	{
		s += v1.elements[i] * v2.elements[i];
	}

	return s;
}

Vector* operator*(const Vector& v, double s)
{
	Vector* r = new Vector(v._taille);
	for (int i = 0; i < r->_taille; i++)
	{
		r->elements[i] = v.elements[i] * s;
	}

	return r;
}

Vector* operator*(double s, const Vector& v)
{
	return v * s;
}

Vector& Vector::operator+=(const Vector& v)
{
	for (int i = 0; i < _taille; i++)
	{
		elements[i] += v.elements[i];
	}

	return *this;
}

bool Vector::operator==(const Vector& v) const
{
	if (_taille != v._taille)
	{
		return false;
	}

	for (int i = 0; i < _taille; i++)
	{
		if (elements[i] != v.elements[i])
		{
			return false;
		}
	}

	return true;
}

bool Vector::operator!=(const Vector& v) const
{
	return !(*this == v);
}

uint64_t Vector::getInstanceCount()
{
	return instanceCount;
}

