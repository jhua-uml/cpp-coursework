/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps4a>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <3.19.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#include <iostream>
#include <string>
#include <vector>

#include "EDistance.h"

using namespace std;

#define PENALTY_GAP 2

string aseq_align = "";
string bseq_align = "";

EDistance::EDistance(string a, string b) : 
optMatrix(a.length() + 1, vector<int>(b.length() + 1)) {
    aseq = a;
    bseq = b;
    n = a.length();
    m = b.length();

    for (size_t i = 0; i <= m; i++)
        optMatrix[0][i] = i * PENALTY_GAP;
    for (size_t i = 0; i <= n; i++)
        optMatrix[i][0] = i * PENALTY_GAP;
}

int EDistance::optDistance() {
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
        optMatrix[i][j] = min(optMatrix[i-1][j-1] + penalty(aseq[i-1], bseq[j-1]),
                                  optMatrix[i-1][j] + PENALTY_GAP,
                                  optMatrix[i][j-1] + PENALTY_GAP);
        }
    }
    return optMatrix[n][m];
    
}

int EDistance::min(int a, int b, int c) {
    if (a <= b && a <= c) 
        return a;
     else if (b <= a && b <= c)
        return b;
     else 
        return c;
}

int EDistance::penalty(char a, char b) {
    return a ==  b ? 0 : 1;
}

string EDistance::alignment() {
    size_t i = aseq.length();
    size_t j = bseq.length();
    for(; i > 0 && j > 0; i--) {
        if(optMatrix[i-1][j-1] + penalty(aseq[i - 1], bseq[j - 1]) == optMatrix[i][j]) {
            aseq_align = aseq[i - 1] + aseq_align;
            bseq_align = bseq[j - 1] + bseq_align;
            //values.push_back(penalty(aseq_align[i], bseq_align[j]));
            j--;
        } else if (optMatrix[i - 1][j] + PENALTY_GAP == optMatrix[i][j]) {
            aseq_align = aseq[i - 1] + aseq_align;
            bseq_align = '-' + bseq_align;
            //values.push_back(2);
        } else {
            aseq_align = '-' + aseq_align;
            bseq_align = bseq[j - 1] + bseq_align;
            //values.push_back(2);
            j--;
        }
    }
    while (i >= 1 && j == 0)
    {
        aseq_align = aseq[i - 1] + aseq_align;
        bseq_align = '-' + bseq_align;
        i--;
    }
    while (j >= 1 && i == 0)
    {
        aseq_align = '-' + aseq_align;
        bseq_align = bseq[j - 1] + bseq_align;
        j--;
    }
    return bseq_align + '\n' + aseq_align;
}

void EDistance::printTable() {
    for(size_t i = 0; i < aseq_align.length(); i++) {
        if (aseq_align[i] == bseq_align[i]) {
            values.push_back(0);
        } else if (aseq_align[i]  != bseq_align[i]) {
            if (aseq_align[i] == '-' || bseq_align[i] == '-') {
                values.push_back(2);
            } else {
                values.push_back(1);
            }
        }
    }
    for (size_t i = 0; i < aseq.length(); i++) {
        cout << aseq_align[i] << " " << bseq_align[i] << " " << values[i] << endl;
    }
}