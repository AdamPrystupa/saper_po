#include "MSSFMLView.h"
#include "MinesweeperBoard.h"

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board (board){


    areLoaded= false;
    areInitiated = false;


};
void MSSFMLView::setSideLength(sf::RenderTarget & window) {
    if(board.getBoardWidth()>board.getBoardHeight())
        this->sideLength=window.getSize().x/board.getBoardWidth();
    else
    this->sideLength=window.getSize().y/board.getBoardHeight();
}

void MSSFMLView::setBoardBeginning(sf::RenderTarget & window) {
    this->xBegining=(window.getSize().x-float(board.getBoardWidth() * sideLength)) / 2;
    this->yBegining=(window.getSize().y-float(board.getBoardHeight() * sideLength)) / 2;
}


void MSSFMLView::draw(sf::RenderTarget &target) {
    setSideLength(target);
    setBoardBeginning(target);

    xPosition = xBegining;
    yPosition = yBegining;

    if(!areLoaded)
        filesLoading();


    drawBoard(target);

    return;
}






float MSSFMLView::getXBeginig() const
{
    return this->xBegining;
}


float MSSFMLView::getYBegining() const {
    return this->yBegining;
}



float MSSFMLView::getSideLength() const {
    return this->sideLength;
}




void MSSFMLView::matchFontColor(sf::Text &minesNearly, sf::RectangleShape &rectangle,int row, int col) {
    std::string mines = "";
    rectangle.setFillColor(sf::Color(196,196,196));
    minesNearly.setPosition(rectangle.getPosition().x + getSideLength()/5, rectangle.getPosition().y /*getSideLength()/12.5*/);
    mines = std::to_string(board.countMines(row, col));
    minesNearly.setString(mines);
    if (mines == "1") {
        minesNearly.setFillColor(sf::Color(28, 31, 128));
        return;
    }
    if (mines == "2") {
        minesNearly.setFillColor(sf::Color(27, 133, 30));
        return;
    }
    if (mines == "3") {
        minesNearly.setFillColor(sf::Color(244, 252, 3));
        return;
    }
    if (mines == "4") {
        minesNearly.setFillColor(sf::Color(245, 158, 44));
        return;
    }
    if (mines == "5") {
        minesNearly.setFillColor(sf::Color(252, 3, 11));
        return;
    } else
        minesNearly.setFillColor(sf::Color(128, 0, 4));
    return;
}




void MSSFMLView::loadTextures() {
    if (!bombTexture.loadFromFile("..\\images\\bomb.png")) {
        return;
    }
    bombTexture.setSmooth(true);

    if (!unrevealedTexture.loadFromFile(
            "..\\images\\unrevealed.png")) {
        return;
    }
    unrevealedTexture.setSmooth(true);

    if (!flagTexture.loadFromFile("..\\images\\flag.png")) {

        return;
    }
    flagTexture.setSmooth(true);
}




void MSSFMLView::loadFonts(){
    if (!font.loadFromFile("..\\fonts\\font.otf")) {
        return;
    }
}


void MSSFMLView::filesLoading() {
    loadTextures();
    loadFonts();
    areLoaded= true;
}



void MSSFMLView::rectangleInit(int col) {
    rectangle = new sf::RectangleShape(sf::Vector2f(sideLength, sideLength));
    rectangle->setOutlineThickness(1.f);
    rectangle->setOutlineColor(sf::Color(40, 40, 40));
    rectangle->setPosition(xPosition + (col * sideLength), yPosition);
}



void MSSFMLView::minesNearlyInit() {
    minesNearly = new sf::Text("", font, getSideLength() / 1.3);
    minesNearly->setOutlineColor(sf::Color::Black);
    minesNearly->setOutlineThickness(1);
}

void MSSFMLView::menuInit() {
    menu = new sf::Text("to replay press ENTER\nto quit press ESCAPE,", font, getSideLength()*0.5);
    menu->setFillColor(sf::Color::Black);
    menu->setOutlineThickness(2);
    menu->setOutlineColor(sf::Color::White);

}

void MSSFMLView::sfInitiation(int col) {
    rectangleInit(col);
    minesNearlyInit();
    menuInit();
    areInitiated==true;
}



void MSSFMLView::setFieldsAppearance(int row,int col) {
    char fieldStatus = board.getFieldInfo(row, col);
    switch (fieldStatus) {
        case '_': {
            rectangle->setTexture(&unrevealedTexture);
            return;
        }
        case 'F': {
            rectangle->setTexture(&flagTexture);
            return;
        }
        case 'x': {
            rectangle->setTexture(&bombTexture);
            return;
        }
        case ' ': {
            rectangle->setFillColor(sf::Color(196, 196, 196));
            return;

        }
        default: {
            matchFontColor(*minesNearly, *rectangle, row, col);

            return;
        }
    }
}

void MSSFMLView::drawBoard(sf::RenderTarget & target) {
    for (int row = 0; row < board.getBoardHeight(); row++) {

        for (int col = 0; col < board.getBoardWidth(); col++) {

            if(!areInitiated)
                sfInitiation(col);

            setFieldsAppearance(row, col);

            target.draw(*rectangle);
            target.draw(*minesNearly);
        }
        yPosition += sideLength;
    }
}

void MSSFMLView::gameOver(sf::RenderTarget & target) {
    announcement= new sf::Text  ("GAME\nOVER!", font, 2*sideLength);
    announcement->setPosition(xBegining+board.getBoardWidth()*sideLength/2.0-3.5*sideLength,yBegining+board.getBoardHeight()*sideLength/2.0-2.5*sideLength);
    announcement->setFillColor(sf::Color::White);
    announcement->setOutlineColor(sf::Color::Black);
    announcement->setOutlineThickness(5.0);
    menu->setPosition(announcement->getPosition().x-0.5*sideLength,announcement->getPosition().y+4.5*sideLength);
    target.draw(*announcement);
    target.draw(*menu);



}

void MSSFMLView::congratulations(sf::RenderTarget & target) {
    announcement= new sf::Text  ("YOU\nWIN!", font, 2*sideLength);
    announcement->setPosition(xBegining+board.getBoardWidth()*sideLength/2.0-2.5*sideLength,yBegining+board.getBoardHeight()*sideLength/2.0-2.5*sideLength);
    announcement->setFillColor(sf::Color::White);
    announcement->setOutlineColor(sf::Color::Black);
    announcement->setOutlineThickness(5.0);
    menu->setPosition(announcement->getPosition().x-1.5*sideLength,announcement->getPosition().y+2.5*sideLength);
    target.draw(*announcement);
    target.draw(*menu);


};
