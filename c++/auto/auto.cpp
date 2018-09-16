#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    double a = 10, b = 20;
    //auto c = 100;
    auto c = a + b;
    decltype(c) d = 40;
    cout << typeid(d).name() << endl;
    return 0;
}
