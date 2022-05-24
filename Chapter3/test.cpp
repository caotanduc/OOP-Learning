#include <iostream>
using namespace std;

class B {
public:
    B() {
        cout << "Tao lap B" << endl;
    }
    ~B() {
        cout << "Huy B" << endl;
    }
};

class A {
private:
    B b;
public:
    A() {
        cout << "Tao Lap A" << endl;
    }
    ~A() {
        cout << "Huy A" << endl;
    }
};

int main() {
    A a;
    return 0;
}
