/*Name: <John Hua>*/
/*Course name: <COMP.2040>*/
/*Assignment: <ps5>*/
/*Instructor's name: <Dr. James Daly>*/
/*Date: <4.4.2022>*/
/*Sources Of Help: */
/*Copyright 2022 <John Hua>
/************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <SFML/System.hpp>

using namespace std;

#include "EDistance.h"

sf::Clock clock1; 
sf::Time t;

int main() {

    string gene_seq1;
    cin >> gene_seq1;

    string gene_seq2;
    cin >> gene_seq2;

    EDistance e1(gene_seq1, gene_seq2);
    std::cout << "Edit Distance =  "  << e1.optDistance() << std::endl;
    std::cout <<  e1.alignment() << std::endl;
    e1.printTable();

    t = clock1.getElapsedTime(); 
    cout << "Execution time: " << t.asSeconds() << " seconds" << endl;
    std::cout << "Edit Distance =  "  << e1.optDistance() << std::endl;
    //cout << gene_seq1 << " " << gene_seq2 << endl;
    return 0;
}