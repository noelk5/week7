#include <stdio.h>
#include <stdlib.h>

void fixLeak() {
// Allocate memory
int *ptr = (int*)malloc(sizeof(int));
*ptr = 42;

printf("Inside fixed function. Value: %d\n", *ptr);

// THE FIX: The free() function returns the memory to the OS.
// free() takes the pointer as an argument.
free(ptr);

// GOOD PRACTICE: Set the pointer to NULL after freeing.
// This prevents using a "dangling pointer".
ptr = NULL;

printf("Memory has been successfully freed.\n");
}

int main() {
printf("--- Testing the Fix ---\n");
fixLeak();
return 0;

}