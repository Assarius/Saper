#pragma once
#include "MineswepperBoard.h"
#include <SFML/Graphics.hpp>


class MSSFMLView
{
	sf::Texture NotRevealed,Revealed[9], Flag, Mine, MineExploded, Panel;
	MinesweeperBoard & board;
	sf::Sprite pole, panel;
	char check;
	GameState state;
	//sf::Text counter, time;
	sf::String counter;
	int height, width;


public:
	explicit MSSFMLView(MinesweeperBoard & board);
	void draw(sf::RenderWindow &win);
	int getBlockWidth();
	int getBlockHeight();
};