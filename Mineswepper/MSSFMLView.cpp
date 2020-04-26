#include "MineswepperBoard.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLEvents.h"
#include <iostream>





MSSFMLView::MSSFMLView(MinesweeperBoard& board) :board(board)
{
	pole = sf::Sprite();
	background = sf::Sprite();
	button[4] = sf::Sprite();	
	
	winner = sf::Text("Congratulations!\n  to play again\n    press space", font, 40);
	lost = sf::Text("   You lost! \nto play again \n press space", font, 40);

	NotRevealed.loadFromFile("icons/NotRevealed.png");
	Revealed[0].loadFromFile("icons/Revealed.png");
	Revealed[1].loadFromFile("icons/Revealed1.png");
	Revealed[2].loadFromFile("icons/Revealed2.png");
	Revealed[3].loadFromFile("icons/Revealed3.png");
	Revealed[4].loadFromFile("icons/Revealed4.png");
	Revealed[5].loadFromFile("icons/Revealed5.png");
	Revealed[6].loadFromFile("icons/Revealed6.png");
	Revealed[7].loadFromFile("icons/Revealed7.png");
	Revealed[8].loadFromFile("icons/Revealed8.png");
	Flag.loadFromFile("icons/Flag.png");
	Mine.loadFromFile("icons/Mine.png");
	MineExploded.loadFromFile("icons/MineExploded.png");

	Menu[0].loadFromFile("icons/Menu1.png");
	Menu[1].loadFromFile("icons/Menu2.png");
	Menu[2].loadFromFile("icons/LevelEasy.png");
	Menu[3].loadFromFile("icons/LevelNormal.png");
	Menu[4].loadFromFile("icons/LevelHard.png");

	text[0].loadFromFile("icons/play.png");
	text[1].loadFromFile("icons/Easy.png");
	text[2].loadFromFile("icons/Normal.png");
	text[3].loadFromFile("icons/Hard.png");

	font.loadFromFile("font/SundayBest.ttf");
}

void MSSFMLView::draw(sf::RenderWindow& win)
{

	for (int row = 0; row < board.getBoardHeight(); row++)
	{
		for (int col = 0; col < board.getBoardWidth(); col++)
		{
		
			check = board.getFieldInfo(row, col);
			if (check == '_') pole.setTexture(NotRevealed);
			if (check == ' ') pole.setTexture(Revealed[0]);
			for (int i = 0; i < 9; i++)
				if (check == i + '0') pole.setTexture(Revealed[i]);
			if (check == 'F') pole.setTexture(Flag);

			if (check == 'x') pole.setTexture(Mine);
			if (check == 'X') pole.setTexture(MineExploded);

			int x = 0 + 50 * row;
			int y = 0 + 50 * col;
			pole.setPosition(x, y);
			win.draw(pole);


		}
	}
	
}

void MSSFMLView::drawMenu(sf::RenderWindow& win)
{
	button[0].setTexture(text[0]);
	
	button[0].setPosition(118, 312);

	if (button[0].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win))))
		background.setTexture(Menu[1]);

	else background.setTexture(Menu[0]);

	win.draw(background);
	win.draw(button[0]);
	if (button[0].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win))) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		clicked = true;
}

void MSSFMLView::drawLevel(sf::RenderWindow& win)
{
	button[1].setTexture(text[1]);
	button[2].setTexture(text[2]);
	button[3].setTexture(text[3]);
	background.setTexture(Menu[1]);
	button[1].setPosition(118, 12);
	button[2].setPosition(68, 64);
	button[3].setPosition(118, 113);

	if (button[1].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win))))
		background.setTexture(Menu[2]);

	if (button[2].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win))))
		background.setTexture(Menu[3]);

	if (button[3].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win))))
		background.setTexture(Menu[4]);

	win.draw(background);
	win.draw(button[1]);
	win.draw(button[2]);
	win.draw(button[3]);
	if (button[1].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win))) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		board = MinesweeperBoard(9, 9, EASY);
		clicked = true;
	}
		
	else if (button[2].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win))) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		board = MinesweeperBoard(12, 12, NORMAL);
		clicked = true;
	}
	else if (button[3].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(win))) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		board = MinesweeperBoard(15, 15, HARD);
		clicked = true;
	}
}



void MSSFMLView::getTextWin(sf::RenderWindow& win)
{
	width = board.getBoardWidth();
	height = board.getBoardHeight();
	winner.setFillColor(sf::Color::White);
	winner.setOutlineThickness(2.5);
	winner.setOutlineColor(sf::Color::Black);
	winner.setOrigin(winner.getLocalBounds().width / 2, winner.getLocalBounds().height / 2);
	winner.setPosition(width * 50 / 2, height * 50 / 2);
	win.draw(winner);
}
void MSSFMLView::getTextLost(sf::RenderWindow& win)
{
	width = board.getBoardWidth();
	height = board.getBoardHeight();
	lost.setFillColor(sf::Color::White);
	lost.setOutlineThickness(2.5);
	lost.setOutlineColor(sf::Color::Black);
	lost.setOrigin(lost.getLocalBounds().width/2,lost.getLocalBounds().height/2);
	lost.setPosition(width*50 / 2, height*50 / 2);	
	win.draw(lost);
}

int MSSFMLView::getState()
{
	return state;
}

void MSSFMLView::setState(int x)
{
	state = x;
}










