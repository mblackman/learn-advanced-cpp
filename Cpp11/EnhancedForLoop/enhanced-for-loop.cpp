#include <iostream>
#include <vector>
using namespace std;

int main() {
    auto texts = {"one", "two", "three"};

    for (auto text: texts) {
        cout << text << endl;
    }

    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    for (auto number: numbers) {
        cout << number << endl;
    }

    string sting = "Hello";

    for (auto c: sting) {
        cout << c << endl;
    }

    return 0;
}