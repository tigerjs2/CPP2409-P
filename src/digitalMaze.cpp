#include <iostream>
#include <windows.h>
#include "keyEvent.h"
#include "stage.h"

using namespace std;

// Function for Main Page
void printMainTitle(); // print title line
void printOption(string s, bool selected); // print option line
void printLine(int num); // print line made with '='
void printTwoStageButton(int start, int size); // print button for selection page

/*
Page Flag Instructions
0: Title Page
1: Stage Selection Page
2: Instruction Page
3: Game Page
*/

int main(){
    const int CENTINEL = -999; // When pageFlag is CENTINEL shutdown the game
    int pageFlag = 0; // Starting Page
    int stageFlag = 1; // Selected Stage
    // Self Defined Direction Values
    const int LEFT = 0;
    const int RIGHT = 1;
    const int UP = 2;
    const int DOWN = 3;

    while(pageFlag != CENTINEL){
        // Display Main Page
        if(pageFlag == 0){
            const int OPTION_SIZE = 3;
            int option = 0; // this will get 0~2
            bool selected[OPTION_SIZE] = {true, false, false};
            while(true){
                // Display Changed State
                system("cls");
                printMainTitle();
                printOption("Select Stage", selected[0]);
                printOption("Instructions", selected[1]);
                printOption("    Exit    ", selected[2]);
                cout << endl << endl << "Enter : Confirm";

                int pointerMove = getKey(1);
                if(pointerMove == 13) break; // Selection Determined
                // Change Selection According to Input
                for(int i = 0; i < OPTION_SIZE; i++){
                    if(selected[i]){
                        if(pointerMove == UP){
                            if(i == 0){
                                selected[0] = false;
                                selected[2] = true;
                                option = 2;
                                break;
                            }
                            else{
                                selected[i] = false;
                                selected[i - 1] = true;
                                --option;
                                break;
                            }
                        }
                        else if(pointerMove == DOWN){
                            if(i == 2){
                                selected[2] = false;
                                selected[0] = true;
                                option = 0;
                                break;
                            }
                            else{
                                selected[i] = false;
                                selected[i + 1] = true;
                                ++option;
                                break;
                            }
                        }
                    }
                }
            }
            if(option == 2)
                pageFlag = CENTINEL; // Terminate Game
            else
                pageFlag = option + 1; // Move onto Selected Page
        }
        // Display Selection Page
        else if(pageFlag == 1){
            while(true){
                system("cls");
                // Print title
                printLine(40);
                cout.width(26);
                cout << "Select Stage" << endl;
                printLine(40);
                // button
                printTwoStageButton(1, stageFlag);
                printTwoStageButton(3, stageFlag);
                cout << endl << "Back to Title";
                if (stageFlag == 0){
                    cout << " *";
                }
                else
                    cout << "  ";
                cout.width(25);
                cout << "Enter : Confirm";
                int select = getKey(2);
                if(select == UP){
                    if((stageFlag - 1) / 2 == 0)
                        stageFlag += 2;
                    else
                        stageFlag -= 2;
                }
                else if(select == DOWN){
                    if((stageFlag - 1) / 2 == 1)
                        stageFlag -= 2;
                    else if(stageFlag ==3){
                        stageFlag = 0;
                    }
                    else
                        stageFlag += 2;
                }
                else if(select == LEFT){

                }
                else if(select == 13)
                    break;
                if(stageFlag == 0)
                    pageFlag = 0;
                else
                    pageFlag = 3;
            }
        }

        // Display Instructions
        else if(pageFlag == 2){
            system("cls");
            // Print title
            printLine(40);
            cout.width(26);
            cout << "Instructions" << endl;
            printLine(40);
            // How to Play
            cout << "* Movement" << endl;
            cout << "   W          ^" << endl;
            cout << " A   D  or  <   > : Move to the Direction Once" << endl;
            cout << "   S          v" << endl;
            cout << endl << "* Entities" << endl;
            cout << "'P' : Player" << endl;
            cout << "'#' : Wall" << endl << endl;
            cout.width(40);
            cout << "Enter : Return to Title...";
            
            getKey(3); // Loof until Pressing Enter
            pageFlag = 0; // Return to Main Page
        }
        else if(pageFlag == 3){
            int gameresult = stage0();
        }
    }

    return 0;
}

// Only needed once but for readability made it into Function
void printMainTitle(){
    printLine(26);
    cout.width(19); // Needed for Alignment
    cout << "Digital Maze" << endl;
    printLine(26);
}
void printLine(int num){
    for(int i = 0; i < num; i++)
        cout << "=";
    cout << endl;
}
// Print Option line on title
void printOption(string s, bool selected){
    cout << endl;
    cout.width(7);
    if (selected == true){
        cout << "* " << s << endl;
    }
    else if(selected == false){
        cout << "  " << s << endl;
    }
}
// Print two button on stage selection page
void printTwoStageButton(int start, int selected){
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout.width(8);
        if(start + i == selected)
         cout << "* ";
        else
            cout << "";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout.width(5);
        cout << "" << "---";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout.width(5);
        cout << "" << "|" << start + i << "|";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout.width(5);
        cout << "" << "---" ;
    }
    cout << endl;   
}