/*
 * Name: Jasmine Severi
 * Date: 10/16/2018
 * Purpose: 2. Roman Numeral Converter
 * Write a program that asks the user to enter a number within the range of 1 through 10. 
 * Use a switch statement to display the Roman numeral version of that number.
 * Input Validation: Do not accept a number less than 1 or greater than 10.
 */

//System Libraries Here
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library created

//User Libraries Here N/A

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or Conversions

//Function Prototype Here N/A

//Program Execution Begins Here
int main ()
{
    //Declare Variables Here
    int choice; //Stores their choice
    
    //Input or Initialize Values Here
    cout << "Enter a number within the range of 1 through 10 to find out its Roman Numeral: ";
    cin >> choice;
    
    //Process Calculations Here
    switch (choice)
    {
        case 1: cout << "I\n";
                break;
        case 2: cout << "II\n";
                break;
        case 3: cout << "III\n";
                break;
        case 4: cout << "IV\n";
                break;
        case 5: cout << "V\n";
                break;
        case 6: cout << "VI\n";
                break;
        case 7: cout << "VII\n";
                break;
        case 8: cout << "VIII\n";
                break;
        case 9: cout << "IX\n";
            break;
        case 10: cout << "X\n";
                break;
        default: cout << "The valid choices are 1-10.";
    }
    //Exit
    return 0;
}