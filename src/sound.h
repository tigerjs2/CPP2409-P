#pragma once
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

// Add Sonud Effect and Delay
class Sound {
    public:
        static void Select();
        static void Confirm();
        static void Move();
        static void Kick();
        static void Break();
        static void Warp();
        static void Unlock();
};