/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps4a>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <3.20.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/

#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(size_t capacity) {
    if (capacity < 1) {
        throw std::invalid_argument
        ("Buffer capacity must be greater than zero.");
    } else {
        buffer = new int16_t[capacity];
        buffer_size = capacity;
    }
}

CircularBuffer::~CircularBuffer() {
    delete buffer;
}

size_t CircularBuffer::size() {
    return buffer_size;
}

bool CircularBuffer::isFull() {
    return(front == (rear + 1) % buffer_size);
}

bool CircularBuffer::isEmpty() {
    return(front == rear);
}

void CircularBuffer::enqueue(int16_t x) {
    if (isFull()) {
        throw std::runtime_error
        ("Cannot enqueue to a ring buffer that is full.");
    } else if (isEmpty()) {
        front = 0;
        rear = (rear + 1) % buffer_size;
        buffer[rear] = x;
    } else {
        rear = (rear + 1) % buffer_size;
        buffer[rear] = x;
    }
}

int16_t CircularBuffer::dequeue() {
    int16_t buf_value;
    if (isEmpty()) {
        throw std::runtime_error
        ("Dequeue: nothing to dequeue as the ring buffer is empty.");
    } else if (front == rear) {  // Only one element in the ring buffer
        front = rear = -1;
    } else {
        buf_value = buffer[front];
        buffer[front] = 0;
        front = (front + 1) % buffer_size;
    }
    return buf_value;
}

int16_t CircularBuffer::peek() {
    if (isEmpty()) {
        throw std::runtime_error
        ("Peek: nothing to peek as ring buffer is empty.");
    } else {
    return buffer[front];
    }
}

int16_t CircularBuffer::peek_front() {
    return buffer[front];
}

int16_t CircularBuffer::peek_rear() {
    return buffer[rear];
}
