/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps4b>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <3.28.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#ifndef _HOME_JHUA_COMPUTING_IV_PS4B_STRINGSOUND_H_
#define _HOME_JHUA_COMPUTING_IV_PS4B_STRINGSOUND_H_

#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "CircularBuffer.h"

class StringSound {
 public:
  explicit StringSound(double frequency);
  explicit StringSound(std::vector<sf::Int16> init);
  StringSound (const StringSound &obj) = delete;  // no copy const
  ~StringSound();
  void pluck();
  void tic();
  sf::Int16 sample();
  int time();

  CircularBuffer * _cb;
  int _time;
 private:
};

#endif  // _HOME_JHUA_COMPUTING_IV_PS4B_STRINGSOUND_H_
