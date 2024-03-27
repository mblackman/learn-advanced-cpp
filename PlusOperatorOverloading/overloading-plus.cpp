#include <iostream>
#include "Complex.h"
using namespace std;
using namespace testproject;

int main() {
    Complex c1(2, 4);
    Complex c2(8,  6);

    Complex c3 = c1 + c2;

    cout << c3 << endl;

    cout << c1 + 5 << endl;

    cout << 3.3 + c2 << endl;
    
    return 0;
}