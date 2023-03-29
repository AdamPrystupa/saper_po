
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <iostream>

int main() {

        MinesweeperBoard board (5, 5, GameMode::NORMAL);
        MSBoardTextView view (board);
        MSTextController ctrl (board,view);
        board.getGameState();

        ctrl.play();

    return 0;
}
