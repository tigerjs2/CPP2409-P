#include "stage.h"
using namespace std;

Stage::~Stage(){  // Stage was allocated Dynamically
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            delete STAGE[i][j];
        }
        delete [] STAGE[i];
    }
    delete [] STAGE;
}
void Stage::buildSupport(int stamina, char stage[][size]) {  // Supporter of BuildStage Function
    Portal *p = nullptr;
    for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                if(stage[i][j] == 'P')  // allocate Player
                    STAGE[i][j] = new Player{stamina};
                else if(stage[i][j] == 'W'){  // allocate Warp Portal
                    if(p == nullptr){  // First Portal Created
                        p = new Portal{j, i};
                        STAGE[i][j] = p;
                    }
                    else{  // Second Portal Created
                        Portal *q = new Portal(j, i);
                        // Connect portals
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
void Stage::buildStage(int stage_flag){ // Load stage according to flag
    // Build Stage with Dynamic Allocation
    // since entities position has no pattern, better type whole stage
    STAGE = new Entity**[size];
    for(int i = 0; i < size; i++){ 
        STAGE[i] = new Entity*[size];
    }
    if (stage_flag == 1){ // Obstacle - Wall only
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
    else if(stage_flag == 2){ // Obstacle - Wall, Breakable Box, and Pushable Box
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
    else if(stage_flag == 3){ // Obstacle - Wall, Breakable Box, Pushable Box, and Warp Portal
        char stage3[size][size] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
                                   {'#','P','#','@','#',' ',' ','O','#','@',' ','#'},
                                   {'#',' ','#','B','#',' ',' ','O',' ',' ','O','#'},
                                   {'#',' ','B','W','#',' ',' ',' ','#','#','#','#'},
                                   {'#',' ','#',' ','B',' ','#','#',' ',' ',' ','#'},
                                   {'#',' ','#',' ','#',' ',' ','#',' ',' ',' ','#'},
                                   {'#',' ','#',' ','#',' ','#','#','#','#','#','#'},
                                   {'#',' ','B','B','B',' ',' ',' ',' ',' ',' ','#'},
                                   {'#',' ','#','#','#','#',' ','#',' ','#','#','#'},
                                   {'#',' ',' ',' ','O',' ',' ',' ','B',' ','W','#'},
                                   {'#',' ','#','#','#','#',' ','#','#','#','#','#'},
                                   {'#','#','#','#','#','#','#','#','#','#','#','#'}
                                   };
        buildSupport(30, stage3);
    }
    else if(stage_flag == 4){
        char stage4[size][size] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
                                   {'#','P',' ',' ',' ',' ',' ',' ','L',' ','@','#'},
                                   {'#','#','O','#',' ','#',' ',' ','L',' ',' ','#'},
                                   {'#','#','#','#',' ','#',' ',' ','W','L','L','#'},
                                   {'#',' ',' ',' ',' ','#',' ',' ','B',' ',' ','#'},
                                   {'#','#',' ','#','#','#',' ','#',' ','#',' ','#'},
                                   {'#',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#'},
                                   {'#','#','#','#','#','#','#','#',' ','#','B','#'},
                                   {'#','O',' ','O',' ',' ',' ',' ','O','#','B','#'},
                                   {'#','K','O','W','O','#',' ',' ',' ','#','B','#'},
                                   {'#',' ',' ','O',' ',' ',' ','#',' ',' ',' ','#'},
                                   {'#','#','#','#','#','#','#','#','#','#','#','#'}
                                   };
        buildSupport(36, stage4);
    }
    // else buildDummyStage();  // Not needed anymore
}
/*
// Don't need this anymore
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
*/

Stage::Stage(int stage_flag){ // later according to flag, will build different stage map
    buildStage(stage_flag);
};
// About GamePlay
void Stage::warp(int next_x, int next_y){ // When player enter Activated portal player warp and portal vanish
    Portal *p = dynamic_cast<Portal*>(STAGE[next_y][next_x]);  // Entered Portal
    // Player warp
    changeBoard(x, y, p->getConnectedX(), p->getConnectedY());
    // Portal Disappear
    STAGE[y][x]->SetSymbol(' ');
    p->SetSymbol(' ');
    // Update player's location
    x = p->getConnectedX();
    y = p->getConnectedY();
}
void Stage::changeBoard(int x, int y, int next_x, int next_y){ // activate when player success moving
    Entity *tmp = STAGE[y][x];
    STAGE[y][x] = STAGE[next_y][next_x];
    STAGE[next_y][next_x] = tmp;
}
void Stage::undo(Player *user){ // Restore previous state
    if(stack.empty() == false){
        user->IncreaseStamina();
        StageNode tmp = stack.top();
        changeBoard(x, y, tmp.x, tmp.y);
        for(int i = 0; i < size; i++){ // Change STAGE with data in StageNode
            for(int j = 0; j < size; j++){
                STAGE[i][j]->SetSymbol(tmp.stage[i][j]);          
            }
        }
        x = tmp.x;
        y = tmp.y;
        stack.pop();
    }
}
void Stage::unlock(){ // Remove every lock
    for(int i = 1; i < size - 1; i++){
        for(int j = 1; j < size - 1; j++){
            if(STAGE[i][j]->GetSymbol() == 'L')
                STAGE[i][j]->SetSymbol(' ');
        }
    }
}
int Stage::play(Frame f, int stageFlag){ // Default Logic of game play, might be changed according to obstacles
    int clearFlag = 0; // if flag is 1 clear
    char encounter; // Entity that is which is on
    Player * user;
    string title[5] = {"Stage0", "Stage1", "Stage2", "Stage3", "Stage4"};
    while(true){
        user = dynamic_cast<Player*>(STAGE[y][x]);
        // refresh displayed screen
        system("cls");
        f.PrintTitle(12, title[stageFlag]);
        cout << endl;
        f.PrintStage(STAGE, size, user->GetStamina());
        cout << "Stamina : " << user->GetStamina() << endl;

        if(encounter == '@'){ // if reaching goal clear!
            clearFlag = 1;
            break;
        }

        int action = KeyListener::GetPlayerKey(); // get user action
        if(action == KeyListener::CTRL_Z){ // return to previous state if Ctrl + Z pressed
            undo(user);
            continue;
        }
        if(!user->CheckAlive()){ // if user try to move when stamina is 0 or less game over
            break;
        }
        // Change stage according to player's movement
        int next_x = x;
        int next_y = y;
        // Identity the object which player's gonna encounter
        if(action == KeyListener::UP) --next_y;
        else if(action == KeyListener::DOWN) ++next_y;
        else if(action == KeyListener::LEFT) --next_x;
        else if(action == KeyListener::RIGHT) ++next_x;
        encounter = STAGE[next_y][next_x]->GetSymbol();
        // Identify Action
        if(encounter == 'L' || encounter == '#' || (encounter == 'W' && user->GetStamina() % 2 == 0)){ // If player meets wall or try to enter disabled portal, no action performed
            // Action Failed
            continue;
        }
        else{ // Action performed
            stack.push(StageNode{STAGE, x, y});  // Before action save present state in stack
            user->DecreaseStamina();  // Every action cost stamina
            if(encounter == ' ' || encounter == '@' || encounter == 'K'){ // Player change position
                if(encounter == 'K'){ // If player get key, unlock all the locks
                    unlock();
                }
                STAGE[next_y][next_x]->SetSymbol(' ');
                changeBoard(x, y, next_x, next_y);
                x = next_x;
                y = next_y;
            }
            else if(encounter == 'B'){ // Break Obstacle
                STAGE[next_y][next_x]->SetSymbol(' ');
            }
            else if(encounter == 'O'){ // Kick Obstacle
                // position beyond 'O'
                int next_x2 = 2 * next_x - x;
                int next_y2 = 2 * next_y - y;
                if(STAGE[next_y2][next_x2]->GetSymbol() == ' '){ // Push Obstacle if space exist
                    changeBoard(next_x, next_y, next_x2, next_y2);
                }
            }
            else if(encounter == 'W'){ // Player Enter Portal and teleport
                warp(next_x, next_y);
            }
        }
    }
    return clearFlag; // 0 = fail, 1 = clear
}
