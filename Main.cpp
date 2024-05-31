#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <vector>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"

using namespace std;
using namespace ariel;

int main()
{

    cout << "Initializing players..." << endl;
    Player p1("Gidi");
    Player p2("Nael");
    Player p3("Ido");
    Catan catan(p1, p2, p3);

    cout << "Getting the game board..." << endl;
    Board& board = catan.getBoard(); // get the board of the game.

    // Set the window dimensions and UI layout variables
    const int windowWidth = 950;
    const int windowHeight = 550;
    const int topBarHeight = 50; // Height for the top bar where buttons will be

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Catan Game");
    sf::Texture mapTexture;
    sf::Sprite mapSprite;

    if (!mapTexture.loadFromFile("Combined_Map.png")) {
        cerr << "Error loading map textures" << endl;
        return -1;
    }

    mapSprite.setTexture(mapTexture);
    mapSprite.setPosition(0, topBarHeight);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Error loading font" << endl;
        return -1;
    }

    sf::Text MapText("The Map We Are Playing On!", font, 24);
    MapText.setPosition(windowWidth/3, 10);

    window.clear();
    window.draw(mapSprite);
    window.draw(MapText);
    window.display();

    // Wait for the user to close the window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //else if the user clicks anywhere on the map
            else if (event.type == sf::Event::MouseButtonPressed) {
                window.close();
            }
        }
    }

	// print player1 isTurn variable (boolean print true or false)
    cout << "Placing settlements and roads for player 1..." << endl;
    int placesNum = 5;
    p1.placeSettelemnt(placesNum, board); 
    p1.placeRoad(4, board);
    placesNum = 8;
    p1.placeSettelemnt(placesNum, board);
    p1.placeRoad(10, board); // p1 chooses Forest, hills, Agricultural Land, Desert with numbers 5, 6, 3, 4.

	catan.endTurn(); // p1 ends his turn.

    cout << "Placing settlements and roads for player 2..." << endl;
    placesNum = 20;
    p2.placeSettelemnt(placesNum, board);
    p2.placeRoad(27, board);
    try
    {
        cout << "Player 3 tries to place a settlement in the same location as player 2..." << endl;
        p3.placeSettelemnt(placesNum, board); // p3 tries to place a settlement in the same location as p2.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    cout << "Continuing to place settlements and roads for player 2..." << endl;
    placesNum = 39;
    p2.placeSettelemnt(placesNum, board);
    p2.placeRoad(49, board); // p2 chooses Mountains, Pasture Land, and Forest with numbers 4, 9, 5.
	catan.endTurn(); // p2 ends his turn.

    cout << "Placing settlements and roads for player 3..." << endl;
    placesNum = 37;
    p3.placeSettelemnt(placesNum, board);
    p3.placeRoad(52, board);
    placesNum = 13;
    p3.placeSettelemnt(placesNum, board);
    p3.placeRoad(21, board); // p3 chooses Mountains, Pasture Land, Agricultural Land, Pasture Land with numbers 3, 8, 3, 9.
	catan.endTurn(); // p3 ends his turn.

    // p1 has wood, bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    cout << "Player 1 rolls the dice..." << endl;
    p1.rollDice(board);           // Lets say it's print 4. Then, p2 gets ore from the mountains.
    cout << "Player 1 places a road..." << endl;
    p1.placeRoad(7, board);       // p1 continues to build a road. (if he can)
    catan.endTurn();              // p1 ends his turn.

    cout << "Player 2 rolls the dice..." << endl;
    p2.rollDice(board);           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    catan.endTurn();              // p2 ends his turn.

    cout << "Player 3 rolls the dice..." << endl;
    p3.rollDice(board);           // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
    catan.endTurn();              // p3 ends his turn.

    try
    {
        cout << "Player 2 tries to roll the dice again, but it's not his turn..." << endl;
        p2.rollDice(board); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    cout << "Player 1 rolls the dice..." << endl;
    p1.rollDice(board);                      // Lets say it's print 6. Then, p1 gets bricks from the hills.
    cout << "Player 1 trades with player 2..." << endl;
	p1.printResources();
	p2.printResources();
    p1.trade(p2, "wood", "brick", 1, 1);     // p1 trades 1 wood for 1 brick with p2.


	p1.cheatResources();
	p1.buyDevelopmentCard(board);
	p1.buyDevelopmentCard(board);
	p1.buyDevelopmentCard(board);
	p1.buyDevelopmentCard(board);
	p1.buyDevelopmentCard(board);
	p1.buyDevelopmentCard(board);
	p1.buyDevelopmentCard(board);
	p1.buyDevelopmentCard(board);


    catan.endTurn();                         // p1 ends his turn.

    cout << "Player 2 rolls the dice..." << endl;
    p2.rollDice(board);           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    cout << "Player 2 buys a development card..." << endl;
	p2.printResources();
    p2.buyDevelopmentCard(board); // p2 buys a development card. Lets say it is a bonus points card.
    catan.endTurn();              // p2 ends his turn.

    cout << "Printing points for all players..." << endl;
    p1.printPoints(); // p1 has 2 points because it has two settlements.
    p2.printPoints(); // p2 has 3 points because it has two settlements and a bonus points card.
    p3.printPoints(); // p3 has 2 points because it has two settlements.

    cout << "Printing the winner..." << endl;
    catan.printWinner(); // Should print None because no player reached 10 points.

    p1.printStats();



    return 0;

}
