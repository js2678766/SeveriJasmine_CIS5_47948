/*
    13. Book Club Points
    Serendipity Booksellers has a book club that awards points to its customers based on
    the number of books purchased each month. The points are awarded as follows:
        • If a customer purchases 0 books, he or she earns 0 points.
        • If a customer purchases 1 book, he or she earns 5 points.
        • If a customer purchases 2 books, he or she earns 15 points.
        • If a customer purchases 3 books, he or she earns 30 points.
        • If a customer purchases 4 or more books, he or she earns 60 points.
    Write a program that asks the user to enter the number of books that he
 */

#include <iostream>
using namespace std;

int main ()
{
    double books;
    
    cout << "How many books did you purchase this month? ";
    cin >> books;
    
    if (books <= 0) cout << "You have earned 0 points.";
    else if (books == 1) cout << "You have earned 5 points.";
    else if (books == 2) cout << "You have earned 15 points.";
    else if (books == 3) cout << "You have earned 30 points.";
    else if (books >= 4) cout << "You have earned 60 points.";
    return 0;
}
