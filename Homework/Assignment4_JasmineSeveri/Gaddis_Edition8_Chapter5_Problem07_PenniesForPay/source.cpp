/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 7. Pennies for Pay
 * Write a program that calculates how much a person would earn over a period of time
 * if his or her salary is one penny the first day and two pennies the second day, and continues
 * to double each day. The program should ask the user for the number of days.
 * Display a table showing how much the salary was for each day, and then show the
 * total pay at the end of the period. The output should be displayed in a dollar amount,
 * not the number of pennies.
 * Input Validation: Do not accept a number less than 1 for the number of days worked.
 */

//System Libraries Here
#include <iostream> //I/O Library
#include <iomanip> //I/O Manipulator Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
 int main()
 {
     //Declare variables here
     int days = 1; //Starting number
     float salary = 1.0; //Their number, the maximum number
     float total = 0.0;
     float pay = 0.0;
     
     //Get their choice of number
     cout<<"This calculates someone's salary in dollars if they were paid one penny for the first day they worked, two for the second,\n";
     cout<<"four for the third, eight for the fourth, and it continues to double for each day.\n";
     cout<<"How many days did they work? ";
     cin>>days;
     
    //Process/Calculations Here
     for (int count = 1; count <= days; count++)
     {
         pay = salary / 100;
         cout<<"Day: "<<count << "\t" << "Salary: $" << pay << endl;
         total += pay;
         salary *= 2;
     }
     
     cout << "Total at the end of the period: $" << total <<endl;
     //Exit
     return 0;
 }