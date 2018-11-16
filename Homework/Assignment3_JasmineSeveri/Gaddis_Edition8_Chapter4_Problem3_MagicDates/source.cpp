/*
    3. Magic Dates
    The date June 10, 1960 is special because when we write it in the following format, the
    month times the day equals the year.
        6/10/60
    Write a program that asks the user to enter a month (in numeric form), a day, and a
    two-digit year. The program should then determine whether the month times the day is
    equal to the year. If so, it should display a message saying the date is magic. Otherwise
    it should display a message saying the date is not magic.
 */

#include <iostream>
using namespace std;

int main ()
{
    double month, day, year;
    
    cout << "If a date's month times its day equals the last two digits of its year then the date is a magic date. Tell me a date I will tell you if it is magic.\n";
    cout << "Enter a month in numeric form (1-12 or 01-12): ";
    cin >> month;
    cout << "Enter a day of the month (1-32 or 01-32): ";
    cin >> day;
    cout << "Enter a two-digit year (01-99): ";
    cin >> year;
    
    if (month <= 12 && month >= 1 && day <= 32 && day >= 1 && year <= 99 && year >= 1)
                if (month * day == year)
                cout << "That is a magic date!";
                else
                cout << "That is not a magic date.";
    else cout << "That date is not valid.";
    return 0;
}

