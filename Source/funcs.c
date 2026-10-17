#include "funcs.h"

char* make_table(double x1, double x2, unsigned int N, double delta)
{
    if (N < 2)
    {
        printf("Кількість точок повинна бути не менше 2!\n");
        return NULL;
    }

    char *result = malloc(4000);

    strcpy(result, "*********************************\n*      N   *     X   *   F(X)   *\n*********************************");

    for (unsigned int i = 1; i <= N; i++)
    {
        char temp[100];
        double func = pow(x1, 2);
        if (x1 > x2) break;

        strcat(result, "\n+----------+----------+----------+");
        sprintf(temp, "\n|%10u|%10.2lf|%10.2lf|", i, x1, func);
        strcat(result, temp);

        x1 += delta;
    }

    strcat(result, "\n+----------+----------+----------+\n");
    return result;
}