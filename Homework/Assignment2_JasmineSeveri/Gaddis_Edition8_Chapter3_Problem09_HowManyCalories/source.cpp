/*
    9. How Many Calories?
    A bag of cookies holds 30 cookies. The calorie information on the bag claims that there
    are 10 “servings” in the bag and that a serving equals 300 calories. Write a program
    that asks the user to input how many cookies he or she actually ate and then reports
    how many total calories were consumed.
 */

#include <iostream>
using namespace std;

int main()
{
    double cookies, caloriespercookie = 300 / 30 * 10, caloriesconsumed;
    
    cout << "A bag of cookies holds 30 cookies. There are 10 servings, each serving has 300 calories.\n";
    cout << "How many cookies did you eat? ";
    cin >> cookies;
    
    caloriesconsumed = cookies * caloriespercookie;
    
    cout << "You consumed " << caloriesconsumed << " calories.";
    return 0;
}