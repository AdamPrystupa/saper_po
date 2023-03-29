//
// Created by Adam on 24.03.2023.
//
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"

using std::cin;
using std::cout;
using std::endl;

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) :board (board), view (view){};

void MSTextController::play() {
    view.display();
    while (board.getGameState() == RUNNING) {
        int chose;
        int row;
        int column;
        cout << "Make a move!" << endl;
        cout << "1 (row column) - Reveal field" << endl;
        cout << "2 (row column) - Toggle flag" << endl;
        if (!(cin >> chose >> row >> column) || chose < 1 || chose > 2 || row < 1 || row > board.getBoardHeight() ||
            column < 1 || column > board.getBoardWidth()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Enter correct values." << endl;
        } else {
            row--;
            column--;

            switch (chose) {
                case 1: {
                    board.revealField(row, column);
                    break;
                }

                case 2: {
                    board.toggleFlag(row, column);
                    break;
                }
                default: {
                    cout << "Invalid input. Enter correct values." << endl;
                    break;
                }
            }

        }

        view.display();
        if (board.getGameState() == FINISHED_LOSS)
            cout << "GAME OVER" << endl;


        if (board.getGameState() == FINISHED_WIN)
            cout << "CONGRATULATIONS" << endl;
    }


}