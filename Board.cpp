// Board.cpp
#include "Board.hpp"
#include "Player.hpp"
#include <algorithm>
#include <random>

namespace ariel {
Board::Board() : robberLocation(10) {
    initializeBoard();
}

void Board::initializeBoard() {
    createTiles();
	createIntersections();
	createRoads();
}

void Board::createTiles() {
    tiles.push_back(Tile("Pasture", Tile::Resource::WOOL, 12));
    tiles.push_back(Tile("Hills", Tile::Resource::ORE, 8));
    tiles.push_back(Tile("Forest", Tile::Resource::WOOL, 4));
    tiles.push_back(Tile("Pasture", Tile::Resource::WOOL, 9));
    tiles.push_back(Tile("Forest", Tile::Resource::LUMBER, 11));
    tiles.push_back(Tile("Hills", Tile::Resource::WOOL, 5));
    tiles.push_back(Tile("Pasture", Tile::Resource::ORE, 5));
    tiles.push_back(Tile("Forest", Tile::Resource::LUMBER, 6));
    tiles.push_back(Tile("Fields", Tile::Resource::BRICK, 10));
    tiles.push_back(Tile("Mountains", Tile::Resource::GRAIN, 3));
    tiles.push_back(Tile("Fields", Tile::Resource::DESERT, 0)); // Desert has no resource and no number
    tiles.push_back(Tile("Mountains", Tile::Resource::GRAIN, 11));
    tiles.push_back(Tile("Fields", Tile::Resource::GRAIN, 2));
    tiles.push_back(Tile("Fields", Tile::Resource::BRICK, 10));
    tiles.push_back(Tile("Forest", Tile::Resource::GRAIN, 6));
    tiles.push_back(Tile("Fields", Tile::Resource::LUMBER, 8));
    tiles.push_back(Tile("Mountains", Tile::Resource::ORE, 9));
    tiles.push_back(Tile("Mountains", Tile::Resource::LUMBER, 4));
    tiles.push_back(Tile("Desert", Tile::Resource::BRICK, 3)); 
}

void Board::createIntersections() {
	int number = 0;
    Intersections.push_back(Dot({tiles[0]}, number++)); // Dot 0
    Intersections.push_back(Dot({tiles[0]}, number++)); // Dot 1
    Intersections.push_back(Dot({tiles[1]}, number++)); // Dot 2
    Intersections.push_back(Dot({tiles[0], tiles[1]}, number++)); // Dot 3
    Intersections.push_back(Dot({tiles[0], tiles[2]}, number++)); // Dot 4
    Intersections.push_back(Dot({tiles[2]}, number++)); // Dot 5
    Intersections.push_back(Dot({tiles[3]}, number++)); // Dot 6
    Intersections.push_back(Dot({tiles[1], tiles[3]}, number++)); // Dot 7
    Intersections.push_back(Dot({tiles[0], tiles[1], tiles[4]}, number++)); // Dot 8
    Intersections.push_back(Dot({tiles[0], tiles[2], tiles[4]}, number++)); // Dot 9
    Intersections.push_back(Dot({tiles[2], tiles[5]}, number++)); // Dot 10
    Intersections.push_back(Dot({tiles[5]}, number++)); // Dot 11
    Intersections.push_back(Dot({tiles[3]}, number++)); // Dot 12
    Intersections.push_back(Dot({tiles[1], tiles[3], tiles[6]}, number++)); // Dot 13
    Intersections.push_back(Dot({tiles[1], tiles[4], tiles[6]}, number++)); // Dot 14
    Intersections.push_back(Dot({tiles[2], tiles[4], tiles[7]}, number++)); // Dot 15
    Intersections.push_back(Dot({tiles[2], tiles[5], tiles[7]}, number++)); // Dot 16
    Intersections.push_back(Dot({tiles[5]}, number++)); // Dot 17
    Intersections.push_back(Dot({tiles[3], tiles[8]}, number++)); // Dot 18
    Intersections.push_back(Dot({tiles[3], tiles[6], tiles[8]}, number++)); // Dot 19
    Intersections.push_back(Dot({tiles[4], tiles[6], tiles[9]}, number++)); // Dot 20
    Intersections.push_back(Dot({tiles[4], tiles[7], tiles[9]}, number++)); // Dot 21
    Intersections.push_back(Dot({tiles[5], tiles[7], tiles[10]}, number++)); // Dot 22
    Intersections.push_back(Dot({tiles[5], tiles[10]}, number++)); // Dot 23
    Intersections.push_back(Dot({tiles[8]}, number++)); // Dot 24
    Intersections.push_back(Dot({tiles[6], tiles[8], tiles[11]}, number++)); // Dot 25
    Intersections.push_back(Dot({tiles[6], tiles[9], tiles[11]}, number++)); // Dot 26
    Intersections.push_back(Dot({tiles[7], tiles[9], tiles[12]}, number++)); // Dot 27
    Intersections.push_back(Dot({tiles[7], tiles[10], tiles[12]}, number++)); // Dot 28
    Intersections.push_back(Dot({tiles[10]}, number++)); // Dot 29
    Intersections.push_back(Dot({tiles[8], tiles[13]}, number++)); // Dot 30
    Intersections.push_back(Dot({tiles[8], tiles[11], tiles[13]}, number++)); // Dot 31
    Intersections.push_back(Dot({tiles[9], tiles[11], tiles[14]}, number++)); // Dot 32
    Intersections.push_back(Dot({tiles[9], tiles[12], tiles[14]}, number++)); // Dot 33
    Intersections.push_back(Dot({tiles[10], tiles[12], tiles[15]}, number++)); // Dot 34
    Intersections.push_back(Dot({tiles[10], tiles[15]}, number++)); // Dot 35
    Intersections.push_back(Dot({tiles[13]}, number++)); // Dot 36
    Intersections.push_back(Dot({tiles[11], tiles[13], tiles[16]}, number++)); // Dot 37
    Intersections.push_back(Dot({tiles[11], tiles[14], tiles[16]}, number++)); // Dot 38
    Intersections.push_back(Dot({tiles[12], tiles[14], tiles[17]}, number++)); // Dot 39
    Intersections.push_back(Dot({tiles[12], tiles[15], tiles[17]}, number++)); // Dot 40
    Intersections.push_back(Dot({tiles[15]}, number++)); // Dot 41
    Intersections.push_back(Dot({tiles[13]}, number++)); // Dot 42
    Intersections.push_back(Dot({tiles[13], tiles[16]}, number++)); // Dot 43
    Intersections.push_back(Dot({tiles[14], tiles[16], tiles[18]}, number++)); // Dot 44
    Intersections.push_back(Dot({tiles[14], tiles[17], tiles[18]}, number++)); // Dot 45
    Intersections.push_back(Dot({tiles[15], tiles[17]}, number++)); // Dot 46
    Intersections.push_back(Dot({tiles[15]}, number++)); // Dot 47
    Intersections.push_back(Dot({tiles[16]}, number++)); // Dot 48
    Intersections.push_back(Dot({tiles[16], tiles[18]}, number++)); // Dot 49
    Intersections.push_back(Dot({tiles[17], tiles[18]}, number++)); // Dot 50
    Intersections.push_back(Dot({tiles[17]}, number++)); // Dot 51
    Intersections.push_back(Dot({tiles[18]}, number++)); // Dot 52
	Intersections.push_back(Dot({tiles[18]}, number)); // Dot 53


	Intersections[0].addNeighbors({&Intersections[1], &Intersections[3]});
    Intersections[1].addNeighbors({&Intersections[0], &Intersections[4]});
    Intersections[2].addNeighbors({&Intersections[3], &Intersections[7]});
    Intersections[3].addNeighbors({&Intersections[0], &Intersections[2], &Intersections[8]});
    Intersections[4].addNeighbors({&Intersections[1], &Intersections[5], &Intersections[9]});
    Intersections[5].addNeighbors({&Intersections[4], &Intersections[10]});
    Intersections[6].addNeighbors({&Intersections[7], &Intersections[12]});
    Intersections[7].addNeighbors({&Intersections[2], &Intersections[6], &Intersections[13]});
    Intersections[8].addNeighbors({&Intersections[3], &Intersections[9], &Intersections[14]});
    Intersections[9].addNeighbors({&Intersections[4], &Intersections[8], &Intersections[15]});
    Intersections[10].addNeighbors({&Intersections[5], &Intersections[11], &Intersections[16]});
    Intersections[11].addNeighbors({&Intersections[10], &Intersections[17]});
    Intersections[12].addNeighbors({&Intersections[6], &Intersections[18]});
    Intersections[13].addNeighbors({&Intersections[7], &Intersections[14], &Intersections[19]});
    Intersections[14].addNeighbors({&Intersections[8], &Intersections[13], &Intersections[20]});
    Intersections[15].addNeighbors({&Intersections[9], &Intersections[16], &Intersections[21]});
    Intersections[16].addNeighbors({&Intersections[10], &Intersections[15], &Intersections[22]});
    Intersections[17].addNeighbors({&Intersections[11], &Intersections[23]});
    Intersections[18].addNeighbors({&Intersections[12], &Intersections[19], &Intersections[24]});
    Intersections[19].addNeighbors({&Intersections[13], &Intersections[18], &Intersections[25]});
    Intersections[20].addNeighbors({&Intersections[14], &Intersections[21], &Intersections[26]});
    Intersections[21].addNeighbors({&Intersections[15], &Intersections[20], &Intersections[27]});
    Intersections[22].addNeighbors({&Intersections[16], &Intersections[23], &Intersections[28]});
    Intersections[23].addNeighbors({&Intersections[17], &Intersections[22], &Intersections[29]});
    Intersections[24].addNeighbors({&Intersections[18], &Intersections[30]});
    Intersections[25].addNeighbors({&Intersections[19], &Intersections[26], &Intersections[31]});
    Intersections[26].addNeighbors({&Intersections[20], &Intersections[25], &Intersections[32]});
    Intersections[27].addNeighbors({&Intersections[21], &Intersections[28], &Intersections[33]});
    Intersections[28].addNeighbors({&Intersections[22], &Intersections[27], &Intersections[34]});
    Intersections[29].addNeighbors({&Intersections[23], &Intersections[35]});
    Intersections[30].addNeighbors({&Intersections[24], &Intersections[31], &Intersections[36]});
    Intersections[31].addNeighbors({&Intersections[25], &Intersections[30], &Intersections[37]});
    Intersections[32].addNeighbors({&Intersections[26], &Intersections[33], &Intersections[38]});
    Intersections[33].addNeighbors({&Intersections[27], &Intersections[32], &Intersections[39]});
    Intersections[34].addNeighbors({&Intersections[28], &Intersections[35], &Intersections[40]});
    Intersections[35].addNeighbors({&Intersections[29], &Intersections[34], &Intersections[41]});
    Intersections[36].addNeighbors({&Intersections[30], &Intersections[42]});
    Intersections[37].addNeighbors({&Intersections[31], &Intersections[38], &Intersections[43]});
    Intersections[38].addNeighbors({&Intersections[32], &Intersections[37], &Intersections[44]});
    Intersections[39].addNeighbors({&Intersections[33], &Intersections[40], &Intersections[45]});
    Intersections[40].addNeighbors({&Intersections[34], &Intersections[39], &Intersections[46]});
    Intersections[41].addNeighbors({&Intersections[35], &Intersections[47]});
    Intersections[42].addNeighbors({&Intersections[36], &Intersections[43]});
    Intersections[43].addNeighbors({&Intersections[37], &Intersections[42], &Intersections[48]});
    Intersections[44].addNeighbors({&Intersections[38], &Intersections[45], &Intersections[49]});
    Intersections[45].addNeighbors({&Intersections[39], &Intersections[44], &Intersections[50]});
    Intersections[46].addNeighbors({&Intersections[40], &Intersections[47], &Intersections[51]});
    Intersections[47].addNeighbors({&Intersections[41], &Intersections[46]});
    Intersections[48].addNeighbors({&Intersections[43], &Intersections[49]});
    Intersections[49].addNeighbors({&Intersections[44], &Intersections[48], &Intersections[52]});
    Intersections[50].addNeighbors({&Intersections[45], &Intersections[51], &Intersections[52]});
    Intersections[51].addNeighbors({&Intersections[46], &Intersections[50]});
    Intersections[52].addNeighbors({&Intersections[49], &Intersections[53]});
    Intersections[53].addNeighbors({&Intersections[50], &Intersections[52]});

}

void Board::createRoads() {
	int number = 0;
	Roads.push_back(Road(&Intersections[0], &Intersections[1], number++)); // Road 0
    Roads.push_back(Road(&Intersections[0], &Intersections[3], number++)); // Road 1
    Roads.push_back(Road(&Intersections[1], &Intersections[4], number++)); // Road 2
    Roads.push_back(Road(&Intersections[2], &Intersections[3], number++)); // Road 3
    Roads.push_back(Road(&Intersections[4], &Intersections[5], number++)); // Road 4
    Roads.push_back(Road(&Intersections[2], &Intersections[7], number++)); // Road 5
    Roads.push_back(Road(&Intersections[3], &Intersections[8], number++)); // Road 6
    Roads.push_back(Road(&Intersections[4], &Intersections[9], number++)); // Road 7
    Roads.push_back(Road(&Intersections[5], &Intersections[10], number++)); // Road 8
    Roads.push_back(Road(&Intersections[6], &Intersections[7], number++)); // Road 9
    Roads.push_back(Road(&Intersections[8], &Intersections[9], number++)); // Road 10
    Roads.push_back(Road(&Intersections[10], &Intersections[11], number++)); // Road 11
    Roads.push_back(Road(&Intersections[6], &Intersections[12], number++)); // Road 12
    Roads.push_back(Road(&Intersections[7], &Intersections[13], number++)); // Road 13
    Roads.push_back(Road(&Intersections[8], &Intersections[14], number++)); // Road 14
    Roads.push_back(Road(&Intersections[9], &Intersections[15], number++)); // Road 15
    Roads.push_back(Road(&Intersections[10], &Intersections[16], number++)); // Road 16
    Roads.push_back(Road(&Intersections[11], &Intersections[17], number++)); // Road 17
    Roads.push_back(Road(&Intersections[13], &Intersections[14], number++)); // Road 18
    Roads.push_back(Road(&Intersections[15], &Intersections[16], number++)); // Road 19
    Roads.push_back(Road(&Intersections[12], &Intersections[18], number++)); // Road 20
    Roads.push_back(Road(&Intersections[13], &Intersections[19], number++)); // Road 21
    Roads.push_back(Road(&Intersections[14], &Intersections[20], number++)); // Road 22
    Roads.push_back(Road(&Intersections[15], &Intersections[21], number++)); // Road 23
    Roads.push_back(Road(&Intersections[16], &Intersections[22], number++)); // Road 24
    Roads.push_back(Road(&Intersections[17], &Intersections[23], number++)); // Road 25
    Roads.push_back(Road(&Intersections[18], &Intersections[19], number++)); // Road 26
    Roads.push_back(Road(&Intersections[20], &Intersections[21], number++)); // Road 27
    Roads.push_back(Road(&Intersections[22], &Intersections[23], number++)); // Road 28
    Roads.push_back(Road(&Intersections[18], &Intersections[24], number++)); // Road 29
    Roads.push_back(Road(&Intersections[19], &Intersections[25], number++)); // Road 30
    Roads.push_back(Road(&Intersections[20], &Intersections[26], number++)); // Road 31
    Roads.push_back(Road(&Intersections[21], &Intersections[27], number++)); // Road 32
    Roads.push_back(Road(&Intersections[22], &Intersections[28], number++)); // Road 33
    Roads.push_back(Road(&Intersections[23], &Intersections[29], number++)); // Road 34
    Roads.push_back(Road(&Intersections[25], &Intersections[26], number++)); // Road 35
    Roads.push_back(Road(&Intersections[27], &Intersections[28], number++)); // Road 36
    Roads.push_back(Road(&Intersections[24], &Intersections[30], number++)); // Road 37
    Roads.push_back(Road(&Intersections[25], &Intersections[31], number++)); // Road 38
    Roads.push_back(Road(&Intersections[26], &Intersections[32], number++)); // Road 39
    Roads.push_back(Road(&Intersections[27], &Intersections[33], number++)); // Road 40
    Roads.push_back(Road(&Intersections[28], &Intersections[34], number++)); // Road 41
    Roads.push_back(Road(&Intersections[29], &Intersections[35], number++)); // Road 42
    Roads.push_back(Road(&Intersections[30], &Intersections[31], number++)); // Road 43
    Roads.push_back(Road(&Intersections[32], &Intersections[33], number++)); // Road 44
    Roads.push_back(Road(&Intersections[34], &Intersections[35], number++)); // Road 45
    Roads.push_back(Road(&Intersections[30], &Intersections[36], number++)); // Road 46
    Roads.push_back(Road(&Intersections[31], &Intersections[37], number++)); // Road 47
    Roads.push_back(Road(&Intersections[32], &Intersections[38], number++)); // Road 48
    Roads.push_back(Road(&Intersections[33], &Intersections[39], number++)); // Road 49
    Roads.push_back(Road(&Intersections[34], &Intersections[40], number++)); // Road 50
    Roads.push_back(Road(&Intersections[35], &Intersections[41], number++)); // Road 51
    Roads.push_back(Road(&Intersections[37], &Intersections[38], number++)); // Road 52
    Roads.push_back(Road(&Intersections[39], &Intersections[40], number++)); // Road 53
    Roads.push_back(Road(&Intersections[36], &Intersections[42], number++)); // Road 54
    Roads.push_back(Road(&Intersections[37], &Intersections[43], number++)); // Road 55
    Roads.push_back(Road(&Intersections[38], &Intersections[44], number++)); // Road 56
    Roads.push_back(Road(&Intersections[39], &Intersections[45], number++)); // Road 57
    Roads.push_back(Road(&Intersections[40], &Intersections[46], number++)); // Road 58
    Roads.push_back(Road(&Intersections[41], &Intersections[47], number++)); // Road 59
    Roads.push_back(Road(&Intersections[42], &Intersections[43], number++)); // Road 60
    Roads.push_back(Road(&Intersections[44], &Intersections[45], number++)); // Road 61
    Roads.push_back(Road(&Intersections[46], &Intersections[47], number++)); // Road 62
    Roads.push_back(Road(&Intersections[43], &Intersections[48], number++)); // Road 63
    Roads.push_back(Road(&Intersections[44], &Intersections[49], number++)); // Road 64
    Roads.push_back(Road(&Intersections[45], &Intersections[50], number++)); // Road 65
    Roads.push_back(Road(&Intersections[46], &Intersections[51], number++)); // Road 66
    Roads.push_back(Road(&Intersections[48], &Intersections[49], number++)); // Road 67
    Roads.push_back(Road(&Intersections[50], &Intersections[51], number++)); // Road 68
    Roads.push_back(Road(&Intersections[49], &Intersections[52], number++)); // Road 69
    Roads.push_back(Road(&Intersections[50], &Intersections[53], number++)); // Road 70
    Roads.push_back(Road(&Intersections[52], &Intersections[53], number++)); // Road 71

}

/**
 * @brief Assign resources to players based on the rolled number.
 *
 * This function iterates through all the intersections (dots) on the board. 
 * For each dot, it checks if there is an owner (a player) and if so, 
 * iterates through all the neighboring tiles. If the tile's token number 
 * matches the rolled number and the tile is not where the robber is located, 
 * the function assigns resources to the player based on the building type 
 * at the dot (settlement or city).
 *
 * @param rolledNumber The number rolled, determining which tiles produce resources.
 */
void Board::assignResources(int rolledNumber) {
    for (Dot& dot : Intersections) {
        Player* owner = dot.getOwner();
        if (owner != nullptr) {
            for (const Tile& tile : dot.getNeighborTiles()) {
                int tileIndex = &tile - &tiles[0]; // Calculate the index of the tile
                if (tile.getToken() == rolledNumber && tileIndex != robberLocation) {
                    Tile::Resource resource = tile.getResource();
                    int resourceAmount = (dot.getBuildingType() == 1) ? 1 : (dot.getBuildingType() == 2) ? 2 : 0;
                    owner->getResources()[resource] += resourceAmount;
                }
            }
        }
    }
}

/**
 * @brief Assign starting resources to a specific dot.
 *
 * This function assigns resources to the owner of a specific dot 
 * based on the neighboring tiles. This is used when a player places 
 * their second settlement.
 *
 * @param dot The dot (intersection) to assign starting resources to.
 */
void Board::assignStartingResources(Dot& dot) {
    Player* owner = dot.getOwner();
    if (owner != nullptr) {
        for (const Tile& tile : dot.getNeighborTiles()) {
            Tile::Resource resource = tile.getResource();
            owner->getResources()[resource]++;
        }
    }
}

std::vector<Dot>& Board::getIntersections() {
    return Intersections;
}

std::vector<Tile>& Board::getTiles() {
    return tiles;
}

std::vector<Road>& Board::getRoads() {
    return Roads;
}

std::map<std::string, int>& Board::getDevelopmentCards() {
    return developmentCards;
}

void Board::setRobberLocation(int location) {
	robberLocation = location;
}
