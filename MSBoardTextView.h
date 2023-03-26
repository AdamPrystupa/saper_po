//
// Created by Adam on 22.03.2023.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"


class MSBoardTextView {

    MinesweeperBoard &board;

public:
    MSBoardTextView(MinesweeperBoard &board);
    void display() const;

};


#endif //SAPER_MSBOARDTEXTVIEW_H
