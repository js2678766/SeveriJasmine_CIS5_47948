/*
    Energy Drink Consumption
    A soft drink company recently surveyed 16,500 of its customers and found that
    approximately 15 percent of those surveyed purchase one or more energy drinks per
    week. Of those customers who purchase energy drinks, approximately 58 percent of
    them prefer citrus-flavored energy drinks. Write a program that displays the following:
        •   The approximate number of customers in the survey who purchase one or more energy drinks per week
        •   The approximate number of customers in the survey who prefer citrus-flavored energy drinks

 */
#include <iostream>
using namespace std;

int main()
{
    double Surveyed = 16500.0, Energy_Drinks, Citrus;
    Energy_Drinks = Surveyed * 0.15;
    Citrus = Energy_Drinks * 0.58;
    
    cout<<"Amount of customers surveyed: 16,500.\n";
    cout<<"Approximate amount of customers who buy one or more energy drinks per week: "<<Energy_Drinks;
    cout<<"\nApproximate amount of customers who buy energy drinks who prefer citrus flavored ones: "<<Citrus;
    return 0;
}
