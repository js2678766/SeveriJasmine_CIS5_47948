/*
 * Name: Jasmine Severi
 * Date: 10/16/2018
 * Purpose: 6. Mass and Weight
 * Scientists measure an object’s mass in kilograms and its weight in newtons. If you know
 * the amount of mass that an object has, you can calculate its weight, in newtons, with
 * the following formula:
 *     Weight = mass x 9.8
 * Write a program that asks the user to enter an object’s mass, and then calculates and
 * displays its weight. If the object weighs more than 1,000 newtons, display a message
 * indicating that it is too heavy. If the object weighs less than 10 newtons, display a message
 * indicating that the object is too light.
 */

//System Libraries Here
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library created

//User Libraries Here N/A

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or Conversions

//Function Prototypes Here N/A

//Program Execution Begins Here
int main()
{
    //Declare Variables Here
    int weight, mass; //Stores the weight and the mass
    
    //Input or Initialize Values Here
    cout << "Enter the object's mass and I'll calculate its weight in newtons: ";
    cin >> mass;
    
    weight = mass * 9.8; //Calculates the weight in newtons
    
    //Process Calculations Here
    if (weight > 1000) cout << "Your object is too heavy.";
    else if (weight < 10) cout << "Your object is too light.";
    else cout << weight;
    
    //Exit
    return 0;
}