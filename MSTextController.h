//
// Created by Adam on 24.03.2023.
//

#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include "MSTextController.h"


class MSTextController {
    MinesweeperBoard &board;
    MSBoardTextView &view;
public:
    MSTextController(MinesweeperBoard &board, MSBoardTextView &view);
    void play();

};


#endif //SAPER_MSTEXTCONTROLLER_H
