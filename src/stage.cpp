/*
Some Stage Doesn't have some Obstacles
So checking Every obstacles for each stage might be useless
As a result, each stage got different logic
*/
#include "stage.h"

using namespace std;
// About Frame
void Stage::buildWall(){ // Every Stage has same border
    for(int i = 0; i < size; i++){ // Fill with empty space
        for(int j = 0; j < size; j++){
            stage[i][j] = ' ';
        }
    }
    for (int i = 0; i < size; i++){  // make border
        stage[i][0] = '#';
        stage[0][i] = '#';
        stage[i][size - 1] = '#';
        stage[size - 1][i] = '#';
    }
}
void Stage::buildStage(int stageFlag){ // Load stage according to flag
    // since entities position has no pattern better type whole stage
    if (stageFlag == 1){ // Obstacle - Wall only
        char stage1[size][size] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
                                   {'#','P',' ',' ',' ',' ',' ','#',' ',' ','@','#'},
                                   {'#',' ','#','#','#','#','#',' ',' ','#','#','#'},
                                   {'#',' ','#',' ',' ',' ','#',' ','#','#',' ','#'},
                                   {'#',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#'},
                                   {'#',' ','#','#','#',' ','#',' ',' ','#','#','#'},
                                   {'#',' ','#',' ',' ',' ','#',' ',' ','#',' ','#'},
                                   {'#',' ','#',' ','#','#','#',' ','#','#',' ','#'},
                                   {'#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                                   {'#',' ','#','#','#','#','#',' ','#','#','#','#'},
                                   {'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ','#'},
                                   {'#','#','#','#','#','#','#','#','#','#','#','#'}
                                   };
        copy(&stage1[0][0], &stage1[size-1][size-1],&stage[0][0]);
    }
    else if(stageFlag == 2){
        char stage2[size][size] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
                                   {'#','P','B','#',' ',' ','#',' ',' ',' ',' ','#'},
                                   {'#','#',' ','#',' ',' ','#',' ','#','#','#','#'},
                                   {'#',' ',' ','#','#','#','#',' ','#',' ',' ','#'},
                                   {'#',' ',' ','B',' ',' ',' ',' ',' ',' ',' ','#'},
                                   {'#','#',' ','#','#','#','#',' ','#','#',' ','#'},
                                   {'#','#',' ','#',' ',' ',' ',' ','#','#',' ','#'},
                                   {'#','#',' ','#','#','#','#','#',' ','#','B','#'},
                                   {'#','#',' ','#',' ',' ','#',' ',' ','O','O','#'},
                                   {'#',' ',' ',' ','O',' ',' ',' ','O','B','#','#'},
                                   {'#','#',' ','#',' ',' ','#','O',' ',' ','@','#'},
                                   {'#','#','#','#','#','#','#','#','#','#','#','#'}
                                   };
        copy(&stage2[0][0], &stage2[size-1][size-1],&stage[0][0]);
    }
    else buildDummyStage();
}
void Stage::buildDummyStage(){
    buildWall();
    stage[size - 1][size - 1] = '#';
    stage[1][1] = 'P'; // Player
    stage[10][10] = '@'; // Goal
}

// For Ctrl + Z
StageNode::StageNode(char s[size][size], Player u){
    copy(&s[0][0], &s[size - 1][size - 1], &stage[0][0]);
    x = u.getX();
    y = u.getY();
    hp = u.getStamina();
}

// About GamePlay
void Stage::changeBoard(int action){ // activate when player success moving
    // change position in board, user's location, and decrease statmina
    stage[user.getY()][user.getX()] = ' ';
    user.move(action);
    stage[user.getY()][user.getX()] = 'P';
    user.decreaseStamina();
}
Stage::Stage(int stageFlag){ // later according to flag, will build different stage map
    switch(stageFlag){
        case 1:
            user = Player{35}; // Least movement for stage 1 is 29
            break;
        default: // for dummy stage
            user = Player{100};
            break;
    }
    buildStage(stageFlag);
};
int Stage::play(Frame f, int stageFlag){ // Default Logic of game play, might be changed according to obstacles
    int clearFlag = 0; // if flag is 1 clear
    char encounter; // Entity that is which is on
    string title[5] = {"Stage0", "Stage1", "Stage2", "Stage3", "Stage4"};
    while(true){
        // refresh displayed screen
        system("cls");
        f.printTitle(12, title[stageFlag]);
        cout << endl;
        f.printStage(stage, size);
        cout << "Stamina : " << user.getStamina() << endl;
        
        if(encounter == '@'){ // if reaching goal clear!
            clearFlag = 1;
            break;
        }

        int action = KeyListener::getPlayerKey(); // get user action
        if(action == KeyListener::CTRL_Z){ // return to previous state if Ctrl + Z pressed
            if(stack.empty() == false){
                StageNode tmp = stack.top();
                user.setLocation(tmp.x, tmp.y);
                user.setStamina(tmp.hp);
                copy(&tmp.stage[0][0], &tmp.stage[size - 1][size - 1], &stage[0][0]);
                stack.pop();
                continue;
            }
        }
        if(!user.checkAlive()){ // if user try to move when stamina is 0 or less game over
            break;
        }
        // Change stage according to player's movement
        if(action == KeyListener::UP){
            encounter = stage[user.getY() - 1][user.getX()];
            if(encounter == ' ' || encounter == '@'){
                stack.push(StageNode{stage, user}); // save state before change
                changeBoard(action);
            }
        }
        else if(action == KeyListener::DOWN){
            encounter = stage[user.getY() + 1][user.getX()];
            if(encounter == ' ' || encounter == '@'){
                stack.push(StageNode{stage, user});
                changeBoard(action);
            }
        }
        else if(action == KeyListener::LEFT){
            encounter = stage[user.getY()][user.getX() - 1];
            if(encounter == ' ' || encounter == '@'){
                stack.push(StageNode{stage, user});
                changeBoard(action);
            }
        }
        else if(action == KeyListener::RIGHT){
            encounter = stage[user.getY()][user.getX() + 1];
            if(encounter == ' ' || encounter == '@'){
                stack.push(StageNode{stage, user});
                changeBoard(action);
            }
        }
    }
    while(!stack.empty()){stack.pop();}
    return clearFlag;
}
