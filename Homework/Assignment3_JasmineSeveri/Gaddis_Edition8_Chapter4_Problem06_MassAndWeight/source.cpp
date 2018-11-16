/*
    6. Mass and Weight
    Scientists measure an object’s mass in kilograms and its weight in newtons. If you know
    the amount of mass that an object has, you can calculate its weight, in newtons, with
    the following formula:
        Weight = mass x 9.8
    Write a program that asks the user to enter an object’s mass, and then calculates and
    displays its weight. If the object weighs more than 1,000 newtons, display a message
    indicating that it is too heavy. If the object weighs less than 10 newtons, display a message
    indicating that the object is too light.
 */

#include <iostream>
using namespace std;

int main()
{
    double weight, mass;
    
    cout << "Enter the object's mass and I'll calculate its weight in newtons: ";
    cin >> mass;
    
    weight = mass * 9.8;
    
    if (weight > 1000) cout << "Your object is too heavy.";
    else if (weight < 10) cout << "Your object is too light.";
    else cout << weight;
    return 0;
}