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
    FILE* output_file;
    FILE* bin_file;

    if((input_data_file = fopen("Texts/input_data.txt", "r")) != 0) {
        fscanf(input_data_file, "%lf", &x1);
        fscanf(input_data_file, "%lf", &x2);
        fscanf(input_data_file, "%u", &N);
        fscanf(input_data_file, "%lf", &delta);
        fscanf(input_data_file, "%s", &group);
        fscanf(input_data_file, " %[^\r\n]", name);

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

    if((output_file = fopen("Texts/output_data.txt", "w+")) != 0) {
        fprintf(output_file, "%s", make_table(x1, x2, N, delta));
        fprintf(output_file, "Group: %s\n", group);
        fprintf(output_file, "Name: %s\n", name);
        fclose(output_file);
    } else {
        printf("Error! File cannot be opened 2");
        return 0;
    }

    if((bin_file = fopen("Texts/bin_file.bin", "wb")) != 0) {
        fwrite(&N, sizeof(unsigned int), 1, bin_file);

        
        for (unsigned int j = 0; j < N; j++) {
            double func = pow(x1, 2);
            if (x1 > x2) break;
            fwrite(&x1, sizeof(double), 1, bin_file);
            fwrite(&func, sizeof(double), 1, bin_file);
            x1 += delta;
        }
        fclose(bin_file);
    } else {
        printf("Error! File cannot be opened 3");
        return 0;
    }
    
    if ((bin_file = fopen("Texts/bin_file.bin", "rb")) != NULL) {
        unsigned int check_N;
        
        fread(&check_N, sizeof(unsigned int), 1, bin_file);

        double* dynamic_array = (double*)malloc(2 * check_N * sizeof(double));
        
        if (dynamic_array != NULL) {
            
            fread(dynamic_array, sizeof(double), 2 * check_N, bin_file);
            
            printf("\nДані з бінарного файлу (динамічний масив)\n");
            
            printf("%12s | %20s | %20s\n", "Номер точки", "Значення аргументу", "Значення функції");
            
            for (unsigned int j = 0; j < check_N; j++) {
                double x = dynamic_array[2 * j];
                double fx = dynamic_array[2 * j + 1];

                printf("%12u | %20.4f | %20.4f\n", j + 1, x, fx);
            }
            
            free(dynamic_array);
            
        } else {
            printf("Помилка! Не вдалося виділити пам'ять для масиву.\n");
        }
        
        fclose(bin_file);
    } else {
        printf("Error! File cannot be opened 4\n");
    }
    
    return 0;
}