//
// Created by Adam on 05.04.2023.
//

#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H
#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"


class MSSFMLView {
    MinesweeperBoard &board;
    float xBegining;
    float yBegining;
    float sideLength;
    float xPosition;
    float yPosition;
    sf::RectangleShape *rectangle;
    sf::Text *minesNearly;
    sf::Texture bombTexture;
    sf::Texture unrevealedTexture;
    sf::Texture flagTexture;
    sf::Font font;


    void matchFontColor(sf::Text &minesNearly, sf::RectangleShape &rectangle,int row, int col);
    void setFieldsAppearance(int row,int col);
    void rectangleInit(int col);
    void minesNearlyInit();
    void loadTextures();
    void loadFonts();
    void drawBoard(sf::RenderTarget & window);


public:
    MSSFMLView(MinesweeperBoard &board);
    void draw (sf::RenderTarget & window);
    float getXBeginig() const;
    float getYBegining() const;
    float getSideLength() const;

};


#endif //SAPER_MSSFMLVIEW_H
