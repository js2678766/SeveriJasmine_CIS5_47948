/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 5. Membership Fees Increase
 * A country club, which currently charges $2,500 per year for membership, has
 * announced it will increase its membership fee by 4% each year for the next six years.
 * Write a program that uses a loop to display the projected rates for the next six years.
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
     //Declare variables
     float inc = 0.04, member = 2500;
     int years = 6;
     
     //Process Calculations Here
     for (int count = 1; count <= years; count++)
     {
         member = member + (member * inc);
         cout << "Year: " << count << " Fees: " << member << endl;
     }
    
     //Exit
     return 0;
 }