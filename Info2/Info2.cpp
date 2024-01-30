#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "Average.h"

int main(void)
{
	// Declaration of variables 
	int i, l_row;  // i - for loop, l_row from *.*dat

	// *ax, *ay, *az - accelerations
	// sr_ax, sr_ay, sr_az - average accelerations
	float temp, * t, * ax, * ay, * az, sr_ax, sr_ay, sr_az;

	// File declaration and opening
	FILE* dane, *our_results;
	dane = fopen("dane.dat", "rt");
	if (!dane)
	{
		printf("Data.dat file missing\n");
		exit(0);
	}

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

	// Loading vectors and displaying them on the screen
	printf("t\t\t ax\t\t ay\t\t az\t\n");
	for (i = 0; i < l_row; i++)
	{
		fscanf(dane, "%f %f %f %f", &t[i], &ax[i], &ay[i], &az[i]);
		printf("%5.2f\t %5.2f\t %5.2f\t %5.2f\n", t[i] / 1000, ax[i], ay[i], az[i]);
	}
	// Closing the file
	fclose(dane);

	// Calculation of averages - calling the Average() function
	sr_ax = average(ax, l_row);
	sr_ay = average(ay, l_row);
	sr_az = average(az, l_row);

	// View averages and write to the resulting file
	our_results = fopen("results.dat", "wt");
	printf("Average acceleration ax=%f\n Average acceleration ay=%f\n Average acceleration az=%f\n", sr_ax, sr_ay, sr_az);
	fprintf(our_results, "%f\t %f\t %f\t", sr_ax, sr_ay, sr_az);


}