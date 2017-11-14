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

// displays current balance remaining
int showBal(int n)
{
    cout << fixed << setprecision(2) << showpoint;
    cout << "You are currently sitting on $" << n << endl;
}

// function for game to run first time
int game()
{
    // constant for the random numbers to be generated
    int const MIN_NUM = 1, MAX_NUM = 36;
    int num;    // number for input for number gametype
    int rng;    // random number to be generated
    int bBal;    // beginning balance of player
    int cBal;   // current balance

    float bet; // bet inputted

    // array for player decisions (number, even, odd)
    char gamet[2];

    // display main menu
    cout << "\t\tWelcome to Roulette!\n\n";
    cout << "=================================================================\n";
    
    // player inputs balance to be played
    cout << "Enter amount of money to be played: $";
    cin >> bBal;
    // set balance input set to current balance
    cBal = bBal;
    
    // player inputs their money for bet
    cout << "\nHow much would you like to bet?\n$"; 
    cin >> bet;
    
    // select bet type
    cout << "\nChoose your type of bet:\n";
    cout << "1. Specific Number\n";
    cout << "2. Odd Numbers\n";
    cout << "3. Even Numbers\n";
    cout << "4. Black Numbers\n";
    cout << "5. Red Numbers\n";
    cin >> gamet;

    // run this if player chose inputted N or n
    if(!strcmp(gamet,"1")||(!strcmp(gamet,"1.")))
    {
        cout << "\nWhat number would you like to bet on? ";   // what number to bet on
        cin >> num;
        
        // random number generator between 0-36
        srand(time(NULL));
        rng = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

        cout << "The ball landed on " << rng << "\n";

    // loss
    if(num != rng)
    {
        cout << "You lose $" << bet << "\n";
        cBal -= bet;    // add -bet to winnings
    }
    // win
    else
    {
        cout << "You win $" << 35*bet << endl;
        wins += 35*bet; // multiply bet times 35 and add to winnings
    }
        
    // display current balance
        showBal(cBal);
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


   /* // final results
    if(wins < bet){
        cout << "You lost a total of $" << abs(wins); // absolute value used
    }                                                 // to not show negative
    else
        cout << "You won a total of $" << wins;
    * */
}

int main()
{
    game();
    return 0;
}