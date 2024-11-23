#include "progressHandle.h"

int Progress::Encode(int val) {

}

int Progress::Decode(int code) {

}

int Progress::Get() {
    fstream f;
    system("mkdir save");
    f.open("save/savedat.dat");
    if(!f.is_open()) {
        f << to_string(Encode(1));
        f.close();
        return 1;
    }
    else{
        string tmp;
        f >> tmp;
        f.close();
        int n = stoi(tmp);
        return Decode(n);
    }
}

void Progress::Save(int opened) {
    int n = Decode(opened);
    fstream f;
    f.open("save/savedat.dat");
    f.clear();
    f << to_string(n);
    f.close();
}