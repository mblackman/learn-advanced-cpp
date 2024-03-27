#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// This directive gets rid of the padding around the data.
#pragma pack(push, 1)

struct Person {
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop)

int main() {
    
    Person someone = {
        "Joe Smoe",
        69,
        420
    };

    string filename = "test.bin";
    // Write binary file
    ofstream outputFile;

    outputFile.open(filename, ios::binary);

    if (!outputFile.is_open()) {
        cout << "Could not create file: " << filename << endl;
        return -1;
    }
    
    outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

    outputFile.close();

    // Read binary file.
    ifstream inputFile;
    Person inPerson;

    inputFile.open(filename, ios::binary);

    if (!inputFile.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return -1;
    }
    
    inputFile.read(reinterpret_cast<char *>(&inPerson), sizeof(Person));

    inputFile.close();

    cout << inPerson.name << ", " << inPerson.age << ", " << inPerson.weight << endl;

    return 0;
}