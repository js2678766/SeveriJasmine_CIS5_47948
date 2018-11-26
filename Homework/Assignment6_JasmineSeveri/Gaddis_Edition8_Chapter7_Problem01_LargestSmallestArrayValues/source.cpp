/*
 * Name: Jasmine Severi
 * Date: 11/25/2018
 * Purpose: Largest/Smallest Array Values
 * Write a program that lets the user enter 10 values into an array. The program should
 * then display the largest and smallest values stored in the array.
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes

//Program Execution Begins

int main()
{
   const int NUM = 10;
   int input[NUM];
   int count;
   int highest;
   int lowest;
   
   //Get the number
   cout<<"Enter " << NUM <<" numbers and we'll tell you the largest and smallest ones entered: ";
   cin>>input[0];
   cin>>input[1];
   cin>>input[2];
   cin>>input[3];
   cin>>input[4];
   cin>>input[5];
   cin>>input[6];
   cin>>input[7];
   cin>>input[8];
   cin>>input[9];
   
   //Find the largest number in the array
    highest = input[0];
    for (count = 1; count < NUM; count++)
    {
        if (input[count] > highest)
        highest = input[count];
    }
    
    //Find the smallest number in the array
    lowest = input[0];
    for (count = 1; count < NUM; count++)
    {
        if (input[count] < lowest)
        lowest = input[count];
    }
    
    //Display the highest and lowest.
    cout<<"The highest is: "<<highest<<endl;
    cout<<"The lowest is: "<<lowest<<endl;
}