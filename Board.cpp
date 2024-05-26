// Board.cpp
#include "Board.hpp"
#include "Player.hpp" // Include the header file for the Player class
#include <algorithm>
#include <random>

namespace ariel {
Board::Board() {
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
    Intersections.push_back(Dot({tiles[0]})); // Dot 0
    Intersections.push_back(Dot({tiles[0]})); // Dot 1
    Intersections.push_back(Dot({tiles[1]})); // Dot 2
    Intersections.push_back(Dot({tiles[0], tiles[1]})); // Dot 3
    Intersections.push_back(Dot({tiles[0], tiles[2]})); // Dot 4
    Intersections.push_back(Dot({tiles[2]})); // Dot 5
    Intersections.push_back(Dot({tiles[3]})); // Dot 6
    Intersections.push_back(Dot({tiles[1], tiles[3]})); // Dot 7
    Intersections.push_back(Dot({tiles[0], tiles[1], tiles[4]})); // Dot 8
    Intersections.push_back(Dot({tiles[0], tiles[2], tiles[4]})); // Dot 9
    Intersections.push_back(Dot({tiles[2], tiles[5]})); // Dot 10
    Intersections.push_back(Dot({tiles[5]})); // Dot 11
    Intersections.push_back(Dot({tiles[3]})); // Dot 12
    Intersections.push_back(Dot({tiles[1], tiles[3], tiles[6]})); // Dot 13
    Intersections.push_back(Dot({tiles[1], tiles[4], tiles[6]})); // Dot 14
    Intersections.push_back(Dot({tiles[2], tiles[4], tiles[7]})); // Dot 15
    Intersections.push_back(Dot({tiles[2], tiles[5], tiles[7]})); // Dot 16
    Intersections.push_back(Dot({tiles[5]})); // Dot 17
    Intersections.push_back(Dot({tiles[3], tiles[8]})); // Dot 18
    Intersections.push_back(Dot({tiles[3], tiles[6], tiles[8]})); // Dot 19
    Intersections.push_back(Dot({tiles[4], tiles[6], tiles[9]})); // Dot 20
    Intersections.push_back(Dot({tiles[4], tiles[7], tiles[9]})); // Dot 21
    Intersections.push_back(Dot({tiles[5], tiles[7], tiles[10]})); // Dot 22
    Intersections.push_back(Dot({tiles[5], tiles[10]})); // Dot 23
    Intersections.push_back(Dot({tiles[8]})); // Dot 24
    Intersections.push_back(Dot({tiles[6], tiles[8], tiles[11]})); // Dot 25
    Intersections.push_back(Dot({tiles[6], tiles[9], tiles[11]})); // Dot 26
    Intersections.push_back(Dot({tiles[7], tiles[9], tiles[12]})); // Dot 27
    Intersections.push_back(Dot({tiles[7], tiles[10], tiles[12]})); // Dot 28
    Intersections.push_back(Dot({tiles[10]})); // Dot 29
    Intersections.push_back(Dot({tiles[8], tiles[13]})); // Dot 30
    Intersections.push_back(Dot({tiles[8], tiles[11], tiles[13]})); // Dot 31
    Intersections.push_back(Dot({tiles[9], tiles[11], tiles[14]})); // Dot 32
    Intersections.push_back(Dot({tiles[9], tiles[12], tiles[14]})); // Dot 33
    Intersections.push_back(Dot({tiles[10], tiles[12], tiles[15]})); // Dot 34
    Intersections.push_back(Dot({tiles[10], tiles[15]})); // Dot 35
    Intersections.push_back(Dot({tiles[13]})); // Dot 36
    Intersections.push_back(Dot({tiles[11], tiles[13], tiles[16]})); // Dot 37
    Intersections.push_back(Dot({tiles[11], tiles[14], tiles[16]})); // Dot 38
    Intersections.push_back(Dot({tiles[12], tiles[14], tiles[17]})); // Dot 39
    Intersections.push_back(Dot({tiles[12], tiles[15], tiles[17]})); // Dot 40
    Intersections.push_back(Dot({tiles[15]})); // Dot 41
    Intersections.push_back(Dot({tiles[13]})); // Dot 42
    Intersections.push_back(Dot({tiles[13], tiles[16]})); // Dot 43
    Intersections.push_back(Dot({tiles[14], tiles[16], tiles[18]})); // Dot 44
    Intersections.push_back(Dot({tiles[14], tiles[17], tiles[18]})); // Dot 45
    Intersections.push_back(Dot({tiles[15], tiles[17]})); // Dot 46
    Intersections.push_back(Dot({tiles[15]})); // Dot 47
    Intersections.push_back(Dot({tiles[16]})); // Dot 48
    Intersections.push_back(Dot({tiles[16], tiles[18]})); // Dot 49
    Intersections.push_back(Dot({tiles[17], tiles[18]})); // Dot 50
    Intersections.push_back(Dot({tiles[17]})); // Dot 51
    Intersections.push_back(Dot({tiles[18]})); // Dot 52
	Intersections.push_back(Dot({tiles[18]})); // Dot 53

}

void Board::createRoads() {
	Roads.push_back(Road(&Intersections[0], &Intersections[1])); // Road 0
    Roads.push_back(Road(&Intersections[0], &Intersections[3])); // Road 1
    Roads.push_back(Road(&Intersections[1], &Intersections[4])); // Road 2
    Roads.push_back(Road(&Intersections[2], &Intersections[3])); // Road 3
    Roads.push_back(Road(&Intersections[4], &Intersections[5])); // Road 4
    Roads.push_back(Road(&Intersections[2], &Intersections[7])); // Road 5
    Roads.push_back(Road(&Intersections[3], &Intersections[8])); // Road 6
    Roads.push_back(Road(&Intersections[4], &Intersections[9])); // Road 7
    Roads.push_back(Road(&Intersections[5], &Intersections[10])); // Road 8
    Roads.push_back(Road(&Intersections[6], &Intersections[7])); // Road 9
    Roads.push_back(Road(&Intersections[8], &Intersections[9])); // Road 10
    Roads.push_back(Road(&Intersections[10], &Intersections[11])); // Road 11
    Roads.push_back(Road(&Intersections[6], &Intersections[12])); // Road 12
    Roads.push_back(Road(&Intersections[7], &Intersections[13])); // Road 13
    Roads.push_back(Road(&Intersections[8], &Intersections[14])); // Road 14
    Roads.push_back(Road(&Intersections[9], &Intersections[15])); // Road 15
    Roads.push_back(Road(&Intersections[10], &Intersections[16])); // Road 16
    Roads.push_back(Road(&Intersections[11], &Intersections[17])); // Road 17
    Roads.push_back(Road(&Intersections[13], &Intersections[14])); // Road 18
    Roads.push_back(Road(&Intersections[15], &Intersections[16])); // Road 19
    Roads.push_back(Road(&Intersections[12], &Intersections[18])); // Road 20
    Roads.push_back(Road(&Intersections[13], &Intersections[19])); // Road 21
    Roads.push_back(Road(&Intersections[14], &Intersections[20])); // Road 22
    Roads.push_back(Road(&Intersections[15], &Intersections[21])); // Road 23
    Roads.push_back(Road(&Intersections[16], &Intersections[22])); // Road 24
    Roads.push_back(Road(&Intersections[17], &Intersections[23])); // Road 25
    Roads.push_back(Road(&Intersections[18], &Intersections[19])); // Road 26
    Roads.push_back(Road(&Intersections[20], &Intersections[21])); // Road 27
    Roads.push_back(Road(&Intersections[22], &Intersections[23])); // Road 28
    Roads.push_back(Road(&Intersections[18], &Intersections[24])); // Road 29
    Roads.push_back(Road(&Intersections[19], &Intersections[25])); // Road 30
    Roads.push_back(Road(&Intersections[20], &Intersections[26])); // Road 31
    Roads.push_back(Road(&Intersections[21], &Intersections[27])); // Road 32
    Roads.push_back(Road(&Intersections[22], &Intersections[28])); // Road 33
    Roads.push_back(Road(&Intersections[23], &Intersections[29])); // Road 34
    Roads.push_back(Road(&Intersections[25], &Intersections[26])); // Road 35
    Roads.push_back(Road(&Intersections[27], &Intersections[28])); // Road 36
    Roads.push_back(Road(&Intersections[24], &Intersections[30])); // Road 37
    Roads.push_back(Road(&Intersections[25], &Intersections[31])); // Road 38
    Roads.push_back(Road(&Intersections[26], &Intersections[32])); // Road 39
    Roads.push_back(Road(&Intersections[27], &Intersections[33])); // Road 40
    Roads.push_back(Road(&Intersections[28], &Intersections[34])); // Road 41
    Roads.push_back(Road(&Intersections[29], &Intersections[35])); // Road 42
    Roads.push_back(Road(&Intersections[30], &Intersections[31])); // Road 43
    Roads.push_back(Road(&Intersections[32], &Intersections[33])); // Road 44
    Roads.push_back(Road(&Intersections[34], &Intersections[35])); // Road 45
    Roads.push_back(Road(&Intersections[30], &Intersections[36])); // Road 46
    Roads.push_back(Road(&Intersections[31], &Intersections[37])); // Road 47
    Roads.push_back(Road(&Intersections[32], &Intersections[38])); // Road 48
    Roads.push_back(Road(&Intersections[33], &Intersections[39])); // Road 49
    Roads.push_back(Road(&Intersections[34], &Intersections[40])); // Road 50
    Roads.push_back(Road(&Intersections[35], &Intersections[41])); // Road 51
    Roads.push_back(Road(&Intersections[37], &Intersections[38])); // Road 52
    Roads.push_back(Road(&Intersections[39], &Intersections[40])); // Road 53
    Roads.push_back(Road(&Intersections[36], &Intersections[42])); // Road 54
    Roads.push_back(Road(&Intersections[37], &Intersections[43])); // Road 55
    Roads.push_back(Road(&Intersections[38], &Intersections[44])); // Road 56
    Roads.push_back(Road(&Intersections[39], &Intersections[45])); // Road 57
    Roads.push_back(Road(&Intersections[40], &Intersections[46])); // Road 58
    Roads.push_back(Road(&Intersections[41], &Intersections[47])); // Road 59
    Roads.push_back(Road(&Intersections[42], &Intersections[43])); // Road 60
    Roads.push_back(Road(&Intersections[44], &Intersections[45])); // Road 61
    Roads.push_back(Road(&Intersections[46], &Intersections[47])); // Road 62
    Roads.push_back(Road(&Intersections[43], &Intersections[48])); // Road 63
    Roads.push_back(Road(&Intersections[44], &Intersections[49])); // Road 64
    Roads.push_back(Road(&Intersections[45], &Intersections[50])); // Road 65
    Roads.push_back(Road(&Intersections[46], &Intersections[51])); // Road 66
    Roads.push_back(Road(&Intersections[48], &Intersections[49])); // Road 67
    Roads.push_back(Road(&Intersections[50], &Intersections[51])); // Road 68
    Roads.push_back(Road(&Intersections[49], &Intersections[52])); // Road 69
    Roads.push_back(Road(&Intersections[50], &Intersections[53])); // Road 70
}


void Board::assignStartingResources(Dot& dot) {
    // Get the owner of the settlement
    Player* owner = dot.getOwner();

    // Check if the dot has an owner
    if (owner == nullptr) {
        return;
    }

    // Get the tiles adjacent to the settlement
    auto adjacentTiles = dot.getNeighborTiles();

    // Iterate over the adjacent tiles
    for (auto& tile : adjacentTiles) {
        // Get the resource of the tile
        Tile::Resource resource = tile.getResource();

        // Increment the resource count of the player
        owner->getResources()[resource]++;
    }
}
}
