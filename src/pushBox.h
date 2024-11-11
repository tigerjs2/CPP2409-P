#pragma once
#include "moveable.h"
// Since it's moveable object, pushable box will be class instance
// It will have similar logic to Player

class PushBox : public Moveable{     
    public:
        static const char ROCK = 'O'; // Symbol for this entity
        PushBox(int x, int y):Moveable(x, y){}
};