#include <iostream>
using namespace std;

int main() {

    int cats = 5;

    // This allows you to change the value passed in without changing the original reference.
    [cats]() mutable {
        cats = 8;
        cout << cats << endl;
    }();

    cout << cats << endl;

    return 0;
}