#include <iostream>
using namespace std;

class lopA {
public:
    lopA();
    virtual void logging();
};


class lopB: public lopA {
public:
    lopB() {};
    void logging();
};


lopA::lopA() {
    logging();
}

void lopA::logging() {
    cout << "Phuong thuc logging cua lop A" << endl;
}

void lopB::logging() {
    cout << "Phuong thuc logging cua lop B" << endl;
}

int main() {
    lopB b;
    return 0;
}
