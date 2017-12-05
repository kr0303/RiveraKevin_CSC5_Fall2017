//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <cstdlib>      //Rand and Srand
#include <ctime>        //Time function Library
#include <cmath>        //Math Library
using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries

//Global Constants - Not variables only Math/Science/Conversion constants
const unsigned int MAXRAND=pow(2,31)-1;

//Function Prototypes
float pRand();  //[0,1]
float stdNorm();//Normal Distribution N(1,0)
float filAray(float [],int);
float mean(float [],int);
float stdDev(float [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=500000;
    float x[SIZE]={};
    
    //Initialize Variables
    filAray(x,SIZE);
    
    //Display/Output all pertinent variables
    cout<<"The simulated Normal Distribution = "
        <<"N("<<stdDev(x,SIZE)<<","<<mean(x,SIZE)
        <<")"<<endl;
    
    //Exit the program
    return 0;
}

float filAray(float x[],int n){
    for(int i=0;i<n;i++){
        x[i]=stdNorm();
    }
}

float stdDev(float x[],int n){
    float sum=0;
    float xmean=mean(x,n);
    for(int i=0;i<n;i++){
        float delx=x[i]-xmean;
        sum+=(delx*delx);
    }
    return sqrt(sum/(n-1));
}

float mean(float x[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=x[i];
    }
    return sum/n;
}

float stdNorm(){
    float sum=0;
    for(int i=1;i<=12;i++){
        sum+=pRand();
    }
    return sum-6;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                     Random Probability
//Input:
//      None
//Output:
//      Pseudo-Random number between [0,1]
//
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

float pRand(){
    //The maximum random number = 2^31-1
    static const float scale=1/(pow(2,31)-1);
    return rand()*scale;
}