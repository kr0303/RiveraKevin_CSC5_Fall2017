#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// bool to check if number is even
bool isEven(int n)
{
    if (n%2==0)
        return true;
    else
        return false;
}

int main()
{
    // constant for the random numbers to be generated
    int const MIN_NUM = 0, MAX_NUM = 36;
    int num;    // number for input for number gametype
    int rng;    // random number to be generated

    float bet, wins = 0; // bet inputted, total earned/lost

    // array for player decisions (number, even, odd)
    char gamet[3];

    // display main menu
    cout << "Welcome to Roulette!\n\n";
                                                                // balance //
    // player inputs their money for bet
    cout << "How much would you like to bet?\n$"; 
    cin >> bet;
    
    // player chooses gametype
    cout << "Betting on a specific number (N), odd numbers(O), or even numbers(E)? ";
    cin >> gamet;

    // run this if player chose inputted N or n
    if(!strcmp(gamet,"N")||(!strcmp(gamet,"n")))
    {
        cout << "What number would you like to bet on? ";   // what number to bet on
        cin >> num;
        
        // random number generator between 0-36
        srand(time(NULL));
        rng = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

        cout << "The ball landed on " << rng << "\n";

    // loss
    if(num != rng)
    {
        cout << "You lose $" << bet << "\n";
        wins -= bet;    // add -bet to winnings
    }
    // win
    else
    {
        cout << "You win $" << 35*bet << endl;
        wins += 35*bet; // multiply bet times 35 and add to winnings
    }
    }
    
    // inputs E or e for gametype
    if((!strcmp(gamet,"E")||(!strcmp(gamet,"e"))))
    {
        // random number generator between 1-36
        srand(time(NULL));
        rng = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        cout << "The ball landed on " << rng << endl;

        if(gamet == "E"||"e")
        {
            // win
            if(isEven(rng))
            {
                cout << "You win $" << bet << endl;
                wins += bet; // add bet to winnings
            }
            // loss
            else
            {
                cout << "You lose $" << bet << endl;
                wins -= bet; // add -bet to winnings
            }
        }
    }
    
    // input O or o for gametype
    if((!strcmp(gamet,"O")||(!strcmp(gamet,"o"))))
    {
        // random number generator between 1-36
        srand(time(NULL));
        rng = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        cout << "The ball landed on " << rng << endl;
            
            // loss
            if(isEven(rng)) // check if random number is even
            {   // if even, then lose because betted on odd
                cout << "You lost $" << bet << endl;
                wins -= bet;    // add bet to winnings
            }
            // win
            else
            {
                cout << "You win $" << bet << endl;
                wins += bet;    // add -bet to winnings
            }
    }


    // final results
    if(wins < bet){
        cout << "You lost a total of $" << abs(wins); // absolute value used
    }                                                 // to not show negative
    else
        cout << "You won a total of $" << wins;
    return 0;
}