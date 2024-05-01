#include <iostream>
#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update(sf::Time delta);
        void render();

        sf::RenderWindow mWindow;
        sf::Texture mTexture;
        sf::Sprite mPlayer;
        sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};


Game::Game()
    : mWindow(sf::VideoMode(640, 480), "SFML Application")
    , mPlayer()
    , mTexture() {

    if(!mTexture.loadFromFile("./assets/pexels-pixabay-531880.jpg")) {
        std::cout << "error to load image ./assets/pexels-pixabay-531880.jpg" << std::endl;
    }

    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
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
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}


void Game::update(sf::Time delta) {
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