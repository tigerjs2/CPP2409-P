/*
Some Stage Doesn't have some Obstacles
So checking Every obstacles for each stage might be useless
As a result, each stage got different logic
*/
#include "stage.h"

using namespace std;
Stage::~Stage(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            delete STAGE[i][j];
        }
        delete [] STAGE[i];
    }
    delete [] STAGE;
}
void Stage::buildSupport(int stamina, char stage[][size]){
    Portal *p = nullptr;
    for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                if(stage[i][j] == 'P')
                    STAGE[i][j] = new Player{stamina};
                else if(stage[i][j] == 'W'){
                    if(p == nullptr){
                        p = new Portal{j, i};
                        STAGE[i][j] = p;
                    }
                    else{
                        Portal *q = new Portal(j, i);
                        p->connect(q);
                        q->connect(p);
                        STAGE[i][j] = q;
                        p = nullptr;
                        q = nullptr;
                    }
                }
                else
                    STAGE[i][j] = new Entity{stage[i][j]};
    }
}
void Stage::buildStage(int stageFlag){ // Load stage according to flag
    // Build Stage with Dynamic Allocation
    // since entities position has no pattern, better type whole stage
    STAGE = new Entity**[size];
    for(int i = 0; i < size; i++){ 
        STAGE[i] = new Entity*[size];
    }
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
        buildSupport(35, stage1);
    }
    else if(stageFlag == 2){
        char stage2[size][size] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
                                   {'#','P','B','#',' ',' ','#',' ',' ',' ',' ','#'},
                                   {'#','#',' ','#',' ',' ','#',' ','#','#','#','#'},
                                   {'#',' ',' ','#','#','#','#',' ','#',' ',' ','#'},
                                   {'#',' ',' ','B','O',' ',' ',' ',' ',' ',' ','#'},
                                   {'#','#','B','#','#','#','#',' ','#','#',' ','#'},
                                   {'#','#','O','#',' ',' ',' ',' ','#','#',' ','#'},
                                   {'#','#',' ','#','#','#','#','#',' ','#','B','#'},
                                   {'#','#',' ','#',' ',' ','#',' ',' ','O','O','#'},
                                   {'#',' ',' ',' ','O',' ',' ',' ','O','B','#','#'},
                                   {'#','#',' ','#',' ',' ','#','O',' ',' ','@','#'},
                                   {'#','#','#','#','#','#','#','#','#','#','#','#'}
                                   };
        buildSupport(35, stage2);
    }
    else if(stageFlag == 3){
        char stage3[size][size] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
                                   {'#','P','#','@','#',' ',' ','O','#','@',' ','#'},
                                   {'#',' ','#','B','#',' ',' ','O',' ',' ','O','#'},
                                   {'#',' ','B','W','#',' ',' ',' ','#','#','#','#'},
                                   {'#',' ','#',' ','B',' ','#','#',' ',' ',' ','#'},
                                   {'#',' ','#',' ','#',' ',' ','#',' ',' ',' ','#'},
                                   {'#',' ','#',' ','#',' ','#','#','#','#','#','#'},
                                   {'#',' ',' ','B',' ',' ',' ',' ',' ',' ',' ','#'},
                                   {'#',' ','#','#','#','#',' ','#',' ','#','#','#'},
                                   {'#',' ',' ',' ','O',' ',' ',' ','B',' ','W','#'},
                                   {'#',' ','#','#','#','#',' ','#','#','#','#','#'},
                                   {'#','#','#','#','#','#','#','#','#','#','#','#'}
                                   };
        buildSupport(30, stage3);
    }
    else buildDummyStage();
}
void Stage::buildDummyStage(){
    for(int i = 0; i < size; i++){ // Fill with empty space
        for(int j = 0; j < size; j++){
            STAGE[i][j] = new Entity{' '};
        }
    }
    for (int i = 0; i < size; i++){  // make border
        STAGE[i][0] = new Entity{'#'};
        STAGE[0][i] = new Entity{'#'};
        STAGE[i][size - 1] = new Entity{'#'};
        STAGE[size - 1][i] = new Entity{'#'};
    }
    STAGE[1][1] = new Player{100};
    STAGE[10][10] = new Entity{'@'};
}

