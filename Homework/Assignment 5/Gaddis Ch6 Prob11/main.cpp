#include <iostream>

using namespace std;

/*
 * 
 */

float getScore();
float findLow(float &);
float avg();
int main(int argc, char** argv) {

    cout << " The Average 4 Highest Scores = " << avg() << endl;
    return 0;
}

float avg()
{
    float sum;
    float lowest=findLow(sum);
    return (sum-lowest)/4;
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
float getScore()
{
    static int cnt=1;
    float score;
    cout << "Type in test score: " << cnt++ << endl;
    cin >> score;
    return score;
}

