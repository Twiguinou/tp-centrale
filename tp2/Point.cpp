#include "Point.h"

#include <iostream>
#include <cmath>

static uint64_t instanceCount = 0;

Point::Point(float x, float y, float z) : _x(x), _y(y), _z(z)
{
	++instanceCount;
}

Point::Point() : Point(0.0f) {}

Point::Point(const Point& point) : Point(point.x(), point.y(), point.z()) {}

Point::Point(float xyz) : Point(xyz, xyz, xyz) {}

Point::~Point()
{
	--instanceCount;
}

float Point::x() const
{
	return _x;
}

void Point::x(float x)
{
	_x = x;
}

float Point::y() const
{
	return _y;
}

void Point::y(float y)
{
	_y = y;
}

float Point::z() const
{
	return _z;
}

void Point::z(float z)
{
	_z = z;
}

void Point::set()
{
	std::cout << "X: ";
	std::cin >> _x;
	std::cout << "Y: ";
	std::cin >> _y;
	std::cout << "Z: ";
	std::cin >> _z;
}

void Point::afficher() const
{
	std::cout << "Point[x=" << x() << ",y=" << y() << ",z=" << z() << "]" << std::endl;
}

void Point::translate(float x, float y, float z)
{
	_x += x;
	_y += y;
	_z += z;
}

float Point::distanceTo(const Point& point) const
{
	return sqrt(x() * point.x() + y() * point.y() + z() * point.z());
}

uint64_t Point::getInstanceCount()
{
	return instanceCount;
}

