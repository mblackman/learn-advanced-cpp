#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;

public:
    Test() : id(0), name("") {

    }

    Test(int id, string name) : id(id), name(name) {

    }

    Test(const Test &other) {
        *this = other;
    }

    const Test &operator=(const Test& other) {
        id = other.id;
        name = other.name;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Test &test) {
        out << test.id << ": " << test.name;
        return out;
    }
};

int main2() {

    Test test1(10, "Mike");
    Test test2(30, "Bob");

    cout << test1 << ", " << test2 << endl;

    return 0;
}