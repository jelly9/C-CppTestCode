#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        cout << "Base()" << endl;
    }
    virtual ~Base(){
        cout << "~Base()" << endl;
    }
};

class Driver: public Base{
public:
    Driver(){
        cout << "Driver" << endl;
    }
    ~Driver(){
        cout << "~Driver" << endl;
    }
};

int main(){

    Base *pb = new Driver();
    delete pb;

    return 0;

}
