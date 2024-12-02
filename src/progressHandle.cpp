#include "progressHandle.h"

int Progress::Encode(int val) {
    return (val + 3) * 9;
}

int Progress::Decode(int code) {
    return code / 9 - 3;
}

int Progress::Get() {  // Get Previous Progress
    // Relative Path of File and Directory
    LPCTSTR save = _T("save");
    LPCTSTR save_dat = _T("save\\savedat.dat");
    ifstream f{"save/savedat.dat"};  // open progress information
    if(!PathFileExists(save)) {  // if file doesn't exist
        system("mkdir save");  // mkdir
    }
    if(!PathFileExists(save_dat)){  // if file doesn't exist create new save file
        ofstream f2;
        if(!f2){  // critical error
            system("cls");
            cerr << "ERROR!! Fail to Save Data. Program Terminate in 3 seconds" << endl;
            Sleep(3000);
            exit(1);
        }
        f2.open("save/savedat.dat");
        f2 << Encode(1);  // make new savedat.dat file
        f2.close();
        return 1;  // unlock first stage
    }
    else{  // Load stage progress
        if(!f){  // critical error
            system("cls");
            cerr << "ERROR!! Fail to Save Data. Program Terminate in 3 seconds" << endl;
            Sleep(3000);
            exit(1);
        }
        int tmp;
        f >> tmp;
        f.close();
        int n = tmp;
        return Decode(n);  // decode and return stage progress
    }
}

void Progress::Save(int opened) {  // Save clear progress
    int n = Encode(opened);  // Encode opened
    ofstream f{"save/savedat.dat"};
    if(!f){  // critical error
        system("cls");
        cerr << "ERROR!! Fail to Save Data. Program Terminate in 3 seconds" << endl;
        Sleep(3000);
        exit(1);
    }
    f << n;  // Save encoded data
    f.close();
}