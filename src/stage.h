#pragma once
#include "frameBuild.h"
#include "player.h"
#include "portal.h"
#include "keyEvent.h"
#include "node.h"
#include <stack>

class Stage{
    private:
        static const int size = 12; // Every stage has 10 X 10 moveable size, edge is covered with walls
        Entity ***STAGE;
        // Player's initial location
        int x = 1;
        int y = 1;
        // Functions
        void buildSupport(int stamina, char stage[][size]);
        void buildStage(int stageFlag);
        void buildDummyStage();
        void changeBoard(int x, int y, int next_x, int next_y);
        void warp(int next_x, int next_y);
        stack<StageNode> stack;
    public:
        Stage(int stageFlag);
        ~Stage();
        int play(Frame f, int stageFlag);       
};

