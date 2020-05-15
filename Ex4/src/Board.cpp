#include "Board.h"

using std::string;
using std::ifstream;

Board::Board(sf::RenderWindow &window)		//constractur
{
	if (!loadLevel())		//if there is'nt Board.txt
	{
		sf::Texture Texture;
		Texture.loadFromFile("background_start.png");
		sf::Sprite background;
		background.setTexture(Texture);

		window.draw(background);

		window.display();
			
		newValue();		//open terminal
		resizeBoard();

		int width_s = WIDTH / m_Cols;
		int lentgh_s = LENGTH / m_Rows;

		sf::RectangleShape empty;
		empty.setFillColor(sf::Color::Black);

		for (int x = 0; x < m_Rows; x++)
		{
			for (int y = 0; y < m_Cols; y++)
			{
				empty.setPosition(100 + (x * width_s), (y * lentgh_s));
				m_board[x][y] = empty;
			}
		}
	}
}

bool Board::loadLevel()		//check if there is a Board.txt exist.
{
	ifstream myFile("Board.txt");	
	if (!myFile.is_open())		//if there isn't a file
	{
		//std::cout << "no" << std::endl;
		return false;
	}
	string num;
	char c;
	int x = 0, y = 0;

	myFile >> num;
	m_Rows = stoi(num);

	myFile >> num;
	m_Cols = stoi(num);

	myFile >> num;
	m_Stones = stoi(num);

	resizeBoard();

	int width_s = WIDTH / m_Cols;
	int lentgh_s = LENGTH / m_Rows;

	myFile.get(c);

	while (!myFile.eof())		//read myFile into the board
	{
		//std::cout << c;
		myFile.get(c);
		std::cout << c;

		if (myFile.peek() == myFile.eof() && c == ' ')
		{
			std::cout << myFile.peek() << std::endl;
			break;
		}

		if (c == 10)
			myFile.get(c);
		
		sf::RectangleShape rec;
		rec.setSize(sf::Vector2f(width_s, lentgh_s));
		rec.setPosition(100+ (x * width_s), (y * lentgh_s));

		sf::Texture pic;
		sf::Sprite objSprite;

		objSprite.setPosition(100 + (x * width_s), (y * lentgh_s));



		switch (c)
		{
		case '#':
			pic.loadFromFile("wall.png");
			objSprite.setTexture(pic);
			m_boardTexture[y][x] = pic;
			m_boardSprite[y][x] = objSprite;
			rec.setTexture(&m_boardTexture[y][x]);
			break;

		case '@':
			pic.loadFromFile("stone.png");
			objSprite.setTexture(pic);
			m_boardTexture[y][x] = pic;
			m_boardSprite[y][x] = objSprite;
			rec.setTexture(&m_boardTexture[y][x]);
			break;

		case '!':
			pic.loadFromFile("monster.png");
			objSprite.setTexture(pic);
			m_boardTexture[y][x] = pic;
			m_boardSprite[y][x] = objSprite;
			rec.setTexture(&m_boardTexture[y][x]);
			break;

		case '/':
			pic.loadFromFile("digger.png");
			objSprite.setTexture(pic);
			m_boardTexture[y][x] = pic;
			m_boardSprite[y][x] = objSprite;
			rec.setTexture(&m_boardTexture[y][x]);
			m_idigger = y;
			m_jdigger = x;
			break;

		case 'D':
			pic.loadFromFile("diamond.png");
			objSprite.setTexture(pic);
			m_boardTexture[y][x] = pic;
			m_boardSprite[y][x] = objSprite;
			rec.setTexture(&m_boardTexture[y][x]);
			break;

		case ' ':
			pic.loadFromFile("empty.png");
			objSprite.setTexture(pic);
			m_boardTexture[y][x] = pic;
			m_boardSprite[y][x] = objSprite;
			rec.setTexture(&m_boardTexture[y][x]);
			break;
		} 

		m_board[y][x] = rec;

		if (x < m_Cols)		//kind of loop
			x++;
		if (x == m_Cols)
		{
			if (y < m_Rows)
				y++;
			x = 0;
		}
	}
	return true;
}

void Board::resizeBoard()		//resize board
{
	m_board.resize(m_Rows);
	m_boardSprite.resize(m_Rows);
	m_boardTexture.resize(m_Rows);
	m_saveBoard.resize(m_Rows);

	for (int i = 0; i < m_Rows; i++)
	{
		m_boardSprite[i].resize(m_Cols);
		m_boardTexture[i].resize(m_Cols);
		m_board[i].resize(m_Cols);
		m_saveBoard[i].resize(m_Cols);
	}
}

//get functions

int Board::getRows()
{
	return m_Rows;
}

int Board::getCols()
{
	return m_Cols;
}

sf::RectangleShape Board::getBoardShapeij(const int i, const int j)
{
	return m_board[i][j];
}

sf::Texture Board::getTexture(const int i)
{
	return m_texture[i];
}

int Board::getWidth()
{
	return WIDTH;
}

int Board::getLength()
{
	return LENGTH;
}

void Board::setNewObj(const int i, const int j, sf::RectangleShape save, const int index)
{
	setNewObjBoard(i, j, save, WIDTH / m_Cols, LENGTH / m_Rows, index, m_Rows, m_Cols);
}

void Board::newValue()		//couts to terminal
{
	std::cout << "Please Enter Number of Rows: ";
	std::cin >> m_Rows;
	std::cout << std::endl << "Please Enter Number of Cols: ";
	std::cin >> m_Cols;
	std::cout << std::endl << "Please Enter Number of Stones: ";
	std::cin >> m_Stones;
}

void Board::clearBoard()		//new pressed -> clean board
{
	sf::RectangleShape empty = emptyObj(WIDTH / m_Cols, LENGTH / m_Rows);

	resizeBoard();

	for (int i = 0; i < m_Rows; i++)
	{
		for (int j = 0; j < m_Cols; j++)
			m_board[i][j] = empty;
	}
}

void Board::saveBoard()		//save Board.txt to 'out' folder
{
	std::ofstream myFile;
	myFile.open("Board.txt");

	myFile << m_Rows << " " << m_Cols << " " << m_Stones << std::endl << std::endl;

	for (int i = 0; i < m_Rows; i++)
	{
		for (int j = 0; j < m_Cols; j++)
		{
			myFile << m_saveBoard[i][j];
		}
		myFile << std::endl;
	}

	myFile.close();
	exit(1);
}
