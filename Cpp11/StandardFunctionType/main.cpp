#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string &value) {
    return value.size() == 3;
}

class Check {
public:
    bool operator()(string &text) {
        return text.size() == 5;
    }
} check1;

void run(function<bool(string&)> check) {
    string test = "Cat";
    cout << check(test) << endl;
}

int main() {

    int size = 5;

    vector<string> vec {"one", "two", "three", "four"};

    auto lambda = [size](string test) { return test.size() == size;};
    int count = count_if(vec.begin(), vec.end(), lambda);
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check);
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check1);
    cout << count << endl;

    run(check);
    run(lambda);
    run(check1);

    function<int(int, int)> sum = [](int a, int b) { return a + b;};
    cout << sum(1, 2) << endl;

    return 0;
}