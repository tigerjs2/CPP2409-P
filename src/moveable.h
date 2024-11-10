// After learning how to inherit class, Player and pushBox will extend this class
#include "keyEvent.h"

class Moveable{
    private:
        int x, y;
    public:
        Moveable(int x, int y);
        void move(int direction);
        int getX();
        int getY();
        void setLocation(int x, int y);
};