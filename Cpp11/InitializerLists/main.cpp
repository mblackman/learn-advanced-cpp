#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Test {
public: 
    Test(initializer_list<string> texts) {
        for (auto value: texts) {
            cout << value << endl;
        }
    }

    void print(initializer_list<string> list) {
        for (auto value: list) {
            cout << value << endl;
        }
    }
};

int main() {

    vector<int> numbers {1, 3, 4, 6};
    cout << numbers[2] << endl;

    Test test { "one", "two", "three", "four"};

    test.print({"apple", "orange", "gun"});

    return 0;
}