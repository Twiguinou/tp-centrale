#include <iostream>
#include <cstdlib>

template<class T, class U> void fct(T a, U b)
{
	std::cout << "je suis la fonction 1" << std::endl;
}

template<class T, class U> void fct(T* a, U b)
{
	std::cout << "je suis la fonction 2" << std::endl;
}

template<class T> void fct(T, T, T)
{
	std::cout << "je suis la fonction 3" << std::endl;
}

void fct(int a, float b)
{
	std::cout << "je suis la fonction 4" << std::endl;
}

int main(void)
{
	int n = 0, p = 0, q = 0;
	float x = 0.0f, y = 0.0f;
	double z = 0.0;

	std::cout << "fct (n, p) ;";
	fct(n, p);

	std::cout << "fct (x, y) ;";
	fct(x, y);

	std::cout << "fct (n, x) ;";
	fct(n, x);

	std::cout << "fct (n, z) ;";
	fct(n, z);

	std::cout << "fct (&n, p) ;";
	fct(&n, p);

	std::cout << "fct (&n, x) ;";
	fct(&n, x);

	std::cout << "fct (&n, &p, &q) ;";
	fct(&n, &p, &q);

	return EXIT_SUCCESS;
}

