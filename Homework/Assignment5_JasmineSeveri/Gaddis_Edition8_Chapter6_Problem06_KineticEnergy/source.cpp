/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Kinetic Energy
 * In physics, an object that is in motion is said to have kinetic energy. The following
 * formula can be used to determine a moving object’s kinetic energy:
 * KE = 1/2 pow(m*v, 2)
 * The variables in the formula are as follows: KE is the kinetic energy, m is the object’s
 * mass in kilograms, and v is the object’s velocity, in meters per second.
 * Write a function named kineticEnergy that accepts an object’s mass (in kilograms)
 * and velocity (in meters per second) as arguments. The function should return the
 * amount of kinetic energy that the object has. Demonstrate the function by calling it in
 * a program that asks the user to enter values for mass and velocity.
 */

//System Libraries
#include <iostream> //I/O Library
#include <cmath> //Math Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
float kine(int, int);

//Program Execution Begins

int main()
{
    float ke = 0;
    int m = 0, v = 0;
    
    cout<<"What is the object's mass in kilograms?: ";
    cin>>m;
    cout<<"What is the object's velocity in meters per second?: ";
    cin>>v;
    
    ke = kine(m, v);
    
    cout<<endl<<"The Kinetic Energy of this object is: "<<ke<<endl;
    
    return 0;
}

float kine(int m, int v)
{
    return (0.5 * m) * (pow(v,2));
}
