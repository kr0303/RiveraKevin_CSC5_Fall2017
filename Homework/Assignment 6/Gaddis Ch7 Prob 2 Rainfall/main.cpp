
#include <iostream>     
#include <iomanip>      
using namespace std;    
 

int main(int argc, char** argv) {


    float rainFal[12];
    float tot=0;
    float avg=0;
    float maxR=0; //Maximum rain
    float minR=0; //Minimum rain
    float tempR=0;
   

    for(int i=0;i<12;i++){
        cout<<"Please enter rainfall for month "<<i+1<<": ";
        cin>>rainFal[i];
        tot+=rainFal[i];
    }
   
    avg=tot/12;
   
    maxR=rainFal[0];
    minR=rainFal[0];
   
    for(int i=0;i<12;i++){
        tempR=rainFal[i];
        if (tempR<minR)
            minR=tempR;
        if (tempR>maxR)
            maxR=tempR;
    }
 
    cout<<"Total rainfall was: "<<tot<<endl;
    cout<<"Average rainfall was: "<<avg<<endl;
    cout<<"Highest amount of rainfall was: "<<maxR<<endl;
    cout<<"Least amount of rainfall was: "<<minR<<endl;
 

    return 0;
}