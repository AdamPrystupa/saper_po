
#include "MinesweeperBoard.h"

int main() {
    MinesweeperBoard board;
    MinesweeperBoard board1(5,7,GameMode::HARD);
    board1.debug_display();
    return 0;
}
