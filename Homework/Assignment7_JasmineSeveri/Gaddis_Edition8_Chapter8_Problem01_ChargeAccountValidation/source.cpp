/*
 * Name: Jasmine Severi
 * Date: 12/03/2018
 * Purpose: Charge Account Validation
 * Write a program that lets the user enter a charge account number. The program should
 * determine if the number is valid by checking for it in the following list:
 * 5658845 4520125 7895122 8777541 8451277 1302850
 * 8080152 4562555 5552012 5050552 7825877 1250255
 * 1005231 6545231 3852085 7576651 7881200 4581002
 * The list of numbers above should be initialized in a single-dimensional array. A simple
 * linear search should be used to locate the number entered by the user. If the user enters
 * a number that is in the array, the program should display a message saying that the
 * number is valid. If the user enters a number that is not in the array, the program should
 * display a message indicating that the number is invalid.
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int numelem = 18;

//Function Prototypes
bool srch (int, int[]);

//Program Execution Begins

int main()
{
    int acnt[] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                   8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                   1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };
    int acnum = 0;
    bool found = true;
    
    cout<<"Please enter your account number: ";
    cin>>acnum;
    
    if (found == srch(acnum, acnt))
    {
        cout<<"\nAccount "<<acnum<<" IS a valid account.";
    }
    else
    {
        cout<<"\nAccount "<<acnum<<" IS NOT a valid account.";
    }
    
    return 0;   
}

bool srch (int enteredValue, int lookUp[numelem])
{    
    for (int i = 0; i < numelem; i++)
    {
        if (enteredValue == lookUp[i])
        {
            return true;
        }   
    }
    return false;
}