/*
    11. Math Tutor
    This is a modification of Programming Challenge 17 from Chapter 3 . Write a program
    that can be used as a math tutor for a young student. The program should display two
    random numbers that are to be added, such as:
        247
      + 129
      ______
    The program should wait for the student to enter the answer. If the answer is correct,
    a message of congratulations should be printed. If he answer is incorrect, a message
    should be printed showing the correct answer.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int MIN_VALUE = 100;
    const int MAX_VALUE = 999;
    
    int random1, random2, their_answer, answer;
    
    unsigned seed = time(0);
    
    char ch;
    
    srand(seed);
    
    random1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    random2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    
    cout << "Type in your answer:\n";
    cout << " " << random1 << endl;
    cout << "+" << random2 << endl;
    cout << "____\n";
    cin >> their_answer;
    
    answer = random1 + random2;
    
    if (their_answer == answer) cout << "Congratulations! That is correct.";
    else cout << "The correct answer is " << answer;
    return 0;
}