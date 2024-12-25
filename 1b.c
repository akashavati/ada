#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 10

// Function for binary search
int binsc(int arr[], int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2; // Correct formula for mid
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    int arr[Max], res;
    clock_t t1, t2;

    // Seed random number generator
    srand(time(NULL));

    // Populate the array with random numbers
    for (int i = 0; i < Max; i++) {
        arr[i] = rand() % 100; // Limiting random numbers for readability
    }

    // Sort the array to use binary search
    for (int i = 0; i < Max - 1; i++) {
        for (int j = 0; j < Max - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < Max; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Use an existing element as the target
    int target = arr[5];
    printf("Searching for target: %d\n", target);

    // Measure the time for binary search
    t1 = clock();
    res = binsc(arr, Max, target);
    t2 = clock();

    // Output the result
    if (res == -1)
        printf("%d element not found\n", target);
    else
        printf("%d is found at index %d\n", target, res);

    // Calculate and display runtime
    float sec = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Runtime of the program: %f seconds\n", sec);

    return 0;
}
