/*
    24. Word Game
    Write a program that plays a word game with the user. The program should ask the
    user to enter the following:
        • His or her name
        • His or her age
        • The name of a city
        • The name of a college
        • A profession
        • A type of animal
        • A pet’s name
After the user has entered these items, the program should display the following story,
inserting the user’s input into the appropriate locations:
There once was a person named NAME who lived in CITY . At the age of
AGE , NAME went to college at COLLEGE . NAME graduated and went to work
as a PROFESSION . Then, NAME adopted a(n) ANIMAL named PETNAME . They
both lived happily ever after!
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string NAME, AGE, CITY, COLLEGE, PROFESSION, ANIMAL, PETNAME;
    
    cout << "Let's play a game!\n";
    cout << "Please type your name: ";
    getline(cin, NAME);
    
    cout << "Hello, " << NAME << "! Type your age: ";
    getline(cin, AGE);
    
    cout << "Type the name of a city: ";
    getline(cin, CITY);
    
    cout << "Type the name of a college: ";
    getline(cin, COLLEGE);
    
    cout << "Type a kind of profession: ";
    getline(cin, PROFESSION);

    cout << "Type the name of a kind of animal: ";
    getline(cin, ANIMAL);  
    
    cout << "Type a name for a pet: ";
    getline(cin, PETNAME);
    
    cout << "There once was a person named " << NAME << " who lived in " << CITY << "\nAt the age of " << AGE << ", " << NAME << " and went to college at " << COLLEGE << ". " << NAME << " graduated and went to work as a(n) " << PROFESSION << ".\n"; 
    cout << "Then, " << NAME << " adopted a(n) " << ANIMAL << " named " << PETNAME << ". \n"; 
    cout << "They both lived happily ever after!\n";
    return 0;
}