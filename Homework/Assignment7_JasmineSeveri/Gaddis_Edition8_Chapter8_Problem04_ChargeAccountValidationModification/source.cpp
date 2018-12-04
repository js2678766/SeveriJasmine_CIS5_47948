/*
 * Name: Jasmine Severi
 * Date: 12/03/2018
 * Purpose: Charge Account Validation Modification
 * Modify the program you wrote for Problem 1 (Charge Account Validation) so it performs
 * a binary search to locate valid account numbers. Use the selection sort algorithm
 * to sort the array before the binary search is performed.
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const int numelem = 18;

//Function Prototypes
void sort(int[]);
bool binsrch(int, int[]);

//Program Execution Begins

int main()
{
    int acnt[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                   8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                   1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int acnum = 0;
    bool found = true;
    
    cout<<"Please enter your account number: ";
    cin>>acnum;
    
    sort(acnt);
    
    if (found == binsrch(acnum, acnt))
    {
        cout<<"\nThe account #"<<acnum<<" IS a valid account.\n";
    }
    else
    {
        cout<<"\nThe account #"<<acnum<<" IS NOT a valid account.\n";
    }
        
    return 0;   
}

void sort(int arr[numelem])
{
    int minin = 0;
    
    for (int i = 0; i < numelem - 1; i++)
    {
        int minin = i;
        int minval = arr[i];
        for (int c = i + 1; c < numelem; c++)
        {
            if (arr[c] < minval)
            {
                minval = arr[c];
                minin = c;
            }
        }
        
        int temp = arr[i];
        arr[i] = minval;
        arr[minin] = temp;
    }
}

bool binsrch (int enval, int arr[numelem])
{
    int first = 0;
    int mid = 0;
    int last = numelem - 1;
    int pos = 0;
    
    while (first <= last)
    {
        mid = (first + last / 2);
        
        if(arr[mid] == enval)
        {
            return true;
        }
        else if (arr[mid] > enval)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return false;
}
