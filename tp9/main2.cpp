#include <cstdlib>
#include <iostream>

template<class T> T somme(T* elements, std::size_t taille)
{
	T resultat(0);
	for (size_t i = 0; i < taille; i++)
	{
		resultat += elements[i];
	}

	return resultat;
}

int main(void)
{
	float t1[3] = { 0.1f, 2.0f, -0.15f };
	std::cout << "t1={ 0.1, 2.0, -0.15 }, somme=" << somme(t1, 3) << std::endl;

	int t2[3] = { 1, 2, 3 };
	std::cout << "t2={ 1, 2, 3 }, somme=" << somme(t2, 3) << std::endl;

	char t3[6] = { 'k', 'h', 'a', 'l', 'i', 'l' };
	std::cout << "t3={ k, h, a, l, i, l }, somme=" << somme(t3, 6) << std::endl;

	return EXIT_SUCCESS;
}

