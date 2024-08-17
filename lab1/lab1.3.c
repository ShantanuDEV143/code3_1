#include <stdio.h>


void count_duplicates_and_find_most_repeating(int arr[], int n) {
    int count_dict[100] = {0}; 
    int max_count = 0;
    int most_repeating = -1;
    int duplicate_count = 0;

    
    for (int i = 0; i < n; i++) {
        count_dict[arr[i]]++;
    }

 
    for (int i = 0; i < 100; i++) {
        if (count_dict[i] > 1) {
            duplicate_count++;
        }
        if (count_dict[i] > max_count) {
            max_count = count_dict[i];
            most_repeating = i;
        }
    }

    printf("Total number of duplicate values = %d\n", duplicate_count);
    printf("The most repeating element in the array = %d\n", most_repeating);
}

int main() {
    int n;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    int arr[n];
    FILE *fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

   
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    count_duplicates_and_find_most_repeating(arr, n);

    return 0;
}