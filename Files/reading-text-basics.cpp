#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    string inputFileName = "test.txt";
    ifstream inFile;

    inFile.open(inputFileName, ios::in);

    if (inFile.is_open()) {
        
        string line;

        while (inFile) {
            getline(inFile, line);
            cout << line << endl;
        }
        
        inFile.close();
    }
    else {
        cout << "Could not open file: " << inputFileName << endl;
    }

    return 0;
}