/*
 * Name: Jasmine Severi
 * Date: 12/03/2018
 * Purpose: Array Expander
 * Write a function that accepts an int array and the array’s size as arguments. The function
 * should create a new array that is twice the size of the argument array. The function
 * should copy the contents of the argument array to the new array and initialize the
 * unused elements of the second array with 0. The function should return a pointer to
 * the new array.
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int *arrex(int[], int);

//Program Execution Begins

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = 5;
    
    int *arrptr = arrex(arr, size);
    
    for (int i = 0; i < size * 2; i++)
    {
        cout<<arrptr[i]<<endl;
    }
    
    return 0;
}

int *arrex(int arr[], int size)
{
    int *exparr = new int[size * 2];
    
    for (int i = 0; i < size * 2; i++)
    {
        if (i < size)
        {
            exparr[i] = arr[i];
        }
        else
        {
            exparr[i] = 0;
        }
    }
    return exparr;
}