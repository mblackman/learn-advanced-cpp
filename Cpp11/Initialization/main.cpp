#include <iostream>
#include <vector>
using namespace std;

int main() {

    // C++98 style
    int values[] = {1, 3, 4};

    cout << values[0] << endl;

    class C { 
    public:
        string text;
        int id;
    };

    C c1 = {
        "Hello",
        7
    };

    cout << c1.text << " " << c1.id << endl;

    struct S {
        string text;
        int id;
    };

    S s1 = {"Wow", 66};

    cout << s1.text << " " << s1.id << endl;

    struct {
        string text;
        int id;
    } s2 = { "Bello", 30};

    cout << s2.text << " " << s2.id << endl;

    // C++11 Initialization
    int value{5};
    cout << value << endl;

    string text{"Hello"};
    cout << text << endl;

    int numbers[] {1, 3, 4};
    cout << numbers[0] << endl;

    int *pInts = new int[3] {2, 4, 6};
    cout << pInts[1] << endl;
    delete [] pInts;

    int value2{};
    cout << value2 << endl;

    int *pSomething {&value};
    cout << *pSomething << endl;

    struct {
        string text;
        int id;
    } s3{ "Bello", 30};

    cout << s3.text << " " << s3.id << endl;

    vector<string> strings{"one", "two", "three"};
    cout << strings[2] << endl;

    return 0;
}