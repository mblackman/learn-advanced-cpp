#include <iostream>
using namespace std;

// This is pre-c++11 syntax
struct Test {
    virtual bool operator()(string &value) = 0;

    virtual ~Test() {}
};

// This is a functor.
struct MatchTest: Test {
    // This overrides the parenthesis operator. You can add as many parameters as you'd like.
    virtual bool operator()(string &value) {
        return value == "Lion";
    }
};

void check(string val, Test &match) {
    if (match(val)) {
        cout << "A match was found." << endl;
    }
    else {
        cout << "Given value was not a match: " + val << endl;
    }
}

int main() {
    MatchTest pred;
    string value = "Lion";
    cout << pred(value) << endl;

    check(value, pred);

    return 0;
}