#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    int i;
    for (i = 0; i < p2 - 1; i++) {
        EXCHANGE(&p1[i], &p1[p2 - 1]);
    }
}

int main() {
    int A[9];
    int i, N;

    printf("Enter an array A of size N (9): ");
    for (i = 0; i < 9; i++) {
        scanf("%d", &A[i]);
    }

    printf("Before ROTATE: ");
    for (i = 0; i < 9; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    ROTATE_RIGHT(A, 5);

    printf("After ROTATE: ");
    for (i = 0; i < 9; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}