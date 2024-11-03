#include <conio.h>




// With this Function, get Key Input without Enter
// flag 0 = Horizontal Key Enable, flag 1 = Vertical Key Enable, flag 2 = Enable Both, else = only Enter
// return value: LEFT = 0, RIGHT = 1, UP = 3, DOWN = 4

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