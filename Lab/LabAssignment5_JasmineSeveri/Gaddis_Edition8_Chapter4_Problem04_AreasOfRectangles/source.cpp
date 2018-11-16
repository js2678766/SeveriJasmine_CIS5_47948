 /*
  * Name: Jasmine Severi
  * Date: 10/16/2018
  * Purpose: 4. Areas of Rectangles
  * The area of a rectangle is the rectangle’s length times its width. Write a program that
  * asks for the length and width of two rectangles. The program should tell the user which
  * rectangle has the greater area, or if the areas are the same.
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
    int Alength, Blength, Awidth, Bwidth, Aarea, Barea; //Stores the length, width and areas of the two rectangles
    
    //Input or Initialize Values Here
    cout << "Enter the length and width of two rectangles and I will tell you which has the greater area or if they are equal.\n";
    cout << "Enter the length and width of rectangle A: ";
    cin >> Alength >> Awidth;
    cout << "Enter the length and width of rectangle B: ";
    cin >> Blength >> Bwidth;
    
    Aarea = Alength * Awidth; //Calculates the area of the first rectangle
    Barea = Blength * Bwidth; //Calculates the area of the second rectangle
    
    //Process Calculations Here
    if (Aarea == Barea) cout << "They are equal.";
    else if (Aarea > Barea) cout << "Rectangle A has the greater area.";
    else if (Aarea < Barea) cout << "Rectangle B has the greater area";
    
    //Exit
    return 0;
}
