#include "frameBuild.h"

void Frame::printLine(int num){ // print '=' 'num' times
    for(int i = 0; i < num; i++)
        cout << "=";
    cout << endl;
}
void Frame::printConfirmAlert(){ // Notify user to press Enter
    cout << "Enter : Confirm";
}
void Frame::printOption(string s, bool selected){ // Print Option line on Main Page
    cout << endl;
    cout.width(7);
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