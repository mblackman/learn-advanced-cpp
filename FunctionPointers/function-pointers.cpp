#include <iostream>
using namespace std;

void test() {
    cout << "Hello" << endl;
}

void argTest(int value) {
    cout << value << endl;
}

int main() {
    test();

    void (*pTest)();
    pTest = test; // You don't need to point to the address of a function, because the function name is a pointer to the function.

    pTest();

    void (*pArgsTest)(int);
    pArgsTest = argTest;

    pArgsTest(10);

    return 0;
}