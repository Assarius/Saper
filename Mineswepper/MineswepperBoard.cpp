#include "MineswepperBoard.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <stdlib.h>

int mines_position_x(int width)
{
    int x;
    x = rand() % width;   
    return x;
}
int mines_position_y(int height)
{
    int y;
    y = rand() % height;
    return y;
}
void level(int how_many_mines, int width, int height, std::vector<std::vector<Field>> & board)
{
    for (int i = 0; i < how_many_mines; i++)
    {
        int row = mines_position_x(width);
        int col = mines_position_y(height);
        while (board.at(row).at(col).hasMine == true)
        {
            col = mines_position_x(width);
            row = mines_position_y(height);
        }
        board.at(row).at(col).hasMine = true;
    }
}


MinesweeperBoard::MinesweeperBoard(int x, int y, GameMode mode) :width(x), height(y) {

    srand(time(NULL));
    this->board.resize(this->width);

    for (int row = 0; row < this->board.size(); row++)
        this->board.at(row).resize(this->height);

   for (int row = 0; row < this->height; row++)
    {
        for (int col= 0; col < this->width; col++)
        {
            this->board.at(col).at(row).hasMine = false;
            this->board.at(col).at(row).hasFlag = false;
            this->board.at(col).at(row).isRevealed = false;
        }
    }

   if (mode == 0)
   {
       for (int col = 0; col < this->height; col++)
       {
           for (int row = 0; row < this->width; row++)
           {
               if (row == col)
                   this->board.at(col).at(row).hasMine = true;

               if (col == 0)
                   this->board.at(row).at(col).hasMine = true;

               if (row == 0 && (col % 2 == 0))
                   this->board.at(row).at(col).hasMine = true;
           }
       }
   }
   else if (mode == 1)
   {
       int how_many_mines = this->width * this->height * 0.1; 
       level(how_many_mines, this->width, this->height, this->board);
   }
   else if (mode == 2)
   {
       int how_many_mines = this->width * this->height * 0.2;
       level(how_many_mines, this->width, this->height, this->board);
   }
   else if (mode == 3)
   {
       int how_many_mines = this->width * this->height * 0.3;
       level(how_many_mines, this->width, this->height, this->board);
   }
}

int MinesweeperBoard::getGameMode()
{
    for (int row = 0; row < this->width; row++)
    {
        for (int col = 0; col < this->height; col++)
        {
            if (row == col)
                this->board.at(col).at(row).hasMine == true;

            if (col == 0)
                this->board.at(row).at(col).hasMine == true;

            if (row == 0 && (col % 2 == 0))
                this->board.at(row).at(col).hasMine == true;
        }
    }
    return DEBUG;
}

void MinesweeperBoard::debug_display() const {
    for (int col = 0; col < this->height; col++)
    {

        for (int row = 0; row < this->width; row++)
        {

            if (this->board.at(row).at(col).hasMine == false)
                std::cout << "[.";
            else
                std::cout << "[M";
            if (this->board.at(row).at(col).isRevealed == false)
                std::cout << ".";
            else
                std::cout << "o";
            if (this->board.at(row).at(col).hasFlag == false)
                std::cout << ".]";
            else
                std::cout << "f]";
        }
        std::cout << std::endl;
    } 
    std::cout << "Szerokosc planszy: " << getBoardWidth() << std::endl;
    std::cout << "Wysokosc planszy: " << getBoardHeight() << std::endl;
    std::cout << "Ilosc bomb: " << getMineCount() << std::endl;
    std::cout << "Status gry: " << getGameState() << std::endl;
    //std::cin.get();
    
}

int MinesweeperBoard::getBoardWidth() const {
      return this->width;
}

int MinesweeperBoard::getBoardHeight() const {
      return this->height;
}

int MinesweeperBoard::getMineCount() const {
    int how_many_mines = 0;
    for (int row = 0; row < this->width; row++)
    {
        for (int col = 0; col < this->height; col++)
        {
            if (this->board.at(row).at(col).hasMine==true)
                how_many_mines++;
            if (this->board.at(row).at(col).hasFlag == true)
                how_many_mines--;
        } 

    }
    return how_many_mines;
}

