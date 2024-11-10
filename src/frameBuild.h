#pragma once
#include <iostream>
#include <windows.h>

using namespace std;
// Class about displaying Pages
class Frame{
    public:
        void printTitle(int num, string name);
        void printLine(int num);
        void printConfirmAlert();
        void printOption(string name, bool selected, int num);
        void printButtonLine(int start, int selected);
        void printStage(char board[][12], int size);
};