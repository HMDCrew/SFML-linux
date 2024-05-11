#include "World.cpp"
#include "Game.cpp"
#include "SpriteNode.cpp"
#include "SceneNode.cpp"
#include "Entity.cpp"
#include "Aircraft.cpp"


#include <stdexcept>
#include <iostream>


int main() {
	try {
		Game game;
		game.run();
	} catch (std::exception& e) {
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
