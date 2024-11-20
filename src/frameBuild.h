#pragma once
#include <iostream>
#include <cstdlib>
#include "entity.h"

using namespace std;
// Class about displaying Pages
class Frame{
    public:
        void PrintTitle(int num, string name);
        void PrintLine(int num);
        void PrintConfirmAlert();
        void PrintOption(string name, bool selected, int num);
        void PrintButtonLine(int start, int selected);
        void PrintStage(Entity ***stage, int size, int stamina);
};