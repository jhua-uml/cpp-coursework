// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
}

/*An more in-depth test for the step function where it checks
that the register bits has been correctly shifted once to the
left after one call to the step function. The test checks the
first 15-bits and ignores the last bit.
*/

BOOST_AUTO_TEST_CASE(checkLeftShift) {
  FibLFSR a("0110101010001100");
  a.step();
  BOOST_REQUIRE(a.get15Bits() == "110101010001100");
}

/*Checks the number of bits in the seed that's passed to the
constructor is equal to 16, otherwise throw an exception. This
does not check whether the seed is valid meaning the register
contains only 0's and 1's.*/

BOOST_AUTO_TEST_CASE(checkExcpt) {
  BOOST_REQUIRE_THROW(FibLFSR abc("011"), std::out_of_range);
}