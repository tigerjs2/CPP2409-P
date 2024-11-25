#include "sound.h"

void Sound::Select(){
    PlaySound(TEXT("sound/select.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(500);
}
void Sound::Confirm(){
    PlaySound(TEXT("sound/confirm.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(1500);
}
void Sound::Move(){
    PlaySound(TEXT("sound/move.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(500);
}
void Sound::Kick(){
    PlaySound(TEXT("sound/kick.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(500);
}
void Sound::Break(){
    PlaySound(TEXT("sound/select.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(500);
}
void Sound::Warp(){
    PlaySound(TEXT("sound/warp.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(1000);
}
void Sound::Unlock(){
    PlaySound(TEXT("sound/unlock.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(500);
}