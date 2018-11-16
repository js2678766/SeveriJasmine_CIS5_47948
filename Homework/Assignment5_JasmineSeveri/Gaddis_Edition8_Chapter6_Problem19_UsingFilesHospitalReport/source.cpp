/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Using Files - Hospital Report
 * Modify Programming Challenge 15, Overloaded Hospital, to write the report it creates
 * to a file.
 */

//System Libraries
#include <iostream> //I/O Library
#include <fstream> //Files
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
int inpat();
int outpat();


//Program Execution Begins
int main()
{ 
    int choice, charge;
    
    cout<<"Type 1 the patient was an In-Patient.\n";
    cout<<"Type 2 if the patient was an Out-Patient.\n";
    cout<<"Choice: ";
    cin>>choice;
    
    if (choice == 1)
    {
        inpat();
    }
    if (choice == 2)
    {
        outpat();
    }
}

int inpat()
{
    int days, rate, meds, serv, dprice, charge;
    ofstream f;
    

    cout<<"How many days did the patient spend in the hospital? ";
    cin>>days;
    if (days < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>days;
        }
    cout<<"What is the daily rate for the hospital? $";
    cin>>rate;
    if (rate < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>rate;
        }
    cout<<"What were the total charges for their medications? $";
    cin>>meds;
    if (meds < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>meds;
        }
    cout<<"What were the total charges for any other services they received (lab tests, etc.)? $";
    cin>>serv;
    if (serv < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>serv;
        }
    
    dprice = days * rate;
    
    charge = dprice + meds + serv;
    
    cout<<"The patient's total charges = $"<<charge;

    f.open("hosfile.txt");
    f<<"How many days did the patient spend in the hospital? "<<days<<endl;
    f<<"What is the daily rate for the hospital? $"<<rate<<endl;
    f<<"What were the total charges for their medications? $"<<meds<<endl;
    f<<"What were the total charges for any other services they received (lab tests, etc.)? $"<<serv<<endl;
    f<<"The patient's total charges = $"<<charge;
    f<<endl;
    f.close();
}

int outpat()
{
    ofstream f;
    int meds, serv, charge;

    cout<<"What was the total charge for their medications? $";
    cin>>meds;
    if (meds < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>meds;
        }
    cout<<"What was the total charge for any services they received (lab tests, etc.)? $";
    cin>>serv;
    if (serv < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>serv;
        }
    
    charge = meds + serv;
    
    cout<<"The patient's total charges = $"<<charge;
    
    f.open("hosfile.txt");
    f<<"What were the total charges for their medications? $"<<meds<<endl;
    f<<"What were the total charges for any other services they received (lab tests, etc.)? $"<<serv<<endl;
    f<<"The patient's total charges = $"<<charge;
    f<<endl;
    f.close();
}