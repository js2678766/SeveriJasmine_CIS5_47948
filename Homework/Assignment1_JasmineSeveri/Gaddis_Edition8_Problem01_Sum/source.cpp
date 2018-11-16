/*
    Write the sum of two numbers.
    Write a program that stores the integers 50 and 100 in variables, and stores the sum of
    these two in a variable named total.
 */
#include <iostream>
using namespace std;

int main()
{
    //Stores the integers 50 and 100 in variables Hours_Friday and Hours_Saturday, respectively
    double Earned_Friday = 50, Earned_Saturday = 100, total;
    
    //Stores the sum of the variables Hours_Friday and Hours_Saturday in the variable total
    total = Earned_Friday + Earned_Saturday;

    //Displays what has been stored in the variable total    
    cout<<"You made $50 on Friday and $100 on Saturday\n";
    cout<<"You earned a total of $"<<total;
    return 0;
}
