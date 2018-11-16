/*
    4. Average Rainfall
    Write a program that calculates the average rainfall for three months. The program
    should ask the user to enter the name of each month, such as June or July, and the
    amount of rain (in inches) that fell each month. The program should display a message
    similar to the following:
    The average rainfall for June, July, and August is 6.72 inches.
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string month1_name, month2_name, month3_name;
    double month1_rain, month2_rain, month3_rain, average;
    
    cout << "Enter the name of the first month: ";
    getline(cin, month1_name);
    cout << "Enter the name of the second month: ";
    getline(cin, month2_name);   
    cout << "Enter the name of the third month: ";
    getline(cin, month3_name);
    
    cout << "Enter the amount of rain (in inches) that fell in the first month: ";
    cin >> month1_rain;
    cout << "Enter the amount of rain (in inches) that fell in the second month: ";
    cin >> month2_rain; 
    cout << "Enter the amount of rain (in inches) that fell in the third month: ";
    cin >> month3_rain;
    
    average = (month1_rain + month2_rain + month3_rain) / 3.0;
    
    cout << "The average rainfall for " << month1_name <<", " << month2_name << " and " << month3_name << " is: " << average;
    return 0;
}