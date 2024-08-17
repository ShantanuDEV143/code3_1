#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else if (a==0 ){
    return b;
    }
    else
        return gcd(b, a % b);
}

int main() {
    char src_filename[100], dst_filename[100];

    printf("Enter the source file name: ");
    scanf("%s", src_filename);

    printf("Enter the destination file name: ");
    scanf("%s", dst_filename);

    FILE *src_file = fopen(src_filename, "r");
    if (src_file == NULL) {
        printf("Error opening source file: %s\n", src_filename);
        return 1;
    }

    FILE *dst_file = fopen(dst_filename, "w");
    if (dst_file == NULL) {
        printf("Error opening destination file: %s\n", dst_filename);
        fclose(src_file);
        return 1;
    }

    int num1, num2;

    while (fscanf(src_file, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        
        fprintf(dst_file, "GCD of %d and %d is: %d\n", num1, num2, result);
    }

    fclose(src_file);
    fclose(dst_file);

    return 0;
}