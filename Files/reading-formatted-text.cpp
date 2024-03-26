#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string inputFileName = "stats.txt";
    ifstream inFile;

    inFile.open(inputFileName, ios::in);

    if (!inFile.is_open()) {
        return -1;
    }
    
    string line;    
    int population;

    while (inFile) {
        getline(inFile, line, ':');
        inFile >> population;
        inFile >> ws; // ws is a command to dispose the output from the read command.

        if (!inFile) {
            break;
        }

        cout << line << " --- " << population << endl;
    }
    
    inFile.close();

    return 0;
}