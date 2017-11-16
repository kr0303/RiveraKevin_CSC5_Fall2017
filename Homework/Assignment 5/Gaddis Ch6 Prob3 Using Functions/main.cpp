/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LordH
 *
 * Created on November 14, 2017, 10:45 PM
 */
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/*
 * 
 */
float gSales(string);
void highest(float, float, float, float);
int main(int argc, char** argv)
{
    
    float NEsales, SEsales, NWsales, SWsales;
    for(int i=0; i<4; i++)
    {
        switch (i)
        {
        case 0:
            NEsales = gSales("NE");
            break;
        case 1:
            SEsales = gSales("SE");
            break;
        case 2:
            SEsales = gSales("NW");
            break;
        default:
            SWsales = gSales("SW");
            break;
        }
    }
    highest(NEsales, SEsales, NWsales, SWsales);
    return 0;
}

float gSales(string name)
{
    float sales = 0;
    
    cout << "Please enter the sales for division " << name << " $";
    cin >> sales;
    
    while (sales < 0)
    {
        cout << "Sales cannot be a negative number. Please re-enter: $";
        cin >> sales;
    }
    return sales;
}

void highest(float NEsales, float SEsales, float NWsales, float SWsales)
{
    float highest=0;
    string division = "";
    
    if (NEsales > SEsales && NEsales > NWsales && SEsales > SWsales)
    {
        highest = NEsales;
        division = "North East";
    }
    
    else if (SEsales > NEsales && SEsales > NWsales && SEsales > SWsales)
    {
        highest = SEsales;
        division = "South East";
    }
    
    else if (NWsales > NEsales && NWsales > SEsales && NWsales > SWsales)
    {
        highest = NWsales;
        division = "North West";
    }
    
    else
    {
        highest = SWsales;
        division = "South West";
    }
    
    cout << "The division with highest sales is currently " << division <<
            " with total of $" << highest;
}


