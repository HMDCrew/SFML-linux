#include <iostream>
#include <cassert>
#include <SFML/Graphics.hpp>

namespace Textures {
    enum ID { Landscape, Airplane, Missile };
}

class TextureHolder {

    public:
        void load(Textures::ID id, const std::string& filename);
        sf::Texture& get(Textures::ID id);
        // const sf::Texture& get(Textures::ID id) const;
        

    private:
        std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};

void TextureHolder::load(Textures::ID id, const std::string& filename) {
    
    std::unique_ptr<sf::Texture> texture(new sf::Texture());

    if( !texture->loadFromFile(filename) ) {
        throw std::runtime_error("TextureHolder::load - Falied to load " + filename);
    }

    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
};

sf::Texture& TextureHolder::get(Textures::ID id) {

    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());

    return *found->second;
}

// const sf::Texture& TextureHolder::get(Textures::ID id) const {

//     TextureHolder textures;
//     textures.load(Textures::Landscape, "Media/Textures/Desert.png");
//     textures.load(Textures::Airplane, "Media/Textures/Airplane.png");
//     textures.load(Textures::Missile, "Media/Textures/Missile.png");

//     sf::Sprite playerPlane;
//     playerPlane.setTexture(textures.get(Textures::Airplane));
// }