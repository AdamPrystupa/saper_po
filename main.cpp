
#include "MinesweeperBoard.h"

int main() {
    MinesweeperBoard board;
    MinesweeperBoard board1(10,10,GameMode::DEBUG);

    board1.debug_display();
    return 0;
}
