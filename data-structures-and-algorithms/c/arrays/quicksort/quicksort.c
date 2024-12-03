#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place pivot element at its correct position
int partition(int arr[], int low, int high) {
    // Choosing the rightmost element as the pivot
    int pivot = arr[high];
    int i = (low - 1);  // Index of the smaller element

    // Re-arranging the elements based on the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;    // Increment the index of smaller element
            swap(&arr[i], &arr[j]);  // Swap the elements
        }
    }

    // Place the pivot element at the correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);  // Return the pivot index
}

// Quicksort function that recursively sorts the subarrays
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);

    // Calling quicksort function to sort the array
    quicksort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
