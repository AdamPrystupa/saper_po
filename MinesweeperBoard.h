//
// Created by c on 3/8/23.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

#include <string>

struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

enum GameMode { DEBUG, EASY, NORMAL, HARD };

class MinesweeperBoard {
    // tablica 2D
    Field board[100][100];
    int columns=5;                // rzeczywista szerokość planszy
    int rows=7;               // rzeczywista wysokość planszy
    GameMode mode;
    int totalFields;
    int minedFields;
    void clearBoard();
    void setTest();
    void generateDebugMines();
    void generateRandomMines();

public:
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void debug_display() const;
};


#endif //SAPER_MINESWEEPERBOARD_H
