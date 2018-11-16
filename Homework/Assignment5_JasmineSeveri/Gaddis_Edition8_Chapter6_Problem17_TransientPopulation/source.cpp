/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Transient Population
 * Modify Programming Challenge 16 to also consider the effect on population caused by
 * people moving into or out of a geographic area. Given as input a starting population
 * size, the annual birth rate, the annual death rate, the number of individuals who typically
 * move into the area each year, and the number of individuals who typically leave
 * the area each year, the program should project what the population will be numYears
 * from now. You can either prompt the user to input a value for numYears, or you can
 * set it within the program.
 * Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
 * negative numbers for birth rate, death rate, arrivals, or departures.
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
float pop(int years);

//Program Execution Begins

int main()
{
    int years;
    
    cout<<"How many years should be displayed?\n";
    cout<<"Years: ";
    cin>>years;
    if (years < 1)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter a positive number: ";
            cin>>years;
        }
    
    pop(years);
    
    return 0;
}

float pop(int years)
{
    int size, birth, death, newsize, arrive, depart;
    cout<<"What is the starting size of the population?\n";
    cout<<"Size: ";
    cin>>size;
    if (size < 2)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter a positive number of 2 or higher: ";
            cin>>size;
        }
    cout<<"What is the annual birth rate?\n";
    cout<<"Birth rate: ";
    cin>>birth;
    if (birth < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>birth;
        }
    cout<<"What is the annual death rate?\n";
    cout<<"Death rate: ";
    cin>>death;
    if (death < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>death;
        }
    cout<<"What is the annual rate of people moving in?\n";
    cout<<"Arrival rate: ";
    cin>>arrive;
    if (arrive < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>arrive;
        }
    cout<<"What is the annual rate of people moving out?\n";
    cout<<"Departure rate: ";
    cin>>depart;
    if (depart < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>depart;
        }
    for(int year = 1; year <= years; year++)
    {
       newsize = size + birth * size - death * size + arrive * size - depart * size;
       cout<<"Year "<<year<<": "<<newsize<<endl;
    }
}