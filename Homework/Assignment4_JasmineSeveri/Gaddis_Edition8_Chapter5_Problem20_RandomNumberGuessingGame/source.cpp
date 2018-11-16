/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 20. Random Number Guessing Game
 * Write a program that generates a random number and asks the user to guess what the
 * number is. If the user’s guess is higher than the random number, the program should
 * display “Too high, try again.” If the user’s guess is lower than the random number,
 * the program should display “Too low, try again.” The program should use a loop that
 * repeats until the user correctly guesses the random number.
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
        
        //Process Calculations
        if (guess == number)
            cout << "Correct!";
        else if (guess < number)
            cout << "Too low! Guess again.\n";
        else if (guess > number)
            cout << "Too high! Guess again.\n";
    } while (guess != number);
    
    return 0;
}