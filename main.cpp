#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"


int main() {

    sf::RenderWindow window(sf::VideoMode(800, 800), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);


    MinesweeperBoard board(14,10,EASY);
    MSSFMLView view (board);  // przekazujemy przez referencję planszę jako argument konstruktora
    MSSFMLController ctrl (board,view);


    while (window.isOpen()) {
        sf::Event event;
        ctrl.play(window,event);
        }
    return 0;
}
