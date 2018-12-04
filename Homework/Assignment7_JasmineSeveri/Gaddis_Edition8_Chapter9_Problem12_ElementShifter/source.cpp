/*
 * Name: Jasmine Severi
 * Date: 12/03/2018
 * Purpose: Element Shifter
 * Write a function that accepts an int array and the array’s size as arguments. The
 * function should create a new array that is one element larger than the argument array.
 * The first element of the new array should be set to 0. Element 0 of the argument array
 * should be copied to element 1 of the new array, element 1 of the argument array should
 * be copied to element 2 of the new array, and so forth. The function should return a
 * pointer to the new array.
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
    
    for (int i = 0; i < size + 1; i++)
    {
        cout<<arrptr[i]<<endl;
    }
    
    return 0;
}

int *arrex(int arr[], int size)
{
    int *exparr = new int[size + 1];
    
    for (int i = 0; i < size + 1; i++)
    {
        if (i < 1)
        {
            exparr[i] = 0;
        }
        else
        {
            exparr[i] = i;
        }
    }
    return exparr;
}