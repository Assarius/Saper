#include "MineswepperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSSFMLEvents.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>



int main() 
{
    MinesweeperBoard board(10, 10, EASY);
    sf::RenderWindow win(sf::VideoMode(8*50,8*50), "Saper");

    win.setVerticalSyncEnabled(true);
    win.setKeyRepeatEnabled(false);    
    
    MSSFMLView view(board);
    MSSFMLEvents game(board, view);
   
   
    while (win.isOpen())
    {
       // ctrl.play();
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }
        
        win.clear(); 
        game.play(win);
        win.display();                 
        
    }
    return 0;
}