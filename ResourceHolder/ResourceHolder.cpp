#include <iostream>
#include <cassert>
#include <SFML/Graphics.hpp>

template <typename Resource, typename Identifier>
class ResourceHolder {
    public:
        void load(Identifier id, const std::string& filename);
        Resource& get(Identifier id);
        //const Resource& get(Identifier id) const;

    private:
        std::map<Identifier, std::unique_prt<Resource>> mResourceMap;
};

template <typename Resource, typename Identifier>
template <typename Paramiter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Paramiter& secondParam) {
 
    std::unique_ptr<Resource> resource(new Resource());
 
    if(!resource->loadFromFile(filename, secondParam))
        throw std::runtime_error("ResourceHolder::load - Fallied to load " + filename);

    auto inserted = mResourceMap.insert(
        std::make_pair(id, std::move(resource))
    );

    assert(inserted.second);
}
