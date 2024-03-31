#include <iostream>
using namespace std;

template<class T>
class Test {
private:
    T object;

public:
    Test(T object) : object(object) {

    }

    void print() {
        cout << object << endl;
    }
};

int main() {
    Test<string> test1("Tester");
    test1.print();

    return 0;
}