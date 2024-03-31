#include <iostream>
using namespace std;

class Test {
private:
    int one{1};
    int two{2};

public:
    void run() {
        int three{3};
        int four{4};

        auto pLambda = [&, this]() {
            one = 31;
            cout << one << endl << two << endl;
            cout << three << endl << four << endl;
        };
        pLambda();

        cout << one << endl;
    }
};

int main() {
    Test test;
    test.run();

    return 0;
}