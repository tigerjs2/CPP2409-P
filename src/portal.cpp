#include "portal.h"

Portal::Portal(int x, int y):Entity('W'){
    this->x = x;
    this->y = y;
}
void Portal::connect(Portal *p){
    next_x = p->x;
    next_y = p->y;
}
bool Portal::isActivate(){
    return activate;
}
void Portal::toggle(){
    activate = !activate;
}