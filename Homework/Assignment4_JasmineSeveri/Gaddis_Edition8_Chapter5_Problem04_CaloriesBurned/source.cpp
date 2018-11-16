/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 4. Calories Burned
 * Running on a particular treadmill you burn 3.6 calories per minute. Write a program that
 * uses a loop to display the number of calories burned after 5, 10, 15, 20, 25, and 30 minutes.
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
     //Declare Variables
     float cal;
     float calpm = 3.9;
     
     //Process Calculations
     for (int count = 10; count <= 30; count += 5)
     {
         cal = count * calpm;
         cout << "In " << count << " minutes, you burned " << cal << " calories!\n";
     }
     
     //Exit
     return 0;
 }