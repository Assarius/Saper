#include "MSBoardTextView.h"
#include "MineswepperBoard.h"
#include <iostream>


MSBoardTextView::MSBoardTextView(MinesweeperBoard & board):board(board) {
	width = board.getBoardWidth();
	height = board.getBoardHeight();
}

void MSBoardTextView::display() const
{
	for (int row = 0; row < width; row++)
	{
		for (int col = 0; col < height; col++)
		{
			std::cout <<"[" <<board.getFieldInfo(row, col)<<"]";
		}
		std::cout<<std::endl;
	}
}