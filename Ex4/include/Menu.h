#pragma once

#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include <string>

using std::string;

class Menu : protected Rectangle {

public:
	Menu();

	sf::RectangleShape getMenuShape();
	sf::RectangleShape getMenuShapei(const int i);
	sf::RectangleShape getSave();

	string getTextureName(const int i);

	void setMenuShape(const int i);
	void loadTexture();
	void loadTextureName();
	void changeSize(const int i);
	void returnSize(const int i);
	void setToSave(const int i);
	void setLocationSave(const float x, const float y);
	void setBoolPressed(const int i);
	bool getBoolPressed();
	int getIndex();

private:
	sf::RectangleShape m_save;
	string texture_names[9];
	bool m_pressed = false;
	int m_saveIndex = 0;
};

