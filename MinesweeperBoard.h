//
// Created by c on 3/8/23.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

#include <string>


enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
enum GameMode { DEBUG, EASY, NORMAL, HARD };
// - EASY   - 10% of game fields with mines (random)
// - NORMAL - 20% of game fields with mines (random)
// - HARD   - 30% of game fields with mines (random)
// - DEBUG  - predefined mine layout (read at the end of file)



struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};



class MinesweeperBoard {
    // tablica 2D
    Field board[100][100];
    int width;                // the actual width of the board
    int height;               // the actual height of the board
    GameMode mode;
    GameState state;
    int mineCount;
    int moveCount;
    void clearBoard();
    void setTest();
    void generateDebugMines();
    void generateRandomMines();
    void moveMine(int row, int col);
    bool belongToBoard(int row, int col) const;

public:
    int totalFields;
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
    bool hasFlag(int row, int col) const;
    bool hasMine(int row, int col) const;
    void toggleFlag(int row, int col);
    void revealField(int row, int col);
    bool isRevealed(int row, int col) const;
    GameState getGameState() const;
    char getFieldInfo(int row, int col) const;


};




#endif //SAPER_MINESWEEPERBOARD_H
