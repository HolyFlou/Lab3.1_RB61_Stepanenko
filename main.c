#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

// Прототип функції для першого варіанту
char* first_var(double x1, double x2, unsigned int N);

// Прототип функції для другого варіанту
void second_var(double x1, double x2, double delta);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    // Оголошення змінних
    double x1, x2, delta;
    unsigned int N, var;

    // Цикл для перевірки коректності введеного варіанту
    do
    {
        printf("\nОбрати варіант роботи програми:\n");
        printf("\t1. Перший варіант\n");
        printf("\t2. Другий варіант\n");

        scanf("%u", &var);

        if (var != 1 && var != 2)
        {
            printf("\nНеправильний варіант!\n");
        }
    } while (var != 1 && var != 2);

    // Створюємо оператор розгалуження для обробки 1 та 2 варіанту
    switch (var)
    {
        case 1:
            printf("Введіть початковий аргумент: ");
            scanf("%lf", &x1);

            printf("Введіть кінцевий аргумент: ");
            scanf("%lf", &x2);

            printf("Введіть кількість точок в таблиці: ");
            scanf("%u", &N);

            printf("%s", first_var(x1, x2, N));
            break;

        case 2:
            printf("Введіть початковий аргумент: ");
            scanf("%lf", &x1);

            printf("Введіть кінцевий аргумент: ");
            scanf("%lf", &x2);

            printf("Введіть крок зміни аргументу: ");
            scanf("%lf", &delta);

            second_var(x1, x2, delta);
            break;
    }
    
    return 0;
}

// Опис функції для першого варіанту
char* first_var(double x1, double x2, unsigned int N)
{
    if (N < 2)
    {
        printf("Кількість точок повинна бути не менше 2!\n");
        return NULL;
    }

    double delta = (x2 - x1) / (N - 1);

    char *result = malloc(4000);

    strcpy(result, "*********************************\n*      N   *     X   *   F(X)   *\n*********************************");

    for (unsigned int i = 1; i <= N; i++)
    {
        char temp[100];
        double func = pow(x1, 2);

        strcat(result, "\n+----------+----------+----------+");
        sprintf(temp, "\n|%10u|%10.2lf|%10.2lf|", i, x1, func);
        strcat(result, temp);

        x1 += delta;
    }

    strcat(result, "\n+----------+----------+----------+\n");
    return result;
}

// Опис функції для другого варіанту
void second_var(double x1, double x2, double delta)
{
    unsigned int N = (unsigned int)((x2 - x1) / delta + 1);

    char result[4000] = "*********************************\n*      N   *     X   *   F(X)   *\n*********************************";

    for (unsigned int i = 1; i <= N; i++)
    {
        char temp[100];

        double func = (x1 * x1 * x1) / 20 - 5 * (x1 * x1) + 1000;

        strcat(result, "\n+----------+----------+----------+");
        sprintf(temp, "\n|%10u|%10.2lf|%10.2lf|", i, x1, func);
        strcat(result, temp);

        x1 += delta;
    }

    strcat(result, "\n+----------+----------+----------+\n");
    printf("%s", result);
}