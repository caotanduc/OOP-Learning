#include "String.h"
#include <crtdbg.h>
using namespace std;

void foo() {
	String s1(12);
	String s2("34");
	String s3 = 56;
	String s4 = "78";
	cout << s1 << ", " << s2 << ", " << s3 << ", " << s4 << endl;
	String s5;
	s5 = s1 + s2 + s3 + s4;
	cout << s5 << endl;
	String s6;
	s6 = s1 + s2 + s3 + s4 + s5;
	cout << s6 << endl;

	String s7 = 123;
	s7 += s1 + "This is a final test";
	cout << s7 << endl;

	String s;
	cout << "Input your string: ";
	cin >> s;
	cout << "Your string is: " << s;
}

int main() {
	foo();
	_CrtDumpMemoryLeaks();
	return 0;
}