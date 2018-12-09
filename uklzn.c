#include "uklzn.h"

//-----------------------------------------------------

int inverse(int b, int n)
{
	int a = n;
	int q, r;
	int y0, y1, y;

	if(b == 1) return b;
	
	y0 = 0;
	y1 = 1;
	q = a/b;
	r = a%b;

	while(r)
	{
		y = y0 - q*y1;
		y0 = y1;
		y1 = y;

		a = b;
		b = r;
		q = a/b;
		r = a%b;
	}

	if(y < 0) y = n + y;

	return y;
}

//----------------------------------------------------

void fill(Matrix *matrix)
{
	int i,j;

	puts("Fill the matrix:");

	for(i = 0; i < matrix -> m; i++)
	{
		printf("Row number %d:\n", i+1);

		for(j = 0; j< matrix -> n; j++)
		{
			scanf("%d", &matrix -> tab[i*matrix -> n + j]);
		}
	}
}

//-----------------------------------------------------

void print(int tab[], int m, int n)
{
	int i,j;

	puts("-------------------------------");

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d  ", tab[i*n + j]);
		}
		printf("\n");
	}

	puts("-------------------------------");
}

//------------------------------------------------------

void randFill(Matrix *matrix, int n)
{
	int i,j;

	srand(time(NULL));

	for(i = 0; i < matrix -> m; i++)
	{
		for(j = 0; j< matrix -> n; j++)
		{
			matrix -> tab[i*matrix -> n + j] = rand()%n;
		}
	}
}

//---------------------------------------------------------

void gauss(Matrix *matrix, int n)
{
	int iOne, jOne;
	int iStart = 0, jStart = 0;

	for(jOne = jStart; jOne < min(matrix -> m, matrix -> n - 1); jOne++)
	{
		iOne = iStart;

		while((iOne < matrix -> m) && (!matrix -> tab[iOne*(matrix -> n) + jOne]))
			iOne++;

		if(iOne == matrix -> m) continue;

		else
		{
			multRow(matrix, iOne, jOne, n);

			//print(matrix -> tab, matrix -> m, matrix -> n);

			if(!subRow(matrix, iOne, jOne, n)) break;

			//print(matrix -> tab, matrix -> m, matrix -> n);

			if(iOne != iStart) swapRow(matrix, iOne, iStart);

			iStart++;
			jStart++;
		}
	}

	if(jOne != min(matrix -> m, matrix -> n - 1))
	{
		puts("Ten uklad jest sprzeczny, przyjacielu. Sam zobacz:");
	}

	else 
	{
		puts("Oto postac wierszowo zredukowana macierzy twojego ukladu:");
	}
}

//---------------------------------------------------------------

void multRow(Matrix *matrix, int iRow, int jOne, int n)
{
	int j;
	int mltp;

	mltp = inverse(matrix -> tab[iRow*(matrix -> n) + jOne], n);

	for(j = 0; j < matrix -> n; j++)
	{
		matrix -> tab[iRow*(matrix -> n) + j] = 
			mult(matrix -> tab[iRow*(matrix -> n) + j], mltp, n);
	}
}
 //-------------------------------------------------------------

bool subRow(Matrix *matrix, int iRow, int jOne, int n)
{
	int i, j;
	int mltp;

	for(i = 0; i < matrix -> m; i++)
	{
		if(i != iRow)
		{
			mltp = matrix -> tab[i*(matrix -> n) + jOne];

			for(j = 0; j < matrix -> n; j++)
			{
				matrix -> tab[i*(matrix -> n) + j] = 
					sub(matrix -> tab[i*(matrix -> n) + j],
						mltp * matrix -> tab[iRow*(matrix -> n) + j], n);
			}

			if(inconsistent(matrix, i)) return false;
		}
	}

	return true;
}

//-------------------------------------------------------------

void swapRow(Matrix *matrix, int i1, int i2)
{
	int j, tmp;

	for(j = 0; j < matrix -> n; j++)
	{
		tmp = matrix -> tab[i1*(matrix -> n) + j];
		matrix -> tab[i1*(matrix -> n) + j] = matrix -> tab[i2*(matrix -> n) + j];
		matrix -> tab[i2*(matrix -> n) + j] = tmp;
	}
}

//--------------------------------------------------------------

int min(int x, int y)
{
	return (x > y) ? x : y;
}

//-------------------------------------------------------------

int mult(int a, int b, int n)
{
	return (a*b)%n;
}

//------------------------------------------------------------

int add(int a, int b, int n)
{
	return (a+b)%n;
}

//------------------------------------------------------------

int sub(int a, int b, int n)
{
	return (a + (n - b))%n;
}

//----------------------------------------------------------

bool inconsistent(Matrix *matrix, int iRow)
{
	int j;

	if(!matrix -> tab[(iRow + 1)*(matrix -> n) - 1]) return false;

	else 
	{
		for(j = 0; j < matrix -> n - 1; j++)
		{
			if(matrix -> tab[iRow*(matrix -> n) + j]) return false;
		}

		return true;
	}
}

//------------------------------------------------------------

/*void findFix(Matrix *matrix, int n)
{
	int cnZero = 0;
	int i, j;
	int parCount = matrix -> n - matrix -> n;  //liczba parametrow

	*(matrix -> fix) = (int**)malloc(parCount*sizeof(int*));

	if(*(malloc -> fix) == NULL)
	{
		puts("No memory available!");
		return;
	}

	for(i = 0; i < matrix -> m; i++)
	{
		for(j = 0; j< matrix -> n - 1; j++)
		{
			if(!matrix -> tab[i*(matrix -> n) + j]) cnZero++; 
		}

	}
}*/

