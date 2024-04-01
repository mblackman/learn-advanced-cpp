#include <iostream>
#include <functional> // Needed for bind

using namespace std;
using namespace placeholders;

class Test {
public:
    int add(int a, int b, int c) {
        cout << a << ", " << b << ", " << c << endl;
        return a + b + c;
    }
};

int add(int a, int b, int c) {
    cout << a << ", " << b << ", " << c << endl;
    return a + b + c;
}

void run(function<int(int, int)> func) {
    func(7, 3);
}

int main() {

    Test test;
    cout << add(1, 2, 3) << endl;

    auto calculate = bind(&Test::add, test, 3, 4, 5); // Bind a method on a specific object.

    cout << calculate() << endl;

    auto calculate2 = bind(add, _1, _2, _3); // This uses placeholders for the values.

    cout << calculate2(10, 20, 30) << endl;

    auto calculate3 = bind(add, _3, _1, _1); // The order of arguments can change

    cout << calculate3(10, 20, 30) << endl;

    auto calculate4 = bind(add, 100, _1, _1); // Mix and match.

    cout << calculate4(10, 20) << endl;

    run(calculate);
    run(calculate4);

    return 0;
}