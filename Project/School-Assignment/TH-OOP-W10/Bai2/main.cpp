/*****************************************************
* Testing
******************************************************/
#include "ageinput.cpp"
int main() {
	int entranAge = 0;
	try {
		AgeInput* input = new AgeInput(24, 55);
		entranAge = input->getAge("Your Age: ");
		cout << "Input Okay. Age = " << entranAge << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	return 0;
}
