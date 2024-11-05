#include "keyEvent.h"

int KeyListener::titleKey() { // Enable Enter vertical direction key, and 'w', 's'
    int move;
    while(1){
        // get key input until meet up, down or ENTER
        move = _getch();
        switch(move){
            case ENTER:
            case UP:
            case DOWN:
            case 'w':
            case 's':
                break;
        }
    }
    return move;
}
int KeyListener::stageSelectionKey() { // Enable Enter, 4 Direction
    int move;
    while(1){
        // get key input until get 4 direction or Enter
        move = _getch();
        switch(move){
            case ENTER:
            case LEFT:
            case RIGHT:
            case UP:
            case DOWN:
            case 'w':
            case 'a':
            case 'd':
            case 's':
                break;
        }
    }
    return move;
}
int KeyListener::getPlayerKey() { // 4 Direction, Ctrl + Z
    int move;
    while(1){
        // get key input until meet up, down or ENTER
        move = _getch();
        switch(move){
            case LEFT:
            case RIGHT:
            case UP:
            case DOWN:
            case 'w':
            case 'a':
            case 'd':
            case 's':
            case CTRL_Z:
                break;
        }
    }
    return move;
}

// Under this will be deleted after Trimming code
int getKey(int flag){
    // ASCII Code of Direction Keys
    // Direction code return "224" and Direction ASCII code but while reading other lines 224 disappear
    const int UP = 72;
    const int DOWN = 80;
    const int LEFT = 75;
    const int RIGHT = 77;
    
    // ASCII Code of Enter
    const int ENTER = 13;

    int returnValue = -1;
    // Loop until Input Enabled key or Enter
    while(returnValue == -1){
        int move = _getch();
        // If Horizontal Key Input Enabled
        if(move == ENTER)
            return ENTER;
        if(flag == 0 || flag == 2){
            if(move == 'a' || move == 'A' || move == LEFT){
                returnValue = 0;
            }
            else if(move == 'd' || move == 'D'|| move == RIGHT){
                returnValue = 1;
            }
            
        }
        // If Vertical Key Input Enabled
        if(flag == 1 || flag == 2){
            if(move == 'w' || move == 'W' || move == UP){
                returnValue = 2;
            }
            else if(move == 's' || move == 'S'|| move == DOWN){
                returnValue = 3;
            }
            
        }
    }
    
    return returnValue;
}