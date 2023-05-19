/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps5>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <4.4.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#ifndef EDistance_H
#define EDistance_H
#include <iostream>
#include <string>
#include <vector>


class EDistance {
 public:
    EDistance(std::string a, std::string b);
    int penalty(char a, char b);
    int min(int a, int b, int c);
    int optDistance();
    std::string alignment();
    void printTable();
    friend std::istream& operator>>(std::istream& input, EDistance &gene) {
      input >> gene.aseq >> gene.bseq;
      return input;
    }

    std::string aseq;
    std::string bseq;
    int n;
    int m;
    std::vector<std::vector<int>> optMatrix;
   std::vector<int> values;
 private:
};

#endif  // _HOME_JHUA_COMPUTING_IV_PS4B_CIRCULARBUFFER_H_