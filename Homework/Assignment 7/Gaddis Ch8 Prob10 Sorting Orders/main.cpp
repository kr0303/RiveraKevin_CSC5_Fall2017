#include <iostream>
using namespace std;

// function prototypes
void displayArray(int[], int);
void bubbleSort(int[], int);
void selectionSort(int[], int);

int main()
{
	const int SIZE = 8;
	int array1[SIZE] = {25, 4, 60, 13, 90, 73, 84, 45};
	int array2[SIZE] = {25, 4, 60, 13, 90, 73, 84, 45};

	cout << "\nContents of the first array.\n";
	displayArray(array1, SIZE);

	cout << "\nBubble sort the first array in ascending order.\n";
	bubbleSort(array1, SIZE);

	cout << "\nContents of the second array.\n";
	displayArray(array2, SIZE);

	cout << "\nSelection sort the second array in ascending order.\n";
	selectionSort(array2, SIZE);

	return 0;
}

// this function displays the contents of an integer array. The parameter size  
// holds the size of the array. 
void displayArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

// this function sorts an integer array in ascending order using the bubble    
// sort method and prints out the array contents after each pass of the sort. 
void bubbleSort(int array[], int size)
{
	int temp;
	bool swap;

	do
	{	swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
			displayArray(array, size);
		}
	} while (swap);
}

// this function sorts an integer array in ascending orger using the selection  
// sort method and prints out the array's contents after each pass of the sort.
void selectionSort(int array[], int size)
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
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
		displayArray(array, size);
	}
}