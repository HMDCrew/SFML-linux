#include <iostream>
#include <SFML/Graphics.hpp>
#include "inc/KeyboardEvents.cpp"

class Game {
    public:
        Game(); // Constructor (potentially initializes member variables)
        void run(); // Main game loop

    private:
        void processEvents(); // Handles window events (mouse clicks, keyboard presses)
        void update(sf::Time delta); // Updates game logic (player movement, state changes)
        void render(); // Draws game objects to the window

        sf::RenderWindow mWindow; // The main window for rendering
        sf::CircleShape mPlayer;
        KeyboardEvents myKeyboardEvents;
        sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};


Game::Game()
    : mWindow(sf::VideoMode(640, 480), "SFML Application")
    , mPlayer() { // Constructor definition

    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
}


void Game::run() {

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen()) {

        processEvents();
        
        timeSinceLastUpdate += clock.restart();

        while(timeSinceLastUpdate > TimePerFrame) {

            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();
    }
}


void Game::processEvents() {

    sf::Event event;

    while(mWindow.pollEvent(event)) {

        switch (event.type) {
            case sf::Event::KeyPressed:
                myKeyboardEvents.handlePlayerInput((int)event.key.code, true);
                break;
            
            case sf::Event::KeyReleased:
                myKeyboardEvents.handlePlayerInput(event.key.code, false);
                break;
            
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}


void Game::update(sf::Time delta) {

    sf::Vector2f moviment(0.f, 0.f);

    if (myKeyboardEvents.mIsMovingUp)
        moviment.y -= 1.f;
    if (myKeyboardEvents.mIsMovingDown)
        moviment.y += 1.f;
    if (myKeyboardEvents.mIsMovingLeft)
        moviment.x -= 1.f;
    if (myKeyboardEvents.mIsMovingRight)
        moviment.x += 1.f;

    mPlayer.move(moviment * delta.asSeconds());
}


void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}


int main() {
    Game game;

    game.run();

    return 0;
}