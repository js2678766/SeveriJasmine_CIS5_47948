/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 21. Random Number Guessing Game Enhancement
 * Enhance the program that you wrote for Programming Challenge 20 so it keeps a count
 * of the number of guesses that the user makes. When the user correctly guesses the random
 * number, the program should display the number of guesses.
 */

//System Libraries Here
#include <iostream> //I/O Library
#include <cstdlib> //General Utilities Library, used for generating the random numbers
#include <ctime>
using namespace std; //Namespace I/O stream library created

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main()
{
    //Declare variables here
    const int MIN_VAL = 1; //The smallest number the random numbers can be
    const int MAX_VAL = 10; //The largest number the random numbers can be
    
    int number, guess; //Stores the two random numbers, their answer, and the correct answer
    int num = MIN_VAL;
    
    unsigned seed = time(0);
    
    char ch;
    
    //Generating the random number
    srand(seed);
    
    number = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    
    //Input or initialize
    do 
    {
    cout << "I've picked a number between 1 and 10. Try to guess the number!\n";
    cout << "Your guess is? ";
    cin >> guess;
    
    //Process Calculations Here
    if (guess == number)
        cout << "Correct! It only took you " << num << " guesses!";
    else if (guess < number)
    {
        cout << "Too low! Guess again.\n";
        num++;
    }
        else if (guess > number)
    {
        cout << "Too high! Guess again.\n";
        num++;
    }
    } while (guess != number);
    
    return 0;
}