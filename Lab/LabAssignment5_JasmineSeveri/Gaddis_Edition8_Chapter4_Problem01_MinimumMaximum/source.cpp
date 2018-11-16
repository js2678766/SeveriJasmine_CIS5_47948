/*
 * Name: Jasmine Severi
 * Date: 10/16/2018
 * Purpose: 1. Minimum/Maximum
 * Write a program that asks the user to enter two numbers. The program should use the
 * conditional operator to determine which number is the smaller and which is the larger.
 */

//System Libraries Here
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library created

//User Libraries Here N/A

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or Conversions

//Function Prototypes Here N/A

//Program Execution Begins Here
int main()
{
    //Declare Variables Here
    int first, second; //Stores the two numbers
    
    //Input or Initialize Values Here
    cout << "Enter two numbers separated by a space: ";
    cin >> first >> second;
    
    //Process Calculations Here
    first > second ? cout << first << " is the bigger number.\n" << second << " is the smaller number." 
    : cout << first << " is the smaller number.\n" << second << " is the bigger number.";
    
    //Exit
    return 0;
}