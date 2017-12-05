#include <iostream>
using namespace std;

// function prototypes
void bubbleSort(int[], int, int&);
void selectionSort(int[], int, int&);
void displayResults(int, int);

int main()
{
	const int SIZE = 20;
	int list1[SIZE] = {80, 12, 30,  6, 16, 98, 43, 53, 22, 11,
                           10, 79, 28, 67, 86, 15,  4, 63, 42, 51};

	int list2[SIZE] = {80, 12, 30,  6, 16, 98, 43, 53, 22, 11,
                           10, 79, 28, 67, 86, 15,  4, 63, 42, 51};

	int exch1 = 0, exch2 = 0;
	
	bubbleSort(list1, SIZE, exch1);
	
	selectionSort(list2, SIZE, exch2);

	displayResults(exch1, exch2);

}

// this function displays the number of exchanges each sort alogrithm made.
void displayResults(int exch1, int exch2)
{	
	cout << "Number of exchanges made by each sort algorithm.\n";
	cout << "Bubble sort:    " << exch1 << endl;
	cout << "Selection sort: " << exch2 << endl;
}

// This function performs an ascending-order bubble sort on an array. The       
// parameter size holds the number of elements in the array. The function also  
// counts the number of exchanges it makes.  
void bubbleSort(int array[], int size, int &exch)
{
	int temp;
	bool swap;

	do
	{ 	swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
				exch++;
			}
		}
	} while (swap);
 }

// This function performs an ascending-order selection sort on an array. The    
// parameter size holds the number of elements in the array. The function also  
// counts the number of exchanges it makes.
void selectionSort(int array[], int size, int &exch2)
{
	int startScan, minIndex, minValue;

	for (int startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
				exch2++;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}