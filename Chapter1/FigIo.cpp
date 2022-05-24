#include "FigIO.h"

istream& operator >> (istream& inDevice, Circle& cir) {
    double Xo, Yo, r;
    inDevice >> Xo >> Yo >> r;
    cir.Set(Xo, Yo, r);
    return inDevice;
}

ostream& operator << (ostream& outDevice, Circle cir) {
    outDevice << " + Area of circle = " << cir.Area() << endl;
    outDevice << " + Perimeter of circle = " << cir.Perimeter() << endl;
    return outDevice;
}
