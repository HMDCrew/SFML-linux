#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextureHolder.cpp" // Include the TextureHolder implementation

int main() {
  // Create a window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Texture Holder Example");

  // Create a TextureHolder object
  TextureHolder textures;

  // Load some textures
  textures.load(Textures::Landscape, "Media/Textures/Desert.png");
  textures.load(Textures::Airplane, "Media/Textures/Airplane.png");
  textures.load(Textures::Missile, "Media/Textures/Missile.png");

  // Create a sprite
  sf::Sprite playerPlane;

  // Set the texture of the sprite using the TextureHolder
  playerPlane.setTexture(textures.get(Textures::Airplane));

  // Game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // Clear the window
    window.clear();

    // Draw the sprite
    window.draw(playerPlane);

    // Display the window contents
    window.display();
  }

  return 0;
}
