/*
 * Name: Jasmine Severi
 * Date: 12/3/2018
 * Purpose: Rainfall Statistics Modification
 * Modify the Rainfall Statistics program you wrote for Programming Challenge 2 of
 * Chapter 7 . The program should display a list of months, sorted in order of rainfall,
 * from highest to lowest.
 */

//System Libraries
#include <iostream> //I/O Library
#include <iomanip> //I/O manipulator
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes

//Program Execution Begins

int main()
{
    float rain[12];
    float copy[12];
    
    //Assign values to rain array
    for (int i = 0; i < 12; i++)
    {
        cout<<"Enter rainfall for month "<<i+1<<" (must be a positive number): ";
        cin>>rain[i];
        if (rain[i] < 0)
        {
            cout<<"Invalid input."<<endl;
            return 0;
        }
    }
    
    for (int i = 0; i < 12; i++)
    {
        copy[i] = rain[i];
    }
    
    //Sort
    int minin = 0;
    
    for (int i = 0; i < 12; i++)
    {
        int minin = i;
        int minval = rain[i];
        for (int c = i + 1; c < 12; c++)
        {
            if (rain[c] < minval)
            {
                minval = rain[c];
                minin = c;
            }
        }
        
        int temp = rain[i];
        rain[i] = minval;
        rain[minin] = temp;
    }
    
    for (int i = 0; i < 12; i++)
    {
        cout<<"Month "<<copy[i]<<": "<<rain[i]<<endl;
    }
    
    return 0;
}
