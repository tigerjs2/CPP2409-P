#include "player.h"

// Player change position according to instruction
void Player::move(int direction){
    if(direction == 0){ // move upper
        y--;
    }
    else if(direction == 1){ // move lower
        y++;
    }
    else if (direction == 2){ // move left
        x--;
    }
    else if (direction == 3){ // move left
        x++;
    }
}
// check remaining stamina and if lower than 0 return false(dead)
bool Player::checkAlive(){
    if(stamina < 0){
        return false;
    }
    else
        return true;
}
