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
#include <algorithm>
#include <string>
#include <vector>
#include <map>

RandWriter::RandWriter(std::string text, int k) {
    m_order = k;
    input_text = text;

    srand(time(NULL));

    /* make the alphabet from the input text string */
    static const size_t npos = -1;
    for (size_t i = 0; i < text.length(); i++) {
        if (alphabet.find(text[i]) == npos) {
            alphabet.push_back(text[i]);
        }
    }
    /*sort the kgram table in descending order*/
    std::sort(alphabet.begin(), alphabet.end(),
              [](char a, char b) {
                  return a > b;
              });

    /* make the kgram table */
    for (size_t i = 0; i < text.length(); i++) {
        std::string tmp;
        std::string tmp2;
        for (size_t j = i; j < i + k; j++) {
            if (j >= text.length()) {
                tmp.push_back(text[j - text.size()]);
            } else {
                tmp.push_back(text[j]);
            }
        }

        if (kgram_cnt.end() ==  kgram_cnt.find(tmp)) {
            kgram_cnt[tmp] = 1;
        } else {
            kgram_cnt[tmp]++;
        }

        for (size_t j = 0; j < alphabet.length(); j++) {
            if (kgram_cnt.find(tmp + alphabet[j]) == kgram_cnt.end())
                kgram_cnt[tmp + alphabet[j]] = 0;
        }

        for (size_t j = i; j < i + (k + 1); j++) {
            if (j >= text.length()) {
                tmp2.push_back(text[j - text.length()]);
            } else {
                tmp2.push_back(text[j]);
            }
        kgram_cnt[tmp2]++;
        }
    }
}

/*returns the order of the markov model*/
int RandWriter::orderK() const {
    return m_order;
}

/*returns the frequency of given kgram in the sequence*/
int RandWriter::freq(std::string kgram) {
    if (kgram.size()  != (unsigned)m_order) {
        throw std::runtime_error
        ("Invalid length k for kgram.");
    }

    std::map<std::string, int>::iterator it;
    it = kgram_cnt.find(kgram);

    if (it == kgram_cnt.end()) {
        return 0;
    } else {
        return it->second;
    }
}

/*returns the frequency of given kgram followed by the
given char 'c' in the sequence. throws an exception
if given kgram length != order*/
int RandWriter::freq(std::string kgram, char c) {
    if (kgram.size()  != (unsigned)m_order) {
        throw std::runtime_error
        ("Invalid length k for kgram.");
    }
    if (m_order  == 0) {
        int cnt = 0;
        for (size_t i = 0; i < input_text.size(); i++) {
            if (input_text[i] == c) {
                cnt++;
            }
        }
        return cnt;
    } else {
        return kgram_cnt[kgram + c];
    }
}

/*returns a random char following the kgram passed to kRand
throws exception if the kgram length != order or if the
kgram doesn't exist within the sequence*/
char RandWriter::kRand(std::string kgram) {
    std::map<std::string, int>::iterator it;
    it = kgram_cnt.find(kgram);

    if (kgram.size() != (unsigned)m_order) {
        throw std::runtime_error
        ("Invalid length k for kgram.");
    } else if (it == kgram_cnt.end()) {
        throw std::runtime_error
        ("No such kgram exists");
    }
    std::string tmp;
    for (size_t i = 0; i < alphabet.size(); i++) {
        for (int j = 0; j < kgram_cnt[kgram + alphabet[i]]; j++)
        tmp.push_back(alphabet[i]);
    }
    return tmp[rand() % tmp.size()];
}

/*generates string of L characters given by command line argument*/
std::string RandWriter::generate(std::string kgram, int L) {
    if (kgram.size() != (unsigned)m_order) {
        throw std::runtime_error
        ("Invalid length k for kgram.");
    }
    std::string gen_string = kgram;
    char rand_c;
    for (size_t i = 0; i < L - (unsigned)m_order; i++) {
        rand_c = kRand(gen_string.substr(i, m_order));
        gen_string.push_back(rand_c);
    }
    return gen_string;
}

/*outputs the kgram table*/
std::ostream& operator<< (std::ostream &output, RandWriter &model) {
  output << "\n_Order: " << model.m_order << "\n";
  output << "Alphabet: "<< model.alphabet << "\n";

  output << "Kgrams Table:" << std::endl;

  std::map<std::string, int>::iterator it;
  std::map<std::string, int> model_temp = model.kgram_cnt;

  for (it = model_temp.begin(); it != model.kgram_cnt.end(); it++) {
    output << it->first << " " << it->second << "\n";
  }

  return output;
}
