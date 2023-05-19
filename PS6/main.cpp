/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps6>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <4.10.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#include "RandWriter.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  if (argc < 3 || argc > 3) {
    std::cout << "Invalid command arguments." << std::endl;
    std::cout << "Correct usage: ./TextWriter <order> <length> < input.txt" << std::endl; //NOLINT
    return 0;
  }

  int k = atoi(argv[1]);
  int L = atoi(argv[2]);
  std::string yoho = "yoho fox";

  std::string text;
  std::string next;
  while (std::cin >> next) {
    text += " " + next;
    next = "";
  }

  RandWriter a(text, k);

  std::string temp;
  std::string test = "gagggagaggcgagaaa";
  for (int i = 0; i < k; i++)
    temp.push_back(text[i]);

  std::cout << a.generate(temp, L) <<  std::endl;
}

