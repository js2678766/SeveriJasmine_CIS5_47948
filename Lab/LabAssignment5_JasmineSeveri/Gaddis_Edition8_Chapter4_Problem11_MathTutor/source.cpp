/*
 * Name: Jasmine Severi
 * Date: 10/16/2018
 * Purpose: 11. Math Tutor
 * This is a modification of Programming Challenge 17 from Chapter 3 . Write a program
 * that can be used as a math tutor for a young student. The program should display two
 * random numbers that are to be added, such as:
 *    247
 *   + 129
 *   ______
 * The program should wait for the student to enter the answer. If the answer is correct,
 * a message of congratulations should be printed. If he answer is incorrect, a message
 * should be printed showing the correct answer.
 */

//System Libraries Here
#include <iostream> //I/O Library
#include <cstdlib> //General Utilities Library, used for generating the random numbers
using namespace std; //Namespace I/O stream library created

//User Libraries Here N/A

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or Conversions

//Function Prototypes Here N/A

//Program Execution Begins Here
int main()
{
    //Declare Variables Here
    const int MIN_VAL = 100; //The smallest number the random numbers can be
    const int MAX_VAL = 999; //The largest number the random numbers can be
    
    int random1, random2, theiran, answer; //Stores the two random numbers, their answer, and the correct answer
    
    unsigned seed = time(0);
    
    char ch;
    
    //Generating the random numbers
    srand(seed);
    
    random1 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    random2 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    
    //Input or Initialize Values Here
    cout << "Type in your answer:\n";
    cout << " " << random1 << endl;
    cout << "+" << random2 << endl;
    cout << "____\n";
    cin >> theiran;
       
    answer = random1 + random2;
    
    //Process Calculations Here
    if (theiran == answer) cout << "Congratulations! That is correct.";
    else cout << "The correct answer is " << answer;
    
    //Exit
    return 0;
}