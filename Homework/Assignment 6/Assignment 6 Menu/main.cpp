#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */

///////////////////////////FUNCTIONS////////////////////////////////////////////
    // program 1
 
////////////////////////////////////////////////////////////////////////////////    
    // program 2
  
////////////////////////////////////////////////////////////////////////////////
    // program 3
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
////////////////////////////////////////////////////////////////////////////////
    // program 4
        void display_filtered(const int array[], int size, int n )
        {
            cout<<"Numbers greater than "<<n<<" are: ";
            for(int i=0;i<size;i++)
                if(array[i]>n)
                cout<<array[i]<<endl;
            cout<<endl;
        }

        void fill( int array[], int size )
        {
            cout<<"Enter "<<size<<" numbers in the array: ";
            for(int i=0;i<size;i++)
                cin>>array[i];
        }

        void display( const int array[], int size )
        {
            cout<<"The numbers in the array are: ";
            for(int i=0;i<size;i++)
                cout<<array[i]<<endl;
            cout<<endl;
        }
 
////////////////////////////////////////////////////////////////////////////////
    // program 5
        float mean(float x[],int n){
                float sum=0;
                for(int i=0;i<n;i++){
                    sum+=x[i];
                }
                return sum/n;
            }
        float pRand(){
        //The maximum random number = 2^31-1
        static const float scale=1/(pow(2,31)-1);
        return rand()*scale;
}
        float stdNorm(){
                float sum=0;
                for(int i=1;i<=12;i++){
                    sum+=pRand();
                }
                return sum-6;
            }
        
        float filAray(float x[],int n){
         for(int i=0;i<n;i++){
             x[i]=stdNorm();
         }
            }

            float stdDev(float x[],int n){
                float sum=0;
                float xmean=mean(x,n);
                for(int i=0;i<n;i++){
                    float delx=x[i]-xmean;
                    sum+=(delx*delx);
                }
                return sqrt(sum/(n-1));
            }

            

            
            
   
int main(int argc, char** argv)
{
    int prg;
    
    cout << "Choose a program to initialize.\n";
    cout << endl;
    cout << "1.  Largest/Smallest Array Values \n";
    cout << "2.  Rainfall Statistics\n";
    cout << "3.  Chips and Salsa\n";
    cout << "4.  Larger Than n\n";
    cout << "5.  Kinetic Energy Calculator\n";
    cin >> prg;
    
////////////////////////////////////////////////////////////////////////////////
    // program 1
    switch(prg)
    {
    case 1:
        int num[10]; // numbers
        int sm = 0; // smallest number
        int lrg = 0; // largest number
        int temp = 0; // temporary 

        // user inputs numbers
        for (int i = 0; i < 10; i++)
        {
            cout << "Input number " << i+1 << ": " << endl;
            cin >> num[i];
        }

        sm = num[0];
        lrg = num[0];

        for (int i = 1; i <= 10; i++)
        {
            temp = num[i];
            if (temp < sm)
                sm = temp;
            if (temp > lrg)
                lrg = temp;
        }

        // results
        cout << "Largest number is: " << lrg << endl;
        cout << "Smallest number is: " << sm << endl;
    }
////////////////////////////////////////////////////////////////////////////////
    // program 2
    switch(prg)
    {    
    case 2:
        float rainFal[12];
        float tot=0;
        float avg=0;
        float maxR=0; //Maximum rain
        float minR=0; //Minimum rain
        float tempR=0;


        for(int i=0;i<12;i++){
            cout<<"Please enter rainfall for month "<<i+1<<": ";
            cin>>rainFal[i];
            tot+=rainFal[i];
        }

        avg=tot/12;

        maxR=rainFal[0];
        minR=rainFal[0];

        for(int i=0;i<12;i++){
            tempR=rainFal[i];
            if (tempR<minR)
                minR=tempR;
            if (tempR>maxR)
                maxR=tempR;
        }

        cout<<"Total rainfall was: "<<tot<<endl;
        cout<<"Average rainfall was: "<<avg<<endl;
        cout<<"Highest amount of rainfall was: "<<maxR<<endl;
        cout<<"Least amount of rainfall was: "<<minR<<endl;
    }
////////////////////////////////////////////////////////////////////////////////
    // program 3
    switch(prg)
    {
    case 3:
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
    }
////////////////////////////////////////////////////////////////////////////////
    // program 4
    switch(prg)
    {
    case 4:
        const int MAX_SIZE = 100;
        int array[MAX_SIZE]={};

        int size;
        cout<<"Enter the number of elements in the array: ";
        cin>>size;
        if(size>MAX_SIZE ) size=MAX_SIZE;
        if(size<1) size=1;

        fill( array, size );
        display( array, size );

        int n;
        cout<<"Enter a value: ";
        cin>>n;

        display_filtered( array, size, n );
    }
////////////////////////////////////////////////////////////////////////////////
    // program 5
    switch(prg)
    {
    case 5:
        const unsigned int MAXRAND=pow(2,31)-1;
        
        //Set the random number seed
        srand(static_cast<unsigned int>(time(0)));

        //Declare Variables
        const int SIZE=500000;
        float x[SIZE]={};

        //Initialize Variables
        filAray(x,SIZE);

        //Display/Output all pertinent variables
        cout<<"The simulated Normal Distribution = "
            <<"N("<<stdDev(x,SIZE)<<","<<mean(x,SIZE)
            <<")"<<endl;
    }

    return 0;
}

