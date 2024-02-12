// Task_2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#define _CRT_SECURE_NO_WARNINGS // protection against buffer overflow error "warning C4996"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fun(float x);

#include "integral_trapeze.h"
#include "integral_simpson.h"
#include "integral_rectangular.h"

float fun(float x) // f(x) = 1/x^2
{
    return 1 / (x * x);
}

float analytic_integral(float x)
{
    return -1 / x;
}
 
int main(int)
{
    float a, b, resume_num_rectangular, resume_num_trapeze, resume_num_simpson, resume_analytic;
    float error_rectangular, error_trapeze, error_simpson, h;

    FILE* save_file;
    save_file = fopen("Rectangular.txt", "wt");
    printf("Give the limit of the integration interval: a, b\n");
    scanf("%f %f", &a, &b);
    
    int i, n;
    n = 1;
    for (i = 0; i < 8; i++)
    {
        n = 2 * n;
        h = (b - a) / n;

        resume_num_rectangular = rectangular(a, b, n);
        resume_num_trapeze = trapeze(a, b, n);
        resume_num_simpson = simpson(a, b, n);
        resume_analytic = analytic_integral(b) - analytic_integral(a);

        error_rectangular = fabs(resume_num_rectangular - resume_analytic);
        error_trapeze = fabs(resume_num_trapeze - resume_analytic);
        error_simpson = fabs(resume_num_simpson - resume_analytic);

        fprintf(save_file, "%f %f %f %f\n", error_rectangular, error_trapeze, error_simpson, h);
        printf("%f %f %f %f\n", error_rectangular, error_trapeze, error_simpson, h);
    }
    fclose(save_file);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
