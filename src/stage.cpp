/*
Some Stage Doesn't have some Obstacles
So checking Every obstacles for each stage might be useless
As a result, each stage got different logic
*/
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "keyEvent.h"

using namespace std;
// Stack Node for cancel with ctrl + z
typedef struct{
    char stage[12][12];
    int x = 0; 
    int y = 0;
    prevState next;
}prevState;

// Stage will return 0 = Lose, or 1 = win

//dummy stage for test
int stage0(){
    prevState stack;
    int remainder = 300;
    char stage[12][12];
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            stage[i][j] = ' ';
        }
    }
    for (int i = 0; i < 12; i++)
    {
        stage[i][0] = '#';
        stage[0][i] = '#';
        stage[i][11] = '#';
        stage[11][i] = '#';
    }
    stage[11][11] = '#';
    const char playerSymbol = 'P';
    // player always starts on 
    int player_x = 1;
    int player_y = 1;
    while(true){
        system("cls");
        stage[player_y][player_x] = playerSymbol;
        for (int i = 0; i < 12; i++){
            for (int j = 0; j < 12; j++){
                cout << stage[i][j];
            }
            cout << endl;
        }
        cout << "Stamina : " << remainder << endl;
        
        int move = getKey(2);
        /* Self Defined Direction Values
        LEFT = 0;
        RIGHT = 1;
        UP = 2;
        DOWN = 3;
        */
        if(move == 0){
            if(stage[player_y][player_x - 1] == ' '){
                stage[player_y][player_x] = ' ';
                stage[player_y][--player_x] = playerSymbol;
                --remainder;
            }
            else
                continue;
        }
        else if(move == 1){
            if(stage[player_y][player_x + 1] == ' '){
                stage[player_y][player_x] = ' ';
                stage[player_y][++player_x] = playerSymbol;
                --remainder;
            }
            else
                continue;
        }
        else if(move == 2){
            if(stage[player_y - 1][player_x] == ' '){
                stage[player_y][player_x] = ' ';
                stage[--player_y][player_x] = playerSymbol;
                --remainder;
            }
            else
                continue;
        }
        else if(move == 3){
            if(stage[player_y + 1][player_x ] == ' '){
                stage[player_y][player_x] = ' ';
                stage[++player_y][player_x] = playerSymbol;
                --remainder;
            }
            else
                continue;
        }
        else
            continue;

        if(remainder < 0)
            return 0;
        else continue;
    }
    
}

void add(prevState stack, char stage[12][12], int x, int y){
    prevState p;
    p.x = x;
    p.y = y;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            p.stage[i][j] = stage[i][j];
        }
    }
}
prevState cancel(prevState stack){
    if (stack.x != 0){
        return stack.next;
    }
}