/**********************************************************
* processing Exception in caller program,
* using try-catch block
***********************************************************/

#include "exception.h"

int main() {
	int num1, num2, result;
	for (int i = 0; i < 3; i++) {
		cout << "Enter an integer: ";
		cin >> num1;
		cout << "Enter another integer: ";
		cin >> num2;

		// chon giải pháp giải quyết
		int chon = 0;
		while (1) {
			cout << "Nhap: (1 || 2 || 0 thoat)";
			cin >> chon;
			/* 1. Solution 1*/
			if (chon == 1) {
				// try-catch block
				try {
					cout << "Result: " << quotient(num1, num2) << endl;
				}
				catch (...) {
					cout << "Phep chia cho zero!" << endl;
				}
			}
			/* 2. Solution 2*/
			else if (chon == 2) {
				// try-catch block
				try {
					cout << "Result of divition: " << stdQuotient(num1, num2);
					cout << endl;
				}
				catch (invalid_argument ex) {
					cout << ex.what() << endl;
				}
			}
			else 
				break;
		}
	}
	return 0;
}