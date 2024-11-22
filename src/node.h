#pragma once
#include "player.h"

class StageNode { // class for holding previous game state
    public:
        static const int SIZE = 12;
        char stage[SIZE][SIZE];
        int x;
        int y;
        StageNode();
        StageNode(Entity ***stage, int x, int y);
};