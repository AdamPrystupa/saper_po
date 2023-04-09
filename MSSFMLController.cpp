//
// Created by Adam on 06.04.2023.
//

#include "MSSFMLController.h"
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

MSSFMLController::MSSFMLController(MinesweeperBoard &board, MSSFMLView &view) : board(board), view(view) {}

void MSSFMLController::play() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(166, 161, 161));
        view.draw(window);
        window.display();
    }

}