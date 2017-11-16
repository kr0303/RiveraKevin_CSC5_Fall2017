/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LordH
 *
 * Created on November 14, 2017, 9:57 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */

int numAcc(string);
void lowest(int, int, int, int, int);

int main(int argc, char** argv)
{
    int accN, accS, accE, accW, accC;
    for(int i=0; i<5; i++)
    {
        switch(i)
        {
        case 0:
            accN = numAcc("North");
            break;
        case 1:
            accS = numAcc("South");
            break;
        case 2:
            accE = numAcc("East");
            break;
        case 3:
            accW = numAcc("West");
            break;
        default:
            accC = numAcc("Central");
            
        }
    }
    lowest(accN, accS, accE, accW, accC);
    return 0;
}

int numAcc(string reg)
{
    int accs = 0;
    cout << "Input the number of accidents for " << reg << " :";
    cin >> accs;
    
    return accs;
}

void lowest(int r1, int r2, int r3, int r4, int r5)
{
    int lowest = 0;
    string reg = "";
    
    if(r1 < r2 && r1 < r3 && r1 < r4 && r1 < r5)
    {
        lowest = r1;
        reg = "North";
    }
    else if(r2 < r1 && r2 < r3 && r2 < r4 && r2 < r5)
    {
        lowest = r2;
        reg = "South";
    }
    if(r3 < r1 && r3 < r2 && r3 < r4 && r3 < r5)
    {
        lowest = r3;
        reg = "East";
    }
    if(r4 < r1 && r4 < r2 && r4 < r3 && r4 < r5)
    {
        lowest = r4;
        reg = "West";
    }
    else
    {
        lowest = r5;
        reg = "Central";
    }
    
    cout << "Region with least accidents is " << reg << " with " << lowest <<
            " accidents.";
}

