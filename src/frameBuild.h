#include <iostream>
# include <windows.h>
using namespace std;
// Class about displaying Pages
class Frame{

    public:
        // Sharing
        void printTitle(int num);
        void printLine(int num);
        void printConfirmAlert(int num);
        // title
        void printOption(string name, bool selected);
        // for Stage Selection 
        void printButtonLine(int start, int stageFlag);
}
