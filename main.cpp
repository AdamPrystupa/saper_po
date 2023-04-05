#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(16, 12, DEBUG);
    MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora

    // symulujemy rozgrywkę
    board.toggleFlag(0, 0);
    board.revealField(2, 3);

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

    return 0;
} 