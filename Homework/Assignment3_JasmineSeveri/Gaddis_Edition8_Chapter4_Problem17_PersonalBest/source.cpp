/*
    17. Personal Best
    Write a program that asks for the name of a pole vaulter and the dates and vault
    heights (in meters) of the athlete’s three best vaults. It should then report, in order of
    height (best first), the date on which each vault was made and its height.
    Input Validation: Only accept values between 2.0 and 5.0 for the heights.
 */

#include <iostream>
using namespace std;

int main()
{
    string name;
    double date1, date2, date3, height1, height2, height3;
    
    cout << "Enter the name of the pole vaulter: ";
    cin >> name;
    cout << "Enter three days of a month (numbers only): ";
    cin >> date1 >> date2 >> date3;
    cout << "Enter the height of the jump on each date, one jump for each day: ";
    cin >> height1 >> height2 >> height3;
    
    if (height1 > height2 && height2 > height3) cout << date1 << height1 << date2 << height2 << date3 << height3;
    if (height1 > height3 && height3 > height2) cout << date1 << height1 << date3 << height3 << date2 << height2;
    if (height2 > height3 && height3 > height1) cout << date2 << height2 << date3 << height3 << date1 << height1;
    if (height2 > height1 && height1 > height3) cout << date2 << height2 << date1 << height1 << date3 << height3;
    if (height3 > height1 && height1 > height2) cout << date3 << height3 << date1 << height1 << date2 << height2;
    if (height3 > height2 && height2 > height1) cout << date3 << height3 << date2 << height2 << date1 << height1;
}

