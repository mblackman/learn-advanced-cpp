#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() = 0; // This means there's no implementation. This is how you define a pure, virtual function.
    // This method turns Animal into a virtual class, so the compiler won't let you create an instance of it.
    virtual void run() = 0;
};

class Dog: public Animal {
public:
    virtual void speak() {
        cout << "Woof" << endl;
    }
};

class Labrador: public Dog {
public:
    Labrador() {
        cout << "New lab created" << endl;
    }

    virtual void run() {
        cout << "Labrador running" << endl;
    }
};

void test(Animal &a) {
    a.run();
}

int main() {
    Labrador dog;
    dog.speak();
    dog.run();

    Animal *animals[5]; // Your collection must be a pointer of the base class to work.
    animals[0] = &dog;

    animals[0]->speak();

    test(dog);
    test(*animals[0]);

    return 0;
}