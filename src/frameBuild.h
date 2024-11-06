#include <iostream>
#include <windows.h>

using namespace std;
// Class about displaying Pages
class Frame{
    public:
        // Sharing
        void printTitle(int num, string name);
        void printLine(int num);
        void printConfirmAlert();
        // Main Page
        void printOption(string name, bool selected, int num);
        // for Stage Selection 
        void printButtonLine(int start, int selected);
        // for game play
        void printStage(char board[][22], int size);
};
