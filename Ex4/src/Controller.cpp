#include "Controller.h"

void Controller::building_map()
{
	auto window = sf::RenderWindow(sf::VideoMode(1200, 800), "Digger: Create a Level!");

	Menu menu;
	Board board(window);

	sf::Texture Texture;	//load background
	Texture.loadFromFile("background.png");
	sf::Sprite background;
	background.setTexture(Texture);

	while (window.isOpen())
	{
		window.clear();

		window.draw(background);

		holdTheMouse(window, menu);		//moving menu effect
		eventMouse(window, menu, board);	//events

		if (menu.getBoolPressed())
		{
			changeBoard(window, menu, board);
		}

		for (int i = 0; i < 8; i++)		//draw 8 buttons
		{
			window.draw(menu.getMenuShapei(i));		//get RectangleShape in index i
		}

		for (int i = 0; i < board.getRows(); i++)	//draw board
		{
			for (int j = 0; j < board.getCols(); j++)
			{
				window.draw(board.getBoardShapeij(i, j));
			}
		}

		window.draw(menu.getSave());	//draw the mouse 

		window.display();

		for (auto event = sf::Event{}; window.pollEvent(event); )
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
}

void Controller::eventMouse(sf::RenderWindow& window, Menu& menu, Board &board)
{
	sf::Vector2i mouseLoc = sf::Mouse::getPosition(window);		//save always mouse location 

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (sf::Event::EventType::MouseButtonReleased)
		{
			int x = sf::Mouse::getPosition(window).x;
			int y = sf::Mouse::getPosition(window).y;

			if (x >= 270 && x <= 980 && y >= 700 && y > 0)
			{
				if (x <= 340)				//pressed on the digger
					menu.setToSave(0);

				if (x > 350 && x <= 420)	//pressed on the monster
					menu.setToSave(1);

				if (x > 430 && x <= 500)	//pressed on the stone
					menu.setToSave(2);

				if (x > 510 && x <= 580)	//pressed on the diamond
					menu.setToSave(3);

				if (x > 590 && x <= 660)	//pressed on the wall
					menu.setToSave(4);

				if (x > 670 && x <= 740)	//pressed on the delete
					menu.setToSave(5);

				if (x > 750 && x <= 820)	//pressed on the new
				{
					window.clear();

					sf::Texture Texture;		//backgronud texture
					Texture.loadFromFile("background_start.png");
					sf::Sprite background;
					background.setTexture(Texture);

					window.draw(background);

					window.display();

					board.newValue();		//open terminal
					board.clearBoard();
				}

				if (x > 830 && x <= 900)	//pressed on the save
					board.saveBoard();

				menu.setBoolPressed(1);
			}

			else if (x < 270 && x > 980 && y >= 700 && y>0)
				menu.setBoolPressed(0);
		}
	}
	menu.setLocationSave(static_cast<float>(mouseLoc.x) - 35, static_cast<float>(mouseLoc.y)- 35);
}

void Controller::holdTheMouse(sf::RenderWindow& window, Menu& menu)		//moving button effect
{
	int x = sf::Mouse::getPosition(window).x;
	int y = sf::Mouse::getPosition(window).y;

	if (x >= 270 && x <= 980 && y >= 700 && y> 0)		//Menu Size
	{
		if (x > 270 && x <= 340)				//mouse on the digger
			menu.changeSize(0);
		else
			menu.returnSize(0);

		if (x > 350 && x <= 420)				//mouse on the monster
			menu.changeSize(1);
		else
			menu.returnSize(1);

		if (x > 430 && x <= 500)				//mouse on the stone
			menu.changeSize(2);
		else
			menu.returnSize(2);

		if (x > 510 && x <= 580)				//mouse on the diamond
			menu.changeSize(3);
		else
			menu.returnSize(3);

		if (x > 590 && x <= 660)				//mouse on the wall
			menu.changeSize(4);
		else
			menu.returnSize(4);

		if (x > 670 && x <= 740)				//mouse on the delete
			menu.changeSize(5);
		else
			menu.returnSize(5);

		if (x > 750 && x <= 820)				//mouse on the new
			menu.changeSize(6);
		else
			menu.returnSize(6);

		if (x > 830 && x <= 900)				//mouse on the save
			menu.changeSize(7);
		else
			menu.returnSize(7);
	}
	else
		for (int i = 0; i < 8; i++)
			menu.returnSize(i);
}

void Controller::changeBoard(sf::RenderWindow& window, Menu& menu, Board& board)
{
	sf::Vector2i mouseLoc = sf::Mouse::getPosition(window);		//save always mouse location 

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int x = sf::Mouse::getPosition(window).x;
		int y = sf::Mouse::getPosition(window).y;

		if (x > 100 && x < 1090 && y < 640 && y > 0)		//Board Size
		{
			int width = board.getWidth() / board.getCols();		
			int length = board.getLength() / board.getRows();
			
			int j = (x-100) / width;	// -100 for the empty board 
			int i = (y) / length;

			board.setNewObj(i, j, menu.getSave() , menu.getIndex());
		}
	}
}
