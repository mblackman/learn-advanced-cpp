#include <iostream>
using namespace std;

class Test {
    int id{3}; // You could also write: int id = 3;
    string name{"Pete"};

public:
    Test() = default; // Shorthand to create default ctor

    Test(const Test &test) = default;
    // You can remove a ctor of built-in function with this syntax: Test(const Test &test) = delete;
    
    Test(int id): id(id) {

    }

    Test &operator=(const Test &test) = default;

    void print() {
        cout << id << " " << name << endl;
    }
};

int main() {
    Test test;
    test.print();

    Test testId(55);
    testId.print();

    Test test2 = test;
    test2.print();

    return 0;
}