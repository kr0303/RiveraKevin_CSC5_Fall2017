#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

bool isEven(int n)
{
    if (n%2==0)
        return true;
    else
        return false;
}

int main()
{
    // Set as CONSTANT for Random number generation
    int const MIN_NUMBER = 0, MAX_NUMBER = 36;
    int number;
    int random;

    float bet, winnings = 0;

    // Use arrays for player decision
    char gametype[2];

    // Main Menu Screen
    cout << "Welcome to Roulette!\n\n";
    cout << "How much would you like to bet?\n$";
    cin >> bet;

    cout << "Betting on a specific number (N), odd numbers(O), or even numbers(E)? ";
    cin >> gametype;

    // User selects a specific number to place bet on
    if(!strcmp(gametype,"N")||(!strcmp(gametype,"n")))
    {
        cout << "What number would you like to bet on? ";
        cin >> number;
         
        srand(time(NULL));
        random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

        cout << "The ball landed on " << random << "\n";

    // Lose
    if(number != random)
    {
        cout << "You lose $" << bet << "\n";
        winnings -= bet;
    }
    // Win
    else
    {
        cout << "You win $" << 35*bet << endl;
        winnings += 35*bet;
    }
    }

// User selects even or odd
    if((!strcmp(gametype,"E")||(!strcmp(gametype,"e"))))
    {

        srand(time(NULL));
        random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
        cout << "The ball landed on " << random << endl;

        // selects EVEN
        if(gametype == "E"||"e")
        {
        // even win
            if(isEven(random))
            {
                cout << "You win $" << bet << endl;
                winnings += bet;
            }
        // even lose
            else
            {
                cout << "You lose $" << bet << endl;
                winnings -= bet;
            }
        }

        
    }
    
    if((!strcmp(gametype,"O")||(!strcmp(gametype,"o"))))
    {

        srand(time(NULL));
        random = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
        cout << "The ball landed on " << random << endl;

        // selects odd
        if(gametype == "O"||"o")
        {
        // even win
            if(isEven(random))
            {
                cout << "You lost $" << bet << endl;
                winnings -= bet;
            }
        // even lose
            else
            {
                cout << "You win $" << bet << endl;
                winnings += bet;
            }
        }

        
    }

    // Final Results
    if(winnings < bet){
        cout << "You lost a total of $" << abs(winnings);
    }
    else
        cout << "You won a total of $" << winnings;
    return 0;
}