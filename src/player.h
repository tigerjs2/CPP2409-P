class Player{
    private:
        // initial position of player is fixed
        int x = 1;
        int y = 1;
        int stamina; // Can move until 0, different value for each stage
    public:
        Player(int s){ stamina = s; }
        void move(int direction); // change position according to direction flag
        bool checkAlive(); // check remaining stamina
};