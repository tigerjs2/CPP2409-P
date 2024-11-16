#pragma once
#include "frameBuild.h"
#include "player.h"
#include "keyEvent.h"


class StageNode{ // class for holding previous game state
    public:
        static const int size = 12;
};

class Stage{
    private:
        static const int size = 12; // Every stage has 10 X 10 moveable size, edge is covered with walls
        Entity ***STAGE;
        // Player's initial location
        int x = 1;
        int y = 1;
        // Functions
        void buildStage(int stageFlag);
        void buildDummyStage();
        void changeBoard(int x, int y, int next_x, int next_y);
    public:
        Stage(int stageFlag);
        ~Stage();
        int play(Frame f, int stageFlag);       
};