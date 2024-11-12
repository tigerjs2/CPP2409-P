// After learning how to inherit class, Player and PushBox will extend this class
// If I change stage map into Entity Array this class might be deleted
#include "keyEvent.h"
#include "entity.h"

class Moveable : public Entity{
    private:
        int x, y;
    public:
        Moveable(){ x = 1; y = 1;};
        Moveable(int x, int y, char s);
        void move(int direction);
        int getX();
        int getY();
        void setLocation(int x, int y);
};