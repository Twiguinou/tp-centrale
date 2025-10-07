#include "ArrayOfInteger.h"

#include <cstring>
#include <iostream>

static uint64_t instanceCount = 0;

ArrayOfInteger::ArrayOfInteger() : size(0), capacity(0), elements(nullptr)
{
	++instanceCount;
}

ArrayOfInteger::ArrayOfInteger(const ArrayOfInteger& array)
: size(array.size), capacity(array.size), elements(new int[capacity])
{
	std::memcpy(elements, array.elements, size * sizeof(int));
	++instanceCount;
}

ArrayOfInteger::~ArrayOfInteger()
{
	delete[] elements;
	--instanceCount;
}

void ArrayOfInteger::afficher() const
{
	std::cout << "ArrayOfInteger[" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << elements[i] << std::endl;
	}

	std::cout << "]" << std::endl;
}

bool ArrayOfInteger::contient(int value) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (elements[i] == value)
		{
			return true;
		}
	}

	return false;
}

void ArrayOfInteger::retirer(int value)
{
	for (size_t i = 0; i < size; i++)
	{
		if (elements[i] != value)
		{
			continue;
		}

		if (i + 1 < size)
		{
			elements[i] = elements[size - 1];
		}

		--size;
		break;
	}
}

void ArrayOfInteger::ajouter(int value)
{
	if (contient(value))
	{
		return;
	}

	if (size == capacity)
	{
		capacity = capacity == 0 ? 1 : capacity * 2;
		int* newElements = new int[capacity];
		std::memcpy(newElements, elements, size * sizeof(int));
		delete[] elements;
		elements = newElements;
	}

	elements[size] = value;
	++size;
}

bool ArrayOfInteger::equals(const ArrayOfInteger& array) const
{
	if (size != array.size)
	{
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (!array.contient(elements[i]))
		{
			return false;
		}
	}

	return true;
}

uint64_t ArrayOfInteger::getInstanceCount()
{
	return instanceCount;
}

