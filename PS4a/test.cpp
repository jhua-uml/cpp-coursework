/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps4a>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <3.19.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/

#include <iostream>
#include <string>

#include "CircularBuffer.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

/*Check that invalid argument exception is thrown when attempting to
initialize ring buffer with size < 0*/
BOOST_AUTO_TEST_CASE(checkExcpt_bufferSize) {
  BOOST_REQUIRE_THROW(CircularBuffer buffer_zero(0), std::invalid_argument);
  BOOST_REQUIRE_NO_THROW(CircularBuffer buffer_zero(1));
}

/*Check enqueue, dequeue, and peek functions on an empty and full buffer
of size 5.*/
BOOST_AUTO_TEST_CASE(checkExcpt_queue) {
  CircularBuffer fullBuffer(5);
  CircularBuffer emptyBuffer(5);
  for (auto i = 1; i <= fullBuffer.size(); i++) {
    fullBuffer.enqueue(i);
  }
  BOOST_REQUIRE_THROW(fullBuffer.enqueue(1), std::runtime_error);
  BOOST_REQUIRE_THROW(emptyBuffer.dequeue(), std::runtime_error);
  BOOST_REQUIRE_THROW(emptyBuffer.peek(), std::runtime_error);
}
