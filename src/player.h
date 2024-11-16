#pragma once
#include "entity.h"

class Player : public Entity{
    private:
        // initial position of player is fixed
        int x = 1;
        int y = 1;
        int stamina; // Can move until 0, different value for each stage
    public:
        Player(){ stamina = 0; } // Default for make at Least Trash Instance
        Player(int s):Entity('P'){ stamina = s; }
        bool checkAlive(); // check remaining stamina
        int getStamina();
        void setStamina(int n);
        void decreaseStamina();
};