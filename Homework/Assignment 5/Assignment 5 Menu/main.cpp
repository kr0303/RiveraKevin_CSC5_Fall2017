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
    float calRet(float cost, float perc )
    {
        float totC = 0;
        totC = ((cost/100)*perc)+cost;
        return totC;
    }
////////////////////////////////////////////////////////////////////////////////    
    // program 2
    float gSales(string name)
    {
        float sales = 0;

        cout << "Please enter the sales for division " << name << " $";
        cin >> sales;

        while (sales < 0)
        {
            cout << "Sales cannot be a negative number. Please re-enter: $";
            cin >> sales;
        }
        return sales;
    }

    void highest(float NEsales, float SEsales, float NWsales, float SWsales)
    {
        float highest=0;
        string division = "";

        if (NEsales > SEsales && NEsales > NWsales && SEsales > SWsales)
        {
            highest = NEsales;
            division = "North East";
        }

        else if (SEsales > NEsales && SEsales > NWsales && SEsales > SWsales)
        {
            highest = SEsales;
            division = "South East";
        }

        else if (NWsales > NEsales && NWsales > SEsales && NWsales > SWsales)
        {
            highest = NWsales;
            division = "North West";
        }

        else
        {
            highest = SWsales;
            division = "South West";
        }

        cout << "The division with highest sales is currently " << division <<
                " with total of $" << highest;
    }
////////////////////////////////////////////////////////////////////////////////
    // program 3
    int numAcc(string reg)
    {
        int accs = 0;
        cout << "Input the number of accidents for " << reg << " :";
        cin >> accs;

        return accs;
    }

    void lowest(int r1, int r2, int r3, int r4, int r5)
    {
        int lowest = 0;
        string reg = "";

        if(r1 < r2 && r1 < r3 && r1 < r4 && r1 < r5)
        {
            lowest = r1;
            reg = "North";
        }
        else if(r2 < r1 && r2 < r3 && r2 < r4 && r2 < r5)
        {
            lowest = r2;
            reg = "South";
        }
        if(r3 < r1 && r3 < r2 && r3 < r4 && r3 < r5)
        {
            lowest = r3;
            reg = "East";
        }
        if(r4 < r1 && r4 < r2 && r4 < r3 && r4 < r5)
        {
            lowest = r4;
            reg = "West";
        }
        else
        {
            lowest = r5;
            reg = "Central";
        }

        cout << "Region with least accidents is " << reg << " with " << lowest <<
                " accidents.";
    }
////////////////////////////////////////////////////////////////////////////////
    // program 4
    float fDist (int time)
    {
        float dist = 0;
        const float grav = 9.8;

        dist=(.5*grav)*(pow(time,2));
        return dist;
    }
////////////////////////////////////////////////////////////////////////////////
    // program 5
    float KE(int mass, int velo)
    {
        return (.5*mass) * (pow(velo,2));
    }
////////////////////////////////////////////////////////////////////////////////
    // program 6
    float degC(float f)
    {
        return (f-32)*5/9;
    }

    float degC(float f,float f1,float f2,float c1,float c2)
    {
        return c1+(c2-c1)*(f-f1)/(f2-f1);
    }
////////////////////////////////////////////////////////////////////////////////
    // program 7
    int coinToss(void)
    {
        const int num[2] = {1,2};
        // generates a random number between 0-1
        int random = rand()%2;
        return random[num];
    }
////////////////////////////////////////////////////////////////////////////////
    // program 8
    float pVal(float F, float r, int n)
    {
        float P;
        P=F/(pow(1+(r*01),n));
        return P;
    }
////////////////////////////////////////////////////////////////////////////////
    // program 9
    float getScore()
    {
        static int cnt=1;
        float score;
        cout << "Type in test score: " << cnt++ << endl;
        cin >> score;
        return score;
    }
    float findLow(float &sum)
    {
        sum=0;
        float lowest = getScore();
        sum+=lowest;
        for(int i=1; i<=4; i++)
        {
            float add=getScore();
            if(add<lowest)lowest=add;
            sum+=add;
        }
        return lowest;
    }
    float avg()
    {
        float sum;
        float lowest=findLow(sum);
        return (sum-lowest)/4;
    }
    
    
