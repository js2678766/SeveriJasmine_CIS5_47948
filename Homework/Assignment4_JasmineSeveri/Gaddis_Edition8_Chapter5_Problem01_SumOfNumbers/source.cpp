/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 1. Sum of Numbers
 * Write a program that asks the user for a positive integer value. The program should use
 * a loop to get the sum of all the integers from 1 up to the number entered. For example,
 * if the user enters 50, the loop will find the sum of 1, 2, 3, 4, … 50.
 * Input Validation: Do not accept a negative starting number.
 */

//System Libraries Here
#include <iostream> //I/O Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
 int main()
 {
     //Declare variables here
     int start = 1; //Starting number
     int num; //Their number, the maximum number
     int total = 0; //Accumulator initialized with 0
     
     //Get their choice of number
     cout<<"Choose a positive number and I will give you the sum of all the numbers up to that number: ";
     cin>>num;
     
    //Process/Calculations Here
     if (num <= 0)
     {
         cout<<"Invalid Number.";
         return 0;
     }
     else
     //Accumulate the total    
     for (int count = start; count <= num; count++)
     {
        total += count; // Accumulate the running total.
     }
     cout<<"The total is: " << total;
     //Exit
     return 0;
 }