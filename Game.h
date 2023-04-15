//
// Created by user on 4/12/2023.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <chrono>

class Game {
private:
    int fieldWidth = 30;
    int fieldHeight = 20;
    int size = 16;

    //C++11 Random number generator. Apparently better random values than the normal.
    //But not as convenient as the old rand() whatever function.
    std::mt19937 randomGenerator;
    std::uniform_int_distribution<int> randDistributionW;
    std::uniform_int_distribution<int> randDistributionH;
    
    //Window Width and Height will be restricted to the fieldWidth and fieldHeight.
    int windowWidth;
    int windowHeight;
    
    int moveDir; // The snake needs to follow the movement direction so let's keep track of that.
    int snakeLength; // AKA The size of the snake array (number of indices. Whatever.).
    
    //Catch keyboard events.
    sf::Event event;
    
    //The window itself.
    sf::RenderWindow* window;

    sf::Texture emptyTexture;
    sf::Texture snakeTexture;
    sf::Texture foodTexture;
    
    sf::Sprite emptySprite;
    sf::Sprite snakeSprite;
    sf::Sprite foodSprite;
    
    //These three variables govern the update speed. I'm trying to keep it framerate agnostic.
    //The Tick() function (unless I change the name) will be central to this.
    //Tick() governs the movement of the snake and player. It shouldn't be real time. 
    sf::Clock clock; // The clock itself
    float timer = 0; // How much time has passed (in seconds, but decimals are allowed).
    float delay = 0.1; // Governs the total delay allowed. Currently 0.1 seconds.
    
    //The snake is a struct of up to 100 blocks. Hopefully that should cover it. We're going to reserve the memory now.
    //I mean we don't even handle memory properly so I don't know what I'm doing here.
    struct Snake {
        int x=0;
        int y=0;
    } snakeBlocks[100];
    
    struct Fruit {
        int x=0;
        int y=0;
    } fruit;
    
public:
    Game();
    virtual ~Game();
    
    //accessor
    const bool IsRunning() const;
    
    void CatchEvents();
    void Tick();
    void Update();
    void Render();
};

#endif //SNAKE_GAME_H
