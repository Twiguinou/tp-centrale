#include <cstdlib>
#include <iostream>

#include "Point.h"

int main()
{
	{
		Point pz;
		Point p(1.2f, 3.0f, 4.0f);
		p.afficher();
		p.set();
		p.afficher();

		std::cout << Point::getInstanceCount() << std::endl;
	}

	std::cout << Point::getInstanceCount() << std::endl;

	return EXIT_SUCCESS;
}

