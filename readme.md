# Parallel and Sequential Merge Sort in C

This repository contains an implementation of the merge sort algorithm in C, both in sequential and parallel forms using POSIX threads (pthreads). The parallelization aims to improve the sorting performance on multi-core processors by dividing the array into segments and sorting them concurrently.

## Compilation

To compile the program, ensure you have GCC installed and use the following command:

```bash
gcc -o merge_sort merge_sort.c -lpthread
```

This will compile the source code into an executable named `merge_sort`. The `-lpthread` flag links the pthread library, which is necessary for threading support.

## Running the Program

After compilation, you can run the program using:

```bash
./merge_sort
```

The program will automatically generate an array with 1,000,000 elements, fill it with random numbers, and then sort it using both parallel and sequential merge sort implementations. It will print the time taken by each method to complete the sorting.

## Code Structure

- `main()`: The entry point of the program, responsible for initializing the array, calling the sorting functions, and measuring their execution time.
- `fillArray(int arr[], int n)`: Fills the provided array with random numbers.
- `mergeSortThread(void* arg)`: The function executed by threads for parallel sorting. It divides the array and spawns new threads for sorting each half if the segment size is above a defined threshold.
- `mergeSort(int* arr, int l, int r)`: A sequential merge sort implementation used for smaller segments where parallel sorting is inefficient.
- `merge(int arr[], int l, int m, int r)`: Merges two sorted halves of the array into a single sorted segment.
- `min(int x, int y)`: Utility function to find the minimum of two integers.

## Note

The parallel merge sort implementation uses a fixed number of threads defined by `MAX_THREADS` and a segment size threshold (`THRESHOLD`) to control when to switch back to sequential sorting. Adjust these values based on your system's capabilities and the size of the dataset for optimal performance.
