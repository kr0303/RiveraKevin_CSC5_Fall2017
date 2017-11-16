/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LordH
 *
 * Created on November 14, 2017, 9:04 PM
 */

#include <iostream>
#include <cmath>

using namespace std;
float KE (int mass, int velo);

/*
 * 
 */
int main(int argc, char** argv)
{
    float ke = 0;
    int mass = 0;
    int velo = 0;
    
    cout << "Input the mass in kilograms: ";
    cin >> mass;
    cout << endl;
    cout << "Input the velocity in meters: ";
    cin >> velo;
    cout << endl;
    
    ke = KE(mass, velo);
    cout << "The kinetic energy is " << ke << endl;
    return 0;
}

float KE(int mass, int velo)
{
    return (.5*mass) * (pow(velo,2));
}
