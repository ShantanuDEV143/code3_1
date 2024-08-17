#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    int height;
    int weight;
} Person;

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(Person *arr, int n, int i, int (*compare)(Person, Person)) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < n && compare(arr[left], arr[smallest])) {
        smallest = left;
    }

    if (right < n && compare(arr[right], arr[smallest])) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyDown(arr, n, smallest, compare);
    }
}

int compareAge(Person a, Person b) {
    return a.age < b.age;
}

int compareWeight(Person a, Person b) {
    return a.weight > b.weight;
}

void createHeap(Person *arr, int n, int (*compare)(Person, Person)) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDown(arr, n, i, compare);
    }
}

void createMinHeap(Person *arr, int n) {
    createHeap(arr, n, compareAge);
}

void createMaxHeap(Person *arr, int n) {
    createHeap(arr, n, compareWeight);
}

void displayWeightOfYoungestPerson(Person *arr, int n) {
    if (n == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Weight of the youngest person: %.2f kg\n", arr[0].weight / 2.20462);
}

void displayWeightOfHeaviestPerson(Person *arr, int n) {
    if (n == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Weight of the heaviest person: %.2f kg\n", arr[0].weight / 2.20462);
}

int main() {
    Person *arr = (Person *)malloc(MAX_STUDENTS * sizeof(Person));
    int n = 0;
    int minHeapCreated = 0;
    int maxHeapCreated = 0;

    int choice;
    while (1) {
        printf("MAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Display weight of the heaviest person\n");
        printf("6. Insert a new person into the Min-heap\n");
        printf("7. Delete the oldest person\n");
        printf("8. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                FILE *file = fopen("data.txt", "r");
                if (file == NULL) {
                    printf("Error opening file\n");
                    break;
                }

                n = 0;
                while (fscanf(file, "%d %s %d %d %d", &arr[n].id, arr[n].name, &arr[n].age, &arr[n].height, &arr[n].weight) == 5) {
                    n++;
                }

                fclose(file);
                minHeapCreated = 0;
                maxHeapCreated = 0;
                if (n > 0) {
                    printf("Data read from file:\n");
                    for (int i = 0; i < n; i++) {
                        printf("ID: %d, Name: %s, Age: %d, Height: %d, Weight: %d\n",
                               arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
                    }
                } else {
                    printf("No data read from file. Ensure the file format is correct.\n");
                }
                break;
            }

            case 2:
                if (n > 0) {
                                        createMinHeap(arr, n);
                    minHeapCreated = 1;
                    printf("Min-heap created based on age.\n");
                } else {
                    printf("No data available. Please read data first.\n");
                }
                break;

            case 3:
                if (n > 0) {
                    createMaxHeap(arr, n);
                    maxHeapCreated = 1;
                    printf("Max-heap created based on weight.\n");
                } else {
                    printf("No data available. Please read data first.\n");
                }
                break;

            case 4:
                if (!minHeapCreated) {
                    printf("Min-heap is not created. Please select Option 2 to create the min-heap.\n");
                } else {
                    displayWeightOfYoungestPerson(arr, n);
                }
                break;

            case 5:
                if (!maxHeapCreated) {
                    printf("Max-heap is not created. Please select Option 3 to create the max-heap.\n");
                } else {
                    displayWeightOfHeaviestPerson(arr, n);
                }
                break;

            case 6:
                printf("Inserting a new person into the heap is not yet implemented.\n");
                break;

            case 7:
                printf("Deleting the oldest person from the heap is not yet implemented.\n");
                break;

            case 8:
                free(arr);
                return 0;

            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
                   