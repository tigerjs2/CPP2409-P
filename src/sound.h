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
        static void MoveFail();
        static void Kick();
        static void Break();
        static void Warp();
        static void Unlock();
        static void Clear();
        static void Fail();
        static void Back();
        static void Reset();
};