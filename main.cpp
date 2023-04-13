#include <iostream>
#include "Game.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
    
    Game game;

    while (game.IsRunning()) {
        game.Update();
        game.Render();
    }
    return 0;
}
