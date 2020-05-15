#pragma once

#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Menu.h"

using std::string;

const int WIDTH = 1000;
const int LENGTH = 650;

class Board : protected Rectangle {

public:
	Board(sf::RenderWindow& window);
	bool loadLevel();
	void resizeBoard();
	int getRows();
	int getCols();
	sf::RectangleShape getBoardShapeij(const int i, const int j);
	sf::Texture getTexture(const int i);
	int getWidth();
	int getLength();
	void setNewObj(const int i, const int j, sf::RectangleShape save, const int index);
	void newValue();
	void clearBoard();
	void saveBoard();

private:

	int m_Rows = 0;
	int m_Cols = 0;
	int m_Stones = 0;
};

