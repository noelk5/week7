// ============================================================
// ACTIVITY 2: POINTERS IN C (C VERSION)
// Learning Outcome: Analyse code using pointers (simulating aliases)
// ============================================================


// Include the standard input/output library
#include <stdio.h>

// The main function
int main() {
// 1. A normal integer variable
int originalValue = 100;

// 2. In C++, we would use a reference: int& refValue = originalValue;
// Since C lacks references, we use a second pointer as an "alias".
// Both ptr1 and ptr2 point to the exact same memory address.
int *ptr1 = &originalValue;
int *ptr2 = &originalValue;

// Display initial values
printf("--- Initial State ---\n");
printf("originalValue: %d\n", originalValue);
printf("Value via ptr1: %d\n", *ptr1); // * dereferences to get the value

// --- MODIFICATION 1 ---
// Changing the value via ptr1 changes the original variable.
*ptr1 = 200;

printf("\n--- After setting *ptr1 = 200 ---\n");
printf("originalValue: %d\n", originalValue); // Expected: 200
printf("Value via ptr2: %d\n", *ptr2); // Expected: 200



// --- MODIFICATION 2 ---
// Changing the value via ptr2 also changes the original variable.
*ptr2 = 300;

printf("\n--- After setting *ptr2 = 300 ---\n");
printf("originalValue: %d\n", originalValue); // Expected: 300
printf("Value via ptr1: %d\n", *ptr1); // Expected: 300

// --- MODIFICATION 3 ---
// We can change what a pointer points to.
int anotherValue = 500;
ptr1 = &anotherValue; // ptr1 now points to a different memory address

printf("\n--- After pointing ptr1 to anotherValue ---\n");
printf("originalValue: %d\n", originalValue); // Expected: 300 (Unchanged)
printf("Value via ptr1: %d\n", *ptr1); // Expected: 500

return 0;
}