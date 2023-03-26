
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

int main() {

        MinesweeperBoard board (5, 5, GameMode::NORMAL);
        MSBoardTextView view (board);
        MSTextController ctrl (board,view);
        board.debug_display();
        board.getGameState();

        ctrl.play();

    return 0;
}
