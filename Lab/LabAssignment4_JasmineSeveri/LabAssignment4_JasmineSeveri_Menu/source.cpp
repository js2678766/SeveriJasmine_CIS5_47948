/*
     2.  Use the menu program in the Github folder and put all 10 problems from your 
     Assignment 3 Homework into 1 program using the menu.  All you have to do is 
     modify the menu for your 10 projects.  Copy your code for each problem into 
     the case section for that particular problem.  i.e. everything after main and 
     before return.  Do 1 problem at a time and test then continue and add the next 
     problem and repeat till your done.  Al the system libraries you used in all 
     the problems should be included in the normal area where system libraries go.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char** argv)
{
    char choice;
    
    cout<<"Choose the problem you wish to solve"<<endl;
    cout<<"0 -> Gaddis_Edition8_Chapter4_Problem01_MinimumMaximum"<<endl;
    cout<<"1 -> Gaddis_Edition8_Chapter4_Problem02_RomanNumeralConverter"<<endl;
    cout<<"2 -> Gaddis_Edition8_Chapter4_Problem03_MagicDatehs"<<endl;
    cout<<"3 -> Gaddis_Edition8_Chapter4_Problem04_AreasOfRectangles"<<endl;
    cout<<"4 -> Gaddis_Edition8_Chapter4_Problem06_MassAndWeight"<<endl;
    cout<<"5 -> Gaddis_Edition8_Chapter4_Problem08_ColorMixer"<<endl;
    cout<<"6 -> Gaddis_Edition8_Chapter4_Problem11_MathTutor"<<endl;
    cout<<"7 -> Gaddis_Edition8_Chapter4_Problem13_BookClubPoints"<<endl;
    cout<<"8 -> Gaddis_Edition8_Chapter4_Problem16_RunningTheRace"<<endl;
    cout<<"9 -> Gaddis_Edition8_Chapter4_Problem17_PersonalBest"<<endl;
    cin>>choice;
    
    switch(choice)
    {
        case '0':
        {
            double first, second;
    
            cout << "Enter two numbers separated by a space: ";
            cin >> first >> second;
    
            first > second ? cout << first << " is the bigger number.\n" << second << " is the smaller number." 
            : cout << first << " is the smaller number.\n" << second << " is the bigger number.";
            return 0;
        }
            break;
        case '1':
        {
            int choice;
    
            cout << "Enter a number within the range of 1 through 10 to find out its Roman Numeral: ";
            cin >> choice;
    
            switch (choice)
            {
                case 1: cout << "I\n";
                    break;
                case 2: cout << "II\n";
                    break;
                case 3: cout << "III\n";
                    break;
                case 4: cout << "IV\n";
                    break;
                case 5: cout << "V\n";
                    break;
                case 6: cout << "VI\n";
                    break;
                case 7: cout << "VII\n";
                    break;
                case 8: cout << "VIII\n";
                    break;
                case 9: cout << "IX\n";
                    break;
                case 10: cout << "X\n";
                    break;
                default: cout << "The valid choices are 1-10.";
            }
        }
            break;
        case '2':
        {
        double month, day, year;
    
        cout << "If a date's month times its day equals the last two digits of its year then the date is a magic date. Tell me a date I will tell you if it is magic.\n";
        cout << "Enter a month in numeric form (1-12 or 01-12): ";
        cin >> month;
        cout << "Enter a day of the month (1-32 or 01-32): ";
        cin >> day;
        cout << "Enter a two-digit year (01-99): ";
        cin >> year;
    
        if (month <= 12 && month >= 1 && day <= 32 && day >= 1 && year <= 99 && year >= 1)
                if (month * day == year)
                cout << "That is a magic date!";
                else
                cout << "That is not a magic date.";
        else cout << "That date is not valid.";
        }
            break;
        case '3':
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
        }
            break;
        case '4':
        {
            double weight, mass;
    
            cout << "Enter the object's mass and I'll calculate its weight in newtons: ";
            cin >> mass;
    
            weight = mass * 9.8;
    
            if (weight > 1000) cout << "Your object is too heavy.";
            else if (weight < 10) cout << "Your object is too light.";
            else cout << weight;
        }
            break;
        case '5':
        {
            string color_1, color_2;
    
            cout << "The primary colors are Red, Blue and Yellow.\n"; 
            cout << "Enter two primary colors (capitalizing the first letter of each word) and I will tell you what color they make when combined: ";
            cin >> color_1 >> color_2;
    
            if (color_1 == "Blue" && color_2 == "Red") cout << "Blue and Red make Purple.";
            else if (color_2 == "Blue" && color_1 == "Red") cout << "Red and Blue make Purple.";
            else if (color_2 == "Blue" && color_1 == "Yellow") cout << "Blue and Yellow make Green.";
            else if (color_1 == "Blue" && color_1 == "Yellow") cout << "Yellow and Blue make Green.";
            else if (color_1 == "Red" && color_2 == "Yellow") cout << "Red and Yellow make Orange.";
            else if (color_2 == "Red" && color_1 == "Yellow") cout << "Yellow and Red make Orange.";
            else cout << "That is not a valid entry.";
        }
            break;
        case '6':
        {
            const int MIN_VALUE = 100;
            const int MAX_VALUE = 999;
    
            int random1, random2, their_answer, answer;
    
            unsigned seed = time(0);
    
            char ch;
    
            srand(seed);
    
            random1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
            random2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    
            cout << "Type in your answer:\n";
            cout << " " << random1 << endl;
            cout << "+" << random2 << endl;
            cout << "____\n";
            cin >> their_answer;
    
            answer = random1 + random2;
    
            if (their_answer == answer) cout << "Congratulations! That is correct.";
            else cout << "The correct answer is " << answer;
        }
            break;
        case '7':
        {
            double books;
    
            cout << "How many books did you purchase this month? ";
            cin >> books;
    
            if (books <= 0) cout << "You have earned 0 points.";
            else if (books == 1) cout << "You have earned 5 points.";
            else if (books == 2) cout << "You have earned 15 points.";
            else if (books == 3) cout << "You have earned 30 points.";
            else if (books >= 4) cout << "You have earned 60 points.";
        }
            break;
        case '8':
        {
            string runner1, runner2, runner3; 
            double time1, time2, time3;
    
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

            if (time1 <= 0 || time2 <= 0 || time3 <= 0) cout << "The time cannot be 0 or less.\n";
            else if (time1 < time2 && time2 < time3) cout << runner1 << " came in first place!\n" << runner2 << " came in second place.\n" << runner3 << " came in third place.";
            else if (time1 < time3 && time3 < time2) cout << runner1 << " came in first place!\n" << runner3 << " came in second place.\n" << runner2 << " came in third place.";
            else if (time2 < time3 && time3 < time1) cout << runner2 << " came in first place!\n" << runner3 << " came in second place.\n" << runner1 << " came in third place.";
            else if (time2 < time1 && time1 < time3) cout << runner2 << " came in first place!\n" << runner1 << " came in second place.\n" << runner3 << " came in third place.";
            else if (time3 < time1 && time1 < time2) cout << runner3 << " came in first place!\n" << runner1 << " came in second place.\n" << runner2 << " came in third place.";
            else if (time3 < time2 && time2 < time1) cout << runner3 << " came in first place!\n" << runner2 << " came in second place.\n" << runner1 << " came in third place.";
            else cout << "It's a tie!";
        }
            break;
        case '9':
        {
            string name, date1, date2, date3, height1, height2, height3;
    
            cout << "Enter the name of the pole vaulter: ";
            cin >> name;
            cout << "Enter three dates: ";
            cin >> date1 >> date2 >> date3;
            cout << "Enter the height of the jump on each date, one jump for each day (anything from 2.0 to 5.0): ";
            cin >> height1 >> height2 >> height3;
    
            if (height1 < "2.0" || height1 > "5.0" || height2 < "2.0" || height2 > "5.0" || height3 < "2.0" || height3 > "5.0") cout << "Invalid height.";
            else if (height1 > height2 && height2 > height3) cout << "Date: " << date1 << " Best Height: " << height1 << endl << "Date: " << date2 << " Height: " << height2 << endl << "Date: " << date3 << " Height: " << height3;
            else if (height1 > height3 && height3 > height2) cout << "Date: " << date1 << " Best Height: " << height1 << endl << "Date: " << date3 << " Height: " << height3 << endl << "Date: " << date2 << " Height: " << height2;
            else if (height2 > height3 && height3 > height1) cout << "Date: " << date2 << " Best Height: " << height2 << endl << "Date: " << date3 << " Height: " << height3 << endl << "Date: " << date1 << " Height: " << height1;
            else if (height2 > height1 && height1 > height3) cout << "Date: " << date2 << " Best Height: " << height2 << endl << "Date: " << date1 << " Height: " << height1 << endl << "Date: " << date3 << " Height: " << height3;
            else if (height3 > height2 && height2 > height1) cout << "Date: " << date3 << " Best Height: " << height3 << endl << "Date: " << date2 << " Height: " << height2 << endl << "Date: " << date1 << " Height: " << height1;
            else if (height3 > height1 && height1 > height2) cout << "Date: " << date3 << " Best Height: " << height3 << endl << "Date: " << date1 << " Height: " << height1 << endl << "Date: " << date2 << " Height: " << height2;
            else cout << "Invalid entry.";
        }
            break;
        default:
            cout<<"Please choose one of the numbers on the menu only."<<endl;
    }
    return 0;
}