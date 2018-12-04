/*
 * Name: Jasmine Severi
 * Date: 12/03/2018
 * Purpose: Lottery Winners
 * A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit
 * “lucky” combinations. Write a program that initializes an array or a vector with
 * these numbers and then lets the player enter this week’s winning 5-digit number.
 * The program should perform a linear search through the list of the player’s numbers
 * and report whether or not one of the tickets is a winner this week. Here are the
 * numbers:
 * 13579 26791 26792 33445 55555
 * 62483 77777 79422 85647 93121
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int size = 10;

//Function Prototypes
bool srch (int, int[]);

//Program Execution Begins

int main()
{
    int acnt[] = { 13579, 26791, 26792, 33445, 55555,
                   62483, 77777, 79422, 85647, 93121 };
    int num = 0;
    bool found = true;
    
    cout<<"Please enter this week's winning number: ";
    cin>>num;
    
    if (found == srch(num, acnt))
    {
        cout<<"Congratulations! You have a winning number!";
    }
    else
    {
        cout<<"You do not have a winning number. Better luck next time!";
    }
    
    return 0;   
}

bool srch (int enteredValue, int lookUp[size])
{    
    for (int i = 0; i < size; i++)
    {
        if (enteredValue == lookUp[i])
        {
            return true;
        }   
    }
    return false;
}
