#include <windows.h>

#include "funcs.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    // Оголошення змінних
    double x1, x2, delta;
    unsigned int N, var;

    printf("Введіть початковий аргумент: ");
    scanf("%lf", &x1);

    printf("Введіть кінцевий аргумент: ");
    scanf("%lf", &x2);

    printf("Введіть кількість точок в таблиці: ");
    scanf("%u", &N);

    printf("Введіть крок зміни аргументу: ");
    scanf("%lf", &delta);

    printf("%s", make_table(x1, x2, N, delta));
    
    return 0;
}