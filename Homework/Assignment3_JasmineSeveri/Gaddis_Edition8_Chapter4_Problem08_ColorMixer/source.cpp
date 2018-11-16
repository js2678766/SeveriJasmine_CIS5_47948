/*
    8. Color Mixer
    The colors red, blue, and yellow are known as the primary colors because they cannot
    be made by mixing other colors. When you mix two primary colors, you get a secondary
    color, as shown here:
    When you mix red and blue, you get purple.
    When you mix red and yellow, you get orange.
    When you mix blue and yellow, you get green.
    Write a program that prompts the user to enter the names of two primary colors to
    mix. If the user enters anything other than “red,” “blue,” or “yellow,” the program
    should display an error message. Otherwise, the program should display the name of
    the secondary color that results by mixing two primary colors.
 */

#include <iostream>
using namespace std;

int main()
{
    string color_1, color_2;
    
    cout << "The primary colors are Red, Blue and Yellow.\n"; 
    cout << "Enter two primary colors (capitalizing the first letter of each word) and I will tell you what color they make when combined: ";
    cin >> color_1 >> color_2;
    
    if (color_1 == "Blue" && color_2 == "Red") cout << "Blue and Red make Purple.";
    else if (color_2 == "Blue" && color_1 == "Red") cout << "Red and Blue make Purple.";
    else if (color_2 == "Blue" && color_1 == "Yellow") cout << "Blue and Yellow make Green.";
    else if (color_1 == "Blue" && color_1 == "Yellow") cout << "Yellow and Blue make Green.";
    else if (color_1 == "Red" && color_2 == "Yellow") cout << "Red and Yellow make Orange.";
    else if (color_2 == "Red" && color_1 == "Yellow") cout << "Yellow and Red make Orange.";
    else cout << "That is not a valid entry.";
    return 0;
}