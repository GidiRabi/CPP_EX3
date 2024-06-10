# Catan - Classes and Inheritance

The Settlers of Catan is a board game for 3 to 4 players that combines strategic thinking, resource management, and trading skills. The objective of the game is to be the first to accumulate 10 victory points. You can find the full game rules [here](https://www.hakubia.com/wp-content/uploads/2021/01/%D7%A7%D7%98%D7%90%D7%9F.pdf). This project implements a simplified version of the game for 3 players.

## Game Rules

### Game Board
The game board consists of 19 hexagonal tiles, each representing different types of land:
- **Forest**: Produces lumber.
- **Hills**: Produces bricks.
- **Pasture**: Produces wool.
- **Fields**: Produces grain.
- **Mountains**: Produces ore.
- **Desert**: Produces no resources.

Each tile is assigned a number from 2 to 12. When a player rolls the dice, any tile matching the rolled number produces resources for adjacent settlements and cities.

### Players and Resources
Each player starts with:
- 2 settlements (worth 1 victory point each)
- 2 roads
- Initial resources based on the placement of their starting settlements.

Resources are used to build roads, settlements, cities, and to buy development cards. The resources include:
- **Lumber**
- **Brick**
- **Wool**
- **Grain**
- **Ore**

### Building and Development
Players can use resources to:
- **Build Roads**: Cost 1 brick and 1 lumber.
- **Build Settlements**: Cost 1 brick, 1 lumber, 1 wool, and 1 grain. Settlements must be placed on intersections connected by a road and at least two edges away from other settlements.
- **Upgrade Settlements to Cities**: Cost 3 ore and 2 grain. Cities produce double resources and are worth 2 victory points.
- **Buy Development Cards**: Cost 1 ore, 1 wool, and 1 grain. Development cards can provide bonuses such as additional victory points, knights for the largest army, and special actions.

### Gameplay
1. **Initial Placement**: Players take turns placing their initial settlements and roads.
2. **Turn Sequence**:
   - Roll two dice to produce resources.
   - Trade resources with other players.
   - Build roads, settlements, cities, or buy development cards.
3. **End of Turn**: The next player takes their turn.
4. **Special Rolls**: Rolling a 7 activates the robber, which blocks resource production for the tile it is placed on and forces players with more than 7 cards to discard half.
5. **Winning the Game**: The first player to reach 10 victory points wins.

## Project Structure

### Classes and Their Responsibilities

1. **Catan**: Manages the overall game flow, including turn management and determining the winner.
2. **Board**: Represents the game board, including tiles, intersections, and roads.
3. **Player**: Represents a player, managing their resources, settlements, roads, and development cards.
4. **Dot**: Represents intersections on the board where settlements and cities can be built.
5. **Road**: Represents roads that players can build between intersections.
6. **Tile**: Represents a tile on the game board, holding resource and token information.

### Main Function

The main function demonstrates the setup and a sample round of gameplay:
- Initializes players and the game board.
- Sets up the game window using SFML for graphical representation.
- Demonstrates placing settlements, roads, rolling dice, and trading resources.
- Prints player points and determines the winner.

### Dependencies

- **SFML**: Used for rendering the game board and UI elements.

## Compiling and Running

### Makefile

A `Makefile` is provided to compile and run the project. The `make catan` command compiles the main game and runs a demonstration of a single round of gameplay.

### Command

```sh
make catan
./catan
./
```
```sh
make clean
```

## Testing

Unit tests are provided to ensure the correct functionality of the game logic. Tests cover:

- Resource allocation
- Validity of building placements
- Turn management
- Development card purchases
- Victory point calculations

## Additional Notes

- Ensure the SFML library is installed on your system for graphical output.
- The project includes `Combined_Map.png` for the game board and `arial.ttf` for font rendering.

## Contact Information

For any queries, you can reach out to:

**Name**: Gidi Rabi  
**Email**: gidirabi111@gmail.com  
**Location**: Petah Tikva, Israel