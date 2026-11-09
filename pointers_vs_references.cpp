// ============================================================
// ACTIVITY 2: POINTERS VS REFERENCES
// Learning Outcome: Analyse code mixing pointers and references
// ============================================================

#include <iostream>
using namespace std;

int main() {
    // 1. A normal integer variable
    int originalValue = 100;

    // 2. A reference variable
    // The '&' after 'int' means 'refValue' is an alias for originalValue.
    int& refValue = originalValue;

    // 3. A pointer variable
    // The '*' means 'ptrValue' holds a memory address.
    // '&' gets the memory address of originalValue.
    int* ptrValue = &originalValue;

    cout << "--- Initial State ---" << endl;
    cout << "originalValue: " << originalValue << endl;
    cout << "refValue: " << refValue << endl;
    cout << "ptrValue points to: " << *ptrValue << endl; // * dereferences to get the value

    // --- MODIFICATION 1 ---
    // Changing the reference changes the original variable.
    refValue = 200;

    cout << "\n--- After setting refValue = 200 ---" << endl;
    cout << "originalValue: " << originalValue << endl; // Expected: 200
    cout << "ptrValue points to: " << *ptrValue << endl; // Expected: 200

    // --- MODIFICATION 2 ---
    // Changing the value via the pointer changes the original variable.
    *ptrValue = 300; // *ptrValue accesses the value at the address

    cout << "\n--- After setting *ptrValue = 300 ---" << endl;
    cout << "originalValue: " << originalValue << endl; // Expected: 300
    cout << "refValue: " << refValue << endl; // Expected: 300

    // --- MODIFICATION 3 ---
    // We can change what the pointer points to.
    int anotherValue = 500;
    ptrValue = &anotherValue; // Pointer now points to a different memory address

    cout << "\n--- After pointing ptrValue to anotherValue ---" << endl;
    cout << "originalValue: " << originalValue << endl; // Expected: 300
    cout << "ptrValue points to: " << *ptrValue << endl; // Expected: 500

    // Note: We CANNOT do this with references!
    // refValue = anotherValue; would just copy the value 500 into originalValue.

    return 0;
}