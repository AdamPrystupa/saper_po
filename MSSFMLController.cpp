//
// Created by Adam on 06.04.2023.
//

#include "MSSFMLController.h"
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

MSSFMLController::MSSFMLController(MinesweeperBoard &board, MSSFMLView &view) : board(board), view(view) {}

void MSSFMLController::play(sf::RenderWindow &window,sf::Event &event) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        {
            if (event.type == sf::Event::MouseButtonPressed)
                if(event.type==sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button==sf::Mouse::Left)
                        board.revealField((event.mouseButton.y-view.getYBegining())/view.getSideLength(),(event.mouseButton.x-view.getXBeginig())/view.getSideLength());
                    if(event.mouseButton.button==sf::Mouse::Right)
                        board.toggleFlag((event.mouseButton.y-view.getYBegining())/view.getSideLength(),(event.mouseButton.x-view.getXBeginig())/view.getSideLength());

                }
        }
    }
    window.clear(sf::Color(166, 161, 161));
    view.draw(window);
    window.display();
}