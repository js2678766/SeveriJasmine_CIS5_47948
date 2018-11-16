/*
    Average of Values
    To get the average of a series of values, you add the values up and then divide the sum
    by the number of values. Write a program that stores the following values in five different
    variables: 28, 32, 37, 24, and 33. The program should first calculate the sum
    of these five variables and store the result in a separate variable named sum . Then, the
    program should divide the sum variable by 5 to get the average. Display the average
    on the screen.
 */
#include <iostream>
using namespace std;

int main()
{
    double Mon = 28, Tue = 32, Wed = 37, Thur = 24, Fri = 33, sum, average;
   
    sum = Mon + Tue + Wed + Thur + Fri;
    average = sum / 5;
    
    cout<<"Mon: $28\nTue: $32\nWed: $37\nThur: $24\nFri: $33\n";
    cout<<"The average is $"<<average<<" per day";
    return 0;
}
