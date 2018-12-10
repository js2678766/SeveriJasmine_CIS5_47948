/*
 * Name: Jasmine Severi
 * Date: 12/09/2018
 * Purpose: Movie Data
 * Write a program that uses a structure named MovieData to store the following information
 * about a movie:
 *      Title
 *      Director
 *      Year Released
 *      Running Time (in minutes)
 * The program should create two MovieData variables, store values in their members,
 * and pass each one, in turn, to a function that displays the information about the movie
 * in a clearly formatted manner.
 */

//System Libraries
#include <iostream> //I/O Library
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
};

//Function Prototypes
void Movie(MovieData, MovieData);

//Program Execution Begins

int main()
{
    MovieData Movie1 = {"Fantastic Beasts and Where to Find Them", "David Yates", 2016, 133};
    MovieData Movie2 = {"Fantastic Beasts: The Crimes of GrindelWald", "David Yates", 2018, 134};
    
    Movie(Movie1, Movie2);
}

//****************************************************************************
//Definition of function Movie. This function displays what is stored in the *
//MovieData data type variables Movie1 and Movie2.                           *
//****************************************************************************

void Movie (MovieData M1, MovieData M2)
{
    cout<<"Movie 1: "<<M1.Title<<endl;
    cout<<"Director: "<<M1.Direct<<endl;
    cout<<"Year Released: "<<M1.Year<<endl;
    cout<<"Running Time (in minutes): "<<M1.Time<<endl;
    
    cout<<"\nMovie 2: "<<M2.Title<<endl;
    cout<<"Director: "<<M2.Direct<<endl;
    cout<<"Year Released: "<<M2.Year<<endl;
    cout<<"Running Time (in minutes): "<<M2.Time<<endl;
}