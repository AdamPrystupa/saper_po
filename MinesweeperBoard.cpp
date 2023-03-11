//
// Created by c on 3/8/23.
//
#include <iostream>
#include <cmath>
#include <random>
#include "MinesweeperBoard.h"


using std::cin;
using std::cout;
using std::endl;

MinesweeperBoard::MinesweeperBoard() {

    clearBoard();
    setTest();
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode){
    columns=width;
    rows=height;
    this->mode=mode;
    this->totalFields=columns*rows;
    MinesweeperBoard::clearBoard();

    if(mode == DEBUG) {       // Wygenerowanie min
        generateDebugMines();
    } else {
        generateRandomMines();
    }
}
/*Funkcja ustawiająca wszystkie wartości pól na false*/
void MinesweeperBoard::clearBoard(){
    for(int wiersz=0;wiersz<rows;wiersz++){
        for(int kolumna=0;kolumna<columns;kolumna++){
            board[wiersz][kolumna].hasFlag= false;
            board[wiersz][kolumna].hasMine= false;
            board[wiersz][kolumna].isRevealed= false;
        }
    }
}
/*Funkcja ustawiająca testowe pola gry*/
void MinesweeperBoard::setTest(){
    board[0][0].hasMine=true;
    board[1][1].isRevealed= true;
    board[0][2].hasMine=true;
    board[0][2].hasFlag=true;
}

/*Funkcja wyświetlająca pole gry*/
void MinesweeperBoard::debug_display() const {
    for(int kolumna=0;kolumna<columns;kolumna++)
        cout<<"     "<<kolumna;
    cout<<endl;
    for(int wiersz=0;wiersz<rows;wiersz++){
        cout<<wiersz;
        for(int kolumna=0;kolumna<columns;kolumna++){
            if (board[wiersz][kolumna].hasMine)
                cout<<" [M";
            else
                cout<<" [.";
            if (board[wiersz][kolumna].isRevealed)
                cout<<"o";
            else
                cout<<".";
            if (board[wiersz][kolumna].hasFlag)
                cout<<"f]";
            else
                cout<<".]";
        }
        cout<<endl;
    }
}
/*Funkcja ustawiająca miny w predefiniowany sposób*/
void MinesweeperBoard::generateDebugMines(){
    for(int kolumna=0; kolumna<columns; kolumna++) {
        for(int wiersz=0; wiersz<rows; wiersz++) {
            if(kolumna == wiersz || wiersz == 0 || ( wiersz % 2 == 0 && kolumna == 0)) {
                board[wiersz][kolumna].hasMine = true;
            }
        }
    }
}

/*Funkcja ustawiająca miny w losowy sposób*/
void MinesweeperBoard::generateRandomMines(){

    int wiersz;
    int kolumna;

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 9999);

    minedFields=std::ceil(totalFields*mode/10.0);
    cout<<minedFields<<endl;
    for(int tmp=0;tmp<minedFields;tmp++)
    {
        do {
            wiersz= dist(generator) % rows ;
            kolumna= dist(generator) % columns ;
        } while (board[wiersz][kolumna].hasMine);
        board[wiersz][kolumna].hasMine= true;

    }

}

