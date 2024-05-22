// Tile.hpp
#include <string>


namespace ariel {
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

    Tile(const std::string& name, Resource resource, int number);
    Resource getResource() const;
    int getNumber() const;
    const std::string& getName() const;
    Construction getConstruction() const;
    bool hasNumberToken() const;
    void setNumberToken(int number);
 
private:
    std::string name;
    Resource resource;
    int number;
    Construction construction;
    Player owner;  
};
}