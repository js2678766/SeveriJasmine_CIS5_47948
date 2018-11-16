/*
 * Name: Jasmine Severi
 * Date: 10/18/2018
 * Purpose: 8. Math Tutor
 * This program started in Programming Challenge 15 of Chapter 3 , and was modified
 * in Programming Challenge 9 of Chapter 4 . Modify the program again so it displays a
 * menu allowing the user to select an addition, subtraction, multiplication, or division
 * problem. The final selection on the menu should let the user quit the program. After
 * the user has finished the math problem, the program should display the menu again.
 * This process is repeated until the user chooses to quit the program.
 * Input Validation: If the user selects an item not on the menu, display an error message
 * and display the menu again.
 */

//System Libraries Here
#include <iostream> //I/O Library
#include <iomanip>
#include <cstdlib> //General Utilities Library, used for generating the random numbers
#include <ctime>
using namespace std; //Namespace I/O strea0m library created

int main()
{
    char choice;
    
    do
    {
        cout<<"Choose the problem you wish to solve"<<endl;
        cout<<"0 -> Multiplication"<<endl;
        cout<<"1 -> Division"<<endl;
        cout<<"2 -> Addition"<<endl;
        cout<<"3 -> Subtraction"<<endl;
        cout<<"4 -> Quit"<<endl;
        cin>>choice;
    
        switch(choice)
        {
            case '0':
            {
                //Declare Variables Here
                const int MIN_VAL = 100; //The smallest number the random numbers can be
                const int MAX_VAL = 999; //The largest number the random numbers can be
    
                int random1, random2, theiran, answer; //Stores the two random numbers, their answer, and the correct answer
    
                unsigned seed = time(0);
    
                char ch;
    
                //Generating the random numbers
                srand(seed);
    
                random1 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
                random2 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    
                //Input or Initialize Values Here
                cout << "Type in your answer:\n";
                cout << " " << random1 << endl;
                cout << "x" << random2 << endl;
                cout << "____\n";
                cin >> theiran;
       
                answer = random1 * random2;
    
                //Process Calculations Here
                if (theiran == answer) cout << "Congratulations! That is correct.";
                else cout << "The correct answer is " << answer;

            }
                break;
            case '1':
            {
                //Declare Variables Here
                const int MIN_VAL = 100; //The smallest number the random numbers can be
                const int MAX_VAL = 999; //The largest number the random numbers can be
    
                int random1, random2, theiran, answer; //Stores the two random numbers, their answer, and the correct answer
    
                unsigned seed = time(0);
    
                char ch;
    
                //Generating the random numbers
                srand(seed);
    
                random1 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
                random2 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    
                //Input or Initialize Values Here
                cout << "Type in your answer:\n";
                cout << " " << random1 << endl;
                cout << "÷" << random2 << endl;
                cout << "____\n";
                cin >> theiran;
       
                answer = random1 / random2;
    
                //Process Calculations Here
                if (theiran == answer) cout << "Congratulations! That is correct.";
                else cout << "The correct answer is " << answer;
  
            }
                break;
            case '2':
            {
                //Declare Variables Here
                const int MIN_VAL = 100; //The smallest number the random numbers can be
                const int MAX_VAL = 999; //The largest number the random numbers can be
    
                int random1, random2, theiran, answer; //Stores the two random numbers, their answer, and the correct answer
    
                unsigned seed = time(0);
    
                char ch;
    
                //Generating the random numbers
                srand(seed);
    
                random1 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
                random2 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    
                //Input or Initialize Values Here
                cout << "Type in your answer:\n";
                cout << " " << random1 << endl;
                cout << "+" << random2 << endl;
                cout << "____\n";
                cin >> theiran;
       
                answer = random1 + random2;
    
                //Process Calculations Here
                if (theiran == answer) cout << "Congratulations! That is correct.";
                else cout << "The correct answer is " << answer;
   
            }
                break;
            case '3':
            {
                //Declare Variables Here
                const int MIN_VAL = 100; //The smallest number the random numbers can be
                const int MAX_VAL = 999; //The largest number the random numbers can be
    
                int random1, random2, theiran, answer; //Stores the two random numbers, their answer, and the correct answer
    
                unsigned seed = time(0);
    
                char ch;
    
                //Generating the random numbers
                srand(seed);
    
                random1 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
                random2 = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    
                //Input or Initialize Values Here
                cout << "Type in your answer:\n";
                cout << " " << random1 << endl;
                cout << "-" << random2 << endl;
                cout << "____\n";
                cin >> theiran;
       
                answer = random1 - random2;
    
                //Process Calculations Here
                if (theiran == answer) cout << "Congratulations! That is correct.";
                else cout << "The correct answer is " << answer;

            }
                break;
            case '4':
            {
                cout << "Program ended.";
                return 0;
            }
                break;

            default:
                cout<<"Please choose one of the numbers on the menu only."<<endl;
        }
    } while (choice != 4);
    return 0;
}