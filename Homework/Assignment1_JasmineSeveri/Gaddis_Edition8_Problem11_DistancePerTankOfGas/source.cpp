/*
    Distance per Tank of Gas
    A car with a 20-gallon gas tank averages 23.5 miles per gallon when driven in town
    and 28.9 miles per gallon when driven on the highway. Write a program that calculates
    and displays the distance the car can travel on one tank of gas when driven in town
    and when driven on the highway.
    Hint: The following formula can be used to calculate the distance:
    Distance = Number of Gallons * Average Miles per Gallon
 */
#include <iostream>
using namespace std;

int main()
{
    double Gallons = 20, Average_Town = 23.5, Average_Highway = 28.9, Distance_Town, Distance_Highway;
    
    Distance_Town = Gallons * Average_Town;
    Distance_Highway = Gallons * Average_Highway;
    
    cout<<"The car can travel "<<Distance_Town<<" miles when in town\n";
    cout<<"The car can travel "<<Distance_Highway<<" miles when on the highway\n";
    return 0;
}
