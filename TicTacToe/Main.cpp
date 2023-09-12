#include <iostream>
#include <vector>
#include <string>
#include "GameBoard.cpp"

void PrintGrid(void)
{
    char BoardArray[9] = {1,2,3,4,5,6,7,8,9};
    char* ptr = &BoardArray[0];
    std::cout << static_cast<int>(*ptr) << " | " << static_cast<int>(*(ptr+1)) << " | " << static_cast<int>(*(ptr+2)) << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << static_cast<int>(*(ptr+3)) << " | " << static_cast<int>(*(ptr+4)) << " | " << static_cast<int>(*(ptr+5)) << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << static_cast<int>(*(ptr+6)) << " | " << static_cast<int>(*(ptr+7)) << " | " << static_cast<int>(*(ptr+8)) << std::endl;

}

// Check 3 cases for win in a row, column, or diagonal
bool CheckForWin()
{
    bool Win = false;
    return Win;
}

void PrintLine(char* ptr)
{
    for(int i = 0; i < 5; i++)
    {
        // Check if expected char |,X,O or an uint
        if ( *ptr == '|' || *ptr == 'X' || *ptr == 'O') 
        { 
            std::cout << *ptr << " ";
        }
        else
            std::cout << static_cast<int>(*ptr) << " ";
        
        ptr++;
    }
    std::cout << std::endl;
}


int main()
{
    std::cout << "Hello, welcome to TicTacToe!" << std::endl << std::endl;

    char BoardArray[15] = {1,'|',2,'|',3,4,'|',5,'|',6,7,'|',8,'|',9};
    char* ptr = &BoardArray[0];
    //print 1st line and divider line
    PrintLine(ptr);
    std::cout << "----------" << std::endl;
    // Print 2nd line and divider 
    PrintLine(ptr+5);
    std::cout << "----------" << std::endl;
    // Print 3nd line  
    PrintLine(ptr+10);
    std::cout << std::endl;

    // User input
    int16_t UsrInput;
    std::cout << "Please select a position for your X! " << std::endl;
    std::cout << "Position: ";
    std::cin >> UsrInput;

    // Is it valid?
    while( !(UsrInput == 1 || UsrInput == 2 || UsrInput == 3 || UsrInput == 4 || UsrInput == 5 || UsrInput == 6 || UsrInput == 7 || UsrInput == 8) || UsrInput == 9)
    {
        std::cin.clear();   // Clear any error state
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max());   /// Ignore to the end of Stream 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore to the end of line

        std::cout << "Invalid entry, please only enter 1-9 and press enter ";
        std::cin >> UsrInput;
    }

    // Update array
    BoardArray[UsrInput -1] = 'X';

    // ptr = &BoardArray[0];
    // if (*ptr == 'X' || *ptr == 'O')
    //     std::cout << *ptr << " | ";
    // else 
    //     std::cout << static_cast<int>(*ptr) << " | ";
    
    // std::cout << static_cast<int>(*ptr) << " | " << static_cast<int>(*(ptr+1)) << " | " << static_cast<int>(*(ptr+2)) << std::endl;
    // std::cout << "---------" << std::endl;
    // std::cout << static_cast<int>(*(ptr+3)) << " | " << static_cast<int>(*(ptr+4)) << " | " << static_cast<int>(*(ptr+5)) << std::endl;
    // std::cout << "---------" << std::endl;
    // std::cout << static_cast<int>(*(ptr+6)) << " | " << static_cast<int>(*(ptr+7)) << " | " << static_cast<int>(*(ptr+8)) << std::endl;

    // Create gameboard object for game
    GameBoard Game1;


    return 0;
}