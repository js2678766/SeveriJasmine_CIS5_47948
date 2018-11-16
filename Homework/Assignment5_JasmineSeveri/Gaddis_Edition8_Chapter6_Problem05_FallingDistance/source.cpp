/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Falling Distance
 * When an object is falling because of gravity, the following formula can be used to
 * determine the distance the object falls in a specific time period:
 * d = 1/2gt2
 * The variables in the formula are as follows: d is the distance in meters, g is 9.8, and t
 * is the amount of time, in seconds, that the object has been falling.
 * Write a function named fallingDistance that accepts an object’s falling time (in
 * seconds) as an argument. The function should return the distance, in meters, that the
 * object has fallen during that time interval. Write a program that demonstrates the
 * function by calling it in a loop that passes the values 1 through 10 as arguments and
 * displays the return value.
 */

//System Libraries
#include <iostream> //I/O Library
#include <cmath> //Math Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
float falldis(float, float);

//Program Execution Begins

int main()
{
    float d = 0;
    float g = 9.8, t = 10;
    
    d = falldis(g, t);
    
    cout<<"The distance this item has fallen in ten seconds is: "<<d;
    
    return 0;
}

float falldis(float g, float t)
{
    for (int sec = 1; sec <= t; sec++)
    {
        return (0.5 * g) * (pow(t, 2));
    }
}
