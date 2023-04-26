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
    bool areInitiated;
    bool areLoaded;
    sf::RectangleShape *rectangle;
    sf::Text *minesNearly;
    sf::Text *announcement;
    sf::Text *menu;
    sf::Texture bombTexture;
    sf::Texture unrevealedTexture;
    sf::Texture flagTexture;
    sf::Font font;


    void matchFontColor(sf::Text &minesNearly, sf::RectangleShape &rectangle,int row, int col);
    void setFieldsAppearance(int row,int col);
    void rectangleInit(int col);
    void menuInit();
    void minesNearlyInit();
    void loadTextures();
    void loadFonts();
    void drawBoard(sf::RenderTarget & window);
    void sfInitiation(int col);
    void filesLoading();



public:
    MSSFMLView(MinesweeperBoard &board);
    void draw (sf::RenderTarget & window);
    float getXBeginig() const;
    float getYBegining() const;
    float getSideLength() const;
    void gameOver(sf::RenderTarget & window);
    void congratulations(sf::RenderTarget & window);
    void setSideLength(sf::RenderTarget & window);
    void setBoardBeginning(sf::RenderTarget & window);

};


#endif //SAPER_MSSFMLVIEW_H
