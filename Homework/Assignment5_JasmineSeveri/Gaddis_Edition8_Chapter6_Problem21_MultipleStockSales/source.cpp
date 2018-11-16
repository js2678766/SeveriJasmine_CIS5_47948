/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Multiple Stock Sales
 * Use the function that you wrote for Programming Challenge 20 (Stock Profit) in a
 * program that calculates the total profit or loss from the sale of multiple stocks. 
 * The program should ask the user for the number of stock sales and the necessary data for
 * each stock sale. It should accumulate the profit or loss for each stock sale and then
 * display the total
 */

//System Libraries
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int stock(int, int, int, int, int, int);

//Program Execution Begins

int main()
{
    int num, NS, SP, SC, PP, PC, total = 0;
    
    cout<<"How many stock sales should be calculated?: ";
    cin>>num;
    
    for (int j = 1; j <= num; j++)
    {
        cout<<endl<<"Stock Sales #"<<j<<endl;
        cout<<endl<<"What are the number of shares?: ";
        cin>>NS;
        cout<<"What is the purchase price per share?: $";
        cin>>PP;
        cout<<"What is the purchase commission paid?: $";
        cin>>PC;
        cout<<"What is the sale price per share?: $";
        cin>>SP;
        cout<<"What is the sale commission paid?: $";
        cin>>SC;
   
        stock(NS, SP, SC, PP, PC, total);
    }
    return 0;
}

int stock(int NS, int SP, int SC, int PP, int PC, int total)
{
    int profit;

    profit = (( NS * SP ) - SC ) - (( NS * PP ) + PC );
    if (profit > 0)
    {
        cout<<endl<<"The profit is: $"<<profit;
        total += profit;
    }
    if (profit <= 0)
    {
        cout<<endl<<"The loss is: $"<<profit;
        total += profit;
    }
    cout<<endl<<"The total is: $"<<total;
}