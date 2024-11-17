#pragma once
#include "entity.h"

class Portal:public Entity{
    private:
        int x, y; // own location
        int next_x, next_y; // connected portal location
        bool activate = true; // activate when remaining stamina is odd number
    public:
        Portal(int x, int y);
        void connect(Portal *p);
        bool isActivate();
        void toggle();
};