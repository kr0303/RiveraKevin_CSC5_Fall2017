#include <iostream>

using namespace std;

// constant used for array
const int NUM_ELEMENTS = 18;

// function prototype
bool srchArr(int, int[NUM_ELEMENTS]);

int main()
{
	int acct[] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
					  8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
				     1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };

	int accNum = 0;
	bool found = true;
        
        // user input account number
	cout << "Please enter your account number: ";
	cin >> accNum;

        // check whether account number exists
	if (found == srchArr(accNum, acct))
		cout << "\nAccount " << accNum << " is a valid account" << endl;
	else
		cout << "\nAccount " << accNum << " is NOT a valid account" << endl;

	return 0;
}

// function that looks within the array for user input
bool srchArr(int enteredValue, int lookUpArray[NUM_ELEMENTS] )
{
	for (int i = 0; i < NUM_ELEMENTS; i++)
	{
		if (enteredValue == lookUpArray[i])
			return true;
	}

	return false;
}

