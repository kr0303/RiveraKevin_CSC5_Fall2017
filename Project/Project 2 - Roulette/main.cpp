#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// FUNCTIONS ///////////////////////////////////////////////////////////////////

// This function is used when the player decides to play on one single number.
int snPlay(int, int, int, int);
// This function is used to check if number is even.
bool isEven(int n);
// This function shows current balance after a play.
int showBal(int n);
// This function is used for when player plays on even.
int evnPlay(int, int, int);
// This function is used for when player plays on odd.
int oddPlay(int, int, int);
// This function is used for when player wants to play again.'
int playAgn(int, int, int, int, char);
// This function displays the final results
int res(int, int);

// constant for the random numbers to be generated
int const MIN_NUM = 1, MAX_NUM = 36;

   /* // final results
    if(wins < bet){
        cout << "You lost a total of $" << abs(wins); // absolute value used
    }                                                 // to not show negative
    else
        cout << "You won a total of $" << wins;
    * */

int main()
{
    int num;    // number for input for number gametype
    int rng;    // random number to be generated
    int bBal;    // beginning balance of player
    int cBal;   // current balance
    
    char agn;    // play again?

    float bet; // bet inputted

    // array for player decisions (number, even, odd)
    char gamet[4];

    // display main menu
    cout << "\t\tWelcome to Roulette!\n\n";
    cout << "=================================================================\n";
    
    // player inputs balance to be played
    cout << "Enter amount of money to be played: \n$";
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
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    
    if(!strcmp(gamet,"1")||(!strcmp(gamet,"1.")))
    {
        snPlay(num, rng, bet, cBal);
    }
    
    if(!strcmp(gamet,"2")||(!strcmp(gamet,"2.")))
    {
        oddPlay(rng, bet, cBal);
    }
    
    if(!strcmp(gamet,"3")||(!strcmp(gamet,"3.")))
    {
        evnPlay(rng, bet, cBal);
    }
    res(bBal, cBal);
    
    return 0;
}

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
    cout << "You are currently sitting on $" << n << endl << endl;
}

// displays final results
int res(int bb, int c)
{
    cout << "Your results:\n";
    cout << "You entered the game with: $" << bb << endl;
    cout << "Your ending balance:       $" << c << endl;
    cout << "Total winnings:            $" << bb - c << endl;
}

// play on one number
int snPlay(int n, int r, int b, int c)
{
    cout << "\nWhat number would you like to bet on? ";   // what number to bet on
    cin >> n; 
        
    // random number generator between 0-36
    srand(time(NULL));
    r = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

    cout << "The ball landed on " << r << "\n";

    // loss
    if(n != r)
    {
        cout << "You lose $" << b << "\n";
        c -= b;    // add -bet to winnings
    }
    // win
    else
    {
        cout << "You win $" << 35*b << endl;
        c += 35*b; // multiply bet times 35 and add to winnings
    }
    
    showBal(c);
    return c;
}

// play on even numbers
int evnPlay(int r, int b, int c)
{
    // random number generator between 1-36
        srand(time(NULL));
        r = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        cout << "The ball landed on " << r << endl;

            // win
            if(isEven(r))
            {
                cout << "You win $" << b << endl;
                c += b; // add bet to winnings
            }
            // loss
            else
            {
                cout << "You lose $" << b << endl;
                c -= b; // add -bet to winnings
            }
        showBal(c);
        return c;
}

// play on odd numbers
int oddPlay(int r, int b, int c)
{
        // random number generator between 1-36
        srand(time(NULL));
        r = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        cout << "The ball landed on " << r << endl;
            
            // loss
            if(isEven(r)) // check if random number is even
            {   // if even, then lose because betted on odd
                cout << "You lost $" << b << endl;
                c -= b;    // add bet to winnings
            }
            // win
            else
            {
                cout << "You win $" << b << endl;
                c += b;    // add -bet to winnings
            }
        showBal(c);
        return c;
}
/*
int playAgn(int n, int r, int b, int c, char g)
{
     // player inputs their money for bet
    cout << "\nHow much would you like to bet?\n$"; 
    cin >> b;
    
    // select bet type
    cout << "\nChoose your type of bet:\n";
    cout << "1. Specific Number\n";
    cout << "2. Odd Numbers\n";
    cout << "3. Even Numbers\n";
    cout << "4. Black Numbers\n";
    cout << "5. Red Numbers\n";
    cin >> g;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    
    if(!strcmp(g,"1")||(!strcmp(g,"1.")))
    {
        snPlay(n, r, b, c);
    }
    
    if(!strcmp(g,"2")||(!strcmp(g,"2.")))
    {
        oddPlay(r, b, c);
    }
    
    if(!strcmp(g,"3")||(!strcmp(g,"3.")))
    {
        evnPlay(r, b, c);
    }
}
 */