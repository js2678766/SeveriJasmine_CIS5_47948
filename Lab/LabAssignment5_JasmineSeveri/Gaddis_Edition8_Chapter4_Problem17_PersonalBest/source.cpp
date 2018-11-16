/*
 * Name: Jasmine Severi
 * Date: 10/16/2018
 * Purpose: 17. Personal Best
 * Write a program that asks for the name of a pole vaulter and the dates and vault
 * heights (in meters) of the athlete’s three best vaults. It should then report, in order of
 * height (best first), the date on which each vault was made and its height.
 * Input Validation: Only accept values between 2.0 and 5.0 for the heights.
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
    string name, date1, date2, date3, height1, height2, height3;
    
    //Input or Initialize Values Here
    cout << "Enter the name of the pole vaulter: ";
    cin >> name;
    cout << "Enter three dates: ";
    cin >> date1 >> date2 >> date3;
    cout << "Enter the height of the jump on each date, one jump for each day (anything from 2.0 to 5.0): ";
    cin >> height1 >> height2 >> height3;
    
    //Process Calculations Here
    if (height1 < "2.0" || height1 > "5.0" || height2 < "2.0" || height2 > "5.0" || height3 < "2.0" || height3 > "5.0") cout << "Invalid height.";
    else if (height1 > height2 && height2 > height3) cout << "Date: " << date1 << " Best Height: " << height1 << endl << "Date: " << date2 << " Height: " << height2 << endl << "Date: " << date3 << " Height: " << height3;
    else if (height1 > height3 && height3 > height2) cout << "Date: " << date1 << " Best Height: " << height1 << endl << "Date: " << date3 << " Height: " << height3 << endl << "Date: " << date2 << " Height: " << height2;
    else if (height2 > height3 && height3 > height1) cout << "Date: " << date2 << " Best Height: " << height2 << endl << "Date: " << date3 << " Height: " << height3 << endl << "Date: " << date1 << " Height: " << height1;
    else if (height2 > height1 && height1 > height3) cout << "Date: " << date2 << " Best Height: " << height2 << endl << "Date: " << date1 << " Height: " << height1 << endl << "Date: " << date3 << " Height: " << height3;
    else if (height3 > height2 && height2 > height1) cout << "Date: " << date3 << " Best Height: " << height3 << endl << "Date: " << date2 << " Height: " << height2 << endl << "Date: " << date1 << " Height: " << height1;
    else if (height3 > height1 && height1 > height2) cout << "Date: " << date3 << " Best Height: " << height3 << endl << "Date: " << date1 << " Height: " << height1 << endl << "Date: " << date2 << " Height: " << height2;
    else cout << "Invalid entry.";
    
    //Exit
    return 0;
}

