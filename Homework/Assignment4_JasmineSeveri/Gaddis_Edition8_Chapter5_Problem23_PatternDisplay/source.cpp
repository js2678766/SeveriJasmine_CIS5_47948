/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 23. Pattern Displays
 * Write a program that uses a loop to display Pattern A below, followed by another loop
 * that displays Pattern B.
 *    Pattern A    Pattern B
 *    +            ++++++++++
 *    ++           +++++++++
 *    +++          ++++++++
 *    ++++         +++++++
 *    +++++        ++++++
 *    ++++++       +++++
 *    +++++++      ++++
 *    ++++++++     +++
 *    +++++++++    ++
 *    ++++++++++   +
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
    //Pattern 1
    for (int row = 0; row < 10; row++) //Makes the rows
    {
        for (int column = 0; column <= row; column++) //Makes the columns
        {
            cout << "+";
        }
        cout << endl;
    }

    //Makes the space between the two patterns
    cout << endl;

    //Pattern 2
    for (int row = 10; row > 0; row--) //Makes the rows
    {
        for (int column = 0; column < row; column++) //Makes the columns
        {
            cout << "+";
        }
        cout << endl;
    }
    //Exit
    return 0;
}
