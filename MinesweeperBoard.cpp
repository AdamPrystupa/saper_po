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
    width=5;
    height=7;
    clearBoard();
    setTest();
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode){
    this->width=width;
    this->height=height;
    this->mode=mode;
    this->totalFields=width*height;
    MinesweeperBoard::clearBoard();

    if(mode == DEBUG) {       // Wygenerowanie min
        MinesweeperBoard::generateDebugMines();
    } else {
        MinesweeperBoard::generateRandomMines();
    }

    MinesweeperBoard::countMines(0,1);
}


/*Funkcja ustawiająca wszystkie wartości pól na false*/
void MinesweeperBoard::clearBoard(){
    for(int row=0;row<height;row++){
        for(int column=0;column<width;column++){
            board[row][column].hasFlag= false;
            board[row][column].hasMine= false;
            board[row][column].isRevealed= false;
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
    for(int column=0;column<width;column++)
        cout<<"     "<<column;
    cout<<endl;
    for(int row=0;row<height;row++){
        cout<<row;
        for(int column=0;column<width;column++){
            if (board[row][column].hasMine)
                cout<<" [M";
            else
                cout<<" [.";
            if (board[row][column].isRevealed)
                cout<<"o";
            else
                cout<<".";
            if (board[row][column].hasFlag)
                cout<<"f]";
            else
                cout<<".]";
        }
        cout<<endl;
    }
}
/*Funkcja ustawiająca miny w predefiniowany sposób*/
void MinesweeperBoard::generateDebugMines(){
    for(int column=0; column<width; column++) {
        for(int row=0; row<height; row++) {
            if(column == row || row == 0 || ( row % 2 == 0 && column == 0)) {
                board[row][column].hasMine = true;
            }
        }
    }
}

/*Funkcja ustawiająca miny w losowy sposób*/
void MinesweeperBoard::generateRandomMines(){

    int row;
    int column;

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 9999);

    mineCount=std::ceil(totalFields*mode/10.0);
    cout<<mineCount<<endl;
    for(int tmp=0;tmp<mineCount;tmp++)
    {
        do {
            row= dist(generator) % height ;
            column= dist(generator) % width ;
        } while (board[row][column].hasMine);
        board[row][column].hasMine= true;

    }

}

/*Funkcja zwraca szerokość planszy gry*/
int MinesweeperBoard::getBoardWidth() const
{
    return this->width;
}

/*Funkcja zwraca szerokość planszy gry*/
int MinesweeperBoard::getBoardHeight() const
{
    return this->height;
}

/*Funkcja zwraca szerokość planszy gry*/
int MinesweeperBoard::getMineCount() const
{
    return this->mineCount;
}

/*Funkcja sprawdza czy pole należy do planszy gry*/
bool MinesweeperBoard::belongToBoard(int row, int col) const
{
    if(col<0 || col>=width)
        return false;
    if(row<0 || row>=height)
        return false;

    return true;
}

// count mines around (row,col) position
// if the field at (row,col) was not revealed - return -1
// if either row or col is outside board      - return -1
// otherwise - return mine count around this field
// Examples for DEBUG layout on 10x10 board (assuming the field is already revealed)
// - countMines(1,0) should return 4
// - countMines(2,9) should return 0
// - countMines(2,1) should return 3
// - countMines(6,7) should return 2
int MinesweeperBoard::countMines(int row, int col) const
{
    int minesNearby=0;
    for(int rows=row-1;rows<=row+1;rows++)
    {
        for(int columns=col-1;columns<=col+1;columns++)
            {
                if (belongToBoard(columns,rows))
                {
                    if (board[rows][columns].hasMine)
                        minesNearby++;

                }
            }
    }
    cout<<minesNearby<<endl;
    return minesNearby;
}