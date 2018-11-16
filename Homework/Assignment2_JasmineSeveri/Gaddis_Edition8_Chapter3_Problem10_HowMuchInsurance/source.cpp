/*
    10. How Much Insurance?
    Many financial experts advise that property owners should insure their homes or buildings
    for at least 80 percent of the amount it would cost to replace the structure. Write a
    program that asks the user to enter the replacement cost of a building and then displays
    the minimum amount of insurance he or she should buy for the property.
 */

#include <iostream>
using namespace std;

int main()
{
    double replace, insurance;
    
    cout << "How much would it cost to replace your house or building? $";
    cin >> replace;
    
    insurance = replace * 0.8;
    
    cout << "The minimum amount of insurance for your house or building should be $" << insurance;
    return 0;
}
