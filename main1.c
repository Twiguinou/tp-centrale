#include <stdio.h>
#include <stdlib.h>

void exchange(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int a = 3, b = 2;
	printf("a=%d, b=%d\n", a, b);
	exchange(&a, &b);
	printf("a=%d, b=%d\n", a, b);

	return EXIT_SUCCESS;
}
