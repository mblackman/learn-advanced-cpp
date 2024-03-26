#include <iostream>
#include <map>
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
    map<Person, int> people;

    people[Person("Mike", 40)] = 0;
    people[Person("Mike", 60)] = 100;
    people[Person("Viki", 30)] = 1;
    people[Person("Raj", 20)] = 2;
    
    people.insert(make_pair(Person("Bob", 45), 55));

    for (map<Person, int>::iterator it=people.begin(); it!=people.end(); it++) {
        cout << it->second << ": " << flush;
        it->first.print();
        cout << endl;
    }

    return 0;
}