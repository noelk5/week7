// ============================================================
// ACTIVITY 3A: THE MEMORY LEAK
// Learning Outcome: Evaluate memory leak risks
// ============================================================

#include <iostream>
using namespace std;

// A function that allocates memory but forgets to delete it
void fixLeak() {
    //('new int' allocates memory on the heap (dynamic memory) for one integer.
    //it returns the memory address, which we store in 'ptr')

    //allocate memory
    int* ptr = new int(42);

    cout <<"Inside fixed function. The value is: " << *ptr <<endl;
    cout<<"Memory allocated at address: " <<ptr <<endl;

    
    // THE FIX: The 'delete' operator frees the memory back to the operating system.
delete ptr;

// GOOD PRACTICE: Set the pointer to nullptr after deleting it.
// This prevents "dangling pointers" (pointers that point to freed memory).
ptr = nullptr;
cout << "Memory has been successfully freed." << endl;

}

int main() {
   cout << "--- Testing the Fix ---" << endl;
   fixLeak();
    return 0;
}