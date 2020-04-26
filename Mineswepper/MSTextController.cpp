#include "MSTextController.h"
#include "MineswepperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

MSTextController::MSTextController(MinesweeperBoard& board, MSBoardTextView& view):board(board),view(view)
{
}

void MSTextController::play()
{
	int x, y, option;	
	while (board.getGameState() == RUNNING)
	{
		board.debug_display();
		cout << "Maksymalna wspolrzedna x wynosi: " << board.getBoardWidth() << endl;
		cout << "Maksymalna wspolrzedna y wynosi: " << board.getBoardHeight() << endl << endl;
		view.display();
		cout << "Pozostalo min: " << board.getMineCount() << endl;
		
		cout << "Wybierz pole:"<<std::endl;
		cout << "Podaj wspolrzedna x: ";
		cin >> x;

		cout << "Podaj wspolrzedna y: ";
		cin >> y;
		cout << "1. Odslon pole" << endl;
		cout << "2. Przelacz flage" << endl;
		cout << "Co chcesz zrobic?";
		cin >> option;

		switch (option) {
		case 1:
			board.revealField(x-1, y-1);
			break;
		case 2:
			board.toggleFlag(x - 1, y - 1);
			break;
		}
		if (board.getGameState() != 0)
			break;
		system("cls");
	}
	if (board.getGameState() == FINISHED_LOSS)
		cout << "Niestety, tym razem sie nie udalo";

	else cout << "Gratulacje, wygrales!";
	cin.get();
	cin.get();
}
