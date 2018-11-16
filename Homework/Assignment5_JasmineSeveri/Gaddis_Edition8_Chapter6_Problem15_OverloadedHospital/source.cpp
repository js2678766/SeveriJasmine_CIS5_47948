/*
 * Name: Jasmine Severi
 * Date: 11/11/2018
 * Purpose: Overloaded Hospital
 * Write a program that computes and displays the charges for a patient’s hospital stay.
 * First, the program should ask if the patient was admitted as an inpatient or an outpatient.
 * If the patient was an in-patient, the following data should be entered:
 *      • The number of days spent in the hospital
 *      • The daily rate
 *      • Hospital medication charges
 *      • Charges for hospital services (lab tests, etc.)
 * The program should ask for the following data if the patient was an out-patient:
 *      • Charges for hospital services (lab tests, etc.)
 *      • Hospital medication charges
 * The program should use two overloaded functions to calculate the total charges. One
 * of the functions should accept arguments for the in-patient data, while the other function
 * accepts arguments for out-patient information. Both functions should return the
 * total charges.
 * Input Validation: Do not accept negative numbers for any data.
 */

//System Libraries
#include <iostream> //I/O Library
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
    cout<<"What was the total charge for their medications? $";
    cin>>meds;
    if (meds < 0)
        {
            cout<<"Invalid number.\n";
            cout<<"Please enter 0 or a positive number: ";
            cin>>meds;
        }
    cout<<"What was the total charge for any other services they received (lab tests, etc.)? $";
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
}

int outpat()
{
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
}
