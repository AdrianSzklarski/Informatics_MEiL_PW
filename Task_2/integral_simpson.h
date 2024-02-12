#pragma once
float simpson(float a, float b, int n)
{
	float  h, suma, x;
	int i;

	if (!n % 2) n += 1; //zapewnienie aby n bylo parzyste

	h = (b - a) / n;
	suma = 0;

	for (i = 0; i < n; i += 2)
	{
		x = a + i * h;
		suma += h * (fun(x) + 4 * fun(x + h) + fun(x + 2 * h)) / 3;
	}

	return suma;
}