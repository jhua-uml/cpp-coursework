/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps1a>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <1.31.2022>*/
/*Sources Of Help: <Daly's Comp4 Discord Server / Boost Documentation>*/
/************************************************************/


#include "FibLFSR.h"
using namespace std;


FibLFSR::FibLFSR(string seed) {
		if (seed.length() != 16) {
			throw std::out_of_range("Out of range: Invalid seed input.");
		} else {
		_register = seed;
		}
}

string FibLFSR::get15Bits() {

	_register.pop_back();
	return _register;

}

int FibLFSR::getRegSize() {

	return _register.length();

}


int FibLFSR::step() {

	string temp;

	int newbit =
    _register.at(0) ^
	_register.at(2) ^
	_register.at(3) ^
	_register.at(5);

	for (unsigned int i = 0; i < _register.length()-1; i++) {
		temp.push_back(_register.at(i + 1));
	}

	temp.push_back(newbit+48);
	_register = temp;

	return newbit;
}

int FibLFSR::generate(int k) {

	int genBit = 0;

	for (int j = 0; j < k; j++) {
			genBit = genBit*2 + step();
	}

	return genBit;
}



ostream& operator<< (ostream& output, const FibLFSR& fiblfsr) {
	output << fiblfsr._register;
	return output;
}

/*int main() {

	FibLFSR fiblfsr("1011011000110110");
	
	// cout << fiblfsr << "	" << fiblfsr.step() << endl;
	cout << fiblfsr << "	" << fiblfsr.generate(9) << endl;

	return 0;
}
*/