#ifndef _POINT_H_
#define _POINT_H_

#include <cstdint>

class Point
{
private:
	float _x, _y, _z;

public:
	Point(float x, float y, float z);
	Point();
	Point(const Point& point);
	Point(float xyz);
	~Point();

	float x() const;
	void x(float x);

	float y() const;
	void y(float y);

	float z() const;
	void z(float z);

	void set();

	void afficher() const;

	void translate(float x, float y, float z);

	float distanceTo(const Point& point) const;

	static uint64_t getInstanceCount();
};

#endif

