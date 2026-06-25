#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void merge_sort(int a[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = (si + ei) / 2;
    merge_sort(a, si, mid);
    merge_sort(a, mid + 1, ei);
    merge(a, si, mid, ei);
}

void merge(int a[], int si, int mid, int ei) {
    int temp[ei - si + 1];  // Temporary array with the correct size
    int i = si;
    int j = mid + 1;
    int k = 0;

    // Merge the two halves
    while (i <= mid && j <= ei) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of the left half (if any)
    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of the right half (if any)
    while (j <= ei) {
        temp[k] = a[j];
        j++;
        k++;
    }

    // Copy merged elements back to the original array
    for (i = 0; i < (ei - si + 1); i++) {
        a[si + i] = temp[i];
    }
}

int main() {
    int n_value[] = {5000, 6000, 10000, 20000, 50000};
    int num_test = sizeof(n_value) / sizeof(n_value[0]);
    printf("\nTime taken for merge sort: \n");

    for (int t = 0; t < num_test; t++) {
        int n = n_value[t];
        int *a = (int*)malloc(n * sizeof(int));

        // Randomly generate values for the array
        srand(time(0));
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 1000;
        }
        
        clock_t start_time = clock();
        merge_sort(a, 0, n - 1);
        clock_t end_time = clock();

        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        printf("Sorted %d elements in %.6f seconds.\n", n, time_taken);

        free(a);
    }
    return 0;
}
