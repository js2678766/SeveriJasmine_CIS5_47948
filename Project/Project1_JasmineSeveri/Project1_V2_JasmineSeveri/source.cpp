/*
 * Name: Jasmine Severi
 * Date: 11/2/2018
 * Purpose: Project 1: A battle simulator game based on Dungeons & Dragons. 
 * Version 2
 */

//System Libraries
#include <iostream> //I/O Library
#include <cstdlib> //General Utilities Library, used for generating random numbers
#include <ctime>
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes

//Program Execution Begins

int main()
{
    //Declare Constants and Variables
    const int MINVALD = 1; //The smallest number the dice numbers can be
    const int MAXVAL20 = 20; //The largest number for the die 20 (D20)
    const int MAXVAL12 = 12; //D12
    const int MAXVAL8 = 8; //D8
    const int MAXVAL6 = 6; //D6
    int PC_HP, En_HP; //To store PC's and Enemy's Hit Points (randomly generated). The Player will try to get the Enemy's HP to 0 and vice versa.
    int PC_AC, En_AC; //To store PC's and Enemy's Armor Class. The PC needs to get a number >= En_AC in order to do damage to them (knocking their HPs down).
    int PC_Init, En_Init; //To store the PC's and the Enemy's initiative, which will determine who goes first
    int PC_Hit, En_Hit; //To store their To Hit roll, to determine whether they hit their opponent. This number must be >= their opponent's AC to do damage
    int PC_Dam, En_Dam; //To store the PC's and the Enemy's damage rolls. This number will be subtracted from their enemy's HP.
    int En_DHP, PC_DHP; //To store the damage the PC's and the Enemy's HPs take.
    char ch; //To have them press enter
    
    unsigned seed = time(0);
    
    int MINENHP = 20; //The minimum amount of HP the Enemy can have
    int MAXENHP = 30; //The maximum amount of HP the Enemy can have
    int MINPCHP = 20; //The minimum amount of HP the PC can have
    int MAXPCHP = 35; //The maximum amount of HP the PC can have
    int MINENAC = 19; //The minimum amount of HP the Enemy can have
    int MAXENAC = 22; //The maximum amount of HP the Enemy can have
    int MINPCAC = 18; //The minimum amount of HP the PC can have
    int MAXPCAC = 23; //The maximum amount of HP the PC can have
    
    srand(seed);
    
    //When either the Enemy's or the PC's HPs are knocked down to 0, the game is over. Whoever knocked the other down to 0 or lower wins.
    En_HP = (rand() % (MAXENHP - MINENHP + 1)) + MINENHP; //Generating the random number for the Enemy's HPs
    PC_HP = (rand() % (MAXPCHP - MINPCHP + 1)) + MINPCHP; //Generating the random number for the PC's HP
    En_AC = (rand() % (MAXENAC - MINENAC + 1)) + MINENAC; //Generating the random number for the Enemy's AC
    PC_AC = (rand() % (MAXPCAC - MINPCAC + 1)) + MINPCAC; //Generating the random number for the PC's AC
    
    //Displaying the PC's information
    cout<<"[ You have "<<PC_HP<<" Hit Points\n"; //Displaying the PC's HPs
    cout<<"Your Armor Class is "<<PC_AC<<endl; //Displaying PC's AC
    cout<<"Your attack bonus is +8\n";
    cout<<"Your damage is +3\n";
    cout<<"Your initiative bonus is +4 ]\n";
    cout<<endl;
    
    //Displaying the Enemy's information
    cout<<"[ Your opponent has "<<En_HP<<" Hit Points\n"; //Displaying the Enemy's HP
    cout<<"Your opponent's Armor Class is "<<En_AC<<endl; //Displaying Enemy's AC
    cout<<"Your opponent's attack bonus is +7\n";
    cout<<"Your opponent's damage is +3\n";
    cout<<"Your opponent's initiative bonus is +3 ]\n";
    cout<<endl;
    
    //Initiative determines the order of actions, who goes first.
    PC_Init = (rand() % (MAXVAL20 - MINVALD + 1)) + MINVALD; //Generating the random number for the PC's initiative
    En_Init = (rand() % (MAXVAL20 - MINVALD + 1)) + MINVALD; //Generating the random number for the Enemy's initiative
        
    cout<<"Press Enter to roll for initiative.\n";
    cin.get(ch);
    cout<<"[Your initiative is: "<<PC_Init<<" +4 is "<<PC_Init+4<<"]"<<endl;
    cout<<"[Your opponent's initiative is: "<<En_Init<<" +3 is "<<En_Init+3<<"]"<<endl;
    cout<<endl;
    
    if (PC_Init+4 == En_Init+3) //If it's a tie, roll again
    {
        cout<<"[It's a tie!]\n"; 
        cout<<"[Rerolling initiative . . .]\n";
        cout<<"[Press Enter]\n";
        cin.get(ch);
        PC_Init = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Generating the random number for the PC's initiative
        En_Init = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Generating the random number for the Enemy's initiative
        
        cout<<"[Your initiative is: "<<PC_Init<<" +4 is "<<PC_Init+4<<"]"<<endl;
        cout<<"[Your opponent's initiative is: "<<En_Init<<" +3 is "<<En_Init+3<<"]"<<endl;
        cout<<endl;
    }
    if (PC_Init+4 > En_Init+3) //Player is first 
    {
        cout<<"[You're first!]\n";
        while (PC_HP > 0 && En_HP > 0) //This loop will continue until someone is knocked down to 0 HP or lower
        {
            cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
            cout<<"[Press Enter]\n";
            cin.get(ch);
            
            PC_Hit = (rand() % (MAXVAL20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
            cout<<"[You rolled: "<<PC_Hit<<" +8 is "<<PC_Hit+8<<"]"<<endl;
            
            if (PC_Hit+8 >= En_AC) //If the player hits, this is the player's damage
            {
                int Dam;
                
                cout<<"[Hit!]\n";
                cout<<endl;
                cout<<"[Rolling D8 for Damage . . .]\n";
                cout<<"[Press Enter]\n";
                cin.get(ch);
                
                PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                Dam = PC_Dam + 3;
                
                cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" +3 is "<<Dam<<" points of damage.]\n"; //Damage
                cout<<endl;
                
                En_HP = En_HP - Dam;
                
                cout<<"[Your opponent has "<<En_HP<<" Hit Points.]\n";
                cout<<"[You have "<<PC_HP<<" Hit Points].\n";
                cout<<endl;
                cout<<"[Press Enter]\n";
                cin.get(ch);
                if (PC_HP > 0 && En_HP > 0) //If the Enemy is not at 0 or lower hit points, they attack
                {
                    cout<<"[Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                    En_Hit = (rand() % (MAXVAL20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                    cout<<"[They rolled: "<<En_Hit<<" +7 is "<<En_Hit+7<<"]\n";
                    if (En_Hit+7 >= PC_AC) //If the enemy hits
                    {
                        int Dam;
                
                        cout<<"[Hit!]\n";
                        cout<<endl;
                        cout<<"[Rolling D8 for Damage . . .]\n";
                
                        En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                        Dam = En_Dam + 3;
                
                        cout<<"[They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                        cout<<endl;
                
                        PC_HP = PC_HP - Dam;
                
                        cout<<"[You have "<<PC_HP<<" Hit Points.]\n";
                        cout<<"[Your opponent has "<<En_HP<<" Hit Points].\n";
                        cout<<endl;
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                    }
                    else
                    {
                        cout<<"[Miss!]\n"<<endl;
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                    }
                }
            }
            if (PC_Hit+8 < En_AC) //If the player misses
            {
                cout<<"[Miss!]\n";
                cout<<endl;
                
                if (PC_HP > 0 && En_HP > 0) //If the Enemy is not at 0 or lower hit points, they attack
                {
                    cout<<"[Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                    En_Hit = (rand() % (MAXVAL20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                    cout<<"[They rolled: "<<En_Hit<<" +7 is "<<En_Hit+7<<"]\n";
                    if (En_Hit+7 >= PC_AC) //If the enemy hits
                    {
                        int Dam;
                
                        cout<<"[Hit!]\n";
                        cout<<endl;
                        cout<<"[Rolling D8 for Damage . . .]\n";
                
                        En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                        Dam = En_Dam + 3;
                
                        cout<<"[They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                        cout<<endl;
                
                        PC_HP = PC_HP - Dam;
                
                        cout<<"[You have "<<PC_HP<<" Hit Points.]\n";
                        cout<<"[Your opponent has "<<En_HP<<" Hit Points].\n";
                        cout<<endl;
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                    }
                    else
                    {
                        cout<<"[Miss!]\n"<<endl;
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                    }
                }
            }
        }
    
        if (PC_HP > En_HP)
        {
            cout<<"You win!";
        }
        else if (En_HP > PC_HP)
        {
            cout<<"You lose.";
        }
        else
        {
            cout<<"It's a tie!";
        }
    }
        if (PC_Init+4 < En_Init+3) //Enemy is first 
    {
        cout<<"[They're first!]\n";
        while (PC_HP > 0 && En_HP > 0) //This loop will continue until someone is knocked down to 0 HP or lower
        {
            cout<<"[Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
            En_Hit = (rand() % (MAXVAL20 - MINVALD + 1)) + MINVALD; //Enemy rolling to hit
            
            cout<<"[They rolled: "<<En_Hit<<" +7 is "<<En_Hit+7<<"]"<<endl;
            
            if (En_Hit+7 >= PC_AC) //If the enemy hits, this is their damage
            {
                int Dam;
                
                cout<<"[Hit!]\n";
                cout<<endl;
                cout<<"[Rolling D8 for Damage . . .]\n";
                
                En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                Dam = En_Dam + 3;
                
                cout<<"[They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n"; //Damage
                cout<<endl;
                
                PC_HP = PC_HP - Dam;
                
                cout<<"[Your opponent has "<<En_HP<<" Hit Points.]\n";
                cout<<"[You have "<<PC_HP<<" Hit Points].\n";
                cout<<endl;
                cout<<"[Press Enter]\n";
                cin.get(ch);
                if (PC_HP > 0 && En_HP > 0) //If you are not at 0 HP or lower, you attack
                {
                    cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                    cout<<"[Press Enter]\n";
                    cin.get(ch);
            
                    PC_Hit = (rand() % (MAXVAL20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                    cout<<"[You rolled: "<<PC_Hit<<" +8 is "<<PC_Hit+8<<"]\n";
                    if (PC_Hit+7 >= En_AC) //If you hit
                    {
                        int Dam;
                
                        cout<<"[Hit!]\n";
                        cout<<endl;
                        cout<<"[Rolling D8 for Damage . . .]\n";
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                
                        PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                        Dam = PC_Dam + 3;
                
                        cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                        cout<<endl;
                
                        En_HP = En_HP - Dam;
                
                        cout<<"[You have "<<PC_HP<<" Hit Points.]\n";
                        cout<<"[Your opponent has "<<En_HP<<" Hit Points].\n";
                        cout<<endl;
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                    }
                    else
                    {
                        cout<<"[Miss!]\n"<<endl;
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                    }
                }
            }
            if (En_Hit+7 < PC_AC) //If they miss
            {
                cout<<"[Miss!]\n";
                cout<<endl;
                
                if (PC_HP > 0 && En_HP > 0) //If you are not at 0 or lower hit points, you attack
                {
                    cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                    cout<<"[Press Enter]\n";
                    cin.get(ch);
            
                    PC_Hit = (rand() % (MAXVAL20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                    cout<<"[You rolled: "<<PC_Hit<<" +8 is "<<PC_Hit+8<<"]\n";
                    if (PC_Hit+8 >= En_AC) //If you hit
                    {
                        int Dam;
                
                        cout<<"[Hit!]\n";
                        cout<<endl;
                        cout<<"[Rolling D8 for Damage . . .]\n";
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                
                        PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                        Dam = PC_Dam + 3;
                
                        cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                        cout<<endl;
                
                        En_HP = En_HP - Dam;
                
                        cout<<"[You have "<<PC_HP<<" Hit Points.]\n";
                        cout<<"[Your opponent has "<<En_HP<<" Hit Points].\n";
                        cout<<endl;
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                    }
                    else
                    {
                        cout<<"[Miss!]\n"<<endl;
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
                    }
                }
            }
        }
    
        if (PC_HP > En_HP)
        {
            cout<<"You win!";
        }
        else if (En_HP > PC_HP)
        {
            cout<<"You lose.";
        }
        else
        {
            cout<<"It's a tie!";
        }
    }
    return 0;
}