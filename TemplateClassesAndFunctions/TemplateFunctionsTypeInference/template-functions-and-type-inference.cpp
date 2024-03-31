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

template<class T>
void print(T n) {
    cout << "Generic method called: " << n << endl;
}

void print(int n) {
    cout << "Int method called: " << n << endl;
}

template<class T>
void show() {
    cout << T() << endl;
}

int main() {
    print(5);
    print<int>(8);
    int a = 6;
    print<>(a);
    print(a);
    print<double>(10);
    print("Heyo");

    show<string>();

    return 0;
}