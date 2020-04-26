#pragma once
#include "MineswepperBoard.h"
#include <SFML/Graphics.hpp>


class MSSFMLView
{
	sf::Texture NotRevealed, Revealed[9], Flag, Mine, MineExploded, Menu[5], text[4];
	sf::Font font;
	sf::Text winner, lost;
	MinesweeperBoard & board;
	sf::Sprite pole, background,button[4];
	char check;
	sf::String counter;
	int height, width;
	int state;

public:
	explicit MSSFMLView(MinesweeperBoard & board);
	void draw(sf::RenderWindow &win);
	void drawMenu(sf::RenderWindow& win);
	void drawLevel(sf::RenderWindow& win);
	void getTextWin(sf::RenderWindow& win);
	void getTextLost(sf::RenderWindow& win);
	int getState();
	void setState(int x);
	bool clicked = false;
	

	
};

