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
        stack<StageNode> stack;
        // Player's initial location
        int x = 1;
        int y = 1;
        // Functions
        void buildSupport(int stamina, char stage[][size]);
        void buildStage(int stage_flag);
        // void buildDummyStage();  // Not needed anymore
        void changeBoard(int x, int y, int next_x, int next_y);
        void warp(int next_x, int next_y);
        void undo(Player *user);
        void unlock();
    public:
        Stage(int stage_flag);
        ~Stage();
        int play(Frame f, int stage_flag);       
};

