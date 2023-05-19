/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps4b>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <3.28.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/

#include <stdint.h>
#include <iostream>
#include <string>
#include <random>

#include "CircularBuffer.h"
#include "StringSound.h"


int main() {
    CircularBuffer ring_buffer(5);
    CircularBuffer ring_buffer2(5);

    ring_buffer.enqueue(1);
    ring_buffer.enqueue(2);
    ring_buffer.enqueue(3);
    ring_buffer.enqueue(4);
    ring_buffer.enqueue(5);
    std::cout << "Item dequeued was: " << ring_buffer.dequeue() << std::endl;
    std::cout << "Item dequeued was: " << ring_buffer.dequeue() << std::endl;
    ring_buffer.enqueue(7);
    ring_buffer.enqueue(8);
    // std::cout << ring_buffer.size() << std::endl;
    // std::cout << ring_buffer.peek_front() << std::endl;
    // std::cout << ring_buffer.peek_rear() << std::endl;

    if (ring_buffer.isFull()) {
        std::cout << "Ring buffer full." << std::endl;
    } else {
        std::cout << "Ring buffer has space." << std::endl;
    }

    std::cout << ring_buffer2.size() << std::endl;
    std::cout << ring_buffer2.buffer[2] << std::endl;

    StringSound string_test(50.0);
    std::cout << "StringSound buffer size initialized to: "
              << string_test._cb->size() << std::endl;
    string_test.pluck();
    std::cout << "Testing pluck method that it enqueues random values correctly: " << std::endl; //NOLINT
    for (size_t i = 0; i < 10; i++) {
        std::cout << string_test._cb->buffer[i] << std::endl;
    }

    std::cout << "Current sample: " << string_test.sample() << std::endl;
    string_test.tic();
    std::cout << "Sample after call to tic(): " << string_test.sample() << std::endl; //NOLINT
    std::cout << "Current time: " << string_test.time() << std::endl;
    return 0;
}
