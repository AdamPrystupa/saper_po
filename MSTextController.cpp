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
   while(board.getGameState()==RUNNING)
    {
       int chose;
       int row;
       int column;
        cout<<"What do you want to do? Chose option and give coordinates for example: 1 3 4 (if u want to reveal field in row 3 and column 4"<<endl;
        cout<<"1. Reveal field"<<endl;
        cout<<"2. Toggle flag"<<endl;
        cin>>chose>>row>>column;
        row--;
        column--;

        switch (chose) {
            case 1:
            {
                board.revealField(row,column);
                break;
            }

            case 2:
            {
                board.toggleFlag(row,column);
                break;
            }

        }
        view.display();
        if(board.getGameState()==FINISHED_LOSS)
        cout<<"GAME OVER"<<endl;

}
    if(board.getGameState()==FINISHED_WIN)
    cout<<"CONGRATULATIONS"<<endl;
        }

