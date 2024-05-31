// Player.cpp
#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <thread>
#include <random>

using namespace std;
namespace ariel{

ariel::Player::Player(const std::string& name) 
	: name(name),points(2) ,isTurn(false), startingSettlements(2), startingRoads(2), roads(2), hasThreeKnights(false), hasLongestRoad(false) {
	// Each player starts with 2 settlements and 2 road segments, giving them 2 victory points

	// Initialize the resources map with 0 for each resource type
	for (int i = static_cast<int>(Tile::Resource::BRICK); i <= static_cast<int>(Tile::Resource::DESERT); ++i) {
	    resources[static_cast<Tile::Resource>(i)] = 0;
	}
}

void Player::placeSettelemnt(int placeNum, Board& board) {
    if(!this->isTurn) {
        std::cout << "It is not your turn." << std::endl;
        return;
    }

    // Define the resources required to build a settlement
    std::map<Tile::Resource, int> requiredResources = {
        {Tile::Resource::BRICK, 1},
        {Tile::Resource::LUMBER, 1},
        {Tile::Resource::WOOL, 1},
        {Tile::Resource::GRAIN, 1}
    };

    // Check if the settlement is already owned
    Dot& settlement = board.getIntersections().at(placeNum);
    if (settlement.getOwner() != nullptr) {
        std::cout << "This settlement is already owned by another player." << std::endl;
        return;
    }

    // Check neighboring settlements
    for (Dot* neighbor : settlement.getNeighbors()) {
        if (neighbor->getOwner() != nullptr) {
            std::cout << "Cannot place settlement here. Neighboring settlement already owned by " << neighbor->getOwner()->getName() << std::endl;
            return;
        }
    }

    // If this is the first 2 settlements, no resources are required
    if(startingSettlements <= 0){
        // Check if the player has enough resources
        for (const auto& [resource, amount] : requiredResources) {
            if (this->resources[resource] < amount) {
                std::cout << "Not enough resources to place a settlement." << std::endl;
                return;
            }
        }

        // Deduct the resources from the player
        for (const auto& [resource, amount] : requiredResources) {
            this->resources[resource] -= amount;
        }
        points++;
    }

    // Place the settlement
    settlement.buildSettlement(this);

    // If this is the second settlement, assign starting resources
    if (startingSettlements == 1) {
        board.assignStartingResources(settlement);
    }
    startingSettlements--;

    std::cout << "Settlement placed successfully at position " << placeNum << "." << std::endl;
}


void Player::upgradeToCity(int placeNum, Board& board) {
	
	if(this->isTurn == false) {
		std::cout << "It is not your turn." << std::endl;
		return;
	}

    // Define the resources required to upgrade to a city
    std::map<Tile::Resource, int> requiredResources = {
        {Tile::Resource::ORE, 3},
        {Tile::Resource::GRAIN, 2}
    };

    // Check if the settlement exists and is owned by the player
    Dot& settlement = board.getIntersections()[placeNum];
    if (settlement.getOwner() != this) {
        std::cout << "This settlement is not owned by you." << std::endl;
        return;
    }

    // Check if the player has enough resources
    for (const auto& [resource, amount] : requiredResources) {
        if (this->resources[resource] < amount) {
            std::cout << "Not enough resources to upgrade to a city." << std::endl;
        	return;
        }
    }

    // Deduct the resources from the player
    for (const auto& [resource, amount] : requiredResources) {
        this->resources[resource] -= amount;
    }

	points++;
    // Upgrade the settlement to a city
    settlement.upgradeToCity();
    std::cout << "Settlement upgraded to a city at position " << placeNum << "." << std::endl;
}



void Player::placeRoad(int placeNum, Board& board) {

	if(this->isTurn == false) {
		std::cout << "It is not your turn." << std::endl;
		return;
	}
	
    // Define the resources required to build a road
    std::map<Tile::Resource, int> requiredResources = {
        {Tile::Resource::BRICK, 1},
        {Tile::Resource::LUMBER, 1}
    };

    // Access the road to be built
    Road& roadToBuild = board.getRoads()[placeNum];

    // Check if the road is already owned
    if (roadToBuild.getOwner() != nullptr) {
        std::cout << "There is already a road at this position." << std::endl;
        return;
    }

    // Get the dots connected by this road
    Dot* dotA = roadToBuild.getDot1();
    Dot* dotB = roadToBuild.getDot2();

    // Check if the new road connects to an existing road or settlement/city owned by the player
    bool validConnection = false;

    for (Dot* neighbor : dotA->getNeighbors()) {
        if (neighbor->getOwner() == this || dotA->getOwner() == this) {
            validConnection = true;
            break;
        }
    }
    for (Dot* neighbor : dotB->getNeighbors()) {
        if (neighbor->getOwner() == this || dotB->getOwner() == this) {
            validConnection = true;
            break;
        }
    }

    if (!validConnection) {
        std::cout << "The road must connect to an existing road or settlement/city owned by you." << std::endl;
        return;
    }

	// If this is the the first 2 roads, no resources are required
	if(startingRoads <= 0){

		// Check if the player has enough resources
		for (const auto& [resource, amount] : requiredResources) {
			if (this->resources[resource] < amount) {
				std::cout << "Not enough resources to build a road." << std::endl;
				return;
			}
		}

		// Deduct the resources from the player
		for (const auto& [resource, amount] : requiredResources) {
			this->resources[resource] -= amount;
		}
	}
	startingRoads--;

    // Set the owner of the road
    roadToBuild.buildRoad(this); 

    checkLongestRoad(board);

    std::cout << "Road built successfully at position " << placeNum << "." << std::endl;
}

void Player::checkLongestRoad(Board& board) {
    if (roads.size() >= 5) {
        std::vector<Player*>& players = board.getPlayers();
        for (Player* player : players) {
            if (player != this && player->hasLongestRoad) {
                player->points -= 2;
                player->hasLongestRoad = false;
                std::cout << player->getName() << " lost the longest road bonus." << std::endl;
            }
        }
        if (!hasLongestRoad) {
            points += 2;
            hasLongestRoad = true;
            std::cout << getName() << " gained the longest road bonus." << std::endl;
        }
    }
}

void Player::rollDice(Board& board) {
    if (!this->isTurn) {
        std::cout << "It is not your turn." << std::endl;
        return;
    }

    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(nullptr)); // Seed for randomness once
        seeded = true;
    }

    int die1 = std::rand() % 6 + 1;
    int die2 = std::rand() % 6 + 1;
    int rolledNumber = die1 + die2;

    std::cout << "You rolled a " << rolledNumber << " (" << die1 << " + " << die2 << ")." << std::endl;

    if (rolledNumber == 7) {
        std::cout << "Since you rolled a 7. Insert a tile number to place the robber: ";
        int tileNumber;

        bool validTile = false;
        while(!validTile){
            std::cin >> tileNumber;
            if(tileNumber < 0 || tileNumber > 18 || tileNumber == 7){
                cout << "Invalid tile number, Please enter a number between 0 and 18 (not 7): ";
            }else{
                validTile = true;
            }
        }
        board.setRobberLocation(tileNumber);
        std::cout << "Robber placed on tile " << tileNumber << "." << std::endl;
    } else {
        board.assignResources(rolledNumber);
    }
}


