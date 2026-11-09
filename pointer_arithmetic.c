// ============================================================
// ACTIVITY 1: POINTER ARITHMETIC (C VERSION)
// Learning Outcome: Apply pointer arithmetic to traverse an array
// ============================================================

// Include the standard input/output library for printf
#include <stdio.h>

// The main function - where the program starts
int main() {

// Declare and initialise an array of 5 integers
// In C, arrays are contiguous blocks of memory.
int numbers[5] = {10, 20, 30, 40, 50};

// Declare a pointer named 'ptr' that points to an integer.
// We assign it the array name 'numbers'.
// In C, an array name acts as a pointer to its first element.
int *ptr = numbers;



// Display a header
printf("Array elements accessed via pointer arithmetic:\n");

// Loop 5 times to access each element
for (int i = 0; i < 5; i++) {

// *ptr means "dereference" - go to the address stored in ptr and get the value.
// printf uses %d for integers.
printf("Value: %d\n", *ptr);

// ARITHMETIC: ptr++ increments the pointer.
// It moves the pointer to the next integer in memory (usually 4 bytes forward).
ptr++;
}

// Reset the pointer back to the start of the array
ptr = numbers;

// Display a header
printf("\nAccessing using offset arithmetic:\n");

// Another way to use pointer arithmetic: (ptr + i)
for (int i = 0; i < 5; i++) {
// *(ptr + i) takes the base address (ptr) and jumps forward by i integers.
printf("Index %d has value: %d\n", i, *(ptr + i));


}

// Return 0 to signal successful completion
return 0;
}