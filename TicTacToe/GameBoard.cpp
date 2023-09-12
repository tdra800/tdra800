#include <iostream>
#include <vector>
#include <string>


// Class to manage marks on the board
class GameBoard
{
    public:
        // 2x2 array to track marks
        char Board[3][3];
        bool CheckForWin();
        void AskPlyrSpot();
        uint16_t AvailRows();
  

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
        void CheckUsrInput(int& val);
        int IsRowFull(int RowNum);

};

// Return 1 if full, 0 if empty
// Simple summing check, increment sum everytime a value is found in the row
int GameBoard::IsRowFull(int RowNum)
{
    //char* Row = &Board[RowNum][0];

    char Board[3] = {1,2,3};
    char* Row = &Board[0];
    int sum = 0;

    // Check if row 1 has any aviailable positions
    for (int i = 0; i < 3; i++ )
    {
        // When row != 0, there is a mark there
        if ( *Row != 0 ) 
            sum++;
        Row++;              // Move to next pos in board
    }

    // Return based
    if ( sum == 3)
        return 1;
    else 
        return 0;

}


// Check for available spots by checking an entire row
// AvailRows uses last 3 bits to track rows avaiailibilty 
// LSB => Row 1, 2nd bit => Row 2, 3rd bit => Row 3
uint16_t GameBoard::AvailRows()
{
    uint16_t AvailRows = 0;
    //Check row 1 is availalbe
    if (IsRowFull(0))
        AvailRows |= 1;
    if (IsRowFull(1))
        AvailRows |= 2;
    if (IsRowFull(3))
        AvailRows |= 4;
    
    return AvailRows;

}


// Check value pass by reference to update by user if needed
void GameBoard::CheckUsrInput(int& Val)
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
void GameBoard::AskPlyrSpot()
{
    // Check for available spots   

    
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