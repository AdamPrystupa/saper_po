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
    this->moveCount=0;
    MinesweeperBoard::clearBoard();

    if(mode == DEBUG) {       // mine generating
        MinesweeperBoard::generateDebugMines();
    } else {
        MinesweeperBoard::generateRandomMines();
    }
    this->state=RUNNING;

}


//function that sets all field values to false
void MinesweeperBoard::clearBoard(){
    for(int row=0;row<height;row++){
        for(int column=0;column<width;column++){
            board[row][column].hasFlag= false;
            board[row][column].hasMine= false;
            board[row][column].isRevealed= false;
        }
    }
}
//function that sets the test playing fields
void MinesweeperBoard::setTest(){
    board[0][0].hasMine=true;
    board[1][1].isRevealed= true;
    board[0][2].hasMine=true;
    board[0][2].hasFlag=true;
}

//function that displays the playing field
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

//function that places mines in a predefined way
void MinesweeperBoard::generateDebugMines(){
    for(int column=0; column<width; column++) {
        for(int row=0; row<height; row++) {
            if(column == row || row == 0 || ( row % 2 == 0 && column == 0)) {
                board[row][column].hasMine = true;
                mineCount++;
            }
        }
    }
}

//function that places mines in a random way
void MinesweeperBoard::generateRandomMines(){

    int row;
    int column;

    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 9999);

    mineCount=std::ceil(totalFields*mode/10.0);

    for(int tmp=0;tmp<mineCount;tmp++)
    {
        do {
            row= dist(generator) % height ;
            column= dist(generator) % width ;
        } while (board[row][column].hasMine);
        board[row][column].hasMine= true;

    }

}
//function moves the mine to a different place
void MinesweeperBoard::moveMine(int row, int col)
{
    if(!moveCount>1);
    std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 9999);
    int rows;
    int columns;
    do {
        rows= dist(generator) % height ;
        columns= dist(generator) % width ;
    } while (board[rows][columns].hasMine);
    board[rows][columns].hasMine= true;
    board[row][col].hasMine=false;
}


//function returns the width of the game board
int MinesweeperBoard::getBoardWidth() const
{
    return this->width;
}

//function returns the width of the game board
int MinesweeperBoard::getBoardHeight() const
{
    return this->height;
}

//function returns the width of the game board
int MinesweeperBoard::getMineCount() const
{
    return this->mineCount;
}

//function checks whether the field belongs to the game board
bool MinesweeperBoard::belongToBoard(int row, int col) const
{
    if(col<0 || col>=getBoardWidth())
        return false;
    if(row<0 || row>=getBoardHeight())
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
    if(!isRevealed(row, col))
        return -1;
    if(!belongToBoard(row,col))
        return -1;
    for(int rows=row-1;rows<=row+1;rows++)
    {
        for(int columns=col-1;columns<=col+1;columns++)
        {
            if (belongToBoard(rows,columns))
            {
                if (board[rows][columns].hasMine)
                    minesNearby++;

            }
        }
    }
    return minesNearby;
}

// return true if the field at (row,col) position was marked with flag
// return false if any of the following is true:
// - row or col is outside board
// - there is no flag on the field
// - field was already revealed
bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if(!belongToBoard(row,col))
        return false;
    if(isRevealed(row,col))
        return false;
    if(!board[row][col].hasFlag)
        return false;
    return true;
}

bool MinesweeperBoard::hasMine(int row, int col) const
{
    if(!belongToBoard(row,col))
        return false;
    if(isRevealed(row,col))
        return false;
    if(!board[row][col].hasMine)
        return false;
    return true;
}

// if the field at (row,col) was not revealed - change flag status for this field
// Do nothing if any of the following is true
// - field was already revealed
// - either row or col is outside board
// - game is already finished
void MinesweeperBoard::toggleFlag(int row, int col)
{
    moveCount++;
    if(!belongToBoard(row,col)) return;
    if(isRevealed(row,col)) return;
    if(this->state!=RUNNING) return;

    if(!isRevealed(row,col)) {
        if (board[row][col].hasFlag)
            board[row][col].hasFlag = false;
        else
            board[row][col].hasFlag = true;
    }


}

// try to reveal the field at (row,col)
// Do nothing if any of the following is true
// - field was already revealed
// - either row or col is outside board
// - game is already finished
// - there is a flag on the field
//
// If the field was not revealed and there is no mine on it - reveal it
// If the field was not revealed and there is a mine on it:
// - if its the first player action - move mine to another location, reveal field (recursion) (not in DEBUG mode!)
// - reveal (recursion) it and finish game
void MinesweeperBoard::revealField(int row, int col) {

    moveCount++;
    if (!belongToBoard(row, col)) return;
    if (isRevealed(row, col)) return;
    if (board[row][col].hasFlag) return;
    if (this->state != RUNNING) return;
    if (board[row][col].hasMine) {
        if (mode == DEBUG) {
            board[row][col].isRevealed = true;
            state = FINISHED_LOSS;
            return;
        }

        if (moveCount <= 1) {
            moveMine(row, col);
            board[row][col].isRevealed = true;
            if (countMines(row, col) == 0)
            {
                for (int rows = row - 1; rows <= row +1; rows++) {
                    for (int cols = col - 1; cols <= col + 1; cols++) {
                        revealField(rows, cols);
                    }
                }

            }
            return;
        }
        board[row][col].isRevealed = true;
        state = FINISHED_LOSS;
    }

    if (!board[row][col].hasMine) {

        board[row][col].isRevealed = true;
        if (countMines(row, col) == 0) {
            for (int rows = row - 1; rows <= row +1; rows++) {
                for (int cols = col - 1; cols <= col + 1; cols++) {
                    revealField(rows, cols);
                }
            }

        }
    }
}

// return true if the field was revealed
bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if(board[row][col].isRevealed)
        return true;
    return false;
}

// return current game state:
// - FINISHED_LOSS - if the player revealed field with mine
// - FINISHED_WIN  - if the player won the game (all unrevealed fields have mines)
// - RUNNING       - if the game is not yet finished
GameState MinesweeperBoard::getGameState() const
{
    int revealedCount=0;

    for(int rows=0;rows<height;rows++)
    {
        for(int columns=0;columns<width;columns++) {
            if (board[rows][columns].isRevealed) {
                revealedCount++;
                if (board[rows][columns].hasMine) {
                    return FINISHED_LOSS;
                }
            }
        }
    }
    if(revealedCount==totalFields-mineCount) {

        return FINISHED_WIN;
    }
    return RUNNING;
}

// convenience function - returns useful information about field in one function call
// if row or col is outside board                         - return '#' character
// if the field is not revealed and has a flag            - return 'F' character
// if the field is not revealed and does not have a flag  - return '_' (underscore) character
// if the field is revealed and has mine                  - return 'x' character
// if the field is revealed and has 0 mines around        - return ' ' (space) character
// if the field is revealed and has some mines around     - return '1' ... '8' (number of mines as a digit)
char MinesweeperBoard::getFieldInfo(int row, int col) const
{

    if(!belongToBoard(row,col)) {
        return '#';
    }
    if(board[row][col].hasFlag) {
        return 'F';
    }
    if(!isRevealed(row,col) && !hasFlag(row,col)) {
        return '_';
    }
    if(isRevealed(row,col) && board[row][col].hasMine)
    {
        return 'x';
    }
    if(isRevealed(row,col) && countMines(row,col)==0) {
        return ' ';
    }
    if(isRevealed(row,col) && countMines(row,col)!=0) {
        return (countMines(row, col));
    }
}


