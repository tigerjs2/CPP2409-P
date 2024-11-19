// It wasn't planned might be eliminated if fail to implement
#pragma once
#include <cstdlib>

class Audio{
    public:
        static void selectSound();
        static void confirmSound();

        static void moveSound();
        static void kickSound();
        static void breakSound();
        static void warpSound();
        static void unlockSound();
        
        static void clearSound();
        static void failSound();
};