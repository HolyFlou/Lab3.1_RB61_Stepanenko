#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

char* first_var(double x1, double x2, unsigned int N);

void second_var(double x1, double x2, double delta);

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    double x1, x2, delta;
    unsigned int N, var;

    do
    {
        printf("\nОбрати варіант роботи програми:\n");
        printf("\t1. Перший варінт\n");
        printf("\t2. Другий варіант\n");

        scanf("%u", &var);

        if (var != 1 && var != 2)
        {
            printf("\nНеправильний варіант!\n");
        }
    } while (var != 1 && var != 2);

    switch (var)
    {
        case 1:
            printf("Введіть початковий аргумент: ");
            scanf("%lf", &x1);

            printf("Введіть кінцевий аргумент: ");
            scanf("%lf", &x2);

            printf("Введіть кількість точок в таблиці: ");
            scanf("%u", &N);

            //printf("%s", first_var(x1, x2, N));
            break;

        case 2:
            printf("Введіть початковий аргумент: ");
            scanf("%lf", &x1);

            printf("Введіть кінцевий аргумент: ");
            scanf("%lf", &x2);

            printf("Введіть крок зміни аргументу: ");
            scanf("%lf", &delta);

            //second_var(x1, x2, delta);
            break;
    }
    
    return 0;
}