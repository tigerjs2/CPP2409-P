#include "player.h"

void Player::move(int direction){ // Player change position according to instruction
    if(direction == KeyListener::CTRL_Z){
        // After Making stack make logic
        return;
    }
    // decrease 1 stamina when player move
    if(direction == KeyListener::UP){ // move upper
        y--;
    }
    else if(direction == KeyListener::DOWN){ // move lower
        y++;
    }
    else if (direction == KeyListener::LEFT){ // move left
        x--;
    }
    else if (direction == KeyListener::RIGHT){ // move left
        x++;
    }
}

bool Player::checkAlive(){ // check remaining stamina and if lower than 0 return false(dead)
    if(stamina <= 0){
        return false;
    }
    else
        return true;
}
int Player::getStamina() { return stamina;}
int Player::getX() { return x; }
int Player::getY() { return y; }
void Player::decreaseStamina(){ stamina--; } // might be used if any harmful obstacles are designed, at this point only for movement