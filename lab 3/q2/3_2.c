#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Global variable to count the number of comparisons
long long comparison_count = 0;

// Function to generate random data and write to file
void generateRandomData(char *filename, int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", rand() % 1000);
    }

    fclose(file);
}

// Function to read data from a file
void readFile(char *filename, int arr[], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    *n = 0;
    while (fscanf(file, "%d", &arr[*n]) != EOF) {
        (*n)++;
    }

    fclose(file);
}

// Function to write data to a file
void writeFile(char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparison_count++;
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Function to implement quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Function to sort array in descending order
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n = 400; // number of random data points
    generateRandomData("inRand.dat", n);

    int arrRand[500];
    readFile("inRand.dat", arrRand, &n);

    int arrAsce[500];
    int arrDesc[500];
    for (int i = 0; i < n; i++) {
        arrAsce[i] = arrRand[i];
        arrDesc[i] = arrRand[i];
    }

    // Sort arrAsce in ascending order
    quickSort(arrAsce, 0, n - 1);

    // Sort arrDesc in descending order
    sortDescending(arrDesc, n);

    writeFile("inAsce.dat", arrAsce, n);
    writeFile("inDesc.dat", arrDesc, n);

    int choice;
    while (true) {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        int arr[500];
        char filename[20];
        comparison_count = 0;  // Reset comparison count before sorting

        switch (choice) {
            case 1:
                readFile("inAsce.dat", arr, &n);
                strcpy(filename, "outQuickAsce.dat");
                break;
            case 2:
                readFile("inDesc.dat", arr, &n);
                strcpy(filename, "outQuickDesc.dat");
                break;
            case 3:
                readFile("inRand.dat", arr, &n);
                strcpy(filename, "outQuickRand.dat");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                continue;
        }

        printf("Before Sorting: ");
        displayArray(arr, n);

        clock_t start_time = clock();
        quickSort(arr, 0, n - 1);
        clock_t end_time = clock();

        printf("After Sorting: ");
        displayArray(arr, n);

        printf("Number of Comparisons: %lld\n", comparison_count);
        printf("Execution Time: %ld nanoseconds\n", (end_time - start_time) * 1000000 / CLOCKS_PER_SEC);

        writeFile(filename, arr, n);
    }

    return 0;
}
