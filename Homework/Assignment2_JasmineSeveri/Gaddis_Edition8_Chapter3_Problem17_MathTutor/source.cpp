/*
    17. Math Tutor
    Write a program that can be used as a math tutor for a young student. The program
    should display two random numbers to be added, such as
      247
    + 129
      ___
    The program should then pause while the student works on the problem. When the
    student is ready to check the answer, he or she can press a key and the program will
    display the correct solution:
      247
      129
    + ___
      376
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    const int MIN_VALUE = 100;
    const int MAX_VALUE = 999;
    
    int random1, random2, answer;
    
    unsigned seed = time(0);
    
    char ch;
    
    srand(seed);
    
    random1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    random2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    
    cout << "Here is your problem:\n";
    cout << " " << random1 << endl;
    cout << "+" << random2 << endl;
    cout << "____\n";
    
    cout << "When you have solved the problem, press Enter for the answer.";
    cin.get(ch);
    
    answer = random1 + random2;
    
    cout << " " << random1 << endl;
    cout << "+" << random2 << endl;
    cout << "____\n";
    cout << answer;
    return 0;
}