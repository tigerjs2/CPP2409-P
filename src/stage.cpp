#include "stage.h"
using namespace std;

Stage::~Stage(){  // Stage was allocated Dynamically
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            delete stage[i][j];
        }
        delete [] stage[i];
    }
    delete [] stage;
}
void Stage::BuildSupport(int stamina, char stage[][SIZE]) {  // Supporter of BuildStage Function
    Portal *p = nullptr;
    for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++)
                if(stage[i][j] == 'P')  // allocate Player
                    this->stage[i][j] = new Player{stamina};
                else if(stage[i][j] == 'W'){  // allocate Warp Portal
                    if(p == nullptr){  // First Portal Created
                        p = new Portal{j, i};
                        this->stage[i][j] = p;
                    }
                    else{  // Second Portal Created
                        Portal *q = new Portal(j, i);
                        // Connect portals
                        p->Connect(q);
                        q->Connect(p);
                        this->stage[i][j] = q;
                    }
                }
                else
                    this->stage[i][j] = new Entity{stage[i][j]};
    }
}
void Stage::BuildStage(int stage_flag){ // Load stage according to flag
    // Build Stage with Dynamic Allocation
    // since entities position has no pattern, better type whole stage
    stage = new Entity**[SIZE];
    for(int i = 0; i < SIZE; i++){ 
        stage[i] = new Entity*[SIZE];
    }
    if (stage_flag == 1){ // Obstacle - Wall only
        char stage1[SIZE][SIZE] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
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
        BuildSupport(35, stage1);
    }
    else if(stage_flag == 2){ // Obstacle - Wall, Breakable Box, and Pushable Box
        char stage2[SIZE][SIZE] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
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
        BuildSupport(35, stage2);
    }
    else if(stage_flag == 3){ // Obstacle - Wall, Breakable Box, Pushable Box, and Warp Portal
        char stage3[SIZE][SIZE] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
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
        BuildSupport(30, stage3);
    }
    else if(stage_flag == 4){
        char stage4[SIZE][SIZE] = {{'#','#','#','#','#','#','#','#','#','#','#','#'},
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
        BuildSupport(36, stage4);
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

Stage::Stage(int stage_flag){ // according to flag, build different stage map
    BuildStage(stage_flag);
};

// About GamePlay
void Stage::Warp(int next_x, int next_y){ // When player enter Activated portal player warp and portal vanish
    Portal *p = dynamic_cast<Portal*>(stage[next_y][next_x]);  // Entered Portal
    // Player warp
    ChangeBoard(x, y, p->GetConnectedX(), p->GetConnectedY());
    // Portal Disappear
    stage[y][x]->SetSymbol(' ');
    p->SetSymbol(' ');
    // Update player's location
    x = p->GetConnectedX();
    y = p->GetConnectedY();
}
void Stage::ChangeBoard(int x, int y, int next_x, int next_y){ // activate when player success moving
    Entity *tmp = stage[y][x];
    stage[y][x] = stage[next_y][next_x];
    stage[next_y][next_x] = tmp;
}
void Stage::Undo(Player *user){ // Restore previous state
    if(stack.empty() == false){
        user->IncreaseStamina();
        StageNode tmp = stack.top();
        ChangeBoard(x, y, tmp.x, tmp.y);
        for(int i = 0; i < SIZE; i++){ // Change STAGE with data in StageNode
            for(int j = 0; j < SIZE; j++){
                stage[i][j]->SetSymbol(tmp.stage[i][j]);          
            }
        }
        x = tmp.x;
        y = tmp.y;
        stack.pop();
    }
}
void Stage::Unlock(){ // Remove every lock
    for(int i = 1; i < SIZE - 1; i++){
        for(int j = 1; j < SIZE - 1; j++){
            if(stage[i][j]->GetSymbol() == 'L')
                stage[i][j]->SetSymbol(' ');
        }
    }
}
int Stage::Play(Frame f, int stage_flag){ // Default Logic of game play, might be changed according to obstacles
    int clear_flag = 0; // if flag is 1 clear
    char encounter; // Entity that is which is on
    Player * user;
    string title[5] = {"Stage0", "Stage1", "Stage2", "Stage3", "Stage4"};
    while(true){
        user = dynamic_cast<Player*>(stage[y][x]);
        // refresh displayed screen
        system("cls");
        f.PrintTitle(12, title[stage_flag]);
        cout << endl;
        f.PrintStage(stage, SIZE, user->GetStamina());
        cout << "Stamina : " << user->GetStamina() << endl;
        cout << endl << "Ctrl + z : Undo";
        cout << endl << "r : Reset Stage";
        cout << endl << "b : Back to Selection";
        if(encounter == '@'){ // if reaching goal clear!
            clear_flag = 1;
            break;
        }

        int action = KeyListener::GetPlayerKey(); // get user action
        if(action == KeyListener::CTRL_Z){ // return to previous state if Ctrl + Z pressed
            Undo(user);
            continue;
        }
        else if(action == 'r') { // restart this stage
            clear_flag = 2;
            break;
        }
        else if(action == 'b') { // back to stage selection
            clear_flag = 3;
            break;
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
        encounter = stage[next_y][next_x]->GetSymbol();
        // Identify Action
        if(encounter == 'L' || encounter == '#' || (encounter == 'W' && user->GetStamina() % 2 == 0)){ // If player meets wall or try to enter disabled portal, no action performed
            // Action Failed
            continue;
        }
        else{ // Action performed
            stack.push(StageNode{stage, x, y});  // Before action save present state in stack
            user->DecreaseStamina();  // Every action cost stamina
            if(encounter == ' ' || encounter == '@' || encounter == 'K'){ // Player change position
                if(encounter == 'K'){ // If player get key, unlock all the locks
                    Unlock();
                }
                stage[next_y][next_x]->SetSymbol(' ');
                ChangeBoard(x, y, next_x, next_y);
                x = next_x;
                y = next_y;
            }
            else if(encounter == 'B'){ // Break Obstacle
                stage[next_y][next_x]->SetSymbol(' ');
            }
            else if(encounter == 'O'){ // Kick Obstacle
                // position beyond 'O'
                int next_x2 = 2 * next_x - x;
                int next_y2 = 2 * next_y - y;
                if(stage[next_y2][next_x2]->GetSymbol() == ' '){ // Push Obstacle if space exist
                    ChangeBoard(next_x, next_y, next_x2, next_y2);
                }
            }
            else if(encounter == 'W'){ // Player Enter Portal and teleport
                Warp(next_x, next_y);
            }
        }
    }
    return clear_flag; // 0 = fail, 1 = clear, 2 = restart stage, 3 = back to stage selection
}
