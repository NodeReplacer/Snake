//
// Created by user on 4/12/2023.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <SFML/Graphics.hpp>

class Game {
private:
    int fieldWidth = 30;
    int fieldHeight = 20;
    int size = 16;
    int windowWidth;
    int windowHeight;
    
    //The window itself.
    sf::RenderWindow* window;
    
    sf::Texture snakeTexture;
    sf::Texture foodTexture;
    sf::Texture emptyTexture;
    
    sf::Sprite snakeSprite;
    sf::Sprite foodSprite;
    
public:
    Game();
    virtual ~Game();
    
    //accessor
    const bool IsRunning() const;
    
    void CatchEvents();
    void Update();
    void Render();
};

#endif //SNAKE_GAME_H
