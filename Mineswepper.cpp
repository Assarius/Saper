#include <iostream>
#include "MineswepperBoard.h"
#include <stdlib.h>


void test(MinesweeperBoard &game)
{ 
   /* game.debug_display();
    std::cout << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;    
    std::cin.get();
    system("cls");

    game.revealField(2, 4);
    game.debug_display();
    std::cout << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;   
    std::cin.get();
    system("cls");

    game.toggleFlag(2, 1);
    game.debug_display();
    std::cout << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;   
    std::cin.get();
    system("cls");

       
    game.revealField(2, 1);
    game.debug_display();
    std::cout << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;   
    std::cin.get();
    system("cls");

    
    game.revealField(0, 0);
    game.debug_display();
    std::cout << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;

    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;    
    std::cin.get();
    system("cls");

    
    game.toggleFlag(2, 1);
    game.debug_display();
    std::cout << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;   
    std::cin.get();
    system("cls");

    
    game.revealField(2, 1);
    game.debug_display();
    std::cout << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;   
    std::cin.get();
    system("cls");    
    std::cin.get(); */   

    game.debug_display();
    std::cout <<std::endl<< "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;
    std::cin.get();
    system("cls");
    
    game.revealField(0, 0);
    game.toggleFlag(2, 1);
    game.debug_display();
    std::cout << std::endl << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;
    std::cin.get();
    system("cls");
    
    game.revealField(2, 1);
    game.debug_display();
    std::cout << std::endl << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;
    std::cin.get();
    system("cls");


    game.toggleFlag(2, 1);
    game.debug_display();
    std::cout << std::endl << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;
    std::cin.get();
    system("cls");

    game.revealField(2, 1);
    game.debug_display();
    std::cout << std::endl << "Czy pole (2,1) jest odkryte? " << game.isRevealed(2, 1) << std::endl;
    std::cout << "Czy pole (2,1) ma falge? " << game.hasFlag(2, 1) << std::endl;
    std::cout << "Ile min wokol pola (2,1)? " << game.countMines(2, 1) << std::endl;
    std::cout << "Info o polu (2,1): " << game.getFieldInfo(2, 1) << std::endl;
    std::cin.get(); 

   /* game.debug_display();
    std::cout << "Ile min wokol pola? " << game.countMines(9,1) << std::endl;
    std::cout << game.getFieldInfo(1, 0);
    std::cin.get();*/
}

    



int main() 
{
    MinesweeperBoard game(10, 10, DEBUG); //szerokosc, wysokosc
    test(game);
    return 0;
}