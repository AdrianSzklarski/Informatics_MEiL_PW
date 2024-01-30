#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"

int main(void)
{
	// Declaration of variables 
	int i, l_row;  // i - for loop, l_row from *.*dat

	// *ax, *ay, *az - accelerations
	// sr_ax, sr_ay, sr_az - average accelerations
	float temp, *t, *ax, *ay, *az, sr_ax, sr_ay, sr_az;

	// File declaration and opening
	FILE* dane, * wyniki;
	dane = fopen("dane.dat", "rt");
	if (!dane)
	{
		printf("Data.dat file missing\n");
		exit(0);
	}
	wyniki = fopen("results.dat", "wt");

	// Calculating the number of elements and the number of rows in an input file
	i = 0;
	while (fscanf(dane, "%f", &temp) != EOF)
	{
		i++;
	}
	fclose(dane);
	l_row = i / 4;

	// Display the number of elements and the number of rows on the screen 
	printf("Number of elements in the file: %d\n", i);
	printf("Number of lines in the file   : %d\n", l_row);

	// Allocation (memory allocation) of vectors
	t = (float*)malloc(l_row * sizeof(float));
	ax = (float*)malloc(l_row * sizeof(float));
	ay = (float*)malloc(l_row * sizeof(float));
	az = (float*)malloc(l_row * sizeof(float));



}