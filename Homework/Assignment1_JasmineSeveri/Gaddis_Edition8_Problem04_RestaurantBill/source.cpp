/*
    Restaurant Bill
    Write a program that computes the tax and tip on a restaurant bill for a patron with
    a $88.67 meal charge. The tax should be 6.75 percent of the meal cost. The tip should
    be 20 percent of the total after adding the tax. Display the meal cost, tax amount, tip
    amount, and total bill on the screen.
 */
#include <iostream>
using namespace std;

int main()
{
    double Meal = 88.67, Tax, Meal_Tax, Tip, Total;
    Tax = Meal * 0.0675;
    Meal_Tax = Meal + Tax;
    Tip = Meal_Tax * 0.20;
    Total = Meal_Tax + Tip;
    
    cout<<"Meal: "<<Meal;
    cout<<"\nTax: "<<Tax;
    cout<<"\nTip: "<<Tip;
    cout<<"\nTotal: "<<Total;
    return 0;
}
