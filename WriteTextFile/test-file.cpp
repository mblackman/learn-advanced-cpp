#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    string outputFileName = "text.txt";
    ofstream out(outputFileName);
    vector<std::string> content = {
        "This is the first line",
        "The second comes now",
        "What out for rabbits",
        "What count am I on?",
        "This is the final and fifth one."
    };

    if (out.is_open()) {
        
        for (int i = 0; i < content.size(); i++) {
            out << i + 1 << ": " << content[i] << endl;
        }
        
        out.close();
    }
    else {
        cout << "Could not create file: " << outputFileName << endl;
    }

    return 0;
}