#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function protocols
int getTtl(int [], int); // get total

int pOS(int [], int); // position of smallest

int pOL(int [], int); // position of largest

int main()
{
   const int NUM_TYPES = 5;   
   int sales[NUM_TYPES];
   string name[NUM_TYPES] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
  

   // arrays for names and sales
   
   int ttlJSold,    // total jars sold
       hiSProd,     // highest sales product
       loSProd;     // lowest sales product
     
   // user input

	for (int i = 0; i < NUM_TYPES; i++)
	{
		cout << "Jars sold last month of " << name[i] << ": ";
      	cin  >> sales[i];
      
		while (sales[i] < 0)
		{	cout << "Jars sold must be 0 or more.  Please re-enter: ";
		   cin  >> sales[i];
		}
	}

   
   // call function for total sales 
   ttlJSold  = getTtl(sales, NUM_TYPES);
   
   loSProd = pOS(sales, NUM_TYPES);

   hiSProd = pOL(sales, NUM_TYPES);
   
   // output result
   cout << endl << endl;
   cout << "     Salsa Sales Report \n\n";
   cout << "Name              Jars Sold \n";
   cout << "____________________________\n";
 
   
	   cout << name[0] << "                  " << sales[0] << "\n";
       cout << name[1] << "                " << sales[1] << "\n";
	   cout << name[2] << "                 " <<sales[2] << "\n";
	   cout << name[3] << "                   " << sales[3] << "\n";
	   cout << name[4] << "                 " << sales[4] << "\n";  

     // displays the sale results
   
   cout << "\nTotal Sales:" << setw(15) << ttlJSold << endl;
   cout << "High Seller: "  << name[hiSProd] << endl;
   cout << "Low Seller : " << name[loSProd] << endl;    
    
   return 0;
}

// calculates and returns the amount stored in the array
int getTtl (int array[], int numElts)
{
	int total = 0;

	for (int i = 0; i < numElts; i++)
		total += array[i];
	return total;
}

// find and returns the position of array with largest value
int pOL(int array[], int numElts)
{
	int indxLrg = 0;
	
	for (int i = 1; i < numElts; i++)
	{
		if (array[i] > array[indxLrg])
			indxLrg = i;
	}
	return indxLrg;
}

// same as largest but smallest
int pOS(int array[], int numElts)
{
	int indxSml = 0;
	
	for (int i = 1; i < numElts; i++)
	{
		if (array[i] < array[indxSml])
			indxSml = i;
	}		
	return indxSml;
}