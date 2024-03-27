#include <iostream>
#include "Complex.h"
using namespace std;
using namespace testproject;

int main() {
    Complex c1(2, 5);
    Complex c2(2,  4);

    cout << *c1 << *(c1 + c2) << endl;

    return 0;
}