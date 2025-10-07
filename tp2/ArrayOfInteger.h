#ifndef _ARRAY_OF_INTEGER_H_
#define _ARRAY_OF_INTEGER_H_

#include <cstddef>
#include <cstdint>

class ArrayOfInteger
{
private:
	int* elements;
	size_t capacity;
	size_t size;

public:
	ArrayOfInteger();
	ArrayOfInteger(const ArrayOfInteger& array);
	~ArrayOfInteger();
	
	void afficher() const;

	bool contient(int value) const;

	void retirer(int value);

	void ajouter(int value);

	bool equals(const ArrayOfInteger& array) const;

	static uint64_t getInstanceCount();
};

#endif

