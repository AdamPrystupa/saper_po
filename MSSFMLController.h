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
    bool isGameFinished(sf::RenderTarget & window);


public:
    MSSFMLController(MinesweeperBoard &board, MSSFMLView &view);
    bool play(sf::RenderWindow &window);
    void mouseHandling(sf::RenderWindow &window,sf::Event &event);

};


#endif //SAPER_MSSFMLCONTROLLER_H
