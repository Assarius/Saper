#include "MineswepperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <iostream>
#include <stdlib.h>


int main() 
{
    MinesweeperBoard board(10, 10, EASY); //szerokosc, wysokosc
    MSBoardTextView view (board);
    MSTextController ctrl(board, view);
    ctrl.play();

    return 0;
}