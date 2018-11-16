/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Population
 * In a population, the birth rate is the percentage increase of the population due to births,
 * and the death rate is the percentage decrease of the population due to deaths. Write a
 * program that displays the size of a population for any number of years. The program
 * should ask for the following data:
 *      • The starting size of a population
 *      • The annual birth rate
 *      • The annual death rate
 *      • The number of years to display
 * Write a function that calculates the size of the population for a year. The formula is
 * N = P + BP − DP
 * where N is the new population size, P is the previous population size, B is the birth rate,
 * and D is the death rate.
 * Input Validation: Do not accept numbers less than 2 for the starting size. Do not accept
 * negative numbers for birth rate or death rate. Do not accept numbers less than 1 for
 * the number of years.
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
    int size, birth, death, newsize;
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
    for(int year = 1; year <= years; year++)
    {
       newsize = size + birth * size - death * size;
       cout<<"Year "<<year<<": "<<newsize<<endl;
    }
}