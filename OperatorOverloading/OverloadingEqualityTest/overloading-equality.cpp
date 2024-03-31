#include <iostream>
#include "Complex.h"
using namespace std;
using namespace testproject;

int main() {
    Complex c1(2, 5);
    Complex c2(2,  4);

    if (c1 == c2) {
        cout << "Equal!" << endl;
    }
    else {
        cout << "Not equal!" << endl;
    }

    if (c1 != c2) {
        cout << "Not equal!" << endl;
    }
    else {
        cout << "Equal!" << endl;
    }
    
    return 0;
}