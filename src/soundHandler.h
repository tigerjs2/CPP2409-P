// It wasn't planned might be eliminated if fail to implement
#pragma once
#include <cstdlib>
#include <mmsystem.h>  // 

class Audio{
    public:
        static void SelectSound();
        static void confirmSound();

        static void MoveSound();
        static void KickSound();
        static void BreakSound();
        static void WarpSound();
        static void UnlockSound();
        
        static void ClearSound();
        static void FailSound();
};