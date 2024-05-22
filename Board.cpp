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
    assignNumberTokens();
}

void Board::createTiles() {
    // Create the correct number of each type of Tile
    for (int i = 0; i < 4; i++) {
        tiles.push_back(Tile("Forest", Tile::Resource::LUMBER, 0));
        tiles.push_back(Tile("Hills", Tile::Resource::BRICK, 0));
        tiles.push_back(Tile("Pasture", Tile::Resource::WOOL, 0));
    }
    for (int i = 0; i < 3; i++) {
        tiles.push_back(Tile("Mountains", Tile::Resource::ORE, 0));
        tiles.push_back(Tile("Fields", Tile::Resource::GRAIN, 0));
    }
    tiles.push_back(Tile("Desert", Tile::Resource::DESERT, 0));
}

void Board::assignNumberTokens() {
    // Assign number tokens to each Tile, skipping the desert
    std::vector<int> numbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine());
    for (Tile& tile : tiles) {
        if (tile.getResource() != Tile::Resource::DESERT) {
            tile.setNumberToken(numbers.back());
            numbers.pop_back();
        }
    }
}

void Board::assignStartingResources(Player player) {
    // Get the player's settlements
    auto settlements = playerSettlements[player];

    // Iterate over the player's settlements
    for (auto& settlement : settlements) {
        // Get the tiles adjacent to the settlement
        auto adjacentTiles = vertexTiles[settlement];

        // Iterate over the adjacent tiles
        for (auto& tile : adjacentTiles) {
            // Ensure the resource is in the map before incrementing
            auto resources = player.getResources();
            if (resources.count(tile.getResource()) > 0) {
                resources[tile.getResource()]++;
            }
        }
    }
}

void Board::placeInitialSettlements(Player player) {
    // Randomly select two vertices for the player's initial settlements
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, graph.size() - 1);

    // Keep track of occupied vertices
    std::set<int> occupiedVertices;

    for (int i = 0; i < 2; i++) {
        int vertex = dis(gen);

        // Ensure the vertex is not already occupied
        while (occupiedVertices.count(vertex) > 0) {
            vertex = dis(gen);
        }

        // Place the settlement
        playerSettlements[player].insert(vertex);
        occupiedVertices.insert(vertex);
    }
}
}
