#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "My Texture", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen()) {

        sf::Texture texture;

        if(!texture.loadFromFile("./assets/pexels-pixabay-531880.jpg")) {
            std::cout << "error to load image ./assets/pexels-pixabay-531880.jpg" << std::endl;
        }

        sf::Sprite sprite(texture);
        sprite.setPosition(100.f, 100.f);

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
