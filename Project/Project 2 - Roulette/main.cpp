
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <algorithm> // for find
#include <iterator>  // for begin, end
using namespace std;

// FUNCTIONS ///////////////////////////////////////////////////////////////////

// This function is used when the player decides to play on one single number.
int snPlay(int, int, float, int);
// This function is used to check if number is even.
bool isEven(int);
// This function shows current balance after a play.
int showBal(int);
// This function is used for when player plays on even.
int evnPlay(int, float, int);
// This function is used for when player plays on odd.
int oddPlay(int, float, int);
// This function displays the final results
int res(int, int);
// This function is used when the player plays on all black numbers.
int blkPlay(int, float);
// This function is used when the player plays on all red numbers.
int redPlay(int, float);

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
    while (bBal <= 0)
    {
        cout << "\nInsufficient funds to play.\n\n";
        cout << "Enter amount of money to be played: \n$";
        cin >> bBal;
    }
    
    // set balance input set to current balance
    cBal = bBal;
    
    begin:  // links the program to come back here to play again
    // player inputs their money for bet
    cout << "\nHow much would you like to bet?\n$"; 
    cin >> bet;
    // checks if player is inputting valid bet
    while(bet > cBal)
    {
        cout << "\nInsufficient funds to place bet.\n\n";
        cout << "How much would you like to bet?\n$"; 
        cin >> bet;
    }
    errBet:
    // select bet type
    cout << "\nChoose your type of bet:\n";
    cout << "1. Specific Number\n";
    cout << "2. Odd Numbers\n";
    cout << "3. Even Numbers\n";
    cout << "4. Black Numbers\n";
    cout << "5. Red Numbers\n";
    cin >> gamet;
    cout << endl;
    
    // specific number bet
    if(!strcmp(gamet,"1")||(!strcmp(gamet,"1.")))
    {
        cout << "You are betting on a specific number.\n";
        cBal=snPlay(num, rng, bet, cBal);
    }
    // odd number bet
    if(!strcmp(gamet,"2")||(!strcmp(gamet,"2.")))
    {
        cout << "You are betting on odd numbers.\n\n";
        cBal=oddPlay(rng, bet, cBal);
    }
    // even number bet
    if(!strcmp(gamet,"3")||(!strcmp(gamet,"3.")))
    {
        cout << "You are betting on even numbers.\n\n";
        cBal=evnPlay(rng, bet, cBal);
    }
    // black number bet
    if(!strcmp(gamet,"4")||(!strcmp(gamet,"4.")))
    {
        cout << "You are betting on black numbers.\n\n";
        cBal=blkPlay(cBal, bet);
    }
    // red number bet
    if(!strcmp(gamet,"5")||(!strcmp(gamet,"5.")))
    {
        cout << "You are betting on red numbers.\n\n";
        cBal=redPlay(cBal, bet);
    }
    
        // checks if player has enough funds to play again
        if(cBal > 0)
        {
            cout << "Keep playing? (Y/N)\n";
            cin >> agn;
            cout << endl;

            // prompts player if wants to play again
            if ((agn == 'Y')||(agn == 'y'))
            {
                goto begin; // runs the program again from the begin:
            }
        }
        if (cBal <= 0)
        {
            cout << "You are unable to play due to your funds.\n\n";
        }
    res(bBal, cBal);
    
    ofstream results ("Past Results.txt");
    if(results.is_open())
    {
        results << "Your results:" << endl;
        results << "You entered the game with: $" << setw(4) << bBal << endl;
        results << "Your ending balance:       $" << setw(4) << cBal << endl;
        results << "Total earnings:            $" << setw(4) << cBal - bBal << endl;
        results.close();
    }
    
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
    cout << "You are currently sitting on $" << n << endl << endl;
}
// displays final results
int res(int bb, int c)
{
    cout << "Your results:\n";
    cout << "You entered the game with: $" << bb << endl;
    cout << "Your ending balance:       $" << c << endl;
    cout << "Total earnings:            $" << c - bb << endl;
}
// play on one number
int snPlay(int n, int r, float b, int c)
{
    cout << "\nWhat number would you like to bet on? (1-36)\n";   // what number to bet on
    cin >> n;
    while((n > 36)||(n < 1))
    {
        cout << "\nInvalid number.\n\n";
        cout << "What number would you like to bet on? (1-36)\n"; 
        cin >> n;
    }
        
    // random number generator between 0-36
    srand(time(NULL));
    r = rand() % (36 - 1 + 1) + 1;

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
int evnPlay(int r, float b, int c)
{
    // random number generator between 1-36
        srand(time(NULL));
        r = rand() % (36 - 1 + 1) + 1;
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
int oddPlay(int r, float b, int c)
{
        // random number generator between 1-36
        srand(time(NULL));
        r = rand() % (36 - 1 + 1) + 1;
        cout << "The ball landed on " << r << endl;
            
            // loss
            if(isEven(r)) // check if random number is even
            {   
                // if even, then lose because betted on odd
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
// play on black numbers
int blkPlay(int c, float b)
{
    // initialize the random seed
    srand(time(NULL));
    // array for ALL numbers
    int n[36] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                  13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                  23, 24, 25, 26, 27, 28, 29, 30, 31, 33,
                  34, 35, 36 };
    
    // array for black numbers ONLY                   
    int bn[18] = { 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22,
                   24, 26, 28, 29, 31, 33, 35 };
    
    int r = n[rand()%36];  // generates a random number between 0 and 35
    cout << "The ball landed on " << r << endl;
    
    // checks if r is found in second array
    if(find(begin(bn), end(bn), r) != end(bn))
    {
       cout << "You win $" << b << endl;
       c += b;    // add bet to winnings
    }
    else
    {
        cout << "You lost $" << b << endl;
        c -= b;    // add -bet to winnings
    }
    showBal(c);
    return c;
}
// play on red numbers
int redPlay(int c, float b)
{
    // initialize the random seed
    srand(time(NULL));
    // array for ALL numbers
    int n[36] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
                  13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                  23, 24, 25, 26, 27, 28, 29, 30, 31, 33,
                  34, 35, 36 };
    
    // array for red numbers ONLY
    int rn[18] = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21,
                   23, 25, 27, 30, 32, 34, 36 };
    
    int r = n[rand()%36];  // generates a random number between 0 and 35
    cout << "The ball landed on " << r << endl;
    
    // checks if r is found in second array
    if(find(begin(rn), end(rn), r) != end(rn))
    {
       cout << "You win $" << b << endl;
       c += b;    // add bet to winnings
    }
    else
    {
        cout << "You lost $" << b << endl;
        c -= b;    // add -bet to winnings
    }
    showBal(c);
    return c;
}