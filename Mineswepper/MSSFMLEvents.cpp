#include "MSSFMLEvents.h"
#include <SFML/Graphics.hpp>
#include "MineswepperBoard.h"
#include "MSSFMLView.h"
#include <iostream>
#include <vector>


MSSFMLEvents::MSSFMLEvents(MinesweeperBoard& board, MSSFMLView& view):board(board),view(view),win(win)
{
}

void MSSFMLEvents::play(sf::RenderWindow& win)
{

	int MousePosX = sf::Mouse::getPosition(win).x / 50;
	int	MousePosY = sf::Mouse::getPosition(win).y / 50;
	
	switch (view.getState())
	{
	case 0:
		view.drawMenu(win);
		if (view.clicked==true)
			view.setState(1);
			break;
	case 1:
		view.clicked = false;
		view.drawLevel(win);
		
		if (view.clicked == true)
		{
			int winWidth = this->board.getBoardWidth() * 50;
			int winHeight = this->board.getBoardHeight() * 50;
			win.create(sf::VideoMode(winWidth, winHeight), "Saper");
			view.setState(2);
		}
			
		break;

	case 2:
		view.clicked = false;
		view.draw(win);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				board.revealField(sf::Mouse::getPosition(win).x / 50, sf::Mouse::getPosition(win).y / 50);
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
				board.toggleFlag(sf::Mouse::getPosition(win).x / 50, sf::Mouse::getPosition(win).y / 50);
		
		if (board.getGameState() == FINISHED_LOSS)
		{
			view.getTextLost(win);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				win.create(sf::VideoMode(400, 400), "Saper");
				view.setState(1);
			}

		}
		if (board.getGameState() == FINISHED_WIN)
		{
			view.getTextWin(win);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				win.create(sf::VideoMode(400, 400), "Saper");
				view.setState(1);
			}
		}
		break;
	case 3:
		
		view.setState(1);
		break;
		


	}
}

