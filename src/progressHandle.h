// this class is about progress saving
// If player clear stage for the first time the progress will be saved in outer file
// To prevent changing the file without playing game this class will encode & decode the file content
#pragma once
#include <fstream>
#include <cstdlib>
#include <string>
#include <windows.h>
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#include <tchar.h>
#include <iostream>
using namespace std;

class Progress {
    public:
        int Get();
        void Save(int opened);
        int Encode(int val);
        int Decode(int code);
};