// Forward declarations to resolve circular dependencies
namespace ariel {
    class Player;
    class Tile;
}

// Tile.hpp
#include <memory>  // for std::shared_ptr
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
    std::shared_ptr<Player> getOwner() const;  // Changed to shared_ptr
    bool hasNumberToken() const;
    void setNumberToken(int number);

    void buildRoad(std::shared_ptr<Player> player);  // Changed to shared_ptr
    void buildSettlement(std::shared_ptr<Player> player);  // Changed to shared_ptr
    void buildCity(std::shared_ptr<Player> player);  // Changed to shared_ptr
private:
    std::string name;
    Resource resource;
    int number;
    bool numberToken;  // Indicates whether the tile has a number token
    Construction construction;
    std::shared_ptr<Player> owner;  // Changed to shared_ptr
};
}