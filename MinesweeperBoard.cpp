//
// Created by c on 3/8/23.
//
#include <iostream>
#include "MinesweeperBoard.h"
#include <string>

using std::cin;
using std::cout;
using std::endl;

MinesweeperBoard::MinesweeperBoard() {
    width=5;
    height=7;
    clearBoard();
    setTest();
};

void MinesweeperBoard::clearBoard(){
    for(int wiersz=0;wiersz<height;wiersz++){
        for(int kolumna=0;kolumna<width;kolumna++){
            board[wiersz][kolumna].hasFlag= false;
            board[wiersz][kolumna].hasMine= false;
            board[wiersz][kolumna].isRevealed= false;
        }
    }
};

void MinesweeperBoard::setTest(){
    board[0][0].hasMine=true;
    board[1][1].isRevealed= true;
    board[0][2].hasMine=true;
    board[0][2].hasFlag=true;
};

void MinesweeperBoard::debug_display() const {
    for(int kolumna=0;kolumna<width;kolumna++)
        cout<<"     "<<kolumna;
    cout<<endl;
    for(int wiersz=0;wiersz<height;wiersz++){
        cout<<wiersz;
        for(int kolumna=0;kolumna<width;kolumna++){
            if (board[wiersz][kolumna].hasMine==true)
                cout<<" [M";
            else
                cout<<" [.";
            if (board[wiersz][kolumna].isRevealed==true)
                cout<<"o";
            else
                cout<<".";
            if (board[wiersz][kolumna].hasFlag==true)
                cout<<"f]";
            else
                cout<<".]";


        }
        cout<<endl;
    }
};

