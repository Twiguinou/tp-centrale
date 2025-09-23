#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
	uint32_t n, m;
	uint64_t* elements;
} matrix_t;

matrix_t* creer_matrice(uint32_t n, uint32_t m)
{
	if (n == 0 || m == 0)
	{
		return NULL;
	}

	matrix_t* mtx = (matrix_t*) malloc(sizeof(matrix_t));
	if (!mtx)
	{
		return NULL;
	}

	mtx->n = n;
	mtx->m = m;
	mtx->elements = (uint64_t*) calloc(n * m, sizeof(uint64_t));
	if (!mtx->elements)
	{
		free(mtx);
		return NULL;
	}

	return mtx;
}

void liberer_matrice(matrix_t* mtx)
{
	if (mtx)
	{
		free(mtx->elements);
		free(mtx);
	}
}

size_t matrix_index(matrix_t* mtx, uint32_t i, uint32_t j)
{
	return i * mtx->m + j;
}

matrix_t* SaisirMatrice(void)
{
	uint32_t n, m;
	printf("Nombre de lignes: ");
	if (scanf("%u", &n) != 1)
	{
		return NULL;
	}

	printf("Nombre de colonnes: ");
	if (scanf("%u", &m) != 1)
	{
		return NULL;
	}

	matrix_t* mtx = creer_matrice(n, m);
	if (!mtx)
	{
		return NULL;
	}

	for (uint32_t i = 0; i < n; i++)
	{
		for (uint32_t j = 0; j < m; j++)
		{
			printf("Coefficient (%u,%u): ", i, j);
			if (scanf("%u", &mtx->elements[matrix_index(mtx, i, j)]) != 1)
			{
				liberer_matrice(mtx);
				return NULL;
			}
		}
	}

	return mtx;
}

void AfficherMatrice(matrix_t* mtx)
{
	if (!mtx)
	{
		return;
	}

	for (uint32_t i = 0; i < mtx->n; i++)
	{
		for (uint32_t j = 0; j < mtx->m; j++)
		{
			printf("%u ", mtx->elements[matrix_index(mtx, i, j)]);
		}

		printf("\n");
	}
}

uint64_t max(uint64_t a, uint64_t b)
{
	return a > b ? a : b;
}

uint64_t min(uint64_t a, uint64_t b)
{
	return a < b ? a : b;
}

matrix_t* MaxLigne(matrix_t* mtx)
{
	if (!mtx)
	{
		return NULL;
	}

	matrix_t* MaxLig = creer_matrice(mtx->n, mtx->m);
	if (!MaxLig)
	{
		return NULL;
	}

	uint64_t ligneMaxs[mtx->n];
	for (uint32_t i = 0; i < mtx->n; i++)
	{
		ligneMaxs[i] = 0;
		for (uint32_t j = 0; j < mtx->m; j++)
		{
			ligneMaxs[i] = max(ligneMaxs[i], mtx->elements[matrix_index(mtx, i, j)]);
		}
	}

	for (uint32_t i = 0; i < mtx->n; i++)
	{
		for (uint32_t j = 0; j < mtx->m; j++)
		{
			uint32_t index = matrix_index(mtx, i, j);
			MaxLig->elements[index] = mtx->elements[index] == ligneMaxs[i] ? 1 : 0;
		}
	}

	return MaxLig;
}

matrix_t* MinColonne(matrix_t* mtx)
{
	if (!mtx)
	{
		return NULL;
	}

	matrix_t* MinCol = creer_matrice(mtx->n, mtx->m);
	if (!MinCol)
	{
		return NULL;
	}

	uint64_t colonneMins[mtx->m];
	for (uint32_t j = 0; j < mtx->m; j++)
	{
		colonneMins[j] = UINT64_MAX;
		for (uint32_t i = 0; i < mtx->n; i++)
		{
			colonneMins[j] = min(colonneMins[j], mtx->elements[matrix_index(mtx, i, j)]);
		}
	}

	for (uint32_t i = 0; i < mtx->n; i++)
	{
		for (uint32_t j = 0; j < mtx->m; j++)
		{
			uint32_t index = matrix_index(mtx, i, j);
			MinCol->elements[index] = mtx->elements[index] == colonneMins[j] ? 1 : 0;
		}
	}

	return MinCol;
}

void TrouvePointsClos(matrix_t* mtx)
{
	if (!mtx)
	{
		return;
	}

	matrix_t* MaxLig = MaxLigne(mtx);
	if (!MaxLig)
	{
		return;
	}

	matrix_t* MinCol = MinColonne(mtx);
	if (!MinCol)
	{
		free(MaxLig);
		return;
	}

	for (uint32_t i = 0; i < mtx->n; i++)
	{
		for (uint32_t j = 0; j < mtx->m; j++)
		{
			uint32_t index = matrix_index(mtx, i, j);
			if (MaxLig->elements[index] == 1 && MinCol->elements[index] == 1)
			{
				printf("Point clos (%u,%u): %u\n", i, j, mtx->elements[index]);
			}
		}
	}

	free(MaxLig);
	free(MinCol);
}

int main(void)
{
	matrix_t* m = SaisirMatrice();
	TrouvePointsClos(m);
	liberer_matrice(m);

	return EXIT_SUCCESS;
}
