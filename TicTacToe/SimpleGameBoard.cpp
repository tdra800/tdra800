#include <iostream>
#include <vector>
#include <string>
#include <random>

// Class to manage marks on the board
class TicTacToe
{
public:
    void CheckPlyrInput();
    void GetPlyrInput();
    void PrintBoard(const char *ptr);
    void PrintLine(const char *ptr);
    void PlyrUpdBrds();
    void CpuRanChoice();
    void CpuUpdBrds();
    bool CheckWinCond();
    bool BoardFull();
    const char *DB = &DisplayBoard[0];
    const char *MB = &MarksBoard[0];

private:
    // 2x2 array to track marks
    // Init variables
    std::vector<int> AvailableNums = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // BoardArray prints the current board
    char DisplayBoard[15] = {1, '|', 2, '|', 3, 4, '|', 5, '|', 6, 7, '|', 8, '|', 9};
    char MarksBoard[15] = {' ', '|', ' ', '|', ' ', ' ', '|', ' ', '|', ' ', ' ', '|', ' ', '|', ' '}; // Start with empty board
    int16_t PlyrInput;
    int16_t CpuChoice;
};

void TicTacToe::PrintLine(const char *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        // Check if expected char |,X,O or an uint
        if (*ptr == '|' || *ptr == 'X' || *ptr == 'O' || *ptr == ' ')
        {
            std::cout << *ptr << " ";
        }
        else
            std::cout << static_cast<int>(*ptr) << " ";

        ptr++;
    }
    std::cout << std::endl;
}

void TicTacToe::PrintBoard(const char *ptr)
{
    // print 1st line and divider line
    PrintLine(ptr);
    std::cout << "----------" << std::endl;
    // Print 2nd line and divider
    PrintLine(ptr + 5);
    std::cout << "----------" << std::endl;
    // Print 3nd line
    PrintLine(ptr + 10);
    std::cout << std::endl;
}

void TicTacToe::GetPlyrInput()
{
    std::cout << "Please select a listed position for your X! " << std::endl
              << std::endl;
    PrintBoard(DB);
    std::cout << "Position: ";
    std::cin >> PlyrInput;
}

void TicTacToe::CheckPlyrInput()
{
    // Check PlyrInput is valid
    bool valid = false;                                                         // flag for valid input
    auto it = std::find(AvailableNums.begin(), AvailableNums.end(), PlyrInput); // Search vector for PlyrInput, end of vector returned if val not found

    if (it != AvailableNums.end())
    {
        valid = true;
        AvailableNums.erase(it); // If val is found, delete
    }

    // If player input isn't valid, clear possible input stream error and ask user for another entry
    // Check again
    while (!valid)
    {

        std::cin.clear();                                                   // Clear any error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore to the end of line

        // Print available numbers to player
        std::cout << "Invalid entry, please enter ";
        for (int i = 0; i < AvailableNums.size(); i++)
            std::cout << AvailableNums[i] << ' ';
        std::cout << std::endl;
        std::cin >> PlyrInput;

        auto it = std::find(AvailableNums.begin(), AvailableNums.end(), PlyrInput);
        if (it != AvailableNums.end())
        {
            valid = true;
            AvailableNums.erase(it);
        }
    }
}

void TicTacToe::PlyrUpdBrds()
{
    // Update display board to display not available space (empty)
    // Update Maskboard with X as well
    for (int i = 0; DisplayBoard[i] != '\0'; i++)
    {
        if (DisplayBoard[i] == PlyrInput)
        {
            DisplayBoard[i] = ' ';
            MarksBoard[i] = 'X';
            break;
        }
    }
}

