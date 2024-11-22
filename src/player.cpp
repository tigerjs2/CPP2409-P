#include "player.h"

bool Player::CheckAlive() { // check remaining stamina and if lower than 0 return false(dead)
    if(stamina <= 0)
        return false;
    else
        return true;
}
int Player::GetStamina() { return stamina; }
void Player::IncreaseStamina() { stamina++; }
void Player::DecreaseStamina() { stamina--; } // might be used if any harmful obstacles are designed, at this point only for movement