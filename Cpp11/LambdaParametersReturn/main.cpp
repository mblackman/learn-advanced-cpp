#include <iostream>
using namespace std;

void test(void (*greet)(string)) {
    greet("Bob");
}

void runDivide(double (*func)(double, double)) {
    cout << "Ran divide: " <<func(100, 0) << endl;
}

int main() {

    auto pGreet = [](string name){ cout << "Hello " << name << endl; };

    pGreet("Bill");

    test(pGreet);

    auto pDivide = [](double lhs, double rhs) -> double {
        if (rhs == 0) {
            return 0;
        }
        return lhs / rhs;
    };

    cout << pDivide(20, 15) << endl;
    cout << pDivide(20, 0) << endl;

    runDivide(pDivide);

    return 0;
}