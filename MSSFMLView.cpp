#include "MineswepperBoard.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <iostream>





MSSFMLView::MSSFMLView(MinesweeperBoard & board):board(board)
{
	pole = sf::Sprite();
	width = board.getBoardWidth();
	height = board.getBoardHeight();
		
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
	Panel.loadFromFile("icons/Panel.png");
	
}

void MSSFMLView::draw(sf::RenderWindow & win)
{
	
		for (int row = 0; row < height; row++)
		{
			for (int col = 0; col <width; col++)
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

/*int MSSFMLView::getBlockWidth()
{
	float size = pole.getGlobalBounds().width;
	return size;	
}

int MSSFMLView::getBlockHeight()
{
	return pole.getTexture()->getSize().y * pole.getScale().y;	
}*/