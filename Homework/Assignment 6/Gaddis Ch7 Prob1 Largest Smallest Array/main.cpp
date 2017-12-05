#include <iostream>

using namespace std;

int main()
{
    int num[10]; // numbers
    int sm = 0; // smallest number
    int lrg = 0; // largest number
    int temp = 0; // temporary 
    
    // user inputs numbers
    for (int i = 0; i < 10; i++)
    {
        cout << "Input number " << i+1 << ": " << endl;
        cin >> num[i];
    }
    
    sm = num[0];
    lrg = num[0];
    
    for (int i = 1; i <= 10; i++)
    {
        temp = num[i];
        if (temp < sm)
            sm = temp;
        if (temp > lrg)
            lrg = temp;
    }
    
    // results
    cout << "Largest number is: " << lrg << endl;
    cout << "Smallest number is: " << sm << endl;
    
    return 0;
}