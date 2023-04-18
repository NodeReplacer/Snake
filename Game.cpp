//
// Created by user on 4/12/2023.
//

#include "Game.h"

Game::Game() {
    //Usually I have an InitVariables function but that function was not only non-descriptive
    //it was pointless, cluttered my code, and forced the reader to leap around searching my code for
    //what would essentially amount to this.

    //////////////////Establish random seed and number generator//////////////////////////
    //Establish the random device properly before firing it up.
    //This seed is based on time.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    this->randomGenerator = std::mt19937(seed);
    this->randDistributionW = std::uniform_int_distribution<int>(0,this->fieldWidth-1);
    this->randDistributionH = std::uniform_int_distribution<int>(0,this->fieldHeight-1);

    //////////////////Establish variables that are close metal here.//////////////////////////
    //"Close to metal" meaning that it would be easy to code this in assembly.
    //The variable is declared and a hard number is given. No variables are used to set values of other variables, etc.
    //Establish the field of play and the window size to match.
    this->fieldWidth = 30;
    this->fieldHeight = 20;
    this->size = 16; // Size in pixels of each block.
    this->moveDir = 0;
    this->snakeLength = 4; // Player starts with a snake size of 4.

    //////////////////Window Size//////////////////////////
    //window size will be determined by the size of the field. No extra space for UI or HUD.
    this->windowWidth = this->size*this->fieldWidth;
    this->windowHeight = this->size*this->fieldHeight;
    
    this->window = new sf::RenderWindow(sf::VideoMode(this->windowWidth, this->windowHeight), "Snake");
    this->window->setFramerateLimit(60);

    //////////////////Setting Texture then Sprites//////////////////////////
    //Establish the textures before the sprites use them. Better make sure that images folder is next to the exe.
    this->emptyTexture.loadFromFile("images/white.png");
    this->snakeTexture.loadFromFile("images/red.png");
    this->foodTexture.loadFromFile("images/green.png");
    
    this->emptySprite.setTexture(emptyTexture);
    this->snakeSprite.setTexture(snakeTexture);
    this->foodSprite.setTexture(foodTexture);
    
    //////////////////first fruit placement//////////////////////////
    this->fruit.x = 10;
    this->fruit.y = 10;
}

Game::~Game() {
    
}

const bool Game::IsRunning() const {
    return this->window->isOpen();
}

void Game::CatchEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            //If you hit the close button in the top right.
            case sf::Event::Closed:
                this->window->close();
                break;
            
            //Actual keyboard events go here.
            case sf::Event::KeyPressed:
                switch (this->event.key.code) {
                    case sf::Keyboard::Escape:
                        this->window->close();
                        break;
                    case sf::Keyboard::Left:
                        this->moveDir = 1;
                        break;
                    case sf::Keyboard::Right:
                        this->moveDir = 2;
                        break;
                    case sf::Keyboard::Up:
                        this->moveDir = 3;
                        break;
                    case sf::Keyboard::Down:
                        this->moveDir = 0;
                        break;
                    default:
                        break;
                }
                
            default:
                break;
        }
    }
}

void Game::Tick() {
    //////////////////player tail movement//////////////////////////
    //If we move the snake we technically only move the first block, the rest simply take the preceding block's position.
    for (int i=this->snakeLength;i>0;--i) {
        this->snakeBlocks[i].x = this->snakeBlocks[i-1].x;
        this->snakeBlocks[i].y = this->snakeBlocks[i-1].y;
    }

    //////////////////player snake head movement//////////////////////////
    //We still keep track of our player controller block. Because keeping track of its position is so useful
    //to moving the other blocks behind it.
    if (this->moveDir == 0) this->snakeBlocks[0].y+=1;
    if (this->moveDir == 1) this->snakeBlocks[0].x-=1;
    if (this->moveDir == 2) this->snakeBlocks[0].x+=1;
    if (this->moveDir == 3) this->snakeBlocks[0].y-=1;
    //Which manner of single line if statements is easier to read? I can't really tell.
    
    //////////////////fruit collection//////////////////////////
    //If the first snake block overlaps a fruit.
    if ((this->snakeBlocks[0].x == this->fruit.x) && this->snakeBlocks[0].y == this->fruit.y) {
        ++this->snakeLength;
        //But what if we spawn a fruit onto the block that a fruit is already occupying?
        bool isFruitSafe = false;
        do {
            isFruitSafe = true;
            this->fruit.x = this->randDistributionW(this->randomGenerator);
            this->fruit.y = this->randDistributionH(this->randomGenerator);
            for (int i=0;i<snakeLength;++i) {
                if (this->fruit.x == this->snakeBlocks[i].x && this->fruit.y == this->snakeBlocks[i].y) {
                    isFruitSafe = false;
                    break; // We don't really need to go further in the loop. 
                }
            }
        } while (isFruitSafe == false);
    }

    //////////////////player boundary collision handling//////////////////////////
    if (this->snakeBlocks[0].x>this->fieldWidth) this->snakeBlocks[0].x = 0;
    if (this->snakeBlocks[0].x<0) this->snakeBlocks[0].x = this->fieldWidth;
    if (this->snakeBlocks[0].y>this->fieldHeight) snakeBlocks[0].y = 0;
    if (this->snakeBlocks[0].y<0) this->snakeBlocks[0].y = this->fieldHeight;

    //////////////////player self collision handling//////////////////////////
    // You know. The game over state is if the player hits himself.
    for (int i=1;i<snakeLength;++i) {
        //i=1 because otherwise the array would consider the player block when checking self collision. Which will always mean immediate losing.
        if (this->snakeBlocks[0].x == this->snakeBlocks[i].x && this->snakeBlocks[0].y == this->snakeBlocks[i].y) {
            //We just cut it down for now, but we should probably make a GAME OVER screen.
            this->snakeLength = i;
        }
    }
}

void Game::Update() {
    float time = clock.getElapsedTime().asSeconds();
    this->clock.restart();
    this->timer += time;
    
    CatchEvents();
    
    if (timer>delay) {
        this->timer = 0;
        Tick(); //In case not read before: Tick governs the movement of the snake and the reaction time
                // of the game to the player's actions. They can't move immediately but only
                // on each Tick.
        
    }
}

void Game::Render() {
    window->clear();
    
    //Fill Out the empty squares.
    for (int i=0; i<fieldWidth; ++i) {
        for (int j=0;j<fieldHeight;++j) {
            this->emptySprite.setPosition(i*this->size,j*this->size);
            this->window->draw(this->emptySprite);
        }
    }
    
    //Draw the snake.
    for (int i=0;i<snakeLength;++i) {
        this->snakeSprite.setPosition(this->snakeBlocks[i].x*this->size,this->snakeBlocks[i].y*this->size);
        this->window->draw(snakeSprite);
    }
    
    this->foodSprite.setPosition(this->fruit.x*size,this->fruit.y*size);
    this->window->draw(foodSprite);
    
    this->window->display();
}
