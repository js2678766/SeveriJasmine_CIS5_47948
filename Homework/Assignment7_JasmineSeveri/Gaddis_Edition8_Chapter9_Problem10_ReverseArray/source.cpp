/*
 * Name: Jasmine Severi
 * Date: 12/03/2018
 * Purpose: Reverse Array
 * Write a function that accepts an int array and the array’s size as arguments. The function
 * should create a copy of the array, except that the element values should be reversed
 * in the copy. The function should return a pointer to the new array. Demonstrate the
 * function in a complete program.
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int *arr_re(int[], int);

//Program Execution Begins

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = 5;
    
    int *arrptr = arr_re(arr, size);
    
    for (int i = 0; i < size; i++)
    {
        cout<<arrptr[i]<<endl;
    }
    
    return 0;
}

int *arr_re(int arr[], int size)
{
    int *revarr = new int[size];
    
    int r = size;
    for (int i = 0; i < size; i++)
    {
        revarr[i] = r;
        r--;
    }
    return revarr;
}