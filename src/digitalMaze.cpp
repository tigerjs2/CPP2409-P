/*
This source code is the Main Part
This Program only works on Microsoft Windows OS
*/
#include "stage.h"
#include "progressHandle.h"
using namespace std;

/*
Page Flag Instructions
0: Title Page
1: Stage Selection Page
2: Instruction Page
3: Game Page
*/

int main(){
    Progress p;
    int opened = p.Get();  // Opened Stage
    Frame printer;
    const int CENTINEL = -999; // When pageFlag is CENTINEL shutdown the game
    int page_flag = 0; // Starting Page
    int stage_flag = 1; // Selected Stage
    
    while(page_flag != CENTINEL){
        // Display Main Page
        if(page_flag == 0){
            const int OPTION_SIZE = 3;
            int option = 0; // option pointer, this will get 0~2
            bool selected[OPTION_SIZE] = {true, false, false}; // selected option's value is true
            while(true){
                // Display Changed State
                system("cls");
                printer.PrintTitle(26, "Digital Maze");
                printer.PrintOption("Select Stage", selected[0], 7);
                printer.PrintOption("Instructions", selected[1], 7);
                printer.PrintOption("    Exit    ", selected[2], 7);
                printer.PrintConfirmAlert();
                cout << endl << endl;
                printer.PrintLine(26);

                int move = KeyListener::TitleKey(); // determine action
                if(move == KeyListener::ENTER){  // confirm selection
                    Sound::Confirm();
                    break;
                }
                // Change Selection According to Input
                // if not Confirming the move is option changing
                selected[option] = false;
                if(move == KeyListener::UP){
                    if(option == 0) option = 2;
                    else option--;
                }
                else if(move == KeyListener::DOWN){
                    if(option == 2) option = 0;
                    else option++;
                }
                selected[option] = true;
                Sound::Select();
            }
            if(option == 2)
                page_flag = CENTINEL; // Terminate Game
            else
                page_flag = option + 1; // Move onto Selected Page
        }
        // Display Selection Page
        else if(page_flag == 1){
            while(true){
                system("cls");
                // Print title
                printer.PrintTitle(24, "Select Stage");
                // button
                printer.PrintButtonLine(1, stage_flag);
                printer.PrintButtonLine(3, stage_flag);
                // change code under 
                printer.PrintOption("Back to Title", !stage_flag, 2);
                printer.PrintConfirmAlert();

                int selected = KeyListener::StageSelectionKey();
                if(selected == KeyListener::ENTER){  // confirm selection
                    Sound::Confirm();
                    break;
                }
                if(opened == 1){  // only stage 1 is allowed
                    stage_flag = !stage_flag;
                }
                else if(opened == 2){  // stage 1 & 2 allowed
                    if(stage_flag == 0 || selected == KeyListener::UP || selected == KeyListener::DOWN) stage_flag = !stage_flag;
                    else if(selected == KeyListener::LEFT){
                        if(stage_flag % 2 == 1) stage_flag++;
                        else stage_flag--;
                    }
                    else if(selected == KeyListener::RIGHT){
                        if(stage_flag % 2 == 0) stage_flag--;
                        else stage_flag++;
                    }
                }
                else if(opened == 3){  // stage 1, 2 & 3 allowed
                    if(selected == KeyListener::LEFT && stage_flag != 3){
                        if(stage_flag % 2 == 1) stage_flag++;
                        else stage_flag--;
                    }
                    else if(selected == KeyListener::RIGHT && stage_flag != 3){
                        if(stage_flag % 2 == 0) stage_flag--;
                        else stage_flag++;
                    }
                    else if(selected == KeyListener::DOWN){
                        if(stage_flag == 3 || stage_flag == 0) stage_flag = !stage_flag;
                        else stage_flag = 3;
                    }
                    else if(selected == KeyListener::UP){
                        if(stage_flag == 0) stage_flag = 3;
                        else stage_flag = stage_flag / 3;
                    }
                }
                else if(opened == 4){  // Every stage is allowed
                    if(selected == KeyListener::UP){
                        if(stage_flag == 0) stage_flag = 3;
                        else if(stage_flag / 3 == 0) stage_flag += 2;
                        else stage_flag -= 2;
                    }
                    else if(selected == KeyListener::DOWN){
                        if(stage_flag == 3 || stage_flag == 0) stage_flag = !stage_flag;
                        else if(stage_flag == 4) stage_flag -= 2;
                        else stage_flag += 2;
                    }
                    else if(selected == KeyListener::LEFT){
                        if(stage_flag == 0) continue;
                        if(stage_flag % 2 == 1) stage_flag++;
                        else stage_flag--;
                    }
                    else if(selected == KeyListener::RIGHT){
                        if(stage_flag == 0) continue;
                        if(stage_flag % 2 == 0) stage_flag--;
                        else stage_flag++;
                    }
                }
                Sound::Select();
            }
            // If stage is selected go onto page 3, else go onto page 0
            if(stage_flag == 0)
                page_flag = 0;
            else
                page_flag = 3;
        }
        // Display Instructions
        else if(page_flag == 2){
            system("cls");
            // most code in this line will goto Frame Class
            // Print title
            printer.PrintTitle(58, "Instructions");
            // How to Play
            cout << "* Movement" << endl;
            cout << "   W          ^" << endl;
            cout << " A   D  or  <   > : Move to the Direction Once" << endl;
            cout << "   S          v" << endl;
            cout << endl << "'Crtl + Z' : Undo" << endl;
            cout << endl << "* Entities" << endl;
            cout << "'P' : Player" << endl;
            cout << "'#' : Wall - Can't break, push or kick. It's fixed" << endl;
            cout << "'L' : Lock - Can't break, push or kick. But disposable" << endl;
            cout << "'K' : Key - Unlock the 'Lock' Entity" << endl;
            cout << "'W' : Warp Portal - Two object exist." << endl;
            cout << "      Touching one, warp to the other" << endl;
            cout << "      Portal must be activated at the moment you're touching" << endl;
            cout << "'B' : Breakable Box - You can break it by kicking it once" << endl;
            cout << "'O' : Pushable Rock - You can push it." << endl;
            cout << "                      You can kick even when you can't push" << endl << endl;

            cout.width(58);
            cout << "Enter : Return to Title...";
            
            KeyListener::EnableEnter(); // Loof until Pressing Enter
            Sound::Confirm();
            page_flag = 0; // Return to Main Page
        }
        // Actual Game Playing Page
        else if(page_flag == 3){
            Stage s{stage_flag};
            // this logic will be done after at least stage 1 is built
            int gameresult = s.Play(printer, stage_flag);
            if(gameresult == 2) continue; // Reset this Stage
            else if(gameresult == 3) {
                page_flag = 1;
                continue;
            }
            else if(gameresult == 0) Sound::Fail();
            else if(gameresult == 1) {
                Sound::Clear();
                if(opened == stage_flag){  // if the stage is first cleared
                    p.Save(++opened);  // update savedat.dat
                }
            }
            // Stage End, Give Multiple Choice
            bool choice[3] = {true, false, false};
            int pointer = 0;
            int move;
            while(1){
                system("cls");
                if (gameresult == 0 || stage_flag == 4){ // Last stage can't go onto next stage
                    // try again option and back to stage selection option
                    if(gameresult == 0)
                        printer.PrintTitle(14 ,"Fail..");
                    else
                        printer.PrintTitle(14, "Clear!");
                    printer.PrintOption("Try Again?", choice[0], 1);
                    printer.PrintOption("Map Select", choice[1], 1);
                    printer.PrintConfirmAlert();
                    move = KeyListener::TitleKey(); // determine action
                    if(move != KeyListener::ENTER){ // Since only two options it will toggle
                        choice[0] = !choice[0];
                        choice[1] = !choice[1];
                    }
                }
                else{ // if game clear
                    printer.PrintTitle(14, "Clear!");
                    printer.PrintOption("Try Again?", choice[0], 1);
                    printer.PrintOption("Map Select", choice[1], 1);
                    printer.PrintOption("Next Stage", choice[2], 1);
                    printer.PrintConfirmAlert();
                    move = KeyListener::TitleKey(); // determine action
                    choice[pointer] = false;  // there's only selection change action left
                    if(move == KeyListener::UP){
                        if(pointer == 0) pointer = 2;
                        else --pointer;
                    }
                    else if(move == KeyListener::DOWN){
                        if(pointer == 2) pointer = 0;
                        else ++pointer;
                    }
                    choice[pointer] = true;  
                }
                if(move == KeyListener::ENTER) {
                    Sound::Confirm();
                    break;  // confirm selection
                }
                Sound::Select();
            }
            // At this point pageFlag is 3, therefore only choice[1] need to change the flag
            if(choice[1]) 
                page_flag = 1; // go onto selection page
            else if(choice[2])
                ++stage_flag; // go onto next stage
            
        }
    }
    return 0;
}