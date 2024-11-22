#include "portal.h"

Portal::Portal(int x, int y):Entity('W'){
    this->x = x;
    this->y = y;
}
void Portal::Connect(Portal *p){
    next_x = p->x;
    next_y = p->y;
}
int Portal::GetConnectedX(){ return next_x;}
int Portal::GetConnectedY(){ return next_y;}