void Player::trade(Player& other, const std::string& give, const std::string& take, int giveAmount, int takeAmount) {

	if(this->isTurn == false) {
		std::cout << "It is not your turn." << std::endl;
		return;
	}

    std::cout << this->name << " offers " << giveAmount << " " << give << " for " << takeAmount << " " << take << " from " << other.name << "." << std::endl;

    char response;
    cout << "Does " << other.name << " agree to this trade? (Y/n): " << endl;
	cout << other.name << " is thinking whether to accept..." << endl;
	// Simulate a delay to make the game more interesting
	this_thread::sleep_for(std::chrono::seconds(2));
	// 50/50 chance she will accept the trade
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

	if (dis(gen) == 0) {
		response = 'Y';
	} else {
		response = 'n';
	}
    

    if (response == 'Y') {
        Tile::Resource giveResource = stringToResource(give);
        Tile::Resource takeResource = stringToResource(take);

        if (this->resources[giveResource] >= giveAmount && other.resources[takeResource] >= takeAmount) {
            this->resources[giveResource] -= giveAmount;
            this->resources[takeResource] += takeAmount;

            other.resources[takeResource] -= takeAmount;
            other.resources[giveResource] += giveAmount;

            std::cout << "Trade completed successfully." << std::endl;
        } else {
            std::cout << "Trade failed: insufficient resources." << std::endl;
        }
    } else {
        std::cout << "Trade cancelled." << std::endl;
    }
}

