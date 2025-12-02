#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstddef>
#include <type_traits>

template<class T>
class Vector
{
private:
	T* elements;
	std::size_t capacite;
	std::size_t taille;

public:
	Vector() : elements(nullptr), capacite(0), taille(0) {};
	~Vector()
	{
		vider();
		delete[] elements;
		capacite = 0;
	}

	std::size_t getTaille() const
	{
		return taille;
	}

	T& operator[](size_t i)
	{
		return elements[i];
	}

	void vider()
	{
		// Appel du destructeur sur chaque instance si besoin
		if constexpr (!std::is_trivially_destructible<T>())
		{
			for (size_t i = 0; i < taille; i++)
			{
				elements[i].~T();
			}
		}

		taille = 0;
	}

	T& ajouter(const T& e)
	{
		if (taille == capacite)
		{
			capacite = capacite > 0 ? capacite * 2 : 1;
			T* nouveau = new T[capacite];
			for (size_t i = 0; i < taille; i++)
			{
				if constexpr (std::is_trivially_copyable<T>())
				{
					nouveau[i] = elements[i];
				}
				else
				{
					new(&nouveau[i]) T(elements[i]);
				}

				if constexpr (!std::is_trivially_destructible<T>())
				{
					elements[i].~T();
				}
			}

			delete[] elements;
			elements = nouveau;
		}

		if constexpr (std::is_trivially_copyable<T>())
		{
			elements[taille] = e;
		}
		else
		{
			new(&elements[taille]) T(e);
		}

		return elements[taille++];
	}

	void enlever(size_t i)
	{
		if (i < --taille)
		{
			elements[i] = elements[taille];
		}

		if constexpr (!std::is_trivially_destructible<T>())
		{
			elements[taille].~T();
		}
	}
};

#endif

