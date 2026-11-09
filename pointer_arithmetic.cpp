// ============================================================
// ACTIVITY 1: POINTER ARITHMETIC
// Learning Outcome: Apply pointer arithmetic to traverse an array
// ============================================================

// Include the input/output library for cout
#include <iostream>
using namespace std;

// The main function - where the program starts
int main() {

// Declare and initialise an array of 5 integers
// In memory, these are stored sequentially: e.g., at addresses 100, 104, 108...

int numbers[5]= {10, 20, 30, 40, 50};

// Declare a pointer named 'ptr' that points to an integer
// We assign it the array name 'numbers'.
// In C++, an array name acts as a pointer to its first element.
// So, ptr now holds the memory address of numbers[0] (which is 10).

int* ptr = numbers;


cout << "Array elements accessed via pointer arithmetic:" << endl;


//Loop 5 times to access each element 
for (int i = 0; i<5; i++) {
    //*ptr means "dereference" -go to the address stored in ptr and get the value.
    //on the first iteration this prints 10.
    cout << "Value: " << *ptr << endl;

    //ARITHMETIC: ptr++ increments
    //because ptr is an int pointer, it increases the memory adddress by 4 bytes
    //(the size of an int ), moving it to the next element in the array.
    ptr++;

}

//reset the pointer back to the start of the array
ptr = numbers;

cout <<"\nAccessing using offset aritmetic:" << endl;

//Another way to use pointer arithmetic: (ptr + i)
for (int i =0; i < 5; i++) {
    //*(ptr +i) is exactly the same as [i]
    //it takes the base address (ptr) and jumps forward by i integers
    cout <<"Index " <<i <<"has value:" << *(ptr + i) <<endl;

}

return 0;
}
