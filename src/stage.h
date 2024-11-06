#include "player.h"
#include "frameBuild.h"

class Stage{
    private:
        static const int size = 22; // Every stage has 20 X 20 moveable size, edge is covered with walls
        char stage[size][size] = {' ', };
        void buildStage(int stageFlag);
        void buildDummyStage();
        void changeBoard(int action);
        Player user;
    public:
        Stage(int user_stamina);
        int play(Frame f);        
};

int stage0();