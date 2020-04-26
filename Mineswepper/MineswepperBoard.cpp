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
  
    
}

int MinesweeperBoard::getBoardWidth() const {
      return this->width;
}

int MinesweeperBoard::getBoardHeight() const {
      return this->height;
}

int MinesweeperBoard::getMineCount() const 
{
    int how_many_mines = 0;
    for (int row = 0; row < getBoardHeight() ;row++)
    {
        for (int col = 0; col < getBoardWidth(); col++)
        {
            if (this->board.at(row).at(col).hasMine == true)
                how_many_mines++;
            else if (hasFlag(row,col) == true)
                how_many_mines--;
            if (this->board.at(row).at(col).hasMine == true && hasFlag(row,col) == true)
                how_many_mines--;
        } 
        if (how_many_mines == 0) {}

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

    if (row < 0 || col < 0 || row >= this->height || col >= this->width)
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
    }
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    
    if (row<0 || col<0 || row>=this->height || col>=this->width)
        return false;
    if (this->board.at(row).at(col).hasFlag == true)
        return true;
    else if (this->board.at(row).at(col).hasFlag == false)
        return false;
    else if (this->board.at(row).at(col).isRevealed==true)
        return false;
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if (row < 0 || col < 0 || row >= this->height || col >= this->width) {};
    if (this->board.at(row).at(col).isRevealed == true)
        return true;
    else return false;
}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    
    if (getGameState() != 0) return;
    if (getMineCount() == 0)
        board.at(row).at(col).hasFlag = false;
    else if (row<0 || col<0 || row>=width || col>=height) {}
    else if (board.at(row).at(col).isRevealed ==true) {}
    else if (board.at(row).at(col).isRevealed == false && board.at(row).at(col).hasFlag == false)
    {
        board.at(row).at(col).hasFlag = true;
        move1 = false;
    }
        
    else if (board.at(row).at(col).hasFlag == true)
        board.at(row).at(col).hasFlag = false;

   
}

void MinesweeperBoard::revealField(int row, int col)
{
    if (getGameState() != RUNNING) {}
    else if (row < 0 || col < 0 || row >= this->height || col >= this->width) return;
    else if (this->board.at(row).at(col).isRevealed == true) return;
    else if (this->board.at(row).at(col).hasFlag == true) return;
    else if (this->board.at(row).at(col).isRevealed == false && this->board.at(row).at(col).hasMine == false)
    {
        move1 = false;
        this->board.at(row).at(col).isRevealed = true;
        if (countMines(row, col) != 0) return;

        revealField(row - 1, col - 1);
        revealField(row - 1, col);
        revealField(row - 1, col + 1);
        revealField(row, col - 1);
        revealField(row, col + 1);
        revealField(row + 1, col - 1);
        revealField(row + 1, col);
        revealField(row + 1, col + 1);
        

    }
    else if (this->board.at(row).at(col).isRevealed == false && this->board.at(row).at(col).hasMine == true)// && getGameMode()!=0)
    {
        if (move1 == true)
        {
            move1 = false;
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
            
            
        }
        else
        {
            this->board.at(row).at(col).isRevealed = true;
            move1 = false;
        }


    }
  
}

GameState MinesweeperBoard::getGameState() const
{
    
    int how_many_mines = 0;
    for (int row = 0; row < this->height; row++)
    {
        for (int col = 0; col < this->width; col++)
        {
            
            if (isRevealed(row, col) == true && this->board.at(row).at(col).hasMine == true)
                return FINISHED_LOSS;
            else if (hasFlag(row,col) == true && hasMine(row,col) == true && getMineCount() == 0)
                return FINISHED_WIN;
                       
        }
    }
    return RUNNING;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{    
    if (row<0 || col<0 || row>=this->height || col>=this->width)
        return '#';
    else 
    {
        if (isRevealed(row, col) == false && this->board.at(row).at(col).hasMine == true && getGameState()==FINISHED_LOSS)
            return 'x';
        if (isRevealed(row,col) == false && hasFlag(row,col) == true)
            return 'F';
        if (isRevealed(row, col) == false && hasFlag(row, col) == false)
            return '_';
        if (isRevealed(row, col) == true && this->board.at(row).at(col).hasMine == true)
            return 'X';
        if (isRevealed(row, col) == false && this->board.at(row).at(col).hasMine == true)
            return 'x';
        if (isRevealed(row, col) == true && countMines(row, col) == 0)
            return ' ';
        if (isRevealed(row, col) == true && countMines(row, col) != 0)
        {
            int x = (countMines(row, col));
            char ch = x;
            return ch+'0';
        }
    }
}

bool MinesweeperBoard::hasMine(int x, int y) const
{
    if (board.at(x).at(y).hasMine==true)
        return true;
    else return false;
}


