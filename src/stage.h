class Stage{
    private:
        static const int size = 22; // Every stage has 20 X 20 moveable size, edge is covered with walls
        char stage[size][size] = {" ", };
        void buildStage(int stageFlag);
    public:
        Stage(int stageFlag);
        
};

int stage0();