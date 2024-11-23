#include "progressHandle.h"

int Progress::Encode(int val) {
    return 0;
}

int Progress::Decode(int code) {
    return 0;
}

int Progress::Get() {
    ifstream f;
    f.open("save/savedat.dat");  // open progress information
    if(!f.is_open()) {  // if file doesn't exist
        system("mkdir save");  // mkdir
        system("cls");  // remove unwanted alert message
        ofstream f2;
        f2.open("save/savedat.dat");
        f2 << to_string(Encode(1));  // make new savedat.dat file
        f2.close();
        return 1;  // unlock first stage
    }
    else{
        string tmp;
        f >> tmp;
        f.close();
        int n = stoi(tmp);
        return Decode(n);  // decode and return stage progress
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