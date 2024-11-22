#pragma once
#include "entity.h"

class Portal:public Entity{
    private:
        int x, y; // own location
        int next_x, next_y; // connected portal location
    public:
        Portal(int x, int y);
        void Connect(Portal *p);
        int GetConnectedX();
        int GetConnectedY();
};