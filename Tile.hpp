// Tile.hpp
#include <string>

namespace ariel {
class Player;

class Tile {
public:
    enum class Resource {
        BRICK,
        LUMBER,
        WOOL,
        GRAIN,
        ORE,
        DESERT
    };

    enum class Construction {
        NONE,
        ROAD,
        SETTLEMENT,
        CITY
    };

    Tile(const std::string& name, Resource resource, int token);
    Resource getResource() const;
    int getNumber() const;
    const std::string& getName() const;
    Construction getConstruction() const;
    bool hasNumberToken() const;
 
private:
    std::string name;
    Resource resource;
    int token;
    Construction construction;
    Player* owner;  
};
}