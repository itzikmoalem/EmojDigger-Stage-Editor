#pragma once
#include "SFML/Graphics.hpp"
#include "Rectangle.h"
#include "Menu.h"
#include "Board.h"

class Controller
{
public:
	Controller() {};
	void building_map();
	void eventMouse(sf::RenderWindow &window, Menu& menu, Board& board);
	void holdTheMouse(sf::RenderWindow& window, Menu& menu);
	void changeBoard(sf::RenderWindow& window, Menu& menu, Board& board);

private:

};



