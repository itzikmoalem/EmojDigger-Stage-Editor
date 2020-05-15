#include "Menu.h"
#include <SFML/Graphics.hpp>
#include<iostream>


Menu::Menu()	//constractur
{
	loadTextureName();
	loadTexture();
	building_menu(m_menu);
}

sf::RectangleShape Menu::getMenuShape()
{
	return m_menu;
}

void Menu::setMenuShape(const int i)
{
	m_menu = getMenu(i);
}

void Menu::loadTexture()		//load texturs & sprits menu
{
	for (int i = 0; i < 9; i++)
	{
		sf::Texture objTexture;
		objTexture.loadFromFile(this->texture_names[i]);
		m_texture.push_back(objTexture);
	}

	for (int i = 0; i < 9; i++) 
	{
		sf::Sprite objSprite;
		objSprite.setTexture(m_texture[i]);
		m_sprite.push_back(objSprite);
		m_sprite[i].setPosition(270 + (i * 80), 200);
	}
}
string Menu::getTextureName(const int i)
{
	return texture_names[i];
}
void Menu::loadTextureName()		//load from text 
{
	this->texture_names[0] = "digger.png";
	this->texture_names[1] = "monster.png";
	this->texture_names[2] = "stone.png";
	this->texture_names[3] = "diamond.png";
	this->texture_names[4] = "wall.png";
	this->texture_names[5] = "delete.png";
	this->texture_names[6] = "new.png";
	this->texture_names[7] = "save.png";
	this->texture_names[8] = "empty.png";
	this->loadTexture();
}
sf::RectangleShape Menu::getMenuShapei(const int i)
{
	return m_menu_rec[i];
}
void Menu::changeSize(const int i)
{
	changeSizeRec(i);
}
void Menu::returnSize(const int i)
{
	returnSizeRec(i);
}
void Menu::setToSave(const int i)		//save the button that is pressed
{
	m_save = getMenuShapei(i);
	m_saveIndex = i;
}
void Menu::setLocationSave(const float x, const float y)	//follow the cursor
{
	m_save.setPosition(x, y);
	m_save.setFillColor(sf::Color(255, 255, 255, 130));		//change brightness
}
void Menu::setBoolPressed(const int i)		//set bool member pressed
{
	if (i == 1)
		m_pressed = true;
	else
		m_pressed = false;
}

//get functions

bool Menu::getBoolPressed()
{
	if (m_pressed)
		return true;
	
	return false;
}
int Menu::getIndex()
{
	return m_saveIndex;
}
sf::RectangleShape Menu::getSave()
{
	return m_save;
}


