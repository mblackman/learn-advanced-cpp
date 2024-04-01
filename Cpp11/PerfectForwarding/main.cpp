#include <iostream>
using namespace std;

class Test {

};

// The Forward ensures the value maintains as either RValue or LValue.
template<typename T>
void call(T &&arg) {
    check(forward<T>(arg));
}

void check(Test &test) {
    cout << "lvalue" << endl;
}

void check(Test &&test) {
    cout << "rvalue" << endl;
}

int main() {

    auto &&t = Test();

    call(Test());

    Test test;
    call(test);

    return 0;
}