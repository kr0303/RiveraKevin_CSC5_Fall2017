//System Libraries
#include <iostream>    //Input/Output Stream Library
#include <cmath>
using namespace std;   //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants

//Function Prototypes 
float pVal (float, float, int); //Present Value

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float F=0; //Future Value
    float r=0; //Interest Value 
    int n=0; //Number of years
    float P=0; 

    //Initialize Variables

    //Process or map the inputs to the outputs
    cout<<"Enter the amount of money you want to save: $"<<endl;
        cin>>F;
    cout<<"Please enter the interest rate: "<<endl;
        cin>>r;
    cout<<"Please enter the number of years you need to save: "<<endl;
        cin>>n;

    P=pVal(F,r,n);
    cout<<"In order to save $"<<F<<" you will need to deposit $"<<P<<endl;

    //Input Data/Variables

    //Process or map the inputs to the outputs

    //Display/Output all pertinent variables

    //Exit the program
    return 0;
}
float pVal(float F, float r, int n)
{
    float P;
    P=F/(pow(1+(r*01),n));
    return P;
}