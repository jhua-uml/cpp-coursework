/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps4a>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <3.19.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#ifndef _HOME_JHUA_COMPUTING_IV_PS4A_CIRCULARBUFFER_H_
#define _HOME_JHUA_COMPUTING_IV_PS4A_CIRCULARBUFFER_H_
#include <stdint.h>
#include <iostream>
#include <string>

class CircularBuffer {
 public:
    explicit CircularBuffer(size_t capacity);
    ~CircularBuffer();
    size_t size();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);

    int16_t dequeue();
    int16_t peek();
    int16_t peek_front();
    int16_t peek_rear();

 private:
    int16_t* buffer;
    size_t front = -1;
    size_t rear = -1;
    size_t buffer_size;
};

#endif  // _HOME_JHUA_COMPUTING_IV_PS4A_CIRCULARBUFFER_H_
