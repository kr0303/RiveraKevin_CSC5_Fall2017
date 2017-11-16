/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LordH
 *
 * Created on November 14, 2017, 9:29 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
float calRet(float, float);
int main(int argc, char** argv)
{
    float wholeC = 0;
    float perc = 0;
    float totP = 0;
    cout << "Input a number for the wholesale price and the percentage:\n";
    cin >> wholeC >> perc;
    cout << endl;
    
    totP = calRet(wholeC, perc);
    cout << "The total cost is: $" << totP;
    
    return 0;
}

float calRet(float cost, float perc )
{
    float totC = 0;
    totC = ((cost/100)*perc)+cost;
    return totC;
}