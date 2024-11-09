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
    Frame printer;
    const int CENTINEL = -999; // When pageFlag is CENTINEL shutdown the game
    int pageFlag = 0; // Starting Page
    int stageFlag = 1; // Selected Stage
    
    while(pageFlag != CENTINEL){
        // Display Main Page
        if(pageFlag == 0){
            const int OPTION_SIZE = 3;
            int option = 0; // option pointer, this will get 0~2
            bool selected[OPTION_SIZE] = {true, false, false}; // selected option's value is true
            while(true){
                // Display Changed State
                system("cls");
                printer.printTitle(26, "Digital Maze");
                printer.printOption("Select Stage", selected[0], 7);
                printer.printOption("Instructions", selected[1], 7);
                printer.printOption("    Exit    ", selected[2], 7);
                printer.printConfirmAlert();
                cout << endl << endl;
                printer.printLine(26);

                int move = KeyListener::titleKey(); // determine action
                if(move == KeyListener::ENTER) break; // Selection Determined
                // Change Selection According to Input
                // if not Confirming the move is option changing
                selected[option] = false;
                if(move == KeyListener::UP){
                    if(option == 0)
                        selected[option = 2] = true;
                    else
                        selected[--option] = true;
                }
                else if(move == KeyListener::DOWN){
                    if(option == 2)
                        selected[option = 0] = true;
                    else
                        selected[++option] = true;
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
                printer.printTitle(24, "Select Stage");
                // button
                printer.printButtonLine(1, stageFlag);
                printer.printButtonLine(3, stageFlag);
                // change code under 
                printer.printOption("Back to Title", !stageFlag, 2);
                printer.printConfirmAlert();
                // cout.width(25);
                // cout << "Enter : Confirm";

                int selected = KeyListener::stageSelectionKey();
                if(selected == 13) break; // confirm selection
                else if(stageFlag == 0) stageFlag = 3; // When pointer is on back to title, next selection is always stage 3
                else if(selected == KeyListener::UP){
                    if(stageFlag / 3 == 0) stageFlag += 2;
                    else stageFlag -= 2;
                }
                else if(selected == KeyListener::DOWN){
                    if(stageFlag == 3) stageFlag = 0;
                    else if(stageFlag == 4) stageFlag -= 2;
                    else stageFlag += 2;
                }
                else if(selected == KeyListener::LEFT){
                    if(stageFlag % 2 == 1) stageFlag++;
                    else stageFlag--;
                }
                else if(selected == KeyListener::RIGHT){
                    if(stageFlag % 2 == 0) stageFlag--;
                    else stageFlag++;
                }
            }
            // If stage is selected go onto page 3, else go onto page 0
            if(stageFlag == 0)
                pageFlag = 0;
            else
                pageFlag = 3;
        }
        // Display Instructions
        else if(pageFlag == 2){
            system("cls");
            // most code in this line will goto Frame Class
            // Print title
            printer.printTitle(40, "Instructions");
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
            
            KeyListener::enableEnter(); // Loof until Pressing Enter
            pageFlag = 0; // Return to Main Page
        }
        // Actual Game Playing Page
        else if(pageFlag == 3){
            Stage s{stageFlag};
            // this logic will be done after at least stage 1 is built
            int gameresult = s.play(printer, stageFlag);
            if (gameresult == 0){
                // try again option and back to stage selection option
                cout << endl << "Fail..   Press Enter to get back to Selection Page";
                KeyListener::enableEnter();
                pageFlag = 1;
            }
            else{
                cout << endl << "Clear!   Press Enter to get back to Selection Page";
                KeyListener::enableEnter();
                pageFlag = 1;
                // next stage, try again, back to stage selection
            }
        }
    }

    return 0;
}