#include "uklzn.h"

int main()
{
	Matrix matrix;
	int n;

	printf("Rrozwiazujemy rownania w ciele Zn. Podaj n:");
	scanf("%d", &n);

	printf("Podaj liczbe rownan: ");
	scanf("%d", &matrix.m);

	printf("Podaj liczbe niewiadomych: ");
	scanf("%d", &matrix.n);

	matrix.n++;

	matrix.tab = (int*)malloc(matrix.m * matrix.n * sizeof(int));

	if(matrix.tab == NULL)
	{
		puts("No memory available!");
		return 1;
	}

	randFill(&matrix, n);
	
	print(matrix.tab, matrix.m, matrix.n);

	gauss(&matrix, n);

	//multRow(&matrix, 0, 0, n);

	//subRow(&matrix, 0, 0, n);

	print(matrix.tab, matrix.m, matrix.n);

	free(matrix.tab);

	return 0;
}
