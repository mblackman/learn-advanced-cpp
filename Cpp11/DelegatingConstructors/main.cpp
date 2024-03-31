#include <iostream>
using namespace std;

class Parent {
    int dogs;
    string text;

public:
    Parent(): Parent("Yo") {
        dogs = 5;
        cout << "Parameterless ctor called." << endl;
    }

    Parent(string text) {
        dogs = 5;
        this->text = text;
        cout << "String parameter ctor." << endl;
    }
};

class Child: public Parent {
public:
    Child() = default;
};

int main() {
    Parent parent;
    Child child;

    return 0;
}