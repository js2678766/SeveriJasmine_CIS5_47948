/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Coin Toss
 * Write a function named coinToss that simulates the tossing of a coin. When you call
 * the function, it should generate a random number in the range of 1 through 2. If the
 * random number is 1, the function should display “heads.” If the random number is 2,
 * the function should display “tails.” Demonstrate the function in a program that asks
 * the user how many times the coin should be tossed and then simulates the tossing of
 * the coin that number of times.
 */

//System Libraries
#include <iostream> //I/O Library
#include <cstdlib> //General Utilities Library, used for generating random numbers
#include <ctime> //To help with random number generation
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int cointoss(int choice);

//Program Execution Begins

int main()
{
    int choice;
    
    cout<<"How many times do you wish to flip the coin?\n";
    cout<<"Choose: ";
    cin>>choice;
    
    cointoss(choice);
    
    return 0;
}

int cointoss(int choice)
{
    for(int flips = 1; flips <= choice; flips++)
    {
        const int minnum = 1;
        const int maxnum = 2;
        static int toss;
        unsigned seed = time(0);
        
        toss = (rand() % (maxnum - minnum + 1)) + minnum;
        
        if (toss == 1)
        {
            cout<<"Flip "<<flips<<": Heads!\n";
        }
        if (toss == 2)
        {
            cout<<"Flip "<<flips<<": Tails!\n";
        }
    }
}