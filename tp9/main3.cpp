#include <cstdlib>
#include <iostream>

template<class T> std::size_t minimum(T* elements, std::size_t taille)
{
	if (taille == 0)
	{
		return -1;
	}

	size_t indiceMin = 0;
	for (size_t i = 1; i < taille; i++)
	{
		if (elements[i] < elements[indiceMin])
		{
			indiceMin = i;
		}
	}

	return indiceMin;
}

enum class NumeroTableau
{
	T1,
	T2
};

struct emplacement
{
	NumeroTableau tableau;
	size_t indice;
};

template<class T, class U> emplacement minimum(T* t1, std::size_t taille1, U* t2, std::size_t taille2)
{
	std::size_t im1 = minimum(t1, taille1);
	std::size_t im2 = minimum(t2, taille2);

	if (im1 == -1 || (im2 != -1 && t1[im1] > t2[im2]))
	{
		return { .tableau = NumeroTableau::T2, .indice = im2 };
	}
	
	return { .tableau = NumeroTableau::T1, .indice = im1 };
}

int main(void)
{
	float t1[3] = { 0.1f, 2.0f, -0.15f };
	std::cout << "t1={ 0.1, 2.0, -0.15 }, indice_min=" << minimum(t1, 3) << std::endl;

	int t2[3] = { 1, 2, 3 };
	std::cout << "t2={ 1, 2, 3 }, indice_min=" << minimum(t2, 3) << std::endl;

	emplacement e = minimum(t1, 3, t2, 3);
	std::cout << "minimum(t1, t2)=" << e.indice << " dans ";
	switch (e.tableau)
	{
		case NumeroTableau::T1:
			std::cout << "t1";
			break;
		case NumeroTableau::T2:
			std::cout << "t2";
			break;
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

