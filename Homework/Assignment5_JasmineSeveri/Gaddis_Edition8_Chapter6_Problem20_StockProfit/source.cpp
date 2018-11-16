/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Stock Profit
 * The profit from the sale of a stock can be calculated as follows:
 * Profit = (( NS x SP ) - SC ) - (( NS x PP ) + PC )
 * where NS is the number of shares, SP is the sale price per share, SC is the sale commission
 * paid, PP is the purchase price per share, and PC is the purchase commission paid.
 * If the calculation yields a positive value, then the sale of the stock resulted in a profit.
 * If the calculation yields a negative number, then the sale resulted in a loss.
 * Write a function that accepts as arguments the number of shares, the purchase price per
 * share, the purchase commission paid, the sale price per share, and the sale commission
 * paid. The function should return the profit (or loss) from the sale of stock.
 * Demonstrate the function in a program that asks the user to enter the necessary data
 * and displays the amount of the profit or loss.
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int stock(int, int, int, int, int);

//Program Execution Begins

int main()
{
    int NS, SP, SC, PP, PC;
    
    cout<<"What are the number of shares?: ";
    cin>>NS;
    cout<<"What is the purchase price per share?: $";
    cin>>PP;
    cout<<"What is the purchase commission paid?: $";
    cin>>PC;
    cout<<"What is the sale price per share?: $";
    cin>>SP;
    cout<<"What is the sale commission paid?: $";
    cin>>SC;
   
    stock(NS, SP, SC, PP, PC);
    
    return 0;
}

int stock(int NS, int SP, int SC, int PP, int PC)
{
    int profit;

    profit = (( NS * SP ) - SC ) - (( NS * PP ) + PC );
    if (profit > 0)
    {
        cout<<endl<<"The profit is: $"<<profit;
    }
    if (profit <= 0)
    {
        cout<<endl<<"The loss is: $"<<profit;
    }
}