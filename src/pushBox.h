#pragma once
#include "keyEvent.h"
// Since it's moveable object, pushable box will be class instance
// It will have similar logic to Player

class PushBox{
    private:
        int x, y;
    public:
        static const char PUSH = 'O'; // Symbol for this entity
        PushBox(int x, int y);
        void move(int direction);
        int getX();
        int getY();
        void setLocation(int x, int y);
};