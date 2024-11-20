#pragma once
#include "player.h"

class StageNode { // class for holding previous game state
    public:
        static const int size = 12;
        char stage[size][size];
        int x;
        int y;
        StageNode();
        StageNode(Entity ***stage, int x, int y);
};