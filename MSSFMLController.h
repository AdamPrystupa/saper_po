//
// Created by Adam on 06.04.2023.
//

#ifndef SAPER_MSSFMLCONTROLLER_H
#define SAPER_MSSFMLCONTROLLER_H


#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include "MSTextController.h"



class MSSFMLController {
    MinesweeperBoard &board;
    MSSFMLView &view;
public:
    MSSFMLController(MinesweeperBoard &board, MSSFMLView &view);
    void play();

};


#endif //SAPER_MSSFMLCONTROLLER_H
