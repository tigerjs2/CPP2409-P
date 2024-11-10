#pragma once
#include "player.h"
#include "frameBuild.h"
#include <stack>

class StageNode{ // class for holding previous game state
    public:
        static const int size = 12;
        char stage[size][size];
        int x, y, hp;
        StageNode(char s[size][size], Player u);
};

class Stage{
    private:
        static const int size = 12; // Every stage has 10 X 10 moveable size, edge is covered with walls
        char stage[size][size];
        stack<StageNode> stack;
        Player user;
        // Functions
        void buildWall();
        void buildStage(int stageFlag);
        void buildDummyStage();
        void changeBoard(int action);
    public:
        Stage(int stageFlag);
        int play(Frame f, int stageFlag);       
};