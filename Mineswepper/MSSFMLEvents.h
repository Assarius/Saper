#pragma once
#include "MSSFMLView.h"
#include "MineswepperBoard.h"
class MSSFMLEvents
{
	MinesweeperBoard& board;
	MSSFMLView& view;
	sf::RenderWindow& win;
	
public:	
	MSSFMLEvents(MinesweeperBoard &board,MSSFMLView &view);
	void play(sf::RenderWindow &win);
};

