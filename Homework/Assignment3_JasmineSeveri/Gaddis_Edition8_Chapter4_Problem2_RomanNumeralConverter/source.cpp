/*
    2. Roman Numeral Converter
    Write a program that asks the user to enter a number within the range of 1 through 10. 
    Use a switch statement to display the Roman numeral version of that number.
    Input Validation: Do not accept a number less than 1 or greater than 10.
 */

#include <iostream>
using namespace std;

int main ()
{
    int choice;
    
    cout << "Enter a number within the range of 1 through 10 to find out its Roman Numeral: ";
    cin >> choice;
    
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
    return 0;
}