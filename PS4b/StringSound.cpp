/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps4b>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <3.28.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#include "StringSound.h"
#include <math.h>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


#define SAMPLES_PER_SEC 44100


StringSound::StringSound(double frequency) {
    _time = 0;
    if (frequency < 1) {
        throw std::invalid_argument
        ("Frequency must be greater than 0 to initialize circular buffer.");
    } else {
        _cb = new CircularBuffer(ceil(SAMPLES_PER_SEC/frequency));
    }
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    _time = 0;
    if (init.size() < 1)  {
        throw std::invalid_argument
        ("Passed vector's size must be greater than zero.");
    } else {
        _cb =  new CircularBuffer(init.size());
        for (size_t i = 0; !_cb->isFull(); i++) {
            _cb->enqueue(init[i]);
        }
    }
}

StringSound::~StringSound() {
    delete _cb->buffer;
}

void StringSound::pluck() {
    std::random_device rd;

    if (_cb->isFull()) {
        _cb->empty();
    }
    while (!_cb->isFull()) {
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int16_t> uni(-32768, 32767);
        _cb->enqueue(uni(rng));
    }
}

void StringSound::tic() {
    auto n = 0.996 * 0.5 * (_cb->dequeue() + _cb->peek());
    _time++;
}

sf::Int16 StringSound::sample() {
    return _cb->peek();
}

int StringSound::time() {
    return _time;
}
