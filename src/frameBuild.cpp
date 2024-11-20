#include "frameBuild.h"

void Frame::PrintLine(int num){ // print '=' 'num' times
    for(int i = 0; i < num; i++)
        cout << "=";
    cout << endl;
}
void Frame::PrintTitle(int num, string name){ // Print Page Title
    PrintLine(num);
    cout.width((num + name.length()) / 2);
    cout << name << endl;
    PrintLine(num);
}
void Frame::PrintConfirmAlert(){ // Notify user to press Enter
    cout << endl << endl << "Enter : Confirm";
}
void Frame::PrintOption(string s, bool selected, int num){ // Print Option line
    cout << endl;
    cout.width(num);
    if (selected == true){
        cout << "* " << s << endl;
    }
    else if(selected == false){
        cout << "  " << s << endl;
    }
}

void Frame::PrintButtonLine(int start, int selected){ // Print two button on stage selection page
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout.width(8);
        if(start + i == selected) // print * for selected option
         cout << "* ";
        else
            cout << "";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout.width(5);
        cout << "" << "---";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout.width(5);
        cout << "" << "|" << start + i << "|";
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout.width(5);
        cout << "" << "---" ;
    }
    cout << endl;   
}

void Frame::PrintStage(Entity ***stage, int size, int stamina){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(stamina % 2 == 1 && stage[i][j]->getSymbol() == 'W') // later change this with Warp->isActivate
                cout << ' ';
            else
                cout << stage[i][j]->getSymbol();
        }
        cout << endl;
    }
}