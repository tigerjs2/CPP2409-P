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
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                if(stage1[i][j] == 'P')
                    STAGE[i][j] = new Player{35};
                else
                    STAGE[i][j] = new Entity{stage1[i][j]};
        }
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
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                if(stage2[i][j] == 'P')
                    STAGE[i][j] = new Player{35};
                else
                    STAGE[i][j] = new Entity{stage2[i][j]};
        }
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
        f.printStage(STAGE, size);
        cout << "Stamina : " << user->getStamina() << endl;

        if(encounter == '@'){ // if reaching goal clear!
            clearFlag = 1;
            break;
        }

        int action = KeyListener::getPlayerKey(); // get user action
        if(action == KeyListener::CTRL_Z){ // return to previous state if Ctrl + Z pressed
            // stack action
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
        if(encounter == '#'){ // If player meets wall, no action performed
            continue;
        }
        else{ // Action performed
            // stack action
            user->decreaseStamina();
            if(encounter == ' ' || encounter == '@'){ // Player change position
                STAGE[next_y][next_x]->setSymbol(' ');
                changeBoard(x, y, next_x, next_y);
                x = next_x;
                y = next_y;
            }
            else if(encounter == 'B'){
                STAGE[next_y][next_x]->setSymbol(' ');
            }
            else if(encounter == 'O'){
                // position beyond 'O'
                int next_x2 = 2 * next_x - x;
                int next_y2 = 2 * next_y - y;
                if(STAGE[next_y2][next_x2]->getSymbol() == ' '){
                    changeBoard(next_x, next_y, next_x2, next_y2);
                }
            }
        }
    }
    return clearFlag;
}
