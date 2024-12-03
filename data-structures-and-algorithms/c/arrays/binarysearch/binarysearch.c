#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    // Continue searching while the left index is less than or equal to the right index
    while (left <= right) {
        int mid = left + (right - left) / 2; // Find the middle element

        // If the target is found at the mid position
        if (arr[mid] == target) {
            return mid; // Return the index of the target
        }
        // If the target is smaller than the mid element, search in the left half
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // If the target is greater than the mid element, search in the right half
        else {
            left = mid + 1;
        }
    }
    
    // If the target is not found, return -1
    return -1;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 80, 90};  // Example sorted array
    int target = 10;  // Element to be searched
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: \n");
    printArray(arr, n);

    // Calling binarySearch function
    int result = binarySearch(arr, n, target);

    // Checking if the result is valid or not
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
   