int MinesweeperBoard::countMines(int row, int col) const
{
    int mines = 0;
    int row_around = row - 1, row_around2 = row + 1;
    int col_around = col - 1, col_around2 = col + 1;
    if (row == 0) row_around = 0;
    if (col == 0) col_around = 0;
    if (row == this->width-1) row_around2 = row;
    if (col == this->height-1) col_around2 = col;

    if (row < 0 || col < 0 || row >= this->width || col >= this->height)
        return -1;

    else if (this->board.at(row).at(col).isRevealed == false)
        return -1;

    else
    {
        for (int y = col_around; y <= col_around2; y++)
        {
            for (int x = row_around; x <= row_around2; x++)
            {
                if (this->board.at(x).at(y).hasMine == true)
                    mines++;
            }
        }
        return mines;
        //if (this->board.at(row).at(col).hasMine == true)
           /// return mines - 1;
//else
            //return mines;
    }
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if (this->board.at(row).at(col).hasFlag == true)
        return true;
    else if (row<0 || col<0 || row>=this->width || col>=this->height)
        return false;
    else if (this->board.at(row).at(col).hasFlag == false)
        return false;
    else if (this->board.at(row).at(col).isRevealed==true)
        return false;
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (this->board.at(row).at(col).isRevealed == true)
        return true;
    else return false;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if (getGameState() != 0) {}
    if (row<0 || col<0 || row>=this->width || col>=this->height) {}
    if (this->board.at(row).at(col).isRevealed ==true) {}
    if (this->board.at(row).at(col).isRevealed == false && this->board.at(row).at(col).hasFlag == false)
        this->board.at(row).at(col).hasFlag = true;
    else if (this->board.at(row).at(col).hasFlag == true)
        this->board.at(row).at(col).hasFlag = false;
}

void MinesweeperBoard::revealField(int row, int col)
{
    if (getGameState() != 0) {}
    else if (row < 0 || col<0 || row >= this->width || col>=this->height) {}
    else if (this->board.at(row).at(col).isRevealed == true) {}
    else if (this->board.at(row).at(col).hasFlag == true) {}
    else if (this->board.at(row).at(col).isRevealed == false && this->board.at(row).at(col).hasMine == false)
    {
        this->board.at(row).at(col).isRevealed = true;
        move1 = false;
        
    }
    else if (this->board.at(row).at(col).isRevealed == false && this->board.at(row).at(col).hasMine == true && getGameMode()!=0)
    {
        if (move1==true)
        {
            this->board.at(row).at(col).hasMine = false;

            int a = mines_position_x(this->width);
            int b = mines_position_y(this->height);
            while (this->board.at(a).at(b).hasMine == true)
            {
                a = mines_position_x(this->width);
                b = mines_position_y(this->height);
            }
            this->board.at(a).at(b).hasMine = true;
            this->board.at(row).at(col).isRevealed = true;
            move1 = false;
        }
        else
                this->board.at(row).at(col).isRevealed = true;
    }

}

GameState MinesweeperBoard::getGameState() const
{
    for (int row = 0; row < this->width; row++)
    {
        for (int col = 0; col < this->height; col++)
        {
            if (this->board.at(row).at(col).hasMine == true && this->board.at(row).at(col).isRevealed == true)
                return FINISHED_LOSS;
            else if (this->board.at(row).at(col).hasMine == true && this->board.at(row).at(col).hasFlag == true && getMineCount()==0)
                return FINISHED_WIN;
            else if (this->board.at(row).at(col).hasMine == true && this->board.at(row).at(col).isRevealed == false && getMineCount() == 0)
                return FINISHED_WIN;            
            else return RUNNING;
        }
    }
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{    
    if (row<0 || col<0 || row>=this->width || col>=this->height)
        return '#';
    else 
    {
        if (this->board.at(row).at(col).isRevealed == false && this->board.at(row).at(col).hasFlag == true)
            return 'F';
        if (this->board.at(row).at(col).isRevealed == false && this->board.at(row).at(col).hasFlag == false)
            return '_';
        if (this->board.at(row).at(col).isRevealed == true && this->board.at(row).at(col).hasMine == true)
            return 'x';
        if (this->board.at(row).at(col).isRevealed == true && countMines(row, col) == 0)
            return ' ';
        if (this->board.at(row).at(col).isRevealed == true && countMines(row, col) != 0)
        {
            int x = (countMines(row, col));
            char ch = x;
            return ch+'0';
        }

            
    }
}