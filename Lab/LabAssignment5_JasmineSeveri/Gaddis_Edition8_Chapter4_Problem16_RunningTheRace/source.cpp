/*
 * Name: Jasmine Severi
 * Date: 10/16/2018
 * Purpose: 16. Running the Race
 * Write a program that asks for the names of three runners and the time it took each
 * of them to finish a race. The program should display who came in first, second, and
 * third place.
 * Input Validation: Only accept positive numbers for the times.
 */

//System Libraries Here
#include <iostream> //I/O Library
using namespace std; //Namespace I/O stream library created

//User Libraries Here N/A

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or Conversions

//Function Prototypes Here N/A

//Program Execution Begins Here
int main()
{
    //Declare Variables Here
    string runner1, runner2, runner3; 
    int time1, time2, time3;
    
    //Input or Initialize Values Here
    cout << "Enter the name of the first runner: ";
    cin >> runner1;
    cout << "Enter how long it took to finish the race: ";
    cin >> time1;
    cout << "Enter the name of the second runner: ";
    cin >> runner2;
    cout << "Enter how long it took to finish the race: ";
    cin >> time2;
    cout << "Enter the name of the third runner: ";
    cin >> runner3;
    cout << "Enter how long it took to finish the race: ";
    cin >> time3;


    //Process Calculations Here
    if (time1 <= 0 || time2 <= 0 || time3 <= 0) cout << "The time cannot be 0 or less.\n";
    else if (time1 < time2 && time2 < time3) cout << runner1 << " came in first place!\n" << runner2 << " came in second place.\n" << runner3 << " came in third place.";
    else if (time1 < time3 && time3 < time2) cout << runner1 << " came in first place!\n" << runner3 << " came in second place.\n" << runner2 << " came in third place.";
    else if (time2 < time3 && time3 < time1) cout << runner2 << " came in first place!\n" << runner3 << " came in second place.\n" << runner1 << " came in third place.";
    else if (time2 < time1 && time1 < time3) cout << runner2 << " came in first place!\n" << runner1 << " came in second place.\n" << runner3 << " came in third place.";
    else if (time3 < time1 && time1 < time2) cout << runner3 << " came in first place!\n" << runner1 << " came in second place.\n" << runner2 << " came in third place.";
    else if (time3 < time2 && time2 < time1) cout << runner3 << " came in first place!\n" << runner2 << " came in second place.\n" << runner1 << " came in third place.";
    else cout << "It's a tie!";
    
    //Exit
    return 0;
    
}

