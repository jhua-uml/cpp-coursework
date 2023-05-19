/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps6>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <4.10.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#ifndef _HOME_JHUA_COMPUTING_IV_PS6_RANDWRITER_H_
#define _HOME_JHUA_COMPUTING_IV_PS6_RANDWRITER_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>

class RandWriter {
 public:
    RandWriter(std::string text, int k);
    /*Order k of Markov model*/
    int orderK() const;
    int freq(std::string kgram);
    int freq(std::string kgram, char c);
    char kRand(std::string kgram);
    std::string generate(std::string kgram, int L);

    friend std::ostream& operator<<(std::ostream& output, RandWriter& model);

 private:
    int m_order;
    std::map <std::string, int> kgram_cnt;
    std::string input_text;
    std::string alphabet;
};

#endif  // _HOME_JHUA_COMPUTING_IV_PS6_RANDWRITER_H_
