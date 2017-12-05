#include <iostream>
#include <cstdlib>
using namespace std;

// constant number for arrays
const int LUCKY_NUMS =10;

// function prototype
int tixSrch(const int [], int, int);

int main ()
{    
    int winNum; // declares winning number
    int playerNum;  // holds the player input
    int ticket;     // checks if number is winner

    // array holding the winning tickets for each week
    int lotto[LUCKY_NUMS] = {13579, 26791, 26792, 33445, 55555,
                             62483, 77777, 79422, 85647, 93121};	

    for (int week = 0; week < 10; week++)
    {
	// winning lotto tickets for each week
	ticket = lotto[week];
		
        // user input for ticket number
	cout << "Please enter your 5-digit ticket number for week " << (week + 1) << ": " << endl;
	cin >> playerNum;
	
        // linear search for winning ticket
	winNum = tixSrch(lotto, LUCKY_NUMS, playerNum); 
        
	// if user did not win
	if ((winNum == -1) || playerNum != ticket)
	{
            cout << "Sorry, you did not win.\n";
            cout << "Thanks for playing!\n\n";
	}
				
	// user wins 
	else if (playerNum == ticket)
	{
            cout << "You have won yourself more tax payment!\n";
            cout << "Congratulations!\n\n";				
	}
    }
	return 0;
}

// linear search for winning ticket of the week
int tixSrch(const int tixList[], int numTix, int winNum)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while ((index < numTix) && !found) 
	{
		if (tixList[index] == winNum)
		{
			found = true;
			position = index;
		}
		index ++;
	}
	return position;
}