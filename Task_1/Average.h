#pragma once
float average(float* a, int l_elem)
{
	// Declaration of local variables
	float resume, sum;
	int i;

	// Calculation of the sum of all elements 
	sum = 0;
	for (i = 0; i < l_elem; i++)
	{
		sum = sum + a[i];
	}

	// Calculation of the average
	resume = sum / l_elem;

	// Return the value of the resulting variable to the main program 
	return resume;
}