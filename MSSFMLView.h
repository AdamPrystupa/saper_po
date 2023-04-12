//
// Created by Adam on 05.04.2023.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"


class MSSFMLView {
    MinesweeperBoard &board;
    float x0;
    float y0;
    float sideLength;

public:
    MSSFMLView(MinesweeperBoard &board);
    void draw (sf::RenderTarget & window) const;
    float getX0() const;
    float getY0() const;
    float getSideLength() const;

};


#endif //SAPER_MSSFMLVIEW_H
