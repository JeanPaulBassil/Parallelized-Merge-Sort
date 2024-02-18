#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <bits/time.h>

void fillArray(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main() {
    int arr[1000000]; // Consider increasing this if needed
    fillArray(arr, sizeof(arr)/sizeof(arr[0]));

    struct timespec start, end;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);

    mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1E9;
    printf("Time taken to sort the array: %.6f seconds\n", elapsed);

    return 0;
}

// function to fill the array with random numbers
// @param arr[]: array to be filled
// @param n: size of the array
// @return void
// *
// *
// *
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}


// function to merge sort
// @param arr[]: array to be sorted
// @param l: left index
// @param r: right index
// @return void
// *
// *
// *
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// function to merge
// @param arr[]: array to be sorted
// @param l: left index
// @param m: middle index
// @param r: right index
// @return void
// *
// *
// *
void merge (int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // merge the temp arrays back into arr[l..r]
    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = l; // initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
