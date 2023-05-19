/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps6>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <4.10.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "RandWriter.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(model_zero) {
    RandWriter model_zero
    ("gagggagaggcgagaaa", 0);

    // function must return zero
    BOOST_REQUIRE
    (model_zero.orderK() == 0);

    // throws excpt if length of kgram != order
    BOOST_REQUIRE_THROW
    (model_zero.freq("g"), std::runtime_error);

    // length of sequence
    BOOST_REQUIRE
    (model_zero.freq("") ==  17);

     // occurences of 'g' in sequence
    BOOST_REQUIRE
    (model_zero.freq("", 'g') == 9);

    // occurences of 'b' in sequence
    BOOST_REQUIRE
    (model_zero.freq("", 'b') == 0);

    BOOST_REQUIRE_THROW
    (model_zero.kRand("g"), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(model_one) {
    // initializing test sequence order=1
    RandWriter model_one
    ("gagggagaggcgagaaa", 1);

    BOOST_REQUIRE(model_one.orderK() == 1);
    BOOST_REQUIRE_THROW(model_one.freq("gg"), std::runtime_error);
    BOOST_REQUIRE_NO_THROW(model_one.freq("g"));
    BOOST_REQUIRE(model_one.freq("g", 'a') == 5);
    BOOST_REQUIRE_THROW(model_one.generate("ga", 2), std::runtime_error);
}
