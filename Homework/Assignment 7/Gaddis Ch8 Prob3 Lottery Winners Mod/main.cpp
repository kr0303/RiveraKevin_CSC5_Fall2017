#include <iostream>
using namespace std;

// function Prototypes
int searchList(int [], int, int);

int main()
{
	const int NUMS = 10;
	int picks[NUMS] = { 13579, 26791, 26792, 33445, 55555,
						62483, 77777, 79422, 85647, 93121 };

	int winNum,		// holds winning numbers
		srch;			// holds search results

	// ask user to enter a five-digit number
	cout << "Enter this week’s winning five-digit number: ";
	cin  >> winNum;

	// search the array for winNum
	srch = searchList(picks, NUMS, winNum);

	// report whether or not one of the tickets is a winner this week.
	if (srch == -1)
		cout << "Sorry, no winning ticket this week.\n";
	else
	{
		cout << "Congratulations!\nYou have the winning five-digit number: " 
			 << picks[srch] << endl;
	}

	return 0;
}

// this function performs a linear search on an integer array. The list array, 
// which has size elements, is searched for the number stored in value. If the 
// number is found, its array subscript is returned. Otherwise -1 is returned.
int searchList(int array[], int size, int value)
{
	int  position = -1,					// Used to record position of search value
		 first = 0,						// First array element
		 last = size - 1,				// Last array element
		 middle;						// Midpoint of search
	bool found = false;					// Flag to indecate if the value was found

	while (!found && first <= last)
	{
		middle = (first + last) / 2; 	// Calculate midpoint 
		if (array[middle] == value)		// If the value is found
		{
			position = middle;			// Record the value's subscript
			found = true;				// Set flag
		}
		else if (array[middle] > value)	// If value is in lower half
			last = middle - 1;
		else 							// If value is in upper half
			first = middle + 1;
	}
	return position;					// Return the position, or -1
}