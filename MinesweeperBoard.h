//
// Created by c on 3/8/23.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

#include <string>

enum GameMode { DEBUG, EASY, NORMAL, HARD };
// - EASY   - 10% of game fields with mines (random)
// - NORMAL - 20% of game fields with mines (random)
// - HARD   - 30% of game fields with mines (random)
// - DEBUG  - predefined mine layout (read at the end of file)

enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };



struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};



class MinesweeperBoard {
    // tablica 2D
    Field board[100][100];
    int width;                // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy
    GameMode mode;
    int totalFields;
    int mineCount;
    void clearBoard();
    void setTest();
    void generateDebugMines();
    void generateRandomMines();
    bool belongToBoard(int row, int col) const;

public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;
};




#endif //SAPER_MINESWEEPERBOARD_H
