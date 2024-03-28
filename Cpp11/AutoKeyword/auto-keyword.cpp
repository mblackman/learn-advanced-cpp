#include <iostream>
#include <typeinfo>
using namespace std;

// Multiple template definitions can be evaluated at compile time using decltype.
template <class T, class K>
auto test(T value1, K value2) -> decltype(value1 + value2) {
    return value1 + value2;
}

int get() {
    return 999;
}

// Decltype can determine the return type of a function.
auto test2() -> decltype(get()) {
    return get();
}

template <class T, class K>
class Test {
private:
    T tVal;
    K kVal;

public:
    Test(T tVal, K kVal): tVal(tVal), kVal(kVal) {

    }

    auto add() -> decltype(tVal + kVal) {
        return tVal + kVal;
    }

    auto getTVal() -> decltype(tVal) {
        return tVal;
    }

    template <class I>
    auto concat(I value) -> decltype(tVal + kVal + value) {
        return add() + value;
    }
};

int main() {
    auto value = 7;
    auto text = "Yo";

    cout << typeid(value).name() << endl;

    cout << test(5, 10) << endl;

    cout << test2() << endl;

    Test<string, string> test("String", " 10");

    cout << test.add() << endl;
    cout << test.getTVal() << endl;
    cout << test.concat(" More text") << endl;

    return 0;
}