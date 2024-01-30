#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"

int main(void)
{
	// Declaration of variables 
	// int i, l_row;  // i - for loop, l_row from *.*dat

	// *ax, *ay, *az - accelerations
	// sr_ax, sr_ay, sr_az - average accelerations
	// float *t, *ax, *ay, *az, temp, sr_ax, sr_ay, sr_az;

	// File declaration and opening
	FILE* dane, * wyniki;
	dane = fopen("dane.dat", "rt");
	if (!dane)
	{
		printf("Data.dat file missing\n");
		exit(0);
	}
	wyniki = fopen("results.dat", "wt");


}