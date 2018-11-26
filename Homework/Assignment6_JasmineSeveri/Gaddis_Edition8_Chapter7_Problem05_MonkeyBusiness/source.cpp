/*
 * Name: Jasmine Severi
 * Date: 11/25/2018
 * Purpose: Monkey Business
 * A local zoo wants to keep track of how many pounds of food each of its three monkeys
 * eats each day during a typical week. Write a program that stores this information in a
 * two-dimensional 3 × 5 array, where each row represents a different monkey and each
 * column represents a different day of the week. The program should first have the user
 * input the data for each monkey. Then it should create a report that includes the following
 * information:
 *      • Average amount of food eaten per day by the whole family of monkeys.
 *      • The least amount of food eaten during the week by any one monkey.
 *      • The greatest amount of food eaten during the week by any one monkey.
 * Input Validation: Do not accept negative numbers for pounds of food eaten.
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int Cols = 7;
const int Row = 3;

//Function Prototypes
void runMonk(float[][Cols],float[][Row]);
void prntMon(float[][Cols]);
void prntSta(float[][Row]);
void staMonk(float[][Cols],float[][Row]);
void filMonk(float[][Cols],int);
float cal_high(float[][Cols],int);
float cal_low(float[][Cols],int);
float cal_avg(float[][Cols],int);

//Program Execution Begins

int main() 
{
    //Declare the arrays
    float Food[Row][Cols] = {};
    float Stat[Row][Row] = {};

    //
    runMonk(Food, Stat);
    
    //Exit
    return 0;
}

void runMonk(float Food[][Cols], float Stat[][Row])
{
    //Fill the Monkeys with food then 
    //Calculate the results
    staMonk(Food, Stat);
    //Output Monkey Food
    //printMonkeys(mFood);
    //Output the results
    prntSta(Stat);
}

void prntMon(float Food[][Cols])
{
    for(int row = 0; row < Row; row++)
    {
        for(int col = 0; col < Cols; col++)
        {
            cout<<Food[row][col]<<" ";
        }
        cout<<endl;
    }
}

void prntSta(float Stat[][Row])
{
    cout<<"\nAverage    Most       Least"<<endl;
    for(int row = 1; row <= Row; row++)
    {
        cout<<setprecision(2)<<fixed<<Stat[row-1][0]<<"       ";
        cout<<setprecision(2)<<fixed<<Stat[row-1][1]<<"       ";
        cout<<setprecision(2)<<fixed<<Stat[row-1][2]<<endl;
    }
}

void staMonk(float Food[][Cols],float Stat[][Row])
{
    //Input Monkey Food
    for(int monkey = 1; monkey <= Row; monkey++)
    {
        filMonk(Food, monkey);
    }
    //Calculate all the monkey business
    for(int row = 1; row <= Row; row++)
    {
        Stat[row-1][0] = cal_avg(Food, row);
        Stat[row-1][1] = cal_high(Food, row);
        Stat[row-1][2] = cal_low(Food, row);
    }
}

void filMonk(float Food[][Cols], int row)
{
    for(int col = 0; col < Cols; col++)
    {
        do
        {
            cout<<"Input how much Monkey "<<row<<" ate";
            cout<<" on day "<<col + 1<<" (must be a positive number): ";
            cin>>Food[row - 1][col];
            if (Food[row - 1][col] < 0)
            {
                cout<<"Invalid input. Please put a positive number: ";
                cin>>Food[row - 1][col];
            }
        }
        while(Food[row-1][col] < 0);
    }
}

float cal_high(float Food[][Cols], int row)
{
    float high = Food[row - 1][0];
    for(int col = 1; col < Cols; col++)
    {
        if(high < Food[row - 1][col]) 
        {
            high = Food[row - 1][col];
        }
    }
    return high;
}

float cal_low(float Food[][Cols], int row)
{
    float low = Food[row - 1][0];
    for(int col = 1; col < Cols; col++)
    {
        if(low > Food[row - 1][col])
        {
            low = Food[row - 1][col];
        }
    }
    return low;
}

float cal_avg(float Food[][Cols], int row)
{
    float sum = 0;
    for(int col = 0; col < Cols; col++)
    {
        sum += Food[row - 1][col];
    }
    return sum / Cols;
}