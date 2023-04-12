//
// Created by Adam on 05.04.2023.
//

#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include <iostream>
#include <stdlib.h>

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board (board){
    this->sideLength=40;
    this->x0=(800 - float(board.getBoardWidth() * sideLength)) / 2;
    this->y0=(600 - float(board.getBoardHeight() * sideLength)) / 2;

};

void MSSFMLView::draw(sf::RenderTarget &target) const {
    float xPosition;
    float yPosition;
    float rectangleSize;
    rectangleSize=sideLength;
    xPosition = x0;
    yPosition = y0;

    sf::Texture bombTexture;
    if (!bombTexture.loadFromFile("..\\images\\bomb.png")) {
        return;
    }
    bombTexture.setSmooth(true);

    sf::Texture unrevealedTexture;

    if (!unrevealedTexture.loadFromFile(
            "..\\images\\unrevealed.png")) {
        return;
    }
    unrevealedTexture.setSmooth(true);

    sf::Texture flagTexture;
    if (!flagTexture.loadFromFile("..\\images\\flag.png")) {
        return;
    }
    flagTexture.setSmooth(true);

    sf::Font font;
    if (!font.loadFromFile("..\\fonts\\font.otf")) {
        return;
    }


    for (int row = 0; row < board.getBoardHeight(); row++) {

        for (int col = 0; col < board.getBoardWidth(); col++) {

            sf::RectangleShape rectangle(sf::Vector2f(rectangleSize, rectangleSize));
            rectangle.setOutlineThickness(1.f);
            rectangle.setOutlineColor(sf::Color(40, 40, 40));
            rectangle.setPosition(xPosition + (col * rectangleSize), yPosition);

            std::string mines = "";
            sf::Text minesNearly(mines, font, getSideLength()/1.3);
            minesNearly.setOutlineColor(sf::Color::Black);
            minesNearly.setOutlineThickness(1);


            char fieldStatus = board.getFieldInfo(row, col);

            switch (fieldStatus) {
                case '_': {
                    rectangle.setTexture(&unrevealedTexture);
                    break;
                }
                case 'F': {
                    rectangle.setTexture(&flagTexture);
                    break;
                }

                case 'x': {
                    rectangle.setTexture(&bombTexture);
                    break;
                }

                case ' ': {
                    rectangle.setFillColor(sf::Color(196, 196,196));
                    break;

                }

                default: {


                    rectangle.setFillColor(sf::Color(196,196,196));
                    minesNearly.setPosition(rectangle.getPosition().x + getSideLength()/5, rectangle.getPosition().y /*getSideLength()/12.5*/);
                    mines = std::to_string(board.countMines(row, col));
                    minesNearly.setString(mines);
                    if (mines == "1") {
                        minesNearly.setFillColor(sf::Color(28, 31, 128));
                        break;
                    }
                    if (mines == "2") {
                        minesNearly.setFillColor(sf::Color(27, 133, 30));
                        break;
                    }
                    if (mines == "3") {
                        minesNearly.setFillColor(sf::Color(244, 252, 3));
                        break;
                    }
                    if (mines == "4") {
                        minesNearly.setFillColor(sf::Color(245, 158, 44));
                        break;
                    }
                    if (mines == "5") {
                        minesNearly.setFillColor(sf::Color(252, 3, 11));
                        break;
                    } else
                        minesNearly.setFillColor(sf::Color(128, 0, 4));


                    break;
                }

            }
            target.draw(rectangle);
            target.draw(minesNearly);


        }
        yPosition += rectangleSize;
    }
    return;
}

float MSSFMLView::getX0() const
{
    return this->x0;
}
float MSSFMLView::getY0() const {
    return this->y0;
}
float MSSFMLView::getSideLength() const {
    return this->sideLength;
}