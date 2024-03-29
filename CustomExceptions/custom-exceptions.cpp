#include <iostream>
using namespace std;

class MyException: public exception {
    public:
        virtual const char* what() const throw() {
            return "Something bad happened!";
        }
};

class Test {
    public:
        void goesWrong() {
            throw MyException();
        }
};

int main() {

    Test test;

    try
    {
        test.goesWrong();
    }
    catch(const MyException& e)
    {
        std::cerr << e.what() << endl;
    }
    
    return 0;
}