// About GamePlay
void Stage::changeBoard(int x, int y, int next_x, int next_y){ // activate when player success moving
    Entity *tmp = STAGE[y][x];
    STAGE[y][x] = STAGE[next_y][next_x];
    STAGE[next_y][next_x] = tmp;
}
Stage::Stage(int stageFlag){ // later according to flag, will build different stage map
    buildStage(stageFlag);
};
int Stage::play(Frame f, int stageFlag){ // Default Logic of game play, might be changed according to obstacles
    int clearFlag = 0; // if flag is 1 clear
    char encounter; // Entity that is which is on
    Player * user;
    string title[5] = {"Stage0", "Stage1", "Stage2", "Stage3", "Stage4"};
    while(true){
        user = dynamic_cast<Player*>(STAGE[y][x]);
        // refresh displayed screen
        system("cls");
        f.printTitle(12, title[stageFlag]);
        cout << endl;
        f.printStage(STAGE, size, user->getStamina());
        cout << "Stamina : " << user->getStamina() << endl;

        if(encounter == '@'){ // if reaching goal clear!
            clearFlag = 1;
            break;
        }

        int action = KeyListener::getPlayerKey(); // get user action
        if(action == KeyListener::CTRL_Z){ // return to previous state if Ctrl + Z pressed
            if(stack.empty() == false){
                user->increaseStamina();
                StageNode tmp = stack.top();
                changeBoard(x, y, tmp.x, tmp.y);
                for(int i = 0; i < size; i++){ // Change STAGE with data in StageNode
                    for(int j = 0; j < size; j++){
                        STAGE[i][j]->setSymbol(tmp.stage[i][j]);          
                    }
                }
                x = tmp.x;
                y = tmp.y;
                stack.pop();
            }
            continue;
        }
        if(!user->checkAlive()){ // if user try to move when stamina is 0 or less game over
            break;
        }
        // Change stage according to player's movement
        int next_x = x;
        int next_y = y;
        // Identity the object which player's gonna encounter
        if(action == KeyListener::UP)
            encounter = STAGE[--next_y][next_x]->getSymbol();
        else if(action == KeyListener::DOWN)
            encounter = STAGE[++next_y][next_x]->getSymbol();
        else if(action == KeyListener::LEFT)
            encounter = STAGE[next_y][--next_x]->getSymbol();
        else if(action == KeyListener::RIGHT)
            encounter = STAGE[next_y][++next_x]->getSymbol();
        if(encounter == '#' || (encounter == 'W' && user->getStamina() % 2 == 0)){ // If player meets wall or try to enter disabled portal, no action performed
            continue;
        }
        else{ // Action performed
            stack.push(StageNode{STAGE, x, y});
            user->decreaseStamina();
            if(encounter == ' ' || encounter == '@'){ // Player change position
                STAGE[next_y][next_x]->setSymbol(' ');
                changeBoard(x, y, next_x, next_y);
                x = next_x;
                y = next_y;
            }
            else if(encounter == 'B'){ // Break Obstacle
                STAGE[next_y][next_x]->setSymbol(' ');
            }
            else if(encounter == 'O'){ // Kick Obstacle
                // position beyond 'O'
                int next_x2 = 2 * next_x - x;
                int next_y2 = 2 * next_y - y;
                if(STAGE[next_y2][next_x2]->getSymbol() == ' '){ // Push Obstacle if space exist
                    changeBoard(next_x, next_y, next_x2, next_y2);
                }
            }
            else if(encounter == 'W'){
                
            }
        }
    }
    return clearFlag;
}
