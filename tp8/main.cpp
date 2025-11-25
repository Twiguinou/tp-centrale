#include "Vector.h"

#include <cstdlib>
#include <iostream>
#include <memory>

int main(void)
{
	Vector v1(1.0, 2.0);
	std::cout << "v1=" << v1 << std::endl << std::endl;
	Vector v2(0.0, 0.3);
	std::cout << "v2=" << v2 << std::endl << std::endl;

	std::shared_ptr<Vector> r(v1 + v2);

	std::cout << "v1*v2=" << v1 * v2 << std::endl;
	std::cout << "r=" << *r << std::endl;

	return EXIT_SUCCESS;
}

