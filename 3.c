#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

int partition(int A[], int low, int high) {
    int pivot = A[low]; // Pivot is now the first element (low)
    int i = low + 1;
    int j = high;

    while (i <= j) {
        // Find element greater than pivot
        while (i <= j && A[i] <= pivot) {
            i++;
        }
        // Find element less than pivot
        while (i <= j && A[j] > pivot) {
            j--;
        }
        if (i < j) {
            // Swap elements
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Place the pivot in its correct position
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j; // Return pivot index
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pi = partition(A, low, high); 
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main() {
    int A[MAX];
    clock_t t1, t2;

    // Generate random elements
    for (int i = 0; i < MAX; i++) {
        A[i] = rand();
    }

    printf("Elements: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    t1 = clock();

    quickSort(A, 0, MAX - 1);

    t2 = clock();

    printf("Sorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    float sec = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Runtime of program: %f\n", sec);

    return 0;
}
