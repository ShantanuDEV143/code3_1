#include <stdio.h>
#include <stdlib.h>

void decimal_to_binary(int num, FILE *binary_file) {
    if (num == 0) {
        fprintf(binary_file, "0");
        return;
    }

    decimal_to_binary(num / 2, binary_file);
    fprintf(binary_file, "%d", num % 2);
}

int main() {
    int n;
    char decimal_filename[100], binary_filename[100];

    printf("Enter the name of the decimal file: ");
    scanf("%s", decimal_filename);

    printf("Enter the name of the binary file: ");
    scanf("%s", binary_filename);

    printf("Enter the number of decimal numbers to convert: ");
    scanf("%d", &n);

    FILE *decimal_file = fopen(decimal_filename, "r");
    if (decimal_file == NULL) {
        printf("Error opening decimal file!\n");
        return 1;
    }

    FILE *binary_file = fopen(binary_filename, "w");
    if (binary_file == NULL) {
        printf("Error opening binary file!\n");
        return 1;
    }

    int num;
    for (int i = 0; i < n; i++) {
        fscanf(decimal_file, "%d", &num);
        decimal_to_binary(num, binary_file);
        fprintf(binary_file, "\n");
    }

    fclose(decimal_file);
    fclose(binary_file);

    printf("Conversion successful!\n");

    return 0;
}