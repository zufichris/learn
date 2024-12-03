#include <stdio.h>

// Function to add two integers
int add(int a, int b) {
    return a + b; // Return the sum of a and b
}

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a; // Temporarily store the value pointed to by 'a'
    printf("Before Swap: a=%p, temp=%p, b=%p\n", a, &temp, b);
    
    *a = *b; // Assign the value of 'b' to the location 'a' points to
    *b = temp; // Assign the stored value in 'temp' to the location 'b' points to
}

int main() {
    int a = 10;
    int *p = &a; // 'p' stores the address of 'a'
    printf("Address of a=%p, Value at p=%d\n", p, *p); // Dereferencing pointer 'p' to get value of 'a'

    // Void pointers can store the address of any data type but require casting for dereferencing
    void *vp;
    vp = &a; // Storing the address of 'a' in a void pointer
    int *new = (int *)(vp); // Casting 'vp' to an int pointer to dereference
    printf("Dereferenced void pointer value: %d\n", *new);

    // Null pointer demonstration
    int *ptr = NULL; // NULL pointer points to no valid memory address
    if (ptr == NULL) {
        printf("Pointer is NULL\n"); // Check if the pointer is NULL
    }

    /* Function pointers allow storing and calling functions indirectly.
       Syntax: return_type (*pointer_name)(parameter_types);
    */

    // Declaring a function pointer for the 'add' function
    int (*sum)(int, int); 
    sum = add; // Assigning the address of 'add' to the function pointer
    int result = sum(12, 23); // Indirectly calling the 'add' function
    printf("Sum result: %d\n", result);

    // Using a function pointer for 'printf'
    int (*print)(const char *format, ...); // Function pointer with variable arguments
    print = printf; // Assigning 'printf' to the function pointer
    print("Using function pointer for printf: %d\n", 1);

    // Demonstrating swapping two numbers using pointers
    int x = 10, y = 20;
    printf("Before Swap: x=%d, y=%d\n", x, y);
    swap(&x, &y); // Passing addresses of x and y to swap
    printf("After Swap: x=%d, y=%d\n", x, y);

    return 0;
}
