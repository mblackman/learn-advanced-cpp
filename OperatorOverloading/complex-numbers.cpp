#include <iostream>
#include "Complex.h"
using namespace std;
using namespace testproject;

int main() {
    Complex c1(10, 20);
    Complex c2 = c1;

    cout << c1 << ", " << c2 << endl;

    return 0;
}