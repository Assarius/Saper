#pragma once
#include <vector>

enum GameMode{DEBUG, EASY, NORMAL, HARD};
enum GameState{RUNNING, FINISHED_WIN, FINISHED_LOSS};

struct Field {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard {
    std::vector<std::vector<Field>> board;
    int width;
    int height;
    bool move1 = true;
    GameState state = RUNNING;
    int getGameMode();

    public:
    MinesweeperBoard(int x, int y, GameMode mode);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int x, int y) const;
    bool hasFlag(int x, int y) const;
    bool isRevealed(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    GameState getGameState()const;
    char getFieldInfo(int x, int y) const;
};
