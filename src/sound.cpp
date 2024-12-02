#include "sound.h"

void Sound::Select(){  // When user change option of something
    PlaySound(TEXT("sound/select.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void Sound::Confirm(){  // When user confirm something with ENTER
    PlaySound(TEXT("sound/confirm.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(500);
}
void Sound::Move(){  // When Player move on stage
    PlaySound(TEXT("sound/move.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(100);
}
void Sound::MoveFail(){  // When Player encounter wall
    PlaySound(TEXT("sound/moveFail.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(100);
}
void Sound::Kick(){  // When Player kick obstacle
    PlaySound(TEXT("sound/kick.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(100);
}
void Sound::Break(){  // When Player break obstacle
    PlaySound(TEXT("sound/select.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(100);
}
void Sound::Warp(){  // When Player enter portal
    PlaySound(TEXT("sound/warp.wav"), 0, SND_FILENAME | SND_ASYNC);
    Sleep(100);
}
void Sound::Unlock(){  // When Player get key
    PlaySound(TEXT("sound/unlock.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void Sound::Clear(){  // When Player clear the stage
    PlaySound(TEXT("sound/clear.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void Sound::Fail(){  // When Player fail the stage
    PlaySound(TEXT("sound/fail.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void Sound::Back(){  // When Player drop the stage
    PlaySound(TEXT("sound/back.wav"), 0, SND_FILENAME | SND_ASYNC);
}
void Sound::Reset(){  // When Player restart the stage
    PlaySound(TEXT("sound/reset.wav"), 0, SND_FILENAME | SND_ASYNC);
}