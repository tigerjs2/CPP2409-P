#pragma once
#include "frameBuild.h"
#include "player.h"
#include "portal.h"
#include "keyEvent.h"
#include "node.h"
#include <stack>

class Stage{
    private:
        static const int SIZE = 12; // Every stage has 10 X 10 moveable size, edge is covered with walls
        Entity ***stage;
        stack<StageNode> stack;
        // Player's initial location
        int x = 1;
        int y = 1;
        // Functions
        void BuildSupport(int stamina, char stage[][SIZE]);
        void BuildStage(int stage_flag);
        // void buildDummyStage();  // Not needed anymore
        void ChangeBoard(int x, int y, int next_x, int next_y);
        void Warp(int next_x, int next_y);
        void Undo(Player *user);
        void Unlock();
    public:
        Stage(int stage_flag);
        ~Stage();
        int Play(Frame f, int stage_flag);       
};

