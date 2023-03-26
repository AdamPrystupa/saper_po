//
// Created by Adam on 22.03.2023.
//

#include <iostream>

#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"


using std::cout;
using std::endl;

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board) : board (board){};

void MSBoardTextView::display() const {
    cout<<"      ";
    for(int col =0;col < board.getBoardWidth(); col++) {
        if (col + 1 < 10)
            cout<< col + 1 << "   ";
        else
            cout << col + 1 << "  ";
    }
    cout<<endl;
    for (int row = 0; row < board.getBoardHeight(); row++) {
        if(row+1<10)
            cout<<" "<<row+1<<"  |";
        else
            cout<<row+1<<"  |";
        for (int col = 0; col < board.getBoardWidth(); col++) {

            char fieldStatus = board.getFieldInfo(row, col);

            switch (fieldStatus) {
                case '_': {
                    cout << "[_]|";
                    break;
                }
                case 'F': {
                    cout << " F |";
                    break;
                }

                case 'x': {
                    cout << " X |";
                    break;
                }

                case ' ': {
                    cout << "   |";
                    break;
                }

                default: {
                    cout <<" "<<board.countMines(row,col)<<" |";
                    break;
                }

            }



        }
        cout << endl;
    }
    cout << endl;
}



