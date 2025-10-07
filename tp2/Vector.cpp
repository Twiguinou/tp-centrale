#include "Vector.h"

#include <cstring>
#include <iostream>
#include <cmath>

static uint64_t instanceCount = 0;

Vector::Vector(int elementCount, double value)
: elements(new double[elementCount]), dimension(elementCount)
{
	for (int i = 0; i < dimension; i++)
	{
		elements[i] = value;
	}

	++instanceCount;
}

Vector::Vector() : Vector(0) {}

Vector::Vector(const Vector& v)
: elements(new double[v.dimension]), dimension(v.dimension)
{
	std::memcpy(elements, v.elements, dimension * sizeof(double));
	++instanceCount;
}

Vector::~Vector()
{
	delete[] elements;
	--instanceCount;
}

double Vector::getCoordinates(int index) const
{
	return elements[index];
}

void Vector::setCoordinates(int index, double value)
{
	elements[index] = value;
}

void Vector::afficher() const
{
	std::cout << "Vector[" << std::endl;
	for (int i = 0; i < dimension; i++)
	{
		std::cout << "    v" << i << "=" << getCoordinates(i) << std::endl;
	}

	std::cout << "]" << std::endl;
}

double Vector::norme() const
{
	return sqrt(dot(*this));
}

bool Vector::equals(const Vector& v) const
{
	if (dimension != v.dimension)
	{
		return false;
	}

	for (int i = 0; i < dimension; i++)
	{
		if (getCoordinates(i) != v.getCoordinates(i))
		{
			return false;
		}
	}

	return true;
}

double Vector::dot(const Vector& v) const
{
	if (dimension != v.dimension)
	{
		return 0.0;
	}

	double d = 0.0;
	for (int i = 0; i < dimension; i++)
	{
		d += getCoordinates(i) * v.getCoordinates(i);
	}

	return d;
}

void Vector::multiplier(double s)
{
	for (int i = 0; i < dimension; i++)
	{
		setCoordinates(i, getCoordinates(i) * s);
	}
}

void Vector::ajouter(const Vector& v)
{
	if (dimension != v.dimension)
	{
		return;
	}

	for (int i = 0; i < dimension; i++)
	{
		setCoordinates(i, getCoordinates(i) + v.getCoordinates(i));
	}
}

uint64_t Vector::getInstanceCount()
{
	return instanceCount;
}

