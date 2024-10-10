#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int ***MATRIX3D(int x,int y,int z)
{
	int ***arr  = new int **[x]();
	for (int i = 0; i < x; i++)
	{
		arr[i] = new int *[y]();
		for (int j = 0; j < y; j++)
		arr[i][j] = new int [z]();
	}
	return arr;
}





