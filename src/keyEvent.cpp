#include "keyEvent.h"

int KeyListener::titleKey() { // Enable Enter vertical direction key, and 'w', 's'
    while(1){
        // get key input until meet up, down or ENTER
        int move = _getch();
        switch(move){
            case ENTER:
            case UP:
            case DOWN:
                return move;
            case 'w': // Handle alphabet as direction key
                return UP;
            case 's':
                return DOWN;                
        }
    }
    
}
int KeyListener::stageSelectionKey() { // Enable Enter, 4 Direction
    while(1){
        // get key input until get 4 direction or Enter
        int move = _getch();
        switch(move){
            case ENTER:
            case LEFT:
            case RIGHT:
            case UP:
            case DOWN:
                return move;
            case 'w':
                return UP;
            case 'a':
                return LEFT;
            case 'd':
                return RIGHT;
            case 's':
                return DOWN;
                
        }
    }
    
}
int KeyListener::getPlayerKey() { // 4 Direction, Ctrl + Z
    while(1){
        // get key input until meet up, down or ENTER
        int move = _getch();
        switch(move){
            case LEFT:
            case RIGHT:
            case UP:
            case DOWN:
            case CTRL_Z:
                return move;
            case 'w':
                return UP;
            case 'a':
                return LEFT;
            case 'd':
                return RIGHT;
            case 's':
                return DOWN;
            
        }
    }
    
}
int KeyListener::enableEnter(){ // only Enter Allowed
    while(1){
        int move = _getch();
        if (move == ENTER) return move;
    }
}
