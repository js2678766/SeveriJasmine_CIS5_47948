/*
 * Name: Jasmine Severi
 * Date: 12/13/2018
 * Purpose: Project 2: The Cave of Zoltan 2.0
 * A battle simulator game based on Dungeons & Dragons Edition 3.5
 */

//System Libraries
#include <iostream> //I/O Library
#include <cstdlib> //General Utilities Library, used for generating random numbers
#include <ctime> //To help with random number generation
#include <fstream> //To work with files and save the character
#include <string> //To read the name properly
#include <iomanip> //I/O Manipulator
#include <cmath> //Math library 
#include <vector> //Vector library
using namespace std; //Namespace I/O stream library

//User Libraries

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes
void exit(string, int); //Function to end the game
bool confex(char); //Function to confirm that you're quitting
int hit(int, int); //Function to display the player's roll to hit (overloading)
float hit (float); //Function to display the enemy's roll to hit (overloading)
int endam (int &, int); //Function to subtract the player's damage from the enemy's HPs. Passed by reference to work directly with the enemy's HPs
int rounds (int); //Function to keep track of the total amount of rounds the player plays. Static Variables
int stars (int = 10); //Function to display stars ** between each person's turn. Defaulted argument for the beginning of each round.

//Program Execution Begins

int main()
{
    //Declare Variables
    //Input file stream
    ifstream file; //Accepting input for the files
    //Output file stream
    ofstream f; //Displaying output from the files
    //Strings
    string file2; //File name defined by player
    string PC_Name; //To store the Player Character's ("PC's") name when Zoltan asks for their name.
    string word1, word2, word4, word5, word6, word7, word8, word9; //To hold the words for the character sheet files
    string word11, word12, word13, word14, word16, word17, word18, word19; //To hold the words for the character sheet files
    string word21, word22, word23, word24, word26, word27, word28, word29, word30; //To hold the words for the character sheet files
    string word31, word33, word34; //To hold the words for the character sheet files
    //Integers
    int SIZE = 1; //Size for the arrays
    int rows = 4, cols = 2; //Rows and Columns for the 2-Dimensional array
    int word3, word10, word15, word20, word25, word32; //Integers in the character sheet files
    int star = 7; //To send to the stars function
    int PCToHit, PCDam, InitB, x = 2; //Will be defined in the Character Creation part
    int CritTh; //Will be defined in the Character Creation part
    int PC_HP, En_HP; //To store PC's and Enemy's Hit Points (randomly generated). The Player will try to get the Enemy's HP to 0 and vice versa.
    int PC_AC, En_AC; //To store PC's and Enemy's Armor Class. The PC needs to get a number >= En_AC in order to do damage to them (knocking their HPs down).
    int PC_Init, En_Init; //To store the PC's and the Enemy's initiative, which will determine who goes first
    int PC_Hit; //To store their To Hit roll, to determine whether they hit their opponent. This number must be >= their opponent's AC to do damage
    int PC_Dam, PC_Dam2, En_Dam; //To store the PC's and the Enemy's damage rolls. This number will be subtracted from their enemy's HP.
    int Damd; //To store the PC's HP as they go down so the next battle they do they will be restored to full health
    int round = 0; //To store the number of rounds
    //Constant integers
    const int MINVALD = 1; //The smallest number the dice numbers can be
    const int MAXVA20 = 20; //The largest number for the die 20 (D20)
    const int MAXVA12 = 12; //D12
    const int MAXVAL8 = 8; //D8
    const int MAXVAL6 = 6; //D6
    //Characters
    char choice; //To store the Player's choice of opponent
    char Conf; //To confirm they wish to quit
    char ch; //To have them press enter
    char Choose; //To store the Character Creation choice
    char InAn; //Improved Initiative
    //Floats
    float En_Hit;
    float DND = 3.5;
    //Boolean
    bool lorn; //To load or create a character
    //Unsigned integer - seeding the random number generators
    unsigned seed = time(0);
    srand(seed);
    
    //Arrays
    //1 Dimensional integer arrays
    int pass[SIZE]; //Password Array
    int Pass[SIZE]; //To test the password
    //2 Dimensional string array
    string enemy[rows][cols]; //To display the enemy's character sheet in a table format
    
    cout<<"[Welcome to the Dungeons & Dragons "<<setprecision(2)<<DND<<" Battle Simulator!\n";
    cout<<"Type 0 to load a saved character.\n";
    cout<<"Type 1 to create a new character.\n";
    cout<<"Choose: ";
    cin>>lorn;
    cout<<endl;
    
    if (lorn == 1)
    {
        //Character Creation
        cout<<"[Character Creation:\n"; 
        cout<<"This is where you choose what kind of character you want.\n";
        cout<<endl;
        cout<<"Paladin: For this game, a Paladin will focus on Strength.\n";
        cout<<"Having a character who focuses on Strength will give you better attack and damage bonuses,\n";
        cout<<"making it easier to hit your enemy and increasing the amount of damage you cause them.\n";
        cout<<"You also get a +2 magic weapon which adds an additional +2 to your attack and damage bonuses.\n";
        cout<<endl;
        cout<<"Ranger: A Ranger focuses on Dexterity.\n";
        cout<<"Having a character who focuses on Dexterity will give you a better Armor Class which will make it harder for the enemy to hit you,\n";
        cout<<"and gives you a better initiative bonus, which makes it more likely for you to go first.\n";
        cout<<"You also have the option of having the Improved Initiative feat which gives you an additional +4 to your initiative.\n";
        cout<<endl;
        cout<<"Fighter: For this game, a Fighter will focus on Constitution.\n"; 
        cout<<"Having a character who focuses on Constitution gives you more Hit Points.\n";
        cout<<"You also get the Improved Critical feat which increases your Critical Hit threat range from 19-20 to 17-20.\n"; 
        cout<<"Successful Critical Hits double your damage.\n";
        cout<<endl;
        cout<<"--> Type 1 if you want to play a Paladin.\n";
        cout<<"--> Type 2 if you want to play a Ranger.\n";
        cout<<"--> Type 3 if you want to play a Fighter.\n";
        cout<<"Choose your character: ";
        cin>>Choose;
        cout<<endl;
    
        if (Choose == '1')
        {
            int MINPCHP = 20; //The minimum amount of HP the PC can have
            int MAXPCHP = 35; //The maximum amount of HP the PC can have
            int MINPCAC = 18; //The minimum amount of AC the PC can have
            int MAXPCAC = 23; //The maximum amount of AC the PC can have
            PCToHit = 9; //PC focuses on strength, so they have a better to hit
            PCDam = pow(x, 2); //PC focuses on strength, so they do more damage
            InitB = 3; //Initiative bonus
            CritTh = 19; //Critical Hit threat range is 19-20, x2 damage if critical
        
            static_cast<float>(PC_Dam);
            
            //When either the Enemy's or the PC's HPs are knocked down to 0, the game is over. Whoever knocked the other down to 0 or lower wins.
            PC_HP = (rand() % (MAXPCHP - MINPCHP + 1)) + MINPCHP; //Generating the random number for the PC's HP
            PC_AC = (rand() % (MAXPCAC - MINPCAC + 1)) + MINPCAC; //Generating the random number for the PC's AC
        }
        else if (Choose == '2')
        {
            cout<<"Would you like the Improved Initiative feat? Y/N: ";
            cin>>InAn;
            cout<<endl;
            
            InAn == 'Y' || 'y' ? InitB = 8 : InitB = 4;
            
            int MINPCHP = 20; //The minimum amount of HP the PC can have
            int MAXPCHP = 35; //The maximum amount of HP the PC can have
            int MINPCAC = 20; //The minimum amount of AC the PC can have, PC focuses on Dexterity, so they have a better AC
            int MAXPCAC = 26; //The maximum amount of AC the PC can have, PC focuses on Dexterity, so they have a better AC
            PCToHit = 7; //Attack Bonus
            PCDam = 3; //Damage
            CritTh = 19; //Critical Hit threat range is 19-20
        
            //When either the Enemy's or the PC's HPs are knocked down to 0, the game is over. Whoever knocked the other down to 0 or lower wins.
            PC_HP = (rand() % (MAXPCHP - MINPCHP + 1)) + MINPCHP; //Generating the random number for the PC's HP
            PC_AC = (rand() % (MAXPCAC - MINPCAC + 1)) + MINPCAC; //Generating the random number for the PC's AC
            }
        else if (Choose == '3')
        {
            int MINPCHP = 28; //The minimum amount of HP the PC can have, PC focuses on Constitution, so they have more HPs
            int MAXPCHP = 40; //The maximum amount of HP the PC can have, PC focuses on Constitution, so they have more HPs
            int MINPCAC = 18; //The minimum amount of AC the PC can have
            int MAXPCAC = 23; //The maximum amount of AC the PC can have
            PCToHit = 7; //Attack Bonus
            PCDam = 3; //Damage
            InitB = 3; //Initiative bonus
            CritTh = 17; //Critical Hit threat range is 17-20, they have Improved Critical
        
            //When either the Enemy's or the PC's HPs are knocked down to 0, the game is over. Whoever knocked the other down to 0 or lower wins.
            PC_HP = (rand() % (MAXPCHP - MINPCHP + 1)) + MINPCHP; //Generating the random number for the PC's HP
            PC_AC = (rand() % (MAXPCAC - MINPCAC + 1)) + MINPCAC; //Generating the random number for the PC's AC
        }
  
        //Saving the character's information
        cout<<"Please enter a one word file name to save your character: ";
        cin>>file2;
        
        cout<<"Please create a password: ";
        for(int i = 0; i < SIZE; i++)
        {
            cin>>pass[i];
        }

        f.open(file2.c_str());
        f<<"You have "<<PC_HP<<" Hit Points\n"; //Displaying the PC's HPs
        f<<"Your Armor Class is "<<PC_AC<<endl; //Displaying PC's AC
        f<<"Your attack bonus is +"<<PCToHit<<endl;
        f<<"Your damage bonus is +"<<PCDam<<endl;
        f<<"Your initiative bonus is +"<<InitB<<endl;
        f<<"Your Critical Hit threat range is "<<CritTh<<"- 20.]\n";
        f<<pass[0];
        f<<endl;
        f.close();
        
        cout<<"Type a file name to load your character: ";
        cin>>file2;
        cout<<endl;
        
        file.open(file2.c_str());
        file>>word1>>word2>>word3>>word4>>word5;
        file>>word6>>word7>>word8>>word9>>word10;
        file>>word11>>word12>>word13>>word14>>word15;
        file>>word16>>word17>>word18>>word19>>word20;
        file>>word21>>word22>>word23>>word24>>word25;
        file>>word26>>word27>>word28>>word29>>word30;
        file>>word31>>word32>>word33>>word34;
        
        cout<<word1<<" "<<word2<<" "<<word3<<" "<<word4<<" "<<word5<<endl;
        cout<<word6<<" "<<word7<<" "<<word8<<" "<<word9<<" "<<word10<<endl;
        cout<<word11<<" "<<word12<<" "<<word13<<" "<<word14<<" "<<word15<<endl;
        cout<<word16<<" "<<word17<<" "<<word18<<" "<<word19<<" "<<word20<<endl;
        cout<<word21<<" "<<word22<<" "<<word23<<" "<<word24<<" "<<word25<<endl;
        cout<<word26<<" "<<word27<<" "<<word28<<" "<<word29<<" "<<word30<<" ";
        cout<<word31<<" "<<word32<<word33<<word34<<endl;
    }
    if (lorn == 0)
    {
        cout<<"Type a file name to load your character: ";
        cin>>file2;
        
        file.open(file2.c_str());
        file>>word1>>word2>>word3>>word4>>word5;
        file>>word6>>word7>>word8>>word9>>word10;
        file>>word11>>word12>>word13>>word14>>word15;
        file>>word16>>word17>>word18>>word19>>word20;
        file>>word21>>word22>>word23>>word24>>word25;
        file>>word26>>word27>>word28>>word29>>word30;
        file>>word31>>word32>>word33>>word34;
        file>>pass[0];
        
        cout<<"Please enter your password: ";
        for(int i = 0; i < SIZE; i++)
        {
            cin>>Pass[i];
        }
        
        if(Pass[0] == pass[0])
        {
            cout<<word1<<" "<<word2<<" "<<word3<<" "<<word4<<" "<<word5<<endl;
            cout<<word6<<" "<<word7<<" "<<word8<<" "<<word9<<" "<<word10<<endl;
            cout<<word11<<" "<<word12<<" "<<word13<<" "<<word14<<" "<<word15<<endl;
            cout<<word16<<" "<<word17<<" "<<word18<<" "<<word19<<" "<<word20<<endl;
            cout<<word21<<" "<<word22<<" "<<word23<<" "<<word24<<" "<<word25<<endl;
            cout<<word26<<" "<<word27<<" "<<word28<<" "<<word29<<" "<<word30<<" ";
            cout<<word31<<" "<<word32<<word33<<word34<<endl;
        
            PC_HP = word3;
            PC_AC = word10;
            PCToHit = word15;
            PCDam = word20;
            InitB = word25;
            CritTh = word32;
        }
        else
        {
            cout<<"Incorrect password.\n";
            cout<<"Please enter your password: ";
            for(int i = 0; i < SIZE; i++)
            {
                cin>>Pass[i];
            }
            if(Pass[0] == pass[0])
            {
                cout<<word1<<" "<<word2<<" "<<word3<<" "<<word4<<" "<<word5<<endl;
                cout<<word6<<" "<<word7<<" "<<word8<<" "<<word9<<" "<<word10<<endl;
                cout<<word11<<" "<<word12<<" "<<word13<<" "<<word14<<" "<<word15<<endl;
                cout<<word16<<" "<<word17<<" "<<word18<<" "<<word19<<" "<<word20<<endl;
                cout<<word21<<" "<<word22<<" "<<word23<<" "<<word24<<" "<<word25<<endl;
                cout<<word26<<" "<<word27<<" "<<word28<<" "<<word29<<" "<<word30<<" ";
                cout<<word31<<" "<<word32<<word33<<word34<<endl;
        
                PC_HP = word3;
                PC_AC = word10;
                PCToHit = word15;
                PCDam = word20;
                InitB = word25;
                CritTh = word32;
            }
            else
            {
                cout<<"Incorrect password.";
                return 0;
            }   
        }
    }
    
    Damd = PC_HP;
    
    cout<<"\n[Now entering the Cave of Zoltan.]\n";
    cout<<"[Press Enter]\n";
    cin.get(ch);
    
    cout<<"\nGreetings, Mortal. I am\n";
    cout<<endl;
    cout<<"ZZZZZZ     OOOOO       L       TTTTTTTTT       A                 N          N\n";
    cout<<"    Z     O     O      L           T          A A               N N        N\n";
    cout<<"   Z      O     O      L           T         A   A             N  N       N\n";
    cout<<"  Z       O     O      L           T        A     A           N    N     N\n";
    cout<<" Z        O     O      L           T       AAAAAAAAA         N      N   N\n";
    cout<<"Z         O     O      L           T      A         A       N        N N\n";
    cout<<"ZZZZZZ     OOOOO       LLLLLLL     T     A           A     N          N\n";   
    cout<<endl;
    
    cout<<"Who dares enter my dungeon?\n";
    cout<<"Halt, and state your name.\n";
    cout<<"[Enter your character's name]: ";
    getline(cin, PC_Name);
    cout<<endl;
    
    cout<<PC_Name<<", is it?\n"; 
    cout<<"Well, you have caught me in a charitable mood, "<<PC_Name<<", so I will allow you to choose your executioner.\n";
    cout<<"If you defeat my guard in combat, I may let you go free.\n";
    cout<<endl;
    
    do
    {
        //Menu: Difficulty settings and quit, choosing your opponent
        cout<<"Choose your opponent: "<<endl;
        cout<<"1 -> A Kobold (Easy)"<<endl;
        cout<<"2 -> An Orc (Medium)"<<endl;
        cout<<"3 -> A Drow (Hard)"<<endl;
        cout<<"4 -> I am done (Quit)"<<endl;
        cout<<"[Choose 1 for Easy, 2 for Medium, 3 for Hard, or 4 to Quit]: ";
        cin>>choice;
        cout<<endl;
    
        switch(choice)
        {
            case '1':
            {
                int MINENHP = 17; //The minimum amount of HP the Enemy can have
                int MAXENHP = 27; //The maximum amount of HP the Enemy can have
                int MINENAC = 17; //The minimum amount of AC the Enemy can have
                int MAXENAC = 22; //The maximum amount of AC the Enemy can have
                
                En_HP = (rand() % (MAXENHP - MINENHP + 1)) + MINENHP; //Generating the random number for the Enemy's HPs
                En_AC = (rand() % (MAXENAC - MINENAC + 1)) + MINENAC; //Generating the random number for the Enemy's AC
                
                enemy[0][0] = "Attack: ";
                enemy[0][1] = "+5";
                enemy[1][0] = "Damage: ";
                enemy[1][1] = "+3";
                enemy[2][0] = "Init: ";
                enemy[2][1] = "+3";
                enemy[3][0] = "Crit: ";
                enemy[3][1] = "20, x 2";
                
                cout<<"Enemy's Information:\n";
                cout<<setw(10)<<"HP: "<<setw(10)<<En_HP<<endl;
                cout<<setw(10)<<"AC: "<<setw(10)<<En_AC<<endl;
                for (int r = 0; r < rows; r++)
                {
                    for (int c = 0; c < cols; c++)
                    {
                        cout<<setw(10)<<enemy[r][c];
                    }
                    cout<<endl;
                }
                cout<<endl;
                
                //Initiative determines the order of actions, who goes first.
                PC_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the PC's initiative
                En_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the Enemy's initiative
    
                cout<<"[Rolling for Initiative.]\n";
                cout<<"[Press Enter]\n";
                cin.get(ch);
                
                cout<<"\n[Your initiative roll is: "<<PC_Init<<" (+"<<InitB<<" bonus) = "<<PC_Init+InitB<<"]"<<endl;
                cout<<"[Your opponent's initiative roll is: "<<En_Init<<" (+3 bonus) = "<<En_Init+3<<"]"<<endl;
                cout<<endl;
    
                if (PC_Init+InitB == En_Init+3) //If it's a tie, roll again
                {
                    cout<<"[It's a tie!]\n"; 
                    cout<<"[Re-rolling initiative . . .]\n";
                    cout<<"[Press Enter]\n";
                    cin.get(ch);
                    PC_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the PC's initiative
                    En_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the Enemy's initiative
        
                    cout<<"[Your initiative roll is: "<<PC_Init<<" (+"<<InitB<<" bonus) = "<<PC_Init+InitB<<"]"<<endl;
                    cout<<"[Your opponent's initiative roll is: "<<En_Init<<" (+3 bonus) = "<<En_Init+3<<"]"<<endl;
                    cout<<endl;
                }
                if (PC_Init+InitB > En_Init+3) //Player is first 
                {
                    cout<<"[You're first!]\n";
                    for (int count = 3; count > 0; count--)
                    {
                        cout<<count<<endl;
                        cout<<"...\n";
                    }
                    cout<<"Go!\n";
                    while (Damd > 0 && En_HP > 0) //This loop will continue until someone is knocked down to 0 HP or lower
                    {
                        round = rounds(round);
                        
                        stars();
                        
                        cout<<"\n[Your turn!]\n";
                        cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
            
                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                        int hitt = hit(PC_Hit, PCToHit);
            
                        if (hitt >= En_AC) //If the player hits, generate and calculate the player's damage
                        {
                            int Dam;
                
                            cout<<"[You hit!]\n";
                            cout<<endl;
                            if (PC_Hit >= CritTh)
                            {
                                cout<<"[Possible Critical!]\n";
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                                cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                if (PC_Hit+PCToHit >= En_AC)
                                {
                                    cout<<"[Critical Hit!]\n";
                                    cout<<"[Rolling D6 for Damage . . .]\n";
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                
                                    PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                    Dam = (PC_Dam + PCDam) * 2;
                
                                    cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                    cout<<endl;
                
                                    endam(En_HP, Dam);
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                                else
                                {
                                    cout<<"[Not a Critical Hit.]\n";
                                    
                                    cout<<"[Rolling D6 for Damage . . .]\n";
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                
                                    PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                    Dam = PC_Dam + PCDam;
                
                                    cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                    cout<<endl;
                
                                    En_HP = En_HP - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                            else
                            {
                                cout<<"[Rolling D6 for Damage . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                
                                PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                Dam = PC_Dam + PCDam;
                
                                cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                cout<<endl;
                
                                En_HP = En_HP - Dam;
                
                                cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                cout<<endl;
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                            }
                            if (Damd > 0 && En_HP > 0) //If the Enemy is not at 0 or lower hit points, they attack
                            {
                                stars(star);
                                        
                                cout<<"\n                              [Enemy's turn!]\n";
                                cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                float enhit = hit(En_Hit);
                                
                                if (enhit+5 >= PC_AC) //If the enemy hits
                                {
                                    int Dam;
                
                                    cout<<"                              [They hit!]\n";
                                    cout<<endl;
                                        
                                    if (En_Hit == 20)
                                    {
                                        cout<<"                              [Possible Critical!]\n";
                                        En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"                              [They rolled: "<<En_Hit<<" (+5 bonus) = "<<En_Hit+5<<"]"<<endl;
                                        if (En_Hit+5 >= PC_AC)
                                        {
                                            cout<<"                              [Critical Hit!]\n";
                                            cout<<"                              [Rolling D6 for Damage . . .]\n";

                                            En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = (En_Dam + 3) * 2;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+3 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"                              [Not a Critical Hit.]\n";
                                    
                                            cout<<"                              [Rolling D6 for Damage . . .]\n";
                
                                            En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Rolling damage
                                            Dam = En_Dam + 3;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        cout<<"                              [Rolling D6 for Damage . . .]\n";
                
                                        En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = En_Dam + 3;
                
                                        cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        Damd = Damd - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"                              [They missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }   
                            }
                        }
                        if (PC_Hit+PCToHit < En_AC && Damd > 0 && En_HP > 0) //If the player misses
                        {
                            cout<<"[You missed!]\n";
                            cout<<endl;
                            if (Damd > 0 && En_HP > 0)   
                            {
                                stars(star);
                                
                                cout<<"\n                              [Enemy's turn!]\n";
                                cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"                              [They rolled: "<<En_Hit<<" (+5 bonus) = "<<En_Hit+5<<"]\n";
                                if (En_Hit+5 >= PC_AC) //If the enemy hits
                                {
                                    int Dam;
                
                                    cout<<"                              [They hit!]\n";
                                    cout<<endl;
                                        
                                    if (En_Hit == 20)
                                    {
                                        cout<<"                              [Possible Critical!]\n";
                                        En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"                              [They rolled: "<<En_Hit<<" (+5 bonus) = "<<En_Hit+5<<"]"<<endl;
                                        if (En_Hit+5 >= PC_AC)
                                        {
                                            cout<<"                              [Critical Hit!]\n";
                                            cout<<"                              [Rolling D6 for Damage . . .]\n";

                                            En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = (En_Dam + 3) * 2;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+3 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"                              [Not a Critical Hit.]\n";
                                    
                                            cout<<"                              [Rolling D6 for Damage . . .]\n";
                
                                            En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Rolling damage
                                            Dam = En_Dam + 3;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        
                                        cout<<"                              [Rolling D6 for Damage . . .]\n";
                
                                        En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = En_Dam + 3;
                
                                        cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        Damd = Damd - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"                              [They missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                    }
    
                    if (Damd > En_HP)
                    {
                        cout<<"[You are victorious!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else if (En_HP > Damd)
                    {
                        cout<<"[You have been defeated.]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else
                    {
                        cout<<"[It's a tie!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                }
                if (PC_Init+InitB < En_Init+3) //Enemy is first 
                {   
                    cout<<"                              [They're first!]\n";
                    for (int count = 3; count > 0; count--)
                    {
                        cout<<count<<endl;
                        cout<<"...\n";
                    }
                    cout<<"Go!\n";
                    while (Damd > 0 && En_HP > 0) //This loop will continue until someone is knocked down to 0 HP or lower
                    {
                        round = rounds(round);
                        
                        stars();
                        
                        cout<<"\n                              [Enemy's turn!]\n";
                        cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                        En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Enemy rolling to hit
            
                        cout<<"                              [They rolled: "<<En_Hit<<" (+5 bonus) = "<<En_Hit+5<<"]"<<endl;
            
                        if (En_Hit+5 >= PC_AC) //If the enemy hits, this is their damage
                        {
                            int Dam;
                
                            cout<<"                              [They hit!]\n";
                            cout<<endl;
                            if (En_Hit == 20)
                            {
                                cout<<"                              [Possible Critical!]\n";
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                cout<<"                              [They rolled: "<<En_Hit<<" (+5 bonus) = "<<En_Hit+5<<"]"<<endl;
                                if (En_Hit+5 >= PC_AC)
                                {
                                    cout<<"                              [Critical Hit!]\n";
                                    cout<<"                              [Rolling D6 for Damage . . .]\n";

                                    En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                    Dam = (En_Dam + 3) * 2;
                
                                    cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+3 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                    cout<<endl;
                
                                    Damd = Damd - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                                else
                                {
                                    cout<<"                              [Not a Critical Hit.]\n";
                                    
                                    cout<<"                              [Rolling D6 for Damage . . .]\n";
                
                                    En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Rolling damage
                                    Dam = En_Dam + 3;
                
                                    cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                    cout<<endl;
                
                                    Damd = Damd - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                            else
                            {
                                cout<<"                              [Rolling D6 for Damage . . .]\n";
                
                                En_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                Dam = En_Dam + 3;
                
                                cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+3 bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                cout<<endl;
                
                                Damd = Damd - Dam;
                
                                cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                cout<<endl;
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                            }
                            if (Damd > 0 && En_HP > 0) //If you are not at 0 HP or lower, you attack
                            {
                                stars(star);
                                
                                cout<<"\n[Your turn!]\n";
                                cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
            
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]\n";
                                if (PC_Hit+PCToHit >= En_AC) //If you hit
                                {
                                    int Dam;
                
                                    cout<<"[You hit!]\n";
                                    cout<<endl;
                                    if (PC_Hit >= CritTh)
                                    {
                                        cout<<"[Possible Critical!]\n";
                                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                        cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                        if (PC_Hit+PCToHit >= En_AC)
                                        {
                                            cout<<"[Critical Hit!]\n";
                                            cout<<"[Rolling D6 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = (PC_Dam + PCDam) * 2;
                
                                            cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"[Not a Critical Hit.]\n";
                                    
                                            cout<<"[Rolling D6 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = PC_Dam + PCDam;
                
                                            cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        cout<<"[Rolling D6 for Damage . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                
                                        PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = PC_Dam + PCDam;
                
                                        cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        En_HP = En_HP - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"[You missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                        if (En_Hit+7 < PC_AC) //If they miss
                        {
                            cout<<"                              [They missed!]\n";
                            cout<<endl;
                
                            if (PC_HP > 0 && En_HP > 0) //If you are not at 0 or lower hit points, you attack
                            {
                                stars(star);
                                
                                cout<<"\n[Your turn!]\n";
                                cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
            
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"[You rolled: "<<PC_Hit<<" +"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]\n";
                                if (PC_Hit+PCToHit >= En_AC) //If you hit
                                {
                                    int Dam;
                
                                    cout<<"[You hit!]\n";
                                    cout<<endl;
                                    if (PC_Hit >= CritTh)
                                    {
                                        cout<<"[Possible Critical!]\n";
                                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                        cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                        if (PC_Hit+PCToHit >= En_AC)
                                        {
                                            cout<<"[Critical Hit!]\n";
                                            cout<<"[Rolling D6 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = (PC_Dam + PCDam) * 2;
                
                                            cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"[Not a Critical Hit.]\n";
                                    
                                            cout<<"[Rolling D6 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = PC_Dam + PCDam;
                
                                            cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        cout<<"[Rolling D6 for Damage . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                
                                        PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = PC_Dam + PCDam;
                
                                        cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" +"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        En_HP = En_HP - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"[You missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                    }
                    if (Damd > En_HP)
                    {
                        cout<<"[You are victorious!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else if (En_HP > Damd)
                    {
                        cout<<"[You have been defeated.]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else
                    {
                        cout<<"[It's a tie!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                }
            }
                break;
            case '2':
            {
                int MINENHP = 20; //The minimum amount of HP the Enemy can have
                int MAXENHP = 30; //The maximum amount of HP the Enemy can have
                int MINENAC = 19; //The minimum amount of AC the Enemy can have
                int MAXENAC = 24; //The maximum amount of AC the Enemy can have
                
                En_HP = (rand() % (MAXENHP - MINENHP + 1)) + MINENHP; //Generating the random number for the Enemy's HPs
                En_AC = (rand() % (MAXENAC - MINENAC + 1)) + MINENAC; //Generating the random number for the Enemy's AC
                
                enemy[0][0] = "Attack: ";
                enemy[0][1] = "+5";
                enemy[1][0] = "Damage: ";
                enemy[1][1] = "+3";
                enemy[2][0] = "Init: ";
                enemy[2][1] = "+3";
                enemy[3][0] = "Crit: ";
                enemy[3][1] = "20, x 2";
                
                cout<<"Enemy's Information:\n";
                cout<<setw(10)<<"HP: "<<setw(10)<<En_HP<<endl;
                cout<<setw(10)<<"AC: "<<setw(10)<<En_AC<<endl;
                for (int r = 0; r < rows; r++)
                {
                    for (int c = 0; c < cols; c++)
                    {
                        cout<<setw(10)<<enemy[r][c];
                    }
                    cout<<endl;
                }
                cout<<endl;
                
                //Initiative determines the order of actions, who goes first.
                PC_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the PC's initiative
                En_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the Enemy's initiative
    
                cout<<"[Press Enter to roll for initiative]\n";
                cin.get(ch);
                
                cout<<"\n[Your initiative roll is: "<<PC_Init<<" (+"<<InitB<<" bonus) = "<<PC_Init+InitB<<"]"<<endl;
                cout<<"[Your opponent's initiative roll is: "<<En_Init<<" (+3 bonus) = "<<En_Init+3<<"]"<<endl;
                cout<<endl;
    
                if (PC_Init+InitB == En_Init+3) //If it's a tie, roll again
                {
                    cout<<"[It's a tie!]\n"; 
                    cout<<"[Re-rolling initiative . . .]\n";
                    cout<<"[Press Enter]\n";
                    cin.get(ch);
                    PC_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the PC's initiative
                    En_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the Enemy's initiative
        
                    cout<<"[Your initiative roll is: "<<PC_Init<<" (+"<<InitB<<" bonus) = "<<PC_Init+InitB<<"]"<<endl;
                    cout<<"[Your opponent's initiative roll is: "<<En_Init<<" (+3 bonus) = "<<En_Init+3<<"]"<<endl;
                    cout<<endl;
                }
                if (PC_Init+InitB > En_Init+3) //Player is first 
                {
                    cout<<"[You're first!]\n";
                    for (int count = 3; count > 0; count--)
                    {
                        cout<<count<<endl;
                        cout<<"...\n";
                    }
                    cout<<"Go!\n";
                    while (Damd > 0 && En_HP > 0) //This loop will continue until someone is knocked down to 0 HP or lower
                    {
                        round = rounds(round);
                        
                        stars();
                        
                        cout<<"\n[Your turn!]\n";
                        cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
            
                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                        cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
            
                        if (PC_Hit+PCToHit >= En_AC) //If the player hits, generate and calculate the player's damage
                        {
                            int Dam;
                
                            cout<<"[You hit!]\n";
                            cout<<endl;
                            if (PC_Hit >= CritTh)
                            {
                                cout<<"[Possible Critical!]\n";
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                                cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                if (PC_Hit+PCToHit >= En_AC)
                                {
                                    cout<<"[Critical Hit!]\n";
                                    cout<<"[Rolling D8 for Damage . . .]\n";
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                
                                    PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                    Dam = (PC_Dam + PCDam) * 2;
                
                                    cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                    cout<<endl;
                
                                    En_HP = En_HP - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                                else
                                {
                                    cout<<"[Not a Critical Hit.]\n";
                                    
                                    cout<<"[Rolling D8 for Damage . . .]\n";
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                
                                    PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                    Dam = PC_Dam + PCDam;
                
                                    cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                    cout<<endl;
                
                                    En_HP = En_HP - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                            else
                            {
                                cout<<"[Rolling D8 for Damage . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                
                                PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                Dam = PC_Dam + PCDam;
                
                                cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                cout<<endl;
                
                                En_HP = En_HP - Dam;
                
                                cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                cout<<endl;
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                            }
                            if (Damd > 0 && En_HP > 0) //If the Enemy is not at 0 or lower hit points, they attack
                            {
                                stars(star);
                                
                                cout<<"\n                              [Enemy's turn!]\n";
                                cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"                              [They rolled: "<<En_Hit<<" (+7 bonus) = "<<En_Hit+7<<"]\n";
                                if (En_Hit+7 >= PC_AC) //If the enemy hits
                                {
                                    int Dam;
                
                                    cout<<"                              [They hit!]\n";
                                    cout<<endl;
                                        
                                    if (En_Hit >= 19)
                                    {
                                        cout<<"                              [Possible Critical!]\n";
                                        En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"                              [They rolled: "<<En_Hit<<" (+7 bonus) = "<<En_Hit+7<<"]"<<endl;
                                        if (En_Hit+7 >= PC_AC)
                                        {
                                            cout<<"                              [Critical Hit!]\n";
                                            cout<<"                              [Rolling D8 for Damage . . .]\n";

                                            En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                            Dam = (En_Dam + 3) * 2;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+3 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"                              [Not a Critical Hit.]\n";
                                    
                                            cout<<"                              [Rolling D8 for Damage . . .]\n";
                
                                            En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                                            Dam = En_Dam + 3;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        
                                        cout<<"                              [Rolling D8 for Damage . . .]\n";
                
                                        En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = En_Dam + 3;
                
                                        cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        Damd = Damd - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"                              [They missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                        if (PC_Hit+PCToHit < En_AC && Damd > 0 && En_HP > 0) //If the player misses
                        {
                            cout<<"[You missed!]\n";
                            cout<<endl;
                            if (Damd > 0 && En_HP > 0)   
                            {
                                stars(star);
                                
                                cout<<"\n                              [Enemy's turn!]\n";
                                cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"                              [They rolled: "<<En_Hit<<" (+7 bonus) = "<<En_Hit+7<<"]\n";
                                    if (En_Hit+7 >= PC_AC) //If the enemy hits
                                    {
                                        int Dam;
                
                                        cout<<"                              [They hit!]\n";
                                        cout<<endl;
                                        
                                        if (En_Hit >= 19)
                                        {
                                            cout<<"                              [Possible Critical!]\n";
                                            En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                            cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                            cout<<"                              [They rolled: "<<En_Hit<<" (+7 bonus) = "<<En_Hit+7<<"]"<<endl;
                                            if (En_Hit+7 >= PC_AC)
                                            {
                                                cout<<"                              [Critical Hit!]\n";
                                                cout<<"                              [Rolling D8 for Damage . . .]\n";

                                                En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                                Dam = (En_Dam + 3) * 2;
                
                                                cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+3 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                                cout<<endl;
                
                                                Damd = Damd - Dam;
                
                                                cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                                cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                                cout<<endl;
                                                cout<<"[Press Enter]\n";
                                                cin.get(ch);
                                            }
                                            else
                                            {
                                                cout<<"                              [Not a Critical Hit.]\n";
                                    
                                                cout<<"                              [Rolling D8 for Damage . . .]\n";
                
                                                En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                                                Dam = En_Dam + 3;
                
                                                cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                                cout<<endl;
                
                                                Damd = Damd - Dam;
                
                                                cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                                cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                                cout<<endl;
                                                cout<<"[Press Enter]\n";
                                                cin.get(ch);
                                            }
                                        }
                                        else
                                        {
                                        
                                            cout<<"                              [Rolling D8 for Damage . . .]\n";
                
                                            En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                                            Dam = En_Dam + 3;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                else
                                {
                                    cout<<"                              [They missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                    }
                    if (Damd > En_HP)
                    {
                        cout<<"[You are victorious]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else if (En_HP > Damd)
                    {
                        cout<<"[You have been defeated.]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else
                    {
                        cout<<"[It's a tie!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                }
                if (PC_Init+InitB < En_Init+3) //Enemy is first 
                {
                    stars();
                    
                    cout<<"\n                              [They're first!]\n";
                    for (int count = 3; count > 0; count--)
                    {
                        cout<<count<<endl;
                        cout<<"...\n";
                    }
                    cout<<"Go!\n";
                    while (Damd > 0 && En_HP > 0) //This loop will continue until someone is knocked down to 0 HP or lower
                    {
                        round = rounds(round);
                        
                        stars();
                        
                        cout<<"\n                              [Enemy's turn!]\n";
                        cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                        En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Enemy rolling to hit
            
                        cout<<"                              [They rolled: "<<En_Hit<<" (+7 bonus) = "<<En_Hit+7<<"]"<<endl;
            
                        if (En_Hit+7 >= PC_AC) //If the enemy hits, this is their damage
                        {
                            int Dam;
                
                            cout<<"                              [They hit!]\n";
                            cout<<endl;
                            if (En_Hit >= 19)
                            {
                                cout<<"                              [Possible Critical!]\n";
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                cout<<"                              [They rolled: "<<En_Hit<<" (+7 bonus) = "<<En_Hit+7<<"]"<<endl;
                                if (En_Hit+7 >= PC_AC)
                                {
                                    cout<<"                              [Critical Hit!]\n";
                                    cout<<"                              [Rolling D8 for Damage . . .]\n";

                                    En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                    Dam = (En_Dam + 3) * 2;
                
                                    cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+3 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                    cout<<endl;
                
                                    Damd = Damd - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                                else
                                {
                                    cout<<"                              [Not a Critical Hit.]\n";
                                    
                                    cout<<"                              [Rolling D8 for Damage . . .]\n";
                
                                    En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                                    Dam = En_Dam + 3;
                
                                    cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                    cout<<endl;
                
                                    Damd = Damd - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                            else
                            {
                                cout<<"                              [Rolling D8 for Damage . . .]\n";
                
                                En_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                Dam = En_Dam + 3;
                
                                cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+3 bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                cout<<endl;
                
                                Damd = Damd - Dam;
                
                                cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                cout<<endl;
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                            }
                            if (Damd > 0 && En_HP > 0) //If you are not at 0 HP or lower, you attack
                            {
                                stars(star);
                                
                                cout<<"\n[Your turn!]\n";
                                cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
            
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]\n";
                                if (PC_Hit+PCToHit >= En_AC) //If you hit
                                {
                                    int Dam;
                
                                    cout<<"[You hit!]\n";
                                    cout<<endl;
                                    if (PC_Hit >= CritTh)
                                    {
                                        cout<<"[Possible Critical!]\n";
                                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                        cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                        if (PC_Hit+PCToHit >= En_AC)
                                        {
                                            cout<<"[Critical Hit!]\n";
                                            cout<<"[Rolling D8 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                            Dam = (PC_Dam + PCDam) * 2;
                
                                            cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"[Not a Critical Hit.]\n";
                                    
                                            cout<<"[Rolling D8 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                            Dam = PC_Dam + PCDam;
                
                                            cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        cout<<"[Rolling D8 for Damage . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                
                                        PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = PC_Dam + PCDam;
                
                                        cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        En_HP = En_HP - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"[You missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                        if (En_Hit+7 < PC_AC) //If they miss
                        {
                            cout<<"                              [They missed!]\n";
                            cout<<endl;
                
                            if (PC_HP > 0 && En_HP > 0) //If you are not at 0 or lower hit points, you attack
                            {
                                stars(star);
                                
                                cout<<"\n[Your turn!]\n";
                                cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
            
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"[You rolled: "<<PC_Hit<<" +"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]\n";
                                if (PC_Hit+PCToHit >= En_AC) //If you hit
                                {
                                    int Dam;
                
                                    cout<<"[You hit!]\n";
                                    cout<<endl;
                                    if (PC_Hit >= CritTh)
                                    {
                                        cout<<"[Possible Critical!]\n";
                                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                        cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                        if (PC_Hit+PCToHit >= En_AC)
                                        {
                                            cout<<"[Critical Hit!]\n";
                                            cout<<"[Rolling D8 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                            Dam = (PC_Dam + PCDam) * 2;
                
                                            cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"[Not a Critical Hit.]\n";
                                    
                                            cout<<"[Rolling D8 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD;
                                            Dam = PC_Dam + PCDam;
                
                                            cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        cout<<"[Rolling D8 for Damage . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                
                                        PC_Dam = (rand() % (MAXVAL8 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = PC_Dam + PCDam;
                
                                        cout<<"[You rolled "<<PC_Dam<<". "<<PC_Dam<<" +"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        En_HP = En_HP - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"[You missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                    }
                    if (Damd > En_HP)
                    {
                        cout<<"[You are victorious!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else if (En_HP > Damd)
                    {
                        cout<<"[You have been defeated.]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else
                    {
                        cout<<"[It's a tie!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                }
            }
                break;
            case '3':
            {
                int MINENHP = 25; //The minimum amount of HP the Enemy can have
                int MAXENHP = 35; //The maximum amount of HP the Enemy can have
                int MINENAC = 20; //The minimum amount of AC the Enemy can have
                int MAXENAC = 27; //The maximum amount of AC the Enemy can have
                
                En_HP = (rand() % (MAXENHP - MINENHP + 1)) + MINENHP; //Generating the random number for the Enemy's HPs
                En_AC = (rand() % (MAXENAC - MINENAC + 1)) + MINENAC; //Generating the random number for the Enemy's AC
                
                enemy[0][0] = "Attack: ";
                enemy[0][1] = "+5";
                enemy[1][0] = "Damage: ";
                enemy[1][1] = "+3";
                enemy[2][0] = "Init: ";
                enemy[2][1] = "+3";
                enemy[3][0] = "Crit: ";
                enemy[3][1] = "20, x 2";
                
                cout<<"Enemy's Information:\n";
                cout<<setw(10)<<"HP: "<<setw(10)<<En_HP<<endl;
                cout<<setw(10)<<"AC: "<<setw(10)<<En_AC<<endl;
                for (int r = 0; r < rows; r++)
                {
                    for (int c = 0; c < cols; c++)
                    {
                        cout<<setw(10)<<enemy[r][c];
                    }
                    cout<<endl;
                }
                cout<<endl;
                
                //Initiative determines the order of actions, who goes first.
                PC_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the PC's initiative
                En_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the Enemy's initiative
    
                cout<<"[Press Enter to roll for initiative]\n";
                cin.get(ch);
                
                cout<<"\n[Your initiative roll is: "<<PC_Init<<" (+"<<InitB<<" bonus) = "<<PC_Init+InitB<<"]"<<endl;
                cout<<"[Your opponent's initiative roll is: "<<En_Init<<" (+3 bonus) = "<<En_Init+3<<"]"<<endl;
                cout<<endl;
    
                if (PC_Init+InitB == En_Init+4) //If it's a tie, roll again
                {
                    cout<<"[It's a tie!]\n"; 
                    cout<<"[Re-rolling initiative . . .]\n";
                    cout<<"[Press Enter]\n";
                    cin.get(ch);
                    PC_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the PC's initiative
                    En_Init = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Generating the random number for the Enemy's initiative
        
                    cout<<"[Your initiative roll is: "<<PC_Init<<" (+"<<InitB<<" bonus) = "<<PC_Init+InitB<<"]"<<endl;
                    cout<<"[Your opponent's initiative roll is: "<<En_Init<<" (+4 bonus) = "<<En_Init+4<<"]"<<endl;
                    cout<<endl;
                }
                if (PC_Init+InitB > En_Init+4) //Player is first 
                {   
                    cout<<"[You're first!]\n";
                    for (int count = 3; count > 0; count--)
                    {
                        cout<<count<<endl;
                        cout<<"...\n";
                    }
                    cout<<"Go!\n";
                    while (Damd > 0 && En_HP > 0) //This loop will continue until someone is knocked down to 0 HP or lower
                    {
                        stars();
                        
                        cout<<"\n[Your turn!]\n";
                        cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                        cout<<"[Press Enter]\n";
                        cin.get(ch);
            
                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                        cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
            
                        if (PC_Hit+PCToHit >= En_AC) //If the player hits, generate and calculate the player's damage
                        {
                            int Dam;
                
                            cout<<"[You hit!]\n";
                            cout<<endl;
                            if (PC_Hit >= CritTh)
                            {
                                cout<<"[Possible Critical!]\n";
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                                cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                if (PC_Hit+PCToHit >= En_AC)
                                {
                                    cout<<"[Critical Hit!]\n";
                                    cout<<"[Rolling 2D6 for Damage . . .]\n";
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                
                                    PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                    PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                    Dam = (PC_Dam + PC_Dam2 + PCDam) * 2;
                
                                    cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<" and "<<PC_Dam2<<"(+"<<PCDam<<" bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                    cout<<endl;
                
                                    En_HP = En_HP - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                                else
                                {
                                    cout<<"[Not a Critical Hit.]\n";
                                    
                                    cout<<"[Rolling 2D6 for Damage . . .]\n";
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                
                                    PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                    PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                    Dam = (PC_Dam + PC_Dam2 + PCDam);
                
                                    cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<" and "<<PC_Dam2<<"(+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                    cout<<endl;
                
                                    En_HP = En_HP - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                            else
                            {
                                cout<<"[Rolling 2D6 for Damage . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                
                                PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                Dam = (PC_Dam + PC_Dam2 + PCDam);
                
                                cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<" and "<<PC_Dam2<<"(+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                cout<<endl;
                
                                En_HP = En_HP - Dam;
                
                                cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                cout<<endl;
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                            }
                            if (Damd > 0 && En_HP > 0) //If the Enemy is not at 0 or lower hit points, they attack
                            {
                                stars(star);
                                
                                cout<<"\n                              [Enemy's turn!]\n";
                                cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"                              [They rolled: "<<En_Hit<<" (+8 bonus) = "<<En_Hit+8<<"]\n";
                                if (En_Hit+8 >= PC_AC) //If the enemy hits
                                 {
                                    int Dam;
                
                                    cout<<"                              [They hit!]\n";
                                    cout<<endl;
                                        
                                    if (En_Hit >= 18)
                                    {
                                        cout<<"                              [Possible Critical!]\n";
                                        En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"                              [They rolled: "<<En_Hit<<" (+8 bonus) = "<<En_Hit+8<<"]"<<endl;
                                        if (En_Hit+8 >= PC_AC)
                                        {
                                            cout<<"                              [Critical Hit!]\n";
                                            cout<<"                              [Rolling D12 for Damage . . .]\n";

                                            En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD;
                                            Dam = (En_Dam + 4) * 2;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+4 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"                              [Not a Critical Hit.]\n";
                                    
                                            cout<<"                              [Rolling D12 for Damage . . .]\n";
                
                                            En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD; //Rolling damage
                                            Dam = En_Dam + 3;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +3 is "<<Dam<<" points of damage.]\n";
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {   
                                        cout<<"                              [Rolling D12 for Damage . . .]\n";
                
                                        En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = En_Dam + 4;
                
                                        cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +4 is "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        Damd = Damd - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"                              [They missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                        if (PC_Hit+PCToHit < En_AC && Damd > 0 && En_HP > 0) //If the player misses
                        {
                            cout<<"[You missed!]\n";
                            cout<<endl;
                            if (Damd > 0 && En_HP > 0)   
                            {
                                stars(star);
                                
                                cout<<"\n                              [Enemy's turn!]\n";
                                cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"                              [They rolled: "<<En_Hit<<" (+8 bonus) = "<<En_Hit+7<<"]\n";
                                if (En_Hit+8 >= PC_AC) //If the enemy hits
                                {
                                    int Dam;
                
                                    cout<<"                              [They hit!]\n";
                                    cout<<endl;
                                        
                                    if (En_Hit >= 18)
                                    {
                                        cout<<"                              [Possible Critical!]\n";
                                        En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"                              [They rolled: "<<En_Hit<<" (+8 bonus) = "<<En_Hit+8<<"]"<<endl;
                                        if (En_Hit+8 >= PC_AC)
                                        {
                                            cout<<"                              [Critical Hit!]\n";
                                            cout<<"                              [Rolling D12 for Damage . . .]\n";

                                            En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD;
                                            Dam = (En_Dam + 4) * 2;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+4 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"                              [Not a Critical Hit.]\n";
                                    
                                            cout<<"                              [Rolling D12 for Damage . . .]\n";
                
                                            En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD; //Rolling damage
                                            Dam = En_Dam + 4;
                
                                            cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +4 is "<<Dam<<" points of damage.]\n";
                                            cout<<endl;
                
                                            Damd = Damd - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        cout<<"                              [Rolling D12 for Damage . . .]\n";
                
                                        En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD; //Rolling damage
                                        Dam = En_Dam + 4;
                
                                        cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +4 is "<<Dam<<" points of damage.]\n";
                                        cout<<endl;
                
                                        Damd = Damd - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"                              [They missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                    }    
                    if (Damd > En_HP)
                    {
                        cout<<"[You are victorious!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else if (En_HP > Damd)
                    {
                        cout<<"[You have been defeated.]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else
                    {
                        cout<<"[It's a tie!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                }
                if (PC_Init+InitB < En_Init+4) //Enemy is first 
                {
                    
                    cout<<"                              [They're first!]\n";
                    for (int count = 3; count > 0; count--)
                    {
                        cout<<count<<endl;
                        cout<<"...\n";
                    }
                    cout<<"Go!\n";
                    while (Damd > 0 && En_HP > 0) //This loop will continue until someone is knocked down to 0 HP or lower
                    {
                        round = rounds(round);
                        
                        stars();
                        
                        cout<<"\n                              [Enemy's turn!]\n";
                        cout<<"                              [Rolling D20 to hit AC "<<PC_AC<<" . . .]\n";
            
                        En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Enemy rolling to hit
            
                        cout<<"                              [They rolled: "<<En_Hit<<" (+8 bonus) = "<<En_Hit+8<<"]"<<endl;
            
                        if (En_Hit+8 >= PC_AC) //If the enemy hits, this is their damage
                        {
                            int Dam;
                
                            cout<<"                              [They hit!]\n";
                            cout<<endl;
                            if (En_Hit >= 19)
                            {
                                cout<<"                              [Possible Critical!]\n";
                                En_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                cout<<"                              [Re-rolling D20 to see if it's Critical . . .]\n";
                                cout<<"                              [They rolled: "<<En_Hit<<" (+8 bonus) = "<<En_Hit+8<<"]"<<endl;
                                if (En_Hit+8 >= PC_AC)
                                {
                                    cout<<"                              [Critical Hit!]\n";
                                    cout<<"                              [Rolling D12 for Damage . . .]\n";

                                    En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD;
                                    Dam = (En_Dam + 4) * 2;
                
                                    cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+4 bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                    cout<<endl;
                
                                    Damd = Damd - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                                else
                                {
                                    cout<<"                              [Not a Critical Hit.]\n";  
                                    cout<<"                              [Rolling D12 for Damage . . .]\n";
                
                                    En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD; //Rolling damage
                                    Dam = En_Dam + 4;
                
                                    cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" +4 is "<<Dam<<" points of damage.]\n";
                                    cout<<endl;
                
                                    Damd = Damd - Dam;
                
                                    cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining].\n";
                                    cout<<"[You have "<<Damd<<" Hit Points remaining.]\n";
                                    cout<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                            else
                            {
                                cout<<"                              [Rolling D12 for Damage . . .]\n";
                
                                En_Dam = (rand() % (MAXVA12 - MINVALD + 1)) + MINVALD;
                                Dam = En_Dam + 4;
                
                                cout<<"                              [They rolled "<<En_Dam<<". "<<En_Dam<<" (+4 bonus) = "<<Dam<<" points of damage.]\n"; //Damage
                                cout<<endl;
                
                                Damd = Damd - Dam;
                
                                cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                cout<<endl;
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
                            }
                            if (Damd > 0 && En_HP > 0) //If you are not at 0 HP or lower, you attack
                            {
                                stars(star);
                                
                                cout<<"\n[Your turn!]\n";
                                cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
            
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
            
                                cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]\n";
                                if (PC_Hit+PCToHit >= En_AC) //If you hit
                                {
                                    int Dam;
                
                                    cout<<"[You hit!]\n";
                                    cout<<endl;
                                    if (PC_Hit >= CritTh)
                                    {
                                        cout<<"[Possible Critical!]\n";
                                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                        cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                        if (PC_Hit+PCToHit >= En_AC)
                                        {
                                            cout<<"[Critical Hit!]\n";
                                            cout<<"[Rolling 2D6 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = (PC_Dam + PC_Dam2 + PCDam) * 2;
                
                                            cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<"and"<<PC_Dam2<<" (+"<<PCDam<<" bonus) x2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"[Not a Critical Hit.]\n";
                                    
                                            cout<<"[Rolling 2D6 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = (PC_Dam + PC_Dam2 + PCDam);
                
                                            cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<"and"<<PC_Dam2<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        cout<<"[Rolling 2D6 for Damage . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                
                                        PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                        PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                        Dam = (PC_Dam + PC_Dam2 + PCDam);
                
                                        cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<"and"<<PC_Dam2<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                        cout<<endl;
                
                                        En_HP = En_HP - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"[You missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                        if (En_Hit+8 < PC_AC) //If they miss
                        {
                            cout<<"                              [They missed!]\n";
                            cout<<endl;
                            if (PC_HP > 0 && En_HP > 0) //If you are not at 0 or lower hit points, you attack
                            {
                                stars(star);
                                
                                cout<<"\n[Your turn!]\n";
                                cout<<"[Rolling D20 to hit AC "<<En_AC<<" . . .]\n";
                                cout<<"[Press Enter]\n";
                                cin.get(ch);
            
                                PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Rolling to hit
                                
                                cout<<"[You rolled: "<<PC_Hit<<" +"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]\n";
                                if (PC_Hit+PCToHit >= En_AC) //If you hit
                                {
                                    int Dam;
                
                                    cout<<"[You hit!]\n";
                                    cout<<endl;
                                    if (PC_Hit >= CritTh)
                                    {
                                        cout<<"[Possible Critical!]\n";
                                        PC_Hit = (rand() % (MAXVA20 - MINVALD + 1)) + MINVALD; //Player rolling to hit
            
                                        cout<<"[Re-rolling D20 to see if it's Critical . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                        cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
                                        if (PC_Hit+PCToHit >= En_AC)
                                        {
                                            cout<<"[Critical Hit!]\n";
                                            cout<<"[Rolling 2D6 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = (PC_Dam + PC_Dam2 + PCDam) * 2;
                
                                            cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<"and"<<PC_Dam2<<" (+"<<PCDam<<" bonus) x 2 = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                        else
                                        {
                                            cout<<"[Not a Critical Hit.]\n";
                                    
                                            cout<<"[Rolling 2D6 for Damage . . .]\n";
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                
                                            PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                            Dam = (PC_Dam + PC_Dam2 + PCDam);
                
                                            cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<"and"<<PC_Dam2<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                            cout<<endl;
                
                                            En_HP = En_HP - Dam;
                
                                            cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                            cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                            cout<<endl;
                                            cout<<"[Press Enter]\n";
                                            cin.get(ch);
                                        }
                                    }
                                    else
                                    {
                                        cout<<"[Rolling 2D6 for Damage . . .]\n";
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                
                                        PC_Dam = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                        PC_Dam2 = (rand() % (MAXVAL6 - MINVALD + 1)) + MINVALD;
                                        Dam = (PC_Dam + PC_Dam2 + PCDam);
                
                                        cout<<"[You rolled "<<PC_Dam<<" and "<<PC_Dam2<<". "<<PC_Dam<<"and"<<PC_Dam2<<" (+"<<PCDam<<" bonus) = "<<Dam<<" points of damage.]\n"; //Critical Hit Damage
                                        cout<<endl;
                
                                        En_HP = En_HP - Dam;
                
                                        cout<<"[Your opponent has "<<En_HP<<" Hit Points remaining.]\n";
                                        cout<<"[You have "<<Damd<<" Hit Points remaining].\n";
                                        cout<<endl;
                                        cout<<"[Press Enter]\n";
                                        cin.get(ch);
                                    }
                                }
                                else
                                {
                                    cout<<"[You missed!]\n"<<endl;
                                    cout<<"[Press Enter]\n";
                                    cin.get(ch);
                                }
                            }
                        }
                    }
                    if (Damd > En_HP)
                    {
                        cout<<"[You are victorious!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else if (En_HP > Damd)
                    {
                        cout<<"[You have been defeated.]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                    else
                    {
                        cout<<"[It's a tie!]\n";
                        cout<<endl;
                        
                        Damd = PC_HP;
                    }
                }
            }
                break;
            case '4':
            {
                cout<<"Leaving so soon?\n";
                cout<<"[Are you sure you wish to quit?\n";
                cout<<"Y for Yes\n";
                cout<<"N for No]: ";
                cin>>Conf;
                cout<<endl;
                
                if (confex(Conf))
                {
                    exit(PC_Name, round);
                    return 0;
                }
            }
                break;
            default:
            {
                cout<<"You must choose your opponent now, puny mortal, or have you changed your mind?\n";
                cout<<endl;
            }
        }
    } while (choice != 4);
    return 0;
}

bool confex(char Conf)
{
    bool status;
    
    if (Conf == 'Y' || Conf == 'y')
    {
        status = true;
    }
    else if (Conf == 'N' || Conf == 'n')
    {
        status = false;
    }
    
    return status;
}

int stars (int len)
{
    for (int across = 0; across < len; across++)
    {
        cout << "*";
    }
}

int rounds (int rnd)
{
    static int Round =rnd;
    
    Round++;
    
    return Round;
}

int hit(int PC_Hit, int PCToHit)
{
    int Hit;
    cout<<"[You rolled: "<<PC_Hit<<" (+"<<PCToHit<<" bonus) = "<<PC_Hit+PCToHit<<"]"<<endl;
    Hit = PC_Hit + PCToHit;
    return Hit;
}

float hit(float Hit)
{
    cout<<"                              [They rolled: "<<Hit<<" (+5 bonus) = "<<Hit+5<<"]\n";
    return Hit;
}

int endam (int &En_HP, int Dam)
{
    En_HP = En_HP - Dam;
}

void exit(string PC_Name, int round)
{
    cout<<"I will spare your life for now. Next time, you may not be so lucky.\n"; 
    cout<<"[You played "<<round<<" rounds.]\n";
    cout<<"["<<PC_Name<<" has left the dungeon.]\n";
    cout<<"[Game Over]";
    exit(0);
}