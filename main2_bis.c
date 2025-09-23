#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define N 2
typedef struct
{
	float elements[N][N];
} matrice_t;

matrice_t saisir(void)
{
	matrice_t m;
	for (uint32_t i = 0; i < N; i++)
	{
		for (uint32_t j = 0; j < N; j++)
		{
			printf("Coefficient (%u,%u): ", i, j);
			scanf("%f", &m.elements[i][j]);
		}
	}

	return m;
}

void afficher(matrice_t m)
{
	for (uint32_t i = 0; i < N; i++)
	{
		for (uint32_t j = 0; j < N; j++)
		{
			printf("%f ", m.elements[i][j]);
		}

		printf("\n");
	}
}

matrice_t additionner(matrice_t a, matrice_t b)
{
	matrice_t m;
	for (uint32_t i = 0; i < N; i++)
	{
		for (uint32_t j = 0; j < N; j++)
		{
			m.elements[i][j] = a.elements[i][j] + b.elements[i][j];
		}
	}

	return m;
}

matrice_t multiplier(matrice_t a, matrice_t b)
{
	matrice_t m;
	for (uint32_t i = 0; i < N; i++)
	{
		for (uint32_t j = 0; j < N; j++)
		{
			m.elements[i][j] = 0.0f;
			for (uint32_t k = 0; k < N; k++)
			{
				m.elements[i][j] += a.elements[i][k] * b.elements[k][j];
			}
		}
	}

	return m;
}

typedef enum
{
	ADDITION,
	MULTIPLICATION,
	NON_RECONNUE
} operation_t;

operation_t menu(void)
{
	printf("- Tapez 1 pour l'addition\n");
	printf("- Tapez 2 pour la multiplication\n");
	printf("Opération choisie: ");

	uint32_t opCode;
	scanf("%u", &opCode);
	switch(opCode)
	{
		case 1:
			return ADDITION;
		case 2:
			return MULTIPLICATION;
		default:
			printf("Opération non reconnue: %u\n", opCode);
			return NON_RECONNUE;
	};
}

int main(void)
{
	matrice_t a = saisir();
	matrice_t b = saisir();
	switch (menu())
	{
		case ADDITION:
			afficher(additionner(a, b));
			break;
		case MULTIPLICATION:
			afficher(multiplier(a, b));
			break;
		default:
			break;
	}

	return EXIT_SUCCESS;
}

