#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    /* int Num = 0x4F3E; */
    /* cout << setw(25) << right; */
    /* cout << "Num (decimal) = " << Num << endl; */
    /* cout << setw(25) << right; */
    /* cout << "Num (hexa decimal) = " << hex << Num << endl; */
    /* cout << setw(25) << right; */
    /* cout << "Num (octal) = " << oct << Num << endl; */

    int x = 10;
    decltype(x) y = x;
    decltype((x)) z = x;
    z = 20;
    cout << x << " " << y << " " << z << endl;
    cin.get();
    return 0;
}
