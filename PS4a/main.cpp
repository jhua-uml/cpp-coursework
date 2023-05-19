#include <iostream>
#include <string>
#include <stdint.h>

#include "CircularBuffer.h"

int main() {

    CircularBuffer ring_buffer(5);

    //std::cout << "hello world" << std::endl;
    ring_buffer.enqueue(1);
    ring_buffer.enqueue(2);
    ring_buffer.enqueue(3);
    ring_buffer.enqueue(4);
    ring_buffer.enqueue(5);
    std::cout << "Item dequeued was: " << ring_buffer.dequeue() << std::endl;
    std::cout << "Item dequeued was: " << ring_buffer.dequeue() << std::endl;
    ring_buffer.enqueue(7);
    ring_buffer.enqueue(8);
    
    //std::cout << ring_buffer.size() << std::endl;
    //std::cout << ring_buffer.peek_front() << std::endl;
    //std::cout << ring_buffer.peek_rear() << std::endl;

    if(ring_buffer.isFull()) { 
        std::cout << "Ring buffer full." << std::endl;
    } else {
        std::cout << "Ring buffer has space." << std::endl;
    }
    return 0;
}