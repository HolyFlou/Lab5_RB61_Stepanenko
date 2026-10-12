#include <windows.h>

#include "funcs.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    // Оголошення змінних
    double x1, x2, delta;
    unsigned int N;
    char group[20] = "";
    char name[100] = "";

    FILE* input_data_file;

    if((input_data_file = fopen("Texts/input_data.txt", "r")) != 0) {
        fscanf(input_data_file, "%lf", &x1);
        fscanf(input_data_file, "%lf", &x2);
        fscanf(input_data_file, "%u", &N);
        fscanf(input_data_file, "%lf", &delta);
        fscanf(input_data_file, "%s", &group);
        fscanf(input_data_file, "%[^\r\n]", name);

        fclose(input_data_file);
    } else {
        printf("Error! File cannot be opened 1");
        return 0;
    }

    printf("x1: %f\n", x1);
    printf("x2: %f\n", x2);
    printf("N: %u\n", N);
    printf("delta: %f\n", delta);
    printf("Group: %s\n", group);
    printf("Name: %s\n", name);
    
    return 0;
}