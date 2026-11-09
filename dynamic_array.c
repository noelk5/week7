// ============================================================
// ACTIVITY 4: DYNAMIC ARRAY WRAPPER (C VERSION)
// Learning Outcome: Create a dynamic array that resizes
// ============================================================

// Include standard I/O and standard library for printf and memory functions
#include <stdio.h>
#include <stdlib.h>

// In C, we don't have classes. We use a 'struct' to group related data.

// We also define functions that take a pointer to this struct.
typedef struct {
int *data; // Pointer to the dynamically allocated array
int size; // Number of actual elements currently stored
int capacity; // Total number of slots currently allocated
} DynamicArray;

// Function to initialize the array
void initArray(DynamicArray *arr, int initialCapacity) {
// Set the initial capacity and size
arr->capacity = initialCapacity;
arr->size = 0;

// Allocate the initial raw array on the heap using malloc
// We need space for 'capacity' number of integers
arr->data = (int*)malloc(arr->capacity * sizeof(int));

if (arr->data == NULL) {
printf("Failed to allocate memory.\n");
exit(1);
}
}

// Function to free the memory (equivalent to C++ Destructor)
void freeArray(DynamicArray *arr) {
// Free the memory allocated for the array data

free(arr->data);
// Reset the pointers to avoid dangling pointers
arr->data = NULL;
arr->size = 0;
arr->capacity = 0;
}

// Method to add a new element to the end
void push_back(DynamicArray *arr, int value) {
// 1. Check if we have run out of space
if (arr->size == arr->capacity) {
// We need to resize!
// a. Double the capacity
int newCapacity = arr->capacity * 2;

// b. Allocate a new, larger array on the heap using malloc
int *newData = (int*)malloc(newCapacity * sizeof(int));
if (newData == NULL) {
printf("Failed to allocate memory during resize.\n");
return;
}

// c. Copy the old elements into the new array
for (int i = 0; i < arr->size; i++) {
newData[i] = arr->data[i];
}

// d. Free the old, smaller array to prevent a memory leak
free(arr->data);

// e. Update our struct to point to the new array and capacity
arr->data = newData;
arr->capacity = newCapacity;

printf("[Resized capacity from %d to %d]\n", arr->capacity / 2, arr->capacity);
}

// 2. Add the new value at the next available slot
arr->data[arr->size] = value;
arr->size++; // Increment the size counter
}

// Function to print the array contents
void display(DynamicArray *arr) {
printf("Array (Size: %d, Capacity: %d): ", arr->size, arr->capacity);
for (int i = 0; i < arr->size; i++) {
printf("%d ", arr->data[i]);
}
printf("\n");
}

int main() {

// Declare the struct variable
DynamicArray myArray;

// Initialize it with a capacity of 2
initArray(&myArray, 2);
printf("Created dynamic array with capacity 2.\n");

// Add elements and watch it resize automatically
push_back(&myArray, 10);
push_back(&myArray, 20);
display(&myArray);

// This push_back should trigger a resize!
printf("\nAdding third element...\n");
push_back(&myArray, 30);
display(&myArray);

printf("\nAdding fourth and fifth elements...\n");
push_back(&myArray, 40);
push_back(&myArray, 50); // This will trigger another resize
display(&myArray);

// CLEANUP: Call the free function to prevent memory leaks
freeArray(&myArray);

return 0;

}