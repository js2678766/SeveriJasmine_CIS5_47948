/*
    4. Areas of Rectangles
    The area of a rectangle is the rectangle’s length times its width. Write a program that
    asks for the length and width of two rectangles. The program should tell the user which
    rectangle has the greater area, or if the areas are the same.
 */

#include <iostream>
using namespace std;

int main()
{
    double A_length, B_length, A_width, B_width, A_area, B_area;
    
    cout << "Enter the length and width of two rectangles and I will tell you which has the greater area or if they are equal.\n";
    cout << "Enter the length and width of rectangle A: ";
    cin >> A_length >> A_width;
    cout << "Enter the length and width of rectangle B: ";
    cin >> B_length >> B_width;
    
    A_area = A_length * A_width;
    B_area = B_length * B_width;
    
    if (A_area == B_area) cout << "They are equal.";
    else if (A_area > B_area) cout << "Rectangle A has the greater area.";
    else if (A_area < B_area) cout << "Rectangle B has the greater area";
    return 0;
}
