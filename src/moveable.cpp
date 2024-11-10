#include "moveable.h"

Moveable::Moveable(int x, int y){
    setLocation(x, y);
}
void Moveable::move(int direction){
    if(direction == KeyListener::UP){ // move upper
        y--;
    }
    else if(direction == KeyListener::DOWN){ // move lower
        y++;
    }
    else if (direction == KeyListener::LEFT){ // move left
        x--;
    }
    else if (direction == KeyListener::RIGHT){ // move left
        x++;
    }
}
int Moveable::getX(){ return x; }
int Moveable::getY(){ return y; }
void Moveable::setLocation(int x, int y){
    this->x = x;
    this->y = y;
}
