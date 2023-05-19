#ifndef FibLFSR_H
#define FibLFSR_H
#include <iostream>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;


class FibLFSR {
	public:

		FibLFSR(string seed); // constructor to create LFSR with the given initial seed

		int step(); // int step(); // simulate one step and return the new bit as 0 or 1

		int generate(int k); // int generate(int k); // simulate k steps and return k-bit integer

		string get15Bits(); // Returns the first 15-bits of a register. For unit testing purposes.

		int getRegSize(); // Returns the full register size (16-bits). For unit testing purposes.
		
		friend ostream& operator<<(ostream& out, const FibLFSR& fiblfsr);

	private:
		string _register;
};

#endif