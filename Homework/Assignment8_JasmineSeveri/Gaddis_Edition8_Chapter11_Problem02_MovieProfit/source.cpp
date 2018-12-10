/*
 * Name: Jasmine Severi
 * Date: 12/09/2018
 * Purpose: Movie Profit
 * Modify the Movie Data program written for Programming Challenge 1 to include two
 * additional members that hold the movie’s production costs and first-year revenues.
 * Modify the function that displays the movie data to display the title, director, release
 * year, running time, and first year’s profit or loss.
 */

//System Libraries
#include <iostream> //I/O Library
#include <iomanip>
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Structures
struct MovieData
{
    string Title;
    string Direct;
    int Year;
    int Time;
    int Cost;
    int Reven;
};

//Function Prototypes
void Movie(MovieData, MovieData);

//Program Execution Begins

int main()
{
    MovieData Movie1 = {"Fantastic Beasts and Where to Find Them", "David Yates", 2016, 133, 230000000, 814000000 };
    MovieData Movie2 = {"Fantastic Beasts: The Crimes of GrindelWald", "David Yates", 2018, 134, 200000000, 568500000};
    
    Movie(Movie1, Movie2);
}

//****************************************************************************
//Definition of function Movie. This function displays what is stored in the *
//MovieData data type variables Movie1 and Movie2.                           *
//****************************************************************************

void Movie (MovieData M1, MovieData M2)
{
    float prof1, prof2;
    
    prof1 = M1.Reven - M1.Cost;
    prof2 = M2.Reven - M2.Cost;
    
    cout<<"Movie 1: "<<M1.Title<<endl;
    cout<<"Director: "<<M1.Direct<<endl;
    cout<<"Year Released: "<<M1.Year<<endl;
    cout<<"Running Time (in minutes): "<<M1.Time<<endl;
    cout<<fixed<<setprecision(2)<<"Profit: $"<<prof1<<endl;
    
    cout<<"\nMovie 2: "<<M2.Title<<endl;
    cout<<"Director: "<<M2.Direct<<endl;
    cout<<"Year Released: "<<M2.Year<<endl;
    cout<<"Running Time (in minutes): "<<M2.Time<<endl;
    cout<<fixed<<setprecision(2)<<"Profit: $"<<prof2<<endl;
}