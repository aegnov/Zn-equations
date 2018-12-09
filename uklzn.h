#ifndef UKLZN
#define UKLZN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//---------------------------------------------

typedef struct Matrix
{
	int *tab;
	int m;  //columns
	int n;  //rows
	int **fix;  //table with solutions
	int cFix;  //count of solutions

} Matrix;

//------------------------------------------------------

void multRow(Matrix *matrix, int iRow, int jOne, int n);

bool subRow(Matrix *matrix, int iRow, int jOne, int n);

void swapRow(Matrix *matrix, int i1, int i2);

void gauss(Matrix *matrix, int n);

//void findFix(Matrix *matrix, int n);

void fill(Matrix *matrix);

void randFill(Matrix *matrix, int n);

void print(int tab[], int m ,int n);

bool inconsistent(Matrix *matrix, int iRow);

int inverse(int b, int n);  //finds inverse for a figure in Zn

int min(int x, int y);

int mult(int a, int b, int n);

int add(int a, int b, int n);

int sub(int a, int b, int n);

//---------------------------------------------

#endif //UKLZN