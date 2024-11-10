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
            // Stage End, Give Multiple Choice
            bool choice[3] = {true, false, false};
            int pointer = 0;
            int move = 0;
            while(move != KeyListener::ENTER){
                system("cls");
                if (gameresult == 0 || stageFlag == 4){ // Last stage can't go onto next stage
                    // try again option and back to stage selection option
                    if(gameresult == 0)
                        printer.printTitle(14 ,"Fail..");
                    else
                        printer.printTitle(14, "Clear!");
                    printer.printOption("Try Again?", choice[0], 1);
                    printer.printOption("Map Select", choice[1], 1);
                    printer.printConfirmAlert();
                    move = KeyListener::titleKey(); // determine action
                    if(move != KeyListener::ENTER){ // Since only two options it will toggle
                        choice[0] = !choice[0];
                        choice[1] = !choice[1]; 
                    }
                }
                else{ // if game clear
                    printer.printTitle(14, "Clear!");
                    printer.printOption("Try Again?", choice[0], 1);
                    printer.printOption("Map Select", choice[1], 1);
                    printer.printOption("Next Stage", choice[2], 1);
                    printer.printConfirmAlert();
                    move = KeyListener::titleKey(); // determine action
                    if(move == KeyListener::UP){
                        choice[pointer] = false;
                        if(pointer == 0){
                            choice[pointer = 2] = true;
                        }
                        else{
                            choice[--pointer] = true;
                        }
                    }
                    else if(move == KeyListener::DOWN){
                        choice[pointer] = false;
                        if(pointer == 2){
                            choice[pointer = 0] = true;
                        }
                        else{
                            choice[++pointer] = true;
                        }
                    }      
                }          
            }
            // At this point pageFlag is 3, therefore only choice[1] need to change the flag
            if(choice[1]) 
                pageFlag = 1; // go onto selection page
            else if(choice[2])
                ++stageFlag; // go onto next stage
            
        }
    }
    return 0;
}