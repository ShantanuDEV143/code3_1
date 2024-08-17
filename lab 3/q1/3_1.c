#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variable to count the number of comparisons
long long comparison_count = 0;

// Function to merge two halves
void merge(int arr[], int left, int mid, int right, int order) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparison_count++;
        if (order == 1) { // ascending order
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        } else { // descending order
            if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right, int order) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, order);
        mergeSort(arr, mid + 1, right, order);

        merge(arr, left, mid, right, order);
    }
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

int main() {
    int arr[500];
    int n;

    // Read random data from inRand.dat
    readFile("inRand.dat", arr, &n);

    // Create copies of the array for ascending and descending order
    int arrAsce[500];
    int arrDesc[500];
    for (int i = 0; i < n; i++) {
        arrAsce[i] = arr[i];
        arrDesc[i] = arr[i];
    }

    // Write data to inAsce.dat and inDesc.dat
    writeFile("inAsce.dat", arrAsce, n);
    writeFile("inDesc.dat", arrDesc, n);

    // Perform merge sort on inAsce.dat and inDesc.dat
    comparison_count = 0;
    clock_t start_time = clock();
    mergeSort(arrAsce, 0, n - 1, 1); // ascending order
    clock_t end_time = clock();
    writeFile("outMergeAsce.dat", arrAsce, n);
    printf("Number of Comparisons (Ascending): %lld\n", comparison_count);
    printf("Execution Time (Ascending): %ld nanoseconds\n", (end_time - start_time) * 1000000 / CLOCKS_PER_SEC);
    comparison_count = 0;
    start_time = clock();
    mergeSort(arrDesc, 0, n - 1, 2); // descending order
    end_time = clock();
    writeFile("outMergeDesc.dat", arrDesc, n);
    printf("Number of Comparisons (Descending): %lld\n", comparison_count);
    printf("Execution Time (Descending): %ld nanoseconds\n", (end_time - start_time) * 1000000 / CLOCKS_PER_SEC);

    return 0;
}