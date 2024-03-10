#pragma once
float rectangular(float a, float b, int n)
{
	float h, suma, x;
	int i;

	h = (b - a) / n;
	suma = 0;

	for (i = 0; i < n; i++)
	{
		x = a + i * h;
		suma += h * fun(x);
	}

	return suma;
}
