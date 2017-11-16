#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/*
 * 
 */

int coinToss(void)
{
    const int num[2] = {1,2};
    // generates a random number between 0-1
    int random = rand()%2;
    return random[num];
}

int main(int argc, char** argv)
{
    // initialize the random seed
    srand(time(NULL));
    
    string result;
    int loop;
    int rng;
    cout << "Flip the coin how many times?\n";
    cin >> loop; 
    cout << endl;
    cout << "Loop   Result\n";
    cout << "====================================\n";
    
    for(int i=1; i<=loop; i++)
    {
        rng = coinToss();
        if (rng == 1)
        {
            result = "Heads";
        }
    
        else if (rng == 2)
        {
            result = "Tails";
        }
        cout << setw(4) << i << setw(9) << result << endl;
    }
    return 0;
}

