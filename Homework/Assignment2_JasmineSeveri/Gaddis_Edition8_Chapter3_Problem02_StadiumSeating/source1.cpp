/*
    2. Stadium Seating
    There are three seating categories at a stadium. For a softball game, Class A seats cost
    $15, Class B seats cost $12, and Class C seats cost $9. Write a program that asks how
    many tickets for each class of seats were sold, then displays the amount of income generated
    from ticket sales. Format your dollar amount in fixed-point notation, with two
    decimal places of precision, and be sure the decimal point is always displayed.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double ClassA, ClassB, ClassC, Income;
    
    cout << "Class A tickets cost $15\n";
    cout << "Class B tickets cost $12\n";
    cout << "Class C tickets cost $9.\n"; 
    
    cout << "How many Class A tickets were sold? ";
    cin >> ClassA;
    cout << "How many Class B tickets were sold? ";
    cin >> ClassB;
    cout << "How many Class C tickets were sold? ";
    cin >> ClassC;
    
    Income = ClassA * 15 + ClassB * 12 + ClassC * 9;
    
    cout << "The amount of income generated from ticket sales is: $";
    cout << setprecision(2) << fixed;
    cout << Income;
    return 0;
}

