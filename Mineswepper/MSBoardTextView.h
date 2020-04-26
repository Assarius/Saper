#pragma once
#include "MineswepperBoard.h"

class MSBoardTextView
{
	MinesweeperBoard & board;
	int width;
	int height;

public:
	explicit MSBoardTextView(MinesweeperBoard & board);
	void display() const;
};