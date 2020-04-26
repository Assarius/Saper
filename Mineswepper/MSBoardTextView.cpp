#include "MSBoardTextView.h"
#include "MineswepperBoard.h"
#include <iostream>
#include <iomanip>


MSBoardTextView::MSBoardTextView(MinesweeperBoard & board):board(board) 
{
	width = board.getBoardWidth();
	height = board.getBoardHeight();
}

void MSBoardTextView::display() const
{
	int x=1;
	std::cout << "  ";
	for (int i = 1; i <= height; i++)
		std::cout << std::setw(3)<<i;
	std::cout << std::endl;

	for (int col = 0; col < height; col++)
	{
		std::cout << std::setw(2)  <<x << " ";
		x++;
		for (int row = 0; row < width; row++)
		{			
			std::cout << "[" << board.getFieldInfo(row, col) << "]";
		}
		std::cout<<std::endl;
	}
	std::cout << std::endl;
}
