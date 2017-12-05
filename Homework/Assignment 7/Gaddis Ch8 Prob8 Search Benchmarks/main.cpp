#include <iostream>

using namespace std;

// Function prototypes
int linearSearch(int [], int, int);
int binarySearch(int [], int, int);

const int SIZE = 20;

int main()
{
    // array for numbers to be sorted
    int array [SIZE] = {1, 83, 249, 387,507, 609, 729, 895, 1027, 1107, 29, 163, 
                        307, 467, 559, 673, 825, 971, 1067, 1145};

    // initialization of variables and declaration
    int count1, count2;
    count1 = linearSearch(array, SIZE, 319);
    count2 = binarySearch(array,SIZE,319);
    
    cout << "Number of comparisons in linear search: " << count1 << endl;
    cout << "Number of comparisons for binary search: " << count2 << endl;
    return 0;
}
//linear search function
int linearSearch(int list[], int numElems, int value)
{
    
    int index = 0;
    int position = -1;
    int count=0;
    bool found = false;

    while (index < numElems && !found)
    {
        if (list[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
        count++;
    }
    return count;
}

// binary search function
int binarySearch(int array[], int size, int value)
{
    int srst = 0,
        last = size - 1,
        middle,
        position = -1;
    int count = 0;
    
    bool found = false;
    
    while (!found && srst <= last)
    {
        middle = (srst + last) / 2;
        
        if (array[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)
        {
            last = middle - 1;
            count++;
        }
        else
        {
            srst = middle + 1;
            count++;
        }
        count++;
    }
    return count;
}