void TicTacToe::CpuRanChoice()
{
    // Create a random number generator engine
    std::random_device rd;                                   // Seed the generator with a random device
    std::mt19937 gen(rd());                                  // Mersenne Twister engine, a commonly used random number generator
    std::uniform_int_distribution<int> distribution(1, 100); // Define a random distribution (e.g., uniform distribution between 1 and 100)
    bool valid2 = false;                                     // flag for valid input

    // Create random choice between 1-9, check if available
    // If not, create new choice
    do
    {
        CpuChoice = distribution(gen) % 10;                                          // 9 is the number of squares for TicTacToe
        auto it2 = std::find(AvailableNums.begin(), AvailableNums.end(), CpuChoice); // Search vector for CpuChoice, end of vector returned if val not found

        if (it2 != AvailableNums.end())
        {
            valid2 = true;
            AvailableNums.erase(it2);
        }
    } while (!valid2);
}

void TicTacToe::CpuUpdBrds()
{
    // Update display board to display not available space (empty)
    // Update Maskboard with X as well
    for (int i = 0; DisplayBoard[i] != '\0'; i++)
    {
        if (DisplayBoard[i] == CpuChoice)
        {
            DisplayBoard[i] = ' ';
            MarksBoard[i] = 'O';
            break;
        }
    }
}

bool TicTacToe::CheckWinCond()
{
    ////////////////////////////////////////////////////////////////////////////////////
    // Mapping for the values from the boxes to the location in the arrays
    // 1 2 3 4 5 6  7  8  9       board values
    // 0 2 4 5 7 9 10 12 14       array values

    // Check rows for victory
    //  Increments set to check row values in array
    for (int StartPtr = 0; StartPtr < 11; StartPtr += 5)
    {
        if (MarksBoard[StartPtr] == MarksBoard[StartPtr + 2] && MarksBoard[StartPtr + 2] == MarksBoard[StartPtr + 4])
        {
            if (MarksBoard[StartPtr] == 'X') // Check if player won
            {
                std::cout << "Victory! You Won!" << std::endl;
                return true;
            }
            else if (MarksBoard[StartPtr] == 'O') // Check if CPU won
            {
                std::cout << "Oh no! Defeat!" << std::endl;
                return true;
            }
        }
    }

    // Check cols for victory
    for (int StartPtr = 0; StartPtr < 11; StartPtr += 2)
    {
        if (MarksBoard[StartPtr] == MarksBoard[StartPtr + 5] && MarksBoard[StartPtr + 5] == MarksBoard[StartPtr + 10])
        {
            if (MarksBoard[StartPtr] == 'X')
            {
                std::cout << "Victory! You Won!" << std::endl; // Check if player won
                return true;
            }
            else if (MarksBoard[StartPtr] == 'O') // Check if CPU won
            {
                std::cout << "Oh no! Defeat!" << std::endl;
                return true;
            }
        }
    }

    // Check diag 1
    int StartPtr = 0;
    if (MarksBoard[StartPtr] == MarksBoard[StartPtr + 7] && MarksBoard[StartPtr + 7] == MarksBoard[StartPtr + 14])
    {
        if (MarksBoard[StartPtr] == 'X') // Check if player won
        {
            std::cout << "Victory! You Won!" << std::endl;
            return true;
        }
        else if (MarksBoard[StartPtr] == 'O') // Check if CPU won
        {
            std::cout << "Oh no! Defeat!" << std::endl;
            return true;
        }
    }

    // Check diag 2
    StartPtr = 4;
    if (MarksBoard[StartPtr] == MarksBoard[StartPtr + 3] && MarksBoard[StartPtr + 3] == MarksBoard[StartPtr + 6])
    {
        if (MarksBoard[StartPtr] == 'X') // Check if player won
        {
            std::cout << "Victory! You Won!" << std::endl;
            return true;
        }
        else if (MarksBoard[StartPtr] == 'O') // Check if CPU won
        {
            std::cout << "Oh no! Defeat!" << std::endl;
            return true;
        }
    }
    
    // no win condition met
    return false;


}

bool TicTacToe::BoardFull()
{
    if (AvailableNums.empty())
        return true;
    else
        return false;
}
