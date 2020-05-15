#include "Rectangle.h"

Rectangle::Rectangle(){}	//constractur defualt

void Rectangle::building_menu(sf::RectangleShape &menu)		//building menu
{
	for (int i = 0; i < 9; i++)		//there is 8 buttons
	{
		sf::RectangleShape rec;
		rec.setSize(sf::Vector2f(70, 70));		//size of rectangle 
		 
		m_menu_rec.push_back(rec);
		m_menu_rec[i].setTexture(&m_texture[i]);
		m_menu_rec[i].setPosition(270 + (i * 80), 700);
	}
}
sf::RectangleShape Rectangle::getMenu(const int i)
{
	return m_menu_rec[i];
}

void Rectangle::changeSizeRec(const int i)
{
	m_menu_rec[i].setPosition(270 + (i * 80), 715);
}

void Rectangle::returnSizeRec(const int i)		
{
	m_menu_rec[i].setPosition(270 + (i * 80), 700);
}

void Rectangle::setNewObjBoard(const int i, const int j, sf::RectangleShape save,
	const int w, const int l, const int index, const int row, const int col)

//this function updating the board, it's working by indexs of vector m_menu_rec.
{
	if (i >= row || i < 0 || j >= col || j < 0)
		return;
	if (index == 5)		//delete
	{
		sf::RectangleShape empty = emptyObj(w, l);		//load empty

		m_board[i][j] = empty;
		m_saveBoard[i][j] = ' ';
	}
	else if (index == 0)	//digger
	{
		sf::RectangleShape empty = emptyObj(w, l);		//load empty

		m_board[m_idigger][m_jdigger] = empty;
		m_saveBoard[m_idigger][m_jdigger] = ' ';

		m_saveBoard[i][j] = '/';
		m_board[i][j] = save;
		
		m_idigger = i;
		m_jdigger = j;
	}
	if (index != 5)		//monster, stone, diamond, wall buttons
	{
		save.setSize(sf::Vector2f(w, l));
		save.setFillColor(sf::Color(255, 255, 255, 255));
		save.setPosition(100 + (j * w), i * l);
		m_board[i][j] = save;
		
		switch (index)
		{
		case 1: 
			m_saveBoard[i][j] = '!';
			break;

		case 2:
			m_saveBoard[i][j] = '@';
			break;

		case 3:
			m_saveBoard[i][j] = 'D';
			break;

		case 4:
			m_saveBoard[i][j] = '#';
			break;
		}
	}
}

sf::RectangleShape Rectangle::emptyObj(const int w, const int l)		//load empty rectangle
{
	sf::Texture temp;
	temp.loadFromFile("empty.png");
	sf::Sprite del;
	del.setTexture(temp);
	sf::RectangleShape empty;
	empty.setSize(sf::Vector2f(w, l));
	empty.setPosition(-100, -100);

	return empty;
}



