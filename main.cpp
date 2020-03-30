#include <iostream>
#include "MineswepperBoard.h"
#include <stdlib.h>
#include "MSBoardTextView.h"


int main() 
{
    MinesweeperBoard board(10, 10, EASY); //szerokosc, wysokosc
    MSBoardTextView view (board);
    view.display();
    std::cin.get();
    board.revealField(0, 5);
    view.display();
    std::cin.get();

    return 0;
}