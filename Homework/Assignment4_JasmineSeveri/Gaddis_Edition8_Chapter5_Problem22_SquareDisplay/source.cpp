/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 22. Square Display
 * Write a program that asks the user for a positive integer no greater than 15. The program
 * should then display a square on the screen using the character ‘X’. The number
 * entered by the user will be the length of each side of the square. For example, if the
 * user enters 5, the program should display the following:
 *  XXXXX
 *  XXXXX
 *  XXXXX
 *  XXXXX
 *  XXXXX
 * If the user enters 8, the program should display the following:
 *  XXXXXXXX
 *  XXXXXXXX
 *  XXXXXXXX
 *  XXXXXXXX
 *  XXXXXXXX
 *  XXXXXXXX
 *  XXXXXXXX
 *  XXXXXXXX
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
    //Declare Variables Here
    int number;
    
    //Input or initialize values Here
    cout<<"Enter a positive number no larger than 15: ";
    cin>>number;
    
    //Process/Calculations Here
    if (number >= 16 || number <=0)
        cout<<"Invalid Number";
    else
    for (int row = 0; row < number; row++)
    {
        for (int X = 0; X < number; X++)
        {
            cout << 'X';
        }
    cout << endl;
    }
    //Exit
    return 0;
}


