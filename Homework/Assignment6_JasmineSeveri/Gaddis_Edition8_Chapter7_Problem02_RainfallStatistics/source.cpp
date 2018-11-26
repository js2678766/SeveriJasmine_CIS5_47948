/*
 * Name: Jasmine Severi
 * Date: 11/25/2018
 * Purpose: Rainfall Statistics
 * Write a program that lets the user enter the total rainfall for each of 12 months into
 * an array of doubles. The program should calculate and display the total rainfall for
 * the year, the average monthly rainfall, and the months with the highest and lowest
 * amounts.
 * Input Validation: Do not accept negative numbers for monthly rainfall figures.
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
    float total = 0;
    float average = 0;
    float max = 0;
    double min = 0;
    float temp = 0;
    
    //Assign values to rain array
    for (int i = 0; i < 12; i++)
    {
        cout<<"Enter rainfall for month "<<i+1<<"(must be a positive number): "<<endl;
        cin>>rain[i];
        if (rain[i] < 0)
        {
            cout<<"Invalid input."<<endl;
            return 0;
        }
        total += rain[i];
    }
    
    //Average
    average = total / 12;
    
    max = rain[0];
    min = rain[0];
    
    for (int i = 1; i <= 12; i++)
    {
        temp = rain[i];
        if (temp < min)
        {
            min = temp;
        }
        if (temp > max)
        {
            max = temp;
        }
    }
    
    cout<<"Total rainfall was: "<<setprecision(2)<<fixed<<showpoint<<total<<endl;
    cout<<"Average rainfall was: "<<setprecision(2)<<fixed<<showpoint<<average<<endl;
    cout<<"Highest rainfall was: "<<setprecision(2)<<fixed<<showpoint<<max<<endl;
    cout<<"Lowest rainfall was: "<<setprecision(2)<<fixed<<showpoint<<min<<endl;
    
    return 0;
}
