#pragma once
#include <conio.h>
// this class is interface of key event handling
class KeyListener{
    public:
        // ASCII Code of Direction Keys
        // Direction code return "224" and Direction ASCII code but while reading other lines 224 disappear
        static const int UP = 72;
        static const int DOWN = 80;
        static const int LEFT = 75;
        static const int RIGHT = 77;
        static const int ENTER = 13; // ASCII Code of Enter
        static const int CTRL_Z = 26; // Ctrl + Z value

        static int GetPlayerKey(); // method for game play
        static int TitleKey(); // method for option selection in Main page
        static int StageSelectionKey(); // for stage selection page
        static int EnableEnter();
};