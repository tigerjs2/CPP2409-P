/*
Some Stage Doesn't have some Obstacles
So checking Every obstacles for each stage might be useless
As a result, each stage got different logic
*/
#include "stage.h"

// #include <iostream>
// #include <windows.h>
using namespace std;

void Stage::buildDummyStage(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            stage[i][j] = ' ';
        }
    }
    // build wall
    for (int i = 0; i < size; i++){
        stage[i][0] = '#';
        stage[0][i] = '#';
        stage[i][size - 1] = '#';
        stage[size - 1][i] = '#';
    }
    stage[size - 1][size - 1] = '#';
    stage[1][1] = 'P'; // Player
    stage[20][20] = '@'; // Goal
}
void Stage::changeBoard(int action){ // activate when player success moving
    // change position in board, user's location, and decrease statmina
    stage[user.getY()][user.getX()] = ' ';
    user.move(action);
    stage[user.getY()][user.getX()] = 'P';
    user.decreaseStamina();
}
Stage::Stage(int user_stamina){ // later according to flag, will build different stage map
    user = Player {user_stamina};
    buildDummyStage();
};

int Stage::play(Frame f){ // Default Logic of game play, might be changed according to obstacles
    int clearFlag = 0; // if flag is 1 clear
    char encounter; // Entity that is which is on
    while(true){
        // refresh displayed screen
        system("cls");
        f.printTitle(22, "Stage0");
        cout << endl;
        f.printStage(stage, size);
        cout << "Stamina : " << user.getStamina() << endl;
        
        if(encounter == '@'){ // if reaching goal clear!
            clearFlag = 1;
            break;
        }

        int action = KeyListener::getPlayerKey(); // get user action
        if(!user.checkAlive()){ // if user try to move when stamina is 0 or less game over
            break;
        }
        // Change stage according to player's movement
        if(action == KeyListener::UP){
            encounter = stage[user.getY() - 1][user.getX()];
            if(encounter == ' ' || encounter == '@'){
                changeBoard(action);
            }
        }
        else if(action == KeyListener::DOWN){
            encounter = stage[user.getY() + 1][user.getX()];
            if(encounter == ' ' || encounter == '@'){
                changeBoard(action);
            }
        }
        else if(action == KeyListener::LEFT){
            encounter = stage[user.getY()][user.getX() - 1];
            if(encounter == ' ' || encounter == '@'){
                changeBoard(action);
            }
        }
        else if(action == KeyListener::RIGHT){
            encounter = stage[user.getY()][user.getX() + 1];
            if(encounter == ' ' || encounter == '@'){
                changeBoard(action);
            }
        }
    }
    return clearFlag;
}