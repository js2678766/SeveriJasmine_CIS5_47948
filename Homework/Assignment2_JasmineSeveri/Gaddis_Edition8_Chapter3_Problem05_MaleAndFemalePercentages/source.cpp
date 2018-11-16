/*
    5. Male and Female Percentages
    Write a program that asks the user for the number of males and the number of females
    registered in a class. The program should display the percentage of males and females
    in the class.
    Hint: Suppose there are 8 males and 12 females in a class. There are 20 students in the
    class. The percentage of males can be calculated as 8 ÷ 20 = 0.4, or 40%. The percentage
    of females can be calculated as 12 ÷ 20 = 0.6, or 60%.
 */

#include <iostream>
using namespace std;

int main()
{
    double Males, Females, Class, prcntm, prcntf;
    
    cout << "How many males were in the class? ";
    cin >> Males;
    
    cout << "How many females were in the class? ";
    cin >> Females;
    
    Class = Males + Females;
    prcntm = Males / Class * 100;
    prcntf = Females / Class * 100;
    
    cout << "The class is " << prcntm << "% male and " << prcntf << "% female.";
    return 0;
}