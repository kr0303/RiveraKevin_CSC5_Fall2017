/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LordH
 *
 * Created on November 14, 2017, 9:38 PM
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * 
 */

float fDist(int time = 0);
int main(int argc, char** argv)
{
    int time = 0;
    float dist = 0;
    
    for(int i=1; i<=10; i++)
    {
        dist = fDist(i);
        cout << i << " seconds: " << dist << " meters.\n";
    }
    return 0;
}

float fDist (int time)
{
    float dist = 0;
    const float grav = 9.8;
    
    dist=(.5*grav)*(pow(time,2));
    return dist;
}

