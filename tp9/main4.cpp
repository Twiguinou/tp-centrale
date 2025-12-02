#include "Vector.h"

#include <cstdlib>
#include <iostream>

int main(void)
{
	Vector<int> v;
	v.ajouter(3);
	v.ajouter(4);
	v.ajouter(-1);
	v.ajouter(54);
	v.enlever(v.getTaille() - 1);

	std::cout << "Vector<int> v=[" << std::endl;
	for (size_t i = 0; i < v.getTaille(); i++)
	{
		std::cout << v[i] << std::endl;
	}
	std::cout << "]" << std::endl;

	return EXIT_SUCCESS;
}

