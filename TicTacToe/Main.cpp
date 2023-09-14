#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "SimpleGameBoard.cpp"

void PrintGrid(void)
{
    char BoardArray[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char *ptr = &BoardArray[0];
    std::cout << static_cast<int>(*ptr) << " | " << static_cast<int>(*(ptr + 1)) << " | " << static_cast<int>(*(ptr + 2)) << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << static_cast<int>(*(ptr + 3)) << " | " << static_cast<int>(*(ptr + 4)) << " | " << static_cast<int>(*(ptr + 5)) << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << static_cast<int>(*(ptr + 6)) << " | " << static_cast<int>(*(ptr + 7)) << " | " << static_cast<int>(*(ptr + 8)) << std::endl;
}

// Check 3 cases for win in a row, column, or diagonal
bool CheckForWin()
{
    bool Win = false;
    return Win;
}

int main()
{

    TicTacToe Game;

    // start game
    std::cout << "Hello, welcome to TicTacToe!" << std::endl
              << std::endl;
    bool WinDet = false;

    while (!Game.CheckWinCond() && !Game.BoardFull())
    {
        Game.GetPlyrInput();
        Game.CheckPlyrInput();
        Game.PlyrUpdBrds();
        Game.CpuRanChoice();
        Game.CpuUpdBrds();
        std::cout << std::endl
                  << "The CPU has choosen!" << std::endl;
        std::cout << "Here is the board" << std::endl;
        Game.PrintBoard(Game.MB);
    }

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}