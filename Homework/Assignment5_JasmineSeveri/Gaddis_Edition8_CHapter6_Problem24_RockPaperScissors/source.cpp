/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Rock Paper Scissors
 * Write a program that lets the user play the game of Rock, Paper, Scissors against the
 * computer. The program should work as follows.
 *
 *      1. When the program begins, a random number in the range of 1 through 3 is generated.
 *         If the number is 1, then the computer has chosen rock. If the number is 2, then
 *         the computer has chosen paper. If the number is 3, then the computer has chosen
 *         scissors. (Don’t display the computer’s choice yet.)
 *      2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard.
 *         (You can use a menu if you prefer.)
 *      3. The computer’s choice is displayed.
 *      4. A winner is selected according to the following rules:
 *      
 *      • If one player chooses rock and the other player chooses scissors, then rock wins.
 *        (The rock smashes the scissors.)
 *      • If one player chooses scissors and the other player chooses paper, then scissors
 *        wins. (Scissors cuts paper.)
 *      • If one player chooses paper and the other player chooses rock, then paper wins.
 *        (Paper wraps rock.)
 *      • If both players make the same choice, the game must be played again to determine
 *        the winner.
 * 
 * Be sure to divide the program into functions that perform each major task.
 */

//System Libraries
#include <iostream> //I/O Library
#include <cstdlib> //General Utilities Library, used for generating random numbers
#include <ctime> //To help with random number generation
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int winner(int user, int comp);

//Program Execution Begins

int main()
{  
    int user;
    
    cout<<"Let's play Rock, Paper, Scissors!\n";
    cout<<"1 -> Rock\n";
    cout<<"2 -> Paper\n";
    cout<<"3 -> Scissors\n";
    cout<<"4 -> End\n";
    cout<<"Your choice: ";
    cin>>user;
    cout<<endl;
   
    const int MINNUM = 1;
    const int MAXNUM = 3;
    int comp;
    unsigned seed = time(0);
        
    comp = (rand() % (MAXNUM - MINNUM + 1)) + MINNUM; 
   
    cout<<endl<<comp<<endl;
   
    if (comp == 1)
    {
        cout<<"The computer chose Rock!\n";
    }
    if (comp == 2)
    {
        cout<<"The computer chose Paper!\n";
    }
    if (comp == 3)
    {
        cout<<"The computer chose Scissors!\n";
    }
   
    winner(user, comp); 
   
    return 0;
}

int winner(int user, int comp)
{
    if (user == 1 && comp == 2)
    {
       cout<<"You chose Rock.\n";
       cout<<"Paper covers Rock.\n";
       cout<<"You lose.\n";
    }
    if (user == 2 && comp == 1)
    {
       cout<<"You chose Paper.\n";
       cout<<"Paper covers Rock.\n";
       cout<<"You win!\n";
    }
    if (user == 2 && comp == 3)
    {
       cout<<"You chose Paper.\n";
       cout<<"Scissors cuts Paper.\n";
       cout<<"You lose.\n";
    }
    if (user == 3 && comp == 2)
    {
       cout<<"You chose Scissors.\n";
       cout<<"Scissors cuts Paper.\n";
       cout<<"You win!\n";
    }
    if (user == 3 && comp == 1)
    {
       cout<<"You chose Scissors.\n";
       cout<<"Rock smashes Scissors.\n";
       cout<<"You lose.\n";
    }
    if (user == 1 && comp == 3)
    {
       cout<<"You chose Rock.\n";
       cout<<"Rock smashes Scissors.\n";
       cout<<"You win!\n";
    }
    if (user == comp)
    {
        int user;
    
        cout<<"It's a tie! Try again.\n";
        cout<<"1 -> Rock\n";
        cout<<"2 -> Paper\n";
        cout<<"3 -> Scissors\n";
        cout<<"4 -> End\n";
        cout<<"Your choice: ";
        cin>>user;
        cout<<endl;
   
        const int MINNUM = 1;
        const int MAXNUM = 3;
        int comp;
        unsigned seed = time(0);
        
        comp = (rand() % (MAXNUM - MINNUM + 1)) + MINNUM; 
   
        cout<<endl<<comp<<endl;
   
        if (comp == 1)
        {
            cout<<"The computer chose Rock!\n";
        }
        if (comp == 2)
        {
            cout<<"The computer chose Paper!\n";
        }
        if (comp == 3)
        {
            cout<<"The computer chose Scissors!\n";
        }
   
        winner(user, comp); 
    }
   if (user == 4)
   {
       cout<<"Goodbye!";
   } 
}