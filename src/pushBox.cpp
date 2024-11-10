#include "pushBox.h"

PushBox::PushBox(int x, int y){
    setLocation(x, y);
}
void PushBox::move(int direction){
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
int PushBox::getX(){ return x; }
int PushBox::getY(){ return y; }
void PushBox::setLocation(int x, int y){
    this->x = x;
    this->y = y;
}
