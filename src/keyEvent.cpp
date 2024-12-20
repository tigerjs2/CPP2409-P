#include "keyEvent.h"

int KeyListener::TitleKey() { // Enable Enter vertical direction key, and 'w', 's'
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
int KeyListener::StageSelectionKey() { // Enable Enter, 4 Direction
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
int KeyListener::GetPlayerKey() { // 4 Direction, Ctrl + Z, 'b', 'r'
    while(1){
        // get key input until meet up, down or ENTER
        int move = _getch();
        switch(move){
            case LEFT:
            case RIGHT:
            case UP:
            case DOWN:
            case CTRL_Z:
            case 'b':
            case 'r':
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
int KeyListener::EnableEnter() { // only Enter Allowed
    while(1) {
        int move = _getch();
        if (move == ENTER) return move;
    }
}
