#include <iostream>
#include <set>
using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person(): name(""), age(0) {

        }

        Person(const Person &other) {
            name = other.name;
            age = other.age;
        }

        Person(string name, int age) : name(name), age(age) {
            
        }

        void print() const {
            cout << name << ": " << age;
        }

        bool operator<(const Person &other) const {
            if (name == other.name) {
                return age < other.age;
            }
            else {
                return name < other.name;
            }
        }
};

int main() {
    
   set<Person> people;
    auto bob = Person("Bob", 500);
    auto frank = Person("Frank", 40);
    auto otherFrank = Person("Frank", 22);
    auto unset = Person("Unset", 100);

    people.insert(bob);
    people.insert(frank);
    people.insert(otherFrank);

    if (people.find(bob) != people.end()) {
        cout << "We found Bob!" << endl;
    }
    else {
        cout << "No Bob in sight." << endl;
    }

    if (people.find(unset) == people.end()) {
        cout << "No unset person found." << endl;
    }
    else {
        cout << "Somehow the unset person was found." << endl;
    }

    if (people.find(Person("Frank", 22)) != people.end()) {
        cout << "Frank was found." << endl;
    }
    else {
        cout << "Could not find Frank." << endl;
    }

    return 0;
}