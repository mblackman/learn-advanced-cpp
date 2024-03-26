#include <iostream>
#include <vector>
using namespace std;

class Test {
    private:
        int id;
        string name;

    public:
        Test(): id(0), name(""){

        }

        Test(const Test &other) {
            id = other.id;
            name = other.name;
        }

        Test(int id, string name) : id(id), name(name){
            
        }

        void print() const {
            cout << id << ": " << name;
        }

        bool operator<(const Test &other) const {
            if (id == other.id) {
                return name < other.name;
            }
            return id < other.id;
        }

        // This makes it so the comp declared below can access the private variables.
        friend bool comp(const Test &lhs, const Test &rhs);
};

bool comp(const Test &lhs, const Test &rhs) {
    return lhs.name < rhs.name;
}

int main() {
    
    vector<Test> tests;

    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(10, "Sue"));
    tests.push_back(Test(7, "Raj"));
    tests.push_back(Test(3, "Vicky"));

    sort(tests.begin(), tests.end(), comp);

    for (int i=0; i < tests.size(); i++) {
        tests[i].print();
        cout << endl;
    }

    return 0;
}