#include "ProgramFrame.h"


void ProgramFrame::StartMessage(ostream& outDevice) {
	outDevice << "Welcome, entering data: ";
}

void ProgramFrame::ErrorMessage(ostream& outDevice) {
	outDevice << "Input data error!" << endl;
}


bool ProgramFrame::AskToContinue(istream& inDevice, ostream& outDevice) {
	char ch;
	outDevice << "Press 'Y' to continue, other key to stop ...";
	inDevice >> ch;
	return ( ch == 'y' || ch == 'Y' );
}

void ProgramFrame::Run(istream& inDevice, ostream& outDevice) {
	bool ToContinue;
	do {
		StartMessage(outDevice);
		Input(inDevice);
		if (!ValidData()) {
			ErrorMessage(outDevice);
			continue;
		}
		Processing();
		Output(outDevice);
		ToContinue = AskToContinue(inDevice, outDevice);
	} while (ToContinue);
}
