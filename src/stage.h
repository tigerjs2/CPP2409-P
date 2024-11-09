#pragma once
#include "player.h"
#include "frameBuild.h"

class Stage{
    private:
        static const int size = 12; // Every stage has 10 X 10 moveable size, edge is covered with walls
        char stage[size][size] = {' ', };
        void buildWall();
        void buildStage(int stageFlag);
        void buildDummyStage();
        void changeBoard(int action);
        Player user;
    public:
        Stage(int stageFlag);
        int play(Frame f, int stageFlag);        
};

int stage0();