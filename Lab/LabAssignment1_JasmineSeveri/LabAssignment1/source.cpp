/*
    Create a Netbeans project given the following,  calculate the military budget as a percentage of the federal budget for
    Federal Budget ->  $4.1 trillion https://en.wikipedia.org/wiki/2018_United_States_federal_budget   
    Military Budget -> $700 billion https://militarybenefits.info/2018-defense-budget-overview/
 */

#include <iostream>
using namespace std;

int main()
{
    float milBdgt, fedBdgt, mlPrcnt;
    
    milBdgt = 7.0e11f;  //Military Budget = 700 billion;
    fedBdgt = 4.1e12f;  //Federal Budget = 4.1 trillion;
    mlPrcnt = milBdgt / fedBdgt * 100;
    
    cout<<"Federal Budget: $4.1 trillion\n";
    cout<<"Military Budget: $700 billion\n";
    cout<<"Military's Budget as a Percent of the Federal Budget: "<<mlPrcnt<<"%";
    return 0;
}