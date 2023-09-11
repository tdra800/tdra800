#include <iostream>
#include <vector>
#include <string>

void PrintGrid(void)
{
    std::cout << "_|_|_" << std::endl;
    std::cout << "_|_|_" << std::endl;
    std::cout << " | |" << std::endl;
}

// Class to manage marks on the board
class GameBoard
{
    public:
        // 2x2 array to track marks
        char Board[3][3];
        bool CheckForWin();
        void AskPlyrSpot();

        //Constructor, initalize board with 0s
        GameBoard()
        {
            for (int r = 0; r < 3; r++)
            {
                for(int c = 0; c < 3; c++) // Corrected ',' to ';'
                {
                    Board[r][c] = '0'; // Changed 0 to '0'
                }
            }
        }
    private:
        // private functions to check if the player or PC have won the game
        int CheckRows();
        int CheckCols();
        int CheckDiags();
        void AskPlyrSpot();

};

// Check 3 cases for win in a row, column, or diagonal
bool CheckForWin()
{
    bool Win = false;
    return Win;
}

// Check value pass by reference to update by user if needed
void CheckUsrInput(int& Val)
{
    // Check user value is valid and continue checking
    while( !(Val == 1 || Val == 2 || Val == 3) )
    {
        std::cin.clear();   // Clear any error state
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max());   /// Ignore to the end of Stream 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore to the end of line

        std::cout << "Invalid entry, please only enter 1, 2, or 3 and press enter ";
        std::cin >> Val;
    }

}

// Ask user for where they would like there x to go
// Checks valid input using CheckUsrInput()
void AskPlyrSpot()
{
    // Check for available spots
    char AvailRows[3];

    
    // Ask user for column
    std::cout << "Your turn!" << std::endl;
      

    std::cout << "Enter column number (1, 2 or 3) to place X and press enter ";
    int UsrCol = 0;
    std::cin >> UsrCol;

    // Check user input for column
    CheckUsrInput(UsrCol);

    // Ask user for row number
    std::cout << "Enter row number (1, 2 or 3) to place X and press enter ";
    int UsrRow = 0;
    std::cin >> UsrRow;

    // Check user input for row
    CheckUsrInput(UsrRow);

}


int main()
{
    std::cout << "Hello, welcom to TicTacToe!" << std::endl;

    // Printing grid using _ and |
    std::cout << "Grid attempt: " << std::endl;
    PrintGrid();

    // Create gameboard object for game
    GameBoard Game1;

    // Ask player where they want their next marker to go
    AskPlyrSpot();



    return 0;
}