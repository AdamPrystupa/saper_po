//
// Created by Adam on 05.04.2023.
//

#include "MSSFMLView.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board (board){};

void MSSFMLView::draw(sf::RenderTarget &target) const {
    float xPosition;
    float yPosition;
    xPosition=50;
    yPosition=0;
    for (int i=0;i<board.getBoardWidth();i++) {
        for (int j=0; j<board.getBoardHeight();j++) {
            sf::CircleShape c1(25);
            c1.setFillColor(sf::Color::Magenta);
            c1.setPosition(xPosition * j, yPosition);
            target.draw(c1);
        }
        yPosition+=50;
    }
}