#pragma once
float trapeze(float a, float b, int n)
{
	float h, sum, x;
	int i;

	h = (b - a) / n;
	sum = 0;

	for (i = 0; i < n; i++)
	{
		x = a + i * h;
		sum += 0.5 * (fun(x) + fun(x + h)) * h;
	}

	return sum;
}