// Tile.hpp
#include "Player.hpp"

namespace ariel{
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
    Player* getOwner() const;

    void buildRoad(Player& player);
    void buildSettlement(Player& player);
    void buildCity(Player& player);
private:
    std::string name;
    Resource resource;
    int number;
    Construction construction;
    Player* owner;  // Pointer to the player who owns the construction. Null if no construction.
};
}