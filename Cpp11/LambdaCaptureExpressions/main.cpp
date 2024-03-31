#include <iostream>
using namespace std;

int main() {

    int one = 1;
    int two = 2;
    int three = 3;

    // [one] causes that value to get captured by the lambda expression by value.
    [one](){ cout << "Lambda: " << one << endl;}(); 

    // [=] captures all the defined variables by value.
    [=](){ cout << one << " " << two << " " << three << endl;}();

    // Captures all local variables by value, but three by reference.
    [=, &three](){ 
        three = 7;
        cout << one << " " << two << " " << three << endl;
    }();

    cout << three << endl;

    // [&] captures all the defined variables by reference.
    [&](){ 
        three = 3;
        cout << one << " " << two << " " << three << endl;
    }();

    // All local variables are captured by reference. One and two are by value.
    [&, one, two](){ cout << one << " " << two << " " << three << endl;}();

    return 0;
}