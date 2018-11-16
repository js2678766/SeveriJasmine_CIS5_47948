/*
    3. Test Average
    Write a program that asks for five test scores. The program should calculate the average
    test score and display it. The number displayed should be formatted in fixed-point
    notation, with one decimal point of precision.
 *  */


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  double test1, test2, test3, test4, test5;
  double average;
  
  cout << "Enter the first test score: ";
  cin >> test1;
  cout << "Enter the second test score: ";
  cin >> test2;
  cout << "Enter the third test score: ";
  cin >> test3;
  cout << "Enter the fourth test score: ";
  cin >> test4;
  cout << "Enter the fifth test score: ";
  cin >> test5;
  
  average = (test1 + test2 + test3 + test4 + test5) / 5.0;
  
  cout << setprecision(1) << fixed;
  cout << "The average score is: " << average << endl;
  return 0;
}