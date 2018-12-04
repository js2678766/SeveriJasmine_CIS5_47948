/*
 * Name: Jasmine Severi
 * Date: 12/03/2018
 * Purpose: Array Allocator
 * Write a function that dynamically allocates an array of integers. The function should
 * accept an integer argument indicating the number of elements to allocate. The function
 * should return a pointer to the array.
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int num(int);
int* allo (int);

//Program Execution Begins
int main()
{
    int number = 0;
    int *arr;
    number = num(number);
    arr = allo(number);
    
    for(int i = 0; i < number; i++)
    { 
        cout<<arr[i]<<endl;
    }

    return 0;
}

int num(int number)
{
    cout<<"Please enter array size: ";
    cin>>number;
    return number;
}

int* allo (int num)
{
    int *arr = new int(num);

    for(int i = 0; i < num; i++)
    {
        cout<<"Enter number "<<i+1<<": ";
        cin>>arr[i];
    }

    return arr;
}