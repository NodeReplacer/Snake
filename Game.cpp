//
// Created by user on 4/12/2023.
//

#include "Game.h"

Game::Game() {
    //Establish the field of play and the window size to match.
    this->fieldWidth = 30;
    this->fieldHeight = 20;
    this->size = 16; // Size in pixels of each block.
    
    //window size will be determined by the size of the field. No extra space for UI or HUD.
    this->windowWidth = this->size*this->fieldWidth;
    this->windowHeight = this->size*this->fieldHeight;
    
    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Snake");
    this->window->setFramerateLimit(60);
    
    this->snakeTexture.loadFromFile("images/red.png");
    this->foodTexture.loadFromFile("images/green.png");
    this->emptyTexture.loadFromFile("images/white.png");

    this->snakeSprite.setTexture(snakeTexture);
    this->foodSprite.setTexture(foodTexture);
}

Game::~Game() {
    
}

const bool Game::IsRunning() const {
    return this->window->isOpen();
}

void Game::CatchEvents() {
    
}

void Game::Update() {

}

void Game::Render() {

}
