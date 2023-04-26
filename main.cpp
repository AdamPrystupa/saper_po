#include <SFML/Graphics.hpp>
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"


int main() {

    sf::RenderWindow window(sf::VideoMode(800, 800), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    bool gameFinished = false;

    do {
        MinesweeperBoard board(30, 20, EASY);
        MSSFMLView view(board);
        MSSFMLController ctrl(board, view);


            gameFinished=(ctrl.play(window));




    } while (!gameFinished);
    window.close();

    return 0;
}