int main(int argc, char** argv)
{
    int prg;
    
    cout << "Choose a program to initialize.\n";
    cout << endl;
    cout << "1.  Markup\n";
    cout << "2.  Sales Calculations\n";
    cout << "3.  Number of Accidents\n";
    cout << "4.  Fall Distance\n";
    cout << "5.  Kinetic Energy Calculator\n";
    cout << "6.  Temperature Conversions\n";
    cout << "7.  Coin Toss\n";
    cout << "8.  Saving Money\n";
    cout << "9.  Lowest Score\n";
    cin >> prg;
    
////////////////////////////////////////////////////////////////////////////////
    // program 1
    switch(prg)
    {
    case 1:
        float wholeC = 0;
        float perc = 0;
        float totP = 0;
        cout << "Input a number for the wholesale price and the percentage:\n";
        cin >> wholeC >> perc;
        cout << endl;

        totP = calRet(wholeC, perc);
        cout << "The total cost is: $" << totP;
    }
////////////////////////////////////////////////////////////////////////////////
    // program 2
    switch(prg)
    {    
    case 2:
       float NEsales, SEsales, NWsales, SWsales;
        for(int i=0; i<4; i++)
        {
            switch (i)
            {
            case 0:
                NEsales = gSales("NE");
                break;
            case 1:
                SEsales = gSales("SE");
                break;
            case 2:
                SEsales = gSales("NW");
                break;
            default:
                SWsales = gSales("SW");
                break;
            }
        }
        highest(NEsales, SEsales, NWsales, SWsales); 
    }
////////////////////////////////////////////////////////////////////////////////
    // program 3
    switch(prg)
    {
    case 3:
        int accN, accS, accE, accW, accC;
        for(int i=0; i<5; i++)
        {
            switch(i)
            {
            case 0:
                accN = numAcc("North");
                break;
            case 1:
                accS = numAcc("South");
                break;
            case 2:
                accE = numAcc("East");
                break;
            case 3:
                accW = numAcc("West");
                break;
            default:
                accC = numAcc("Central");

            }
        }
        lowest(accN, accS, accE, accW, accC);
    }
////////////////////////////////////////////////////////////////////////////////
    // program 4
    switch(prg)
    {
        case 4:
        int time = 0;
        float dist = 0;

        for(int i=1; i<=10; i++)
        {
            dist = fDist(i);
            cout << i << " seconds: " << dist << " meters.\n";
        }
    }
////////////////////////////////////////////////////////////////////////////////
    // program 5
    switch(prg)
    {
    case 5:
        float ke = 0;
        int mass = 0;
        int velo = 0;

        cout << "Input the mass in kilograms: ";
        cin >> mass;
        cout << endl;
        cout << "Input the velocity in meters: ";
        cin >> velo;
        cout << endl;

        ke = KE(mass, velo);
        cout << "The kinetic energy is " << ke << endl;
    }
////////////////////////////////////////////////////////////////////////////////
    // program 6
    switch(prg)
    {
    case 6:
        float degCent, degFahr;//independent and dependent variable for Temp
        float f1,f2,c1,c2;//Tabular data points


        f1=32; //Freezing Point of water 32 degrees Fahrenheit
        f2=212;//Boiling Point of water 212 degrees Fahrenheit
        c1=0;  //Freezing Point of water  0 degrees Centigrade
        c2=100;//Boiling Point of water 100 degrees Centigrade

        //Output the Temperature Table
        cout<<"The Temperature Conversion Table"<<endl;
        cout<<"Fahrenheit  Celsius 1   Celsius 2"<<endl;
        cout<<fixed<<setprecision(1)<<showpoint;
        for(int f=f1;f<=f2;f++)
        {
            cout<<setw(7)<<f
                <<setw(14)<<degC(f)
                <<setw(12)<<degC(f,f1,f2,c1,c2)<<endl;
        }
    }
////////////////////////////////////////////////////////////////////////////////
    // program 7
    switch(prg)
    {
    case 7:
        // initialize the random seed
        srand(time(NULL));

        string result;
        int loop;
        int rng;
        cout << "Flip the coin how many times?\n";
        cin >> loop; 
        cout << endl;
        cout << "Loop   Result\n";
        cout << "====================================\n";

        for(int i=1; i<=loop; i++)
        {
            rng = coinToss();
            if (rng == 1)
            {
                result = "Heads";
            }

            else if (rng == 2)
            {
                result = "Tails";
            }
            cout << setw(4) << i << setw(9) << result << endl;
        }
    }
////////////////////////////////////////////////////////////////////////////////
    // program 8
    switch(prg)
    {
    case 8:
        float F=0; //Future Value
        float r=0; //Interest Value 
        int n=0; //Number of years
        float P=0; 

        //Initialize Variables

        //Process or map the inputs to the outputs
        cout<<"Enter the amount of money you want to save: $"<<endl;
            cin>>F;
        cout<<"Please enter the interest rate: "<<endl;
            cin>>r;
        cout<<"Please enter the number of years you need to save: "<<endl;
            cin>>n;

        P=pVal(F,r,n);
        cout<<"In order to save $"<<F<<" you will need to deposit $"<<P<<endl;
    }
////////////////////////////////////////////////////////////////////////////////
    // program 9
    switch(prg){
    case 9:
        cout << " The Average 4 Highest Scores = " << avg() << endl;
    }
    return 0;
}

