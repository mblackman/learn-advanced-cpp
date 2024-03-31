#include <iostream>
using namespace std;

void test(void (*func)()) {
    func();
}

int main() {

    auto func = [](){ cout << "Hello lambda!" << endl; };
    func();

    test(func);
    test([](){ cout << "Inner Lambda" << endl; });
    return 0;
}