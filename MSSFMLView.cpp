//
// Created by Adam on 05.04.2023.
//

#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include <iostream>
#include <stdlib.h>

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board (board){};

void MSSFMLView::draw(sf::RenderTarget &target) const {
    float xPosition;
    float yPosition;
    float rectangleSize;
    rectangleSize=25;
    xPosition=(800-float(board.getBoardWidth()*rectangleSize))/2;
    yPosition=(600-float(board.getBoardHeight()*rectangleSize))/2;

    sf::Texture bombTexture;
    if(!bombTexture.loadFromFile("C:\\Users\\pryst\\Desktop\\git\\saper_adam_prystupa\\images\\bomb.png")){
        return;
    }
    bombTexture.setSmooth(true);

    sf::Texture unrevealedTexture;

    if(!unrevealedTexture.loadFromFile("C:\\Users\\pryst\\Desktop\\git\\saper_adam_prystupa\\images\\unrevealed.png")){
        return;
    }
    unrevealedTexture.setSmooth(true);

    sf::Texture flagTexture;
    if(!flagTexture.loadFromFile("C:\\Users\\pryst\\Desktop\\git\\saper_adam_prystupa\\images\\flag.png")){
        return;
    }
    flagTexture.setSmooth(true);

    sf::Font font;
    if(!font.loadFromFile("C:\\Users\\pryst\\Desktop\\git\\saper_adam_prystupa\\fonts\\font.otf")){
        return;
    }


    for (int row=0; row<board.getBoardHeight();row++) {

        for (int col=0;col<board.getBoardWidth();col++) {

            sf::RectangleShape rectangle (sf::Vector2f(rectangleSize,rectangleSize));
            rectangle.setOutlineThickness(1.f);
            rectangle.setOutlineColor(sf::Color(40,40,40));
            rectangle.setPosition(xPosition+(col*rectangleSize), yPosition);

            std::string mines="";
            sf::Text minesNearly(mines, font, 22);



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
                    rectangle.setFillColor(sf::Color(171, 171, 171));
                    break;

                }

                default: {


                        rectangle.setFillColor(sf::Color(171, 171, 171));
                        minesNearly.setPosition(rectangle.getPosition().x+3, rectangle.getPosition().y-2);
                        mines = std::to_string(board.countMines(row, col));
                        minesNearly.setString(mines);
                        if (mines == "1") {
                            minesNearly.setFillColor(sf::Color(28, 31, 128));
                            break;
                        }
                        if (mines == "2") {minesNearly.setFillColor(sf::Color(27, 133, 30));
                            break;
                        }
                        if (mines == "3") {
                            minesNearly.setFillColor(sf::Color(219, 214, 480));
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
        yPosition+=rectangleSize;
    }
    return;
}