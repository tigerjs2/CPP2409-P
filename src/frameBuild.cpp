#include "frameBuild.h"

void Frame::printLine(int num){ // print '=' 'num' times
    for(int i = 0; i < num; i++)
        cout << "=";
    cout << endl;
}
void Frame::printTitle(int num, string name){ // Print Page Title
    printLine(num);
    cout.width((num + name.length()) / 2);
    cout << name << endl;
    printLine(num);
}
void Frame::printConfirmAlert(){ // Notify user to press Enter
    cout << endl << endl << "Enter : Confirm";
}
void Frame::printOption(string s, bool selected, int num){ // Print Option line
    cout << endl;
    cout.width(num);
    if (selected == true){
        cout << "* " << s << endl;
    }
    else if(selected == false){
        cout << "  " << s << endl;
    }
}

void Frame::printButtonLine(int start, int selected){ // Print two button on stage selection page
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

void Frame::printStage(char board[][12], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}