#include "progressHandle.h"

int Progress::Encode(int val) {
    return (val + 3) * 9;
}

int Progress::Decode(int code) {
    return code / 9 - 3;
}

int Progress::Get() {
    LPCTSTR save = _T("save");
    LPCTSTR save_dat = _T("save\\savedat.dat");
    ifstream f;
    f.open("save/savedat.dat");  // open progress information
    if(!PathFileExists(save)) {  // if file doesn't exist
        system("mkdir save");  // mkdir
    }
    if(!PathFileExists(save_dat)){  // if file doesn't exist create new save file
        ofstream f2;
        f2.open("save/savedat.dat");
        f2 << to_string(Encode(1));  // make new savedat.dat file
        f2.close();
        return 1;  // unlock first stage
    }
    else{  // Load stage progress
        string tmp;
        f >> tmp;
        f.close();
        int n = stoi(tmp);
        return Decode(n);  // decode and return stage progress
    }
}

void Progress::Save(int opened) {
    int n = Encode(opened);
    fstream f;
    f.open("save/savedat.dat");
    f.clear();
    f << to_string(n);
    f.close();
}