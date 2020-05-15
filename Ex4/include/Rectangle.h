#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

using std::vector;

class Rectangle
{
public:
	Rectangle();

	sf::RectangleShape getMenu(const int i);
	sf::RectangleShape emptyObj(const int w, const int l);

	void building_menu(sf::RectangleShape& menu);
	void changeSizeRec(const int i);
	void returnSizeRec(const int i);
	void setNewObjBoard(const int i, const int j, sf::RectangleShape save,
		const int w, const int l, const int index, const int row, const int col);
	
private:

protected:

	sf::RectangleShape m_menu;

	vector<sf::Texture> m_texture;		//membres for menu
	vector<sf::Sprite> m_sprite;
	vector<sf::RectangleShape> m_menu_rec;

	vector<vector<char>> m_saveBoard;		//for save board

	vector<vector<sf::RectangleShape>> m_board;		//members for board
	vector<vector<sf::Sprite>> m_boardSprite;
	vector<vector<sf::Texture>> m_boardTexture;

	int m_idigger = 0;
	int m_jdigger = 0;
};