Tile::Resource Player::stringToResource(const std::string& resource) {
    if (resource == "brick") return Tile::Resource::BRICK;
    if (resource == "wood") return Tile::Resource::LUMBER;
    if (resource == "wool") return Tile::Resource::WOOL;
    if (resource == "grain") return Tile::Resource::GRAIN;
    if (resource == "ore") return Tile::Resource::ORE;
    throw std::invalid_argument("Unknown resource: " + resource);
}

void Player::buyDevelopmentCard(Board& board) {

	if(this->isTurn == false) {
		std::cout << "It is not your turn." << std::endl;
		return;
	}

    // Define the resources required to buy a development card
    std::map<Tile::Resource, int> requiredResources = {
        {Tile::Resource::ORE, 1},
        {Tile::Resource::WOOL, 1},
        {Tile::Resource::GRAIN, 1}
    };

    // Check if the player has enough resources
    for (const auto& [resource, amount] : requiredResources) {
        if (this->resources[resource] < amount) {
            std::cout << "Not enough resources to buy a development card." << std::endl;
        	return;
        }
    }


    // Get the available development cards from the board
    std::map<std::string, int>& availableCards = board.getDevelopmentCards();


    // Check if there are any development cards left
    bool cardsAvailable = false;
    for (const auto& [card, amount] : availableCards) {
        if (amount > 0) {
            cardsAvailable = true;
            break;
        }
    }

    if (!cardsAvailable) {
        std::cout << "No development cards left to draw." << std::endl;
        return;
    }

    // Deduct the resources from the player
    for (const auto& [resource, amount] : requiredResources) {
        this->resources[resource] -= amount;
    }

    // Randomly select a development card
    std::srand(std::time(nullptr));
    std::vector<std::string> cardTypes;
    for (const auto& [card, amount] : availableCards) {
        if (amount > 0) {
            cardTypes.push_back(card);
        }
    }

    std::string selectedCard = cardTypes[std::rand() % cardTypes.size()];
	
	if(selectedCard != "Knight"){
		points++;
	}
    // Add the card to the player's inventory and update the available cards on the board
    this->developmentCards[selectedCard]++;
    availableCards[selectedCard]--;

	checkKnights();

    std::cout << "Development card " << selectedCard << " bought successfully." << std::endl;
}

void Player::checkKnights() {
    if (developmentCards["Knight"] >= 3 && !hasThreeKnights) {
        points += 2;
        hasThreeKnights = true;
        std::cout << getName() << " gained the largest army bonus." << std::endl;
    }
}

int Player::getPoints() {
    return points;
}

void Player::printPoints() {
	std::cout << name << " has " << points << " points." << std::endl;
}

string Player::getName() {
	return name;
}

bool Player::getTurn() const{
	return isTurn;
}

map<Tile::Resource, int>& Player::getResources() {
    return resources;
}

void Player::setTurn(bool turn) {
    isTurn = turn;
}

void Player::printResources() const {
	cout << "Resources for " << name << ":" << endl;
    for (const auto& [resource, amount] : resources) {
        cout << "Resource: " << resourceToString(resource) << ", Amount: " << amount << endl;
    }
	cout << endl;
}

string Player::resourceToString(Tile::Resource resource) const {
    switch (resource) {
        case Tile::Resource::BRICK: return "BRICK";
        case Tile::Resource::LUMBER: return "LUMBER";
        case Tile::Resource::WOOL: return "WOOL";
        case Tile::Resource::GRAIN: return "GRAIN";
        case Tile::Resource::ORE: return "ORE";
        case Tile::Resource::DESERT: return "DESERT";
        default: return "UNKNOWN";
    }
}

void Player::printStats(){
	std::cout << "Player: " << name << std::endl;
	std::cout << "Development Cards: " << std::endl;
	for (const auto& [card, amount] : developmentCards) {
		std::cout << card << ": " << amount << std::endl;
	}
	std::cout << "Roads amount: " << roads.size() << std::endl;

	if(hasThreeKnights){
		std::cout << "Has biggest army" << std::endl;
	}

}

void Player::cheatResources() {

    cout << "Cheat activated for "  << this->name << ": Resources set to 500 each." << endl;
	for (int i = static_cast<int>(Tile::Resource::BRICK); i <= static_cast<int>(Tile::Resource::DESERT); ++i) {
		resources[static_cast<Tile::Resource>(i)] = 500;
	}
}

}