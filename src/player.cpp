#include "player.h"

bool Player::checkAlive(){ // check remaining stamina and if lower than 0 return false(dead)
    if(stamina <= 0){
        return false;
    }
    else
        return true;
}
int Player::getStamina() { return stamina;}
void Player::setStamina(int n){ stamina = n;}

void Player::decreaseStamina(){ stamina--; } // might be used if any harmful obstacles are designed, at this point only for movement