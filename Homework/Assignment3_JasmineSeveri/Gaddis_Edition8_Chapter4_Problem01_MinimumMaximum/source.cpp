/*
    1. Minimum/Maximum
    Write a program that asks the user to enter two numbers. The program should use the
    conditional operator to determine which number is the smaller and which is the larger.
 */

#include <iostream>
using namespace std;

int main ()
{
    double first, second;
    
    cout << "Enter two numbers separated by a space: ";
    cin >> first >> second;
    
    first > second ? cout << first << " is the bigger number.\n" << second << " is the smaller number." 
    : cout << first << " is the smaller number.\n" << second << " is the bigger number.";
    return 0;
}