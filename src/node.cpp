#include "node.h"

StageNode::StageNode(Entity ***stage, int x, int y) { 
    this->x = x;
    this->y = y;
    // deepcopy stage
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            this->stage[i][j] = stage[i][j]->GetSymbol();
        }
    }
}