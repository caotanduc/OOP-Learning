#include "Complex.h"
#include <iostream>
#include <stdint.h>
using namespace std;


int main() {
    Complex a(1, 2);
    Complex b(4, 3);
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << (a == b) << endl;
    cout << (a != b) << endl;
    return 0;
}
