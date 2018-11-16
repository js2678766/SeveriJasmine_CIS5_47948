/*
    8. How Many Widgets?
    The Yukon Widget Company manufactures widgets that weigh 12.5 pounds each.
    Write a program that calculates how many widgets are stacked on a pallet, based on
    the total weight of the pallet. The program should ask the user how much the pallet
    weighs by itself and with the widgets stacked on it. It should then calculate and display
    the number of widgets stacked on the pallet.
 */

#include <iostream>
using namespace std;

int main()
{
    double widget = 12.5, empty_pallet, full_pallet, numberofwidgets;
    
    cout << "How much does the empty pallet weigh? ";
    cin >> empty_pallet;
    
    cout << "How much does the pallet weigh with the widgets on it? ";
    cin >> full_pallet;
    
    numberofwidgets = (full_pallet - empty_pallet) / widget;
    
    cout << "There are " << numberofwidgets << " widgets on the pallet.";
    return 0;
}

