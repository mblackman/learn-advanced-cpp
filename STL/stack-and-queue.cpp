#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
    private:
        string name;

    public:
        Test(): name(""){

        }

        Test(const Test &other) {
            name = other.name;
        }

        Test(string name) : name(name){
            
        }

        void print() const {
            cout << name;
        }

        bool operator<(const Test &other) const {
            return name < other.name;
        }
};

int main() {
    
   stack<Test> testStack;

   testStack.push(Test("Mike"));
   testStack.push(Test("John"));
   testStack.push(Test("Sue"));

    while (!testStack.empty()) {
        Test &next = testStack.top(); // This stores the reference and doesn't copy the value.
        next.print();
        testStack.pop(); // Pop after using the object. Popping from the stack will destroy an object.
        cout << endl;
    }

    cout << "Queue time" << endl;

    queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));

    while (!testQueue.empty()) {
        Test &next = testQueue.front();
        next.print();
        testQueue.pop();
        cout << endl;
    }

    return 0;
}