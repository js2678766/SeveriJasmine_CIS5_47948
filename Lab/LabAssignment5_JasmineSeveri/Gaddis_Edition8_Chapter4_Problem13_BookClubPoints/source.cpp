/*
 * Name: Jasmine Severi
 * Date: 10/16/2018
 * Purpose:13. Book Club Points
 * Serendipity Booksellers has a book club that awards points to its customers based on
 * the number of books purchased each month. The points are awarded as follows:
 *     • If a customer purchases 0 books, he or she earns 0 points.
 *     • If a customer purchases 1 book, he or she earns 5 points.
 *     • If a customer purchases 2 books, he or she earns 15 points.
 *     • If a customer purchases 3 books, he or she earns 30 points.
 *     • If a customer purchases 4 or more books, he or she earns 60 points.
 * Write a program that asks the user to enter the number of books that he
 */

//System Libraries Here
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library created

//User Libraries Here N/A

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or Conversions

//Function Prototypes Here N/A

//Program Execution Begins Here
int main ()
{
    //Declare Variables Here
    int books;
    
    //Input or Initialize Values Here
    cout << "How many books did you purchase this month? ";
    cin >> books;
    
    //Process Calculations Here
    if (books <= 0) cout << "You have earned 0 points.";
    else if (books == 1) cout << "You have earned 5 points.";
    else if (books == 2) cout << "You have earned 15 points.";
    else if (books == 3) cout << "You have earned 30 points.";
    else if (books >= 4) cout << "You have earned 60 points.";
    
    //Exit
    return 0;
}
