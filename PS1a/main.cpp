// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

int main() {

	FibLFSR fiblfsr("1011011000110110");
	
	cout << fiblfsr << "	" << fiblfsr.step() << endl;
	cout << fiblfsr << "	" << fiblfsr.step() << endl;
	cout << fiblfsr << "	" << fiblfsr.step() << endl;
	cout << fiblfsr << "	" << fiblfsr.step() << endl;
	cout << fiblfsr << "	" << fiblfsr.step() << endl;
    cout << fiblfsr << "	" << fiblfsr.step() << endl;
    cout << fiblfsr << "	" << fiblfsr.step() << endl;
    cout << fiblfsr << "	" << fiblfsr.step() << endl;
    cout << fiblfsr << "	" << fiblfsr.step() << endl;
    cout << fiblfsr << "	" << fiblfsr.step() << endl;
    
	cout << fiblfsr << "	" << fiblfsr.generate(9) << endl;

	return 0;
}
