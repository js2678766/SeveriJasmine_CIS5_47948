/*
Create a program, i.e. a Netbeans project with the following inputs, knowns, and outputs.

Description -> Calculate the percentage Gas Tax on a gallon of gas, and the profit made from a gallon of gas given

Taxes -> http://watchdog.org/232083/california-gas-taxes

     39 cents for excise tax/gallon

     8% sales tax

     10 cents for cap and trade “fee”—tax on a tax/gallon

     18.4 cents federal excise tax/gallon

Profit -> http://www.forbes.com/2011/05/10/oil-company-earnings.html

     6.5% oil company profit

Input from the command line, using a prompt and the cin object

     The amount it cost you per gallon the last time you put gas in your car.

Compare the percentages and the dollar amount of profit gas companies make vs. taxes to the Govt.

Delete the build and distribution folders.

Zip the project folder

Submit in Canvas

Also, send and email outside of canvas which copies yourself to mark.lehr@rcc.edu with subject:YourLastName, YourFirstName - Lab 3 - 47948 or 47995
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double paid, sales_tax, excise = 0.39, captrade = 0.10, fed = 0.184, tax, oilprofperc, oilprof, taxperc;
    
    cout << "How much did you pay for gas? $";
    cin >> paid;
    
    sales_tax = paid * 0.08;
    tax = sales_tax + excise + captrade + fed;
    taxperc = tax / paid * 100;
    oilprof = 0.065 * paid;
    oilprofperc = 6.5;
    
    cout << setprecision(2) << fixed;
    cout << "Total Tax: $" << tax;
    cout << "\nTax is " << taxperc << "%\n";
    cout << "The oil company's profit is $" << oilprof;
    cout << "\nThe oil company's profit is " << oilprofperc << "%";
    return 0;
}