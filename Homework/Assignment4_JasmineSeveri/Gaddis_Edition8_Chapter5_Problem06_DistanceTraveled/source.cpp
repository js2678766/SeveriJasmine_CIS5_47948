/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 6. Distance Traveled
 * The distance a vehicle travels can be calculated as follows:
 * distance = speed * time
 * For example, if a train travels 40 miles per hour for 3 hours, the distance traveled is
 * 120 miles.
 * Write a program that asks the user for the speed of a vehicle (in miles per hour) and how
 * many hours it has traveled. The program should then use a loop to display the distance the
 * vehicle has traveled for each hour of that time period. Here is an example of the output:
 * 
 * What is the speed of the vehicle in mph? 40
 * How many hours has it traveled? 3
 * Hour           Distance Traveled
 * --------------------------------
 * 1                    40
 * 2                    80
 * 3                   120
 * Input Validation: Do not accept a negative number
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
    int speed, hours;
		   
    //Input or initialize values. Get the speed in MPH
    cout << " What is the speed of the vehicle in mph?  ";
    cin >> speed;
	
    //Error message
    while(speed < 0)
    {
	cout << " Please enter a positive number for the speed:  ";
	cin >> speed;
    }
	
    //Get the number of hours traveled
    cout << " How many hours has it traveled?   ";
    cin >> hours;

    //Error message
    while(hours < 1)
    {
        cout << " Please enter a number greater than 1 for the hours:  ";
	cin >> hours;
    }

    //Process Calculations Here
    cout << endl;
    cout << " Hour" << "\t" << " Distance Traveled" << endl;
    cout << " -------------------------------------" << endl;

    for(int count = 1; count <= hours; count++)
    {
        cout << " " << count << "\t\t" << speed * count << endl;
    }
    //Exit
    return 0;
}