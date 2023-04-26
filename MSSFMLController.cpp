//
// Created by Adam on 06.04.2023.
//

#include "MSSFMLController.h"





MSSFMLController::MSSFMLController(MinesweeperBoard &board, MSSFMLView &view) : board(board), view(view) {}

bool MSSFMLController::play(sf::RenderWindow &window) {

    bool gameOver = false;

    while (!gameOver && window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                return true;
            mouseHandling(window, event);
            window.clear(sf::Color(166, 161, 161));
            view.draw(window);
            isGameFinished(window);
            window.display();
            if (isGameFinished(window))
                if (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Escape)
                    return true;
                if ( event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Enter)
                    return false;
        }
    }
}

bool MSSFMLController::isGameFinished(sf::RenderTarget & window) {
    if(board.getGameState()==FINISHED_LOSS)
    {
        view.gameOver(window);
        return true;
    }

    if(board.getGameState()==FINISHED_WIN) {
        view.congratulations(window);
        return true;
    }
    return false;

}

void MSSFMLController::mouseHandling(sf::RenderWindow &window, sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed)
        if(event.type==sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button==sf::Mouse::Left)
                board.revealField((event.mouseButton.y - view.getYBegining()) / view.getSideLength(),
                                  (event.mouseButton.x - view.getXBeginig()) / view.getSideLength());

            if(event.mouseButton.button==sf::Mouse::Right)
                board.toggleFlag((event.mouseButton.y-view.getYBegining())/view.getSideLength(),
                                 (event.mouseButton.x-view.getXBeginig())/view.getSideLength());
        }
}


