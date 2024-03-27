#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TestMap {
    private:
        map<string, vector<int>> scores;
    
    public: 
        void push_back(const string &name, const int &value) {
            scores[name].push_back(value);
        }

        string toString(const string &name) {
            if (scores.find(name) == scores.end()) {
                return "";
            }

            auto score = scores[name];
            string result = name + ": ";

            for (auto it=score.begin(); it!=score.end(); it++) {
                result += to_string(*it) + " ";
            }

            return result;
        }

        vector<string> getKeys() const {
            vector<string> keys;

            for (auto it=scores.begin(); it!=scores.end(); it++) {
                keys.push_back(it->first);
            }

            return keys;
        }
};

int main() {
    
    // The hard manual way.
    map<string, vector<int>> testScores;

    testScores["Mike"].push_back(10);
    testScores["Mike"].push_back(20);
    testScores["Viki"].push_back(15);

    for (auto it=testScores.begin(); it!=testScores.end(); it++) {
        string name = it->first;
        vector<int> scoreList = it->second;

        cout << name << ": " << flush;

        for (int i=0; i < scoreList.size(); i++) {
            cout << scoreList[i] << " " << flush;
        }

        cout << endl;
    }

    // Make this better with a custom object
    TestMap testMap;

    testMap.push_back("Mike", 10);
    testMap.push_back("Mike", 20);
    testMap.push_back("Viki", 15);

    auto keys = testMap.getKeys();
    for (auto it=keys.begin(); it!=keys.end(); it++) {
        cout << testMap.toString(*it) << endl;
    }

    return 0;
}