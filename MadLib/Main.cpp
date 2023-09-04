//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Objective: Read in madlib text file, ask user for words from file and print out resulting madlib
// Structure:
//   MadLib class with all the madlib words from the user
//   File with story and desired words enclosed in parantheses ()
// Program flow:
//   Read file and extract all necessary words. Store in a seperate string vector
//   Ask user for all desired words
//   Print MadLib with user words
// 2nd option
//   Read in MadLib into a vector, when a desired word is found stop.
//   Ask user for word
//   Add to story vectory
//   Read until end of MadLib
//   Print full MadLib

#include <iostream> // cout and cin
#include <vector>
#include <fstream> // opening files
#include <string>

// Pass the desired word type request (noun, verb, adj) and pass by ref MadLib class instance
// Update the MadLibWords string vector with user input for the WordTypeReq
void GetWord(std::string WordTypeReq, std::vector<std::string> &MadLibWords)
{
    // Def
    std::string InputWord;

    // Ask user for input
    std::cout << "Enter a " << WordTypeReq << " " << std::endl;
    std::cin >> InputWord;
    MadLibWords.push_back(InputWord);
}

int main()
{

    // Class for the MadLibWords that are read in from user input
    class MadLib
    {
    public:
        std::vector<std::string> MadLibWords;
    };

    MadLib CurrMadLib;

    // Open file with MadLib
    std::ifstream MadLibFile;
    MadLibFile.open("SchoolFoodMLSmall.txt");

    // Check file opened
    if (!MadLibFile.is_open())
    {
        std::cerr << "Error: Unable to open the file for reading. " << std::endl;
        return 1; // return with error code
    }

    // Tried reading in char by char, check for () but the char array was full of garbage
    // Can read in file word by word and store in class MadLib, vector string MadLibWords will
    // hold the entire story
    std::string SingleWord;
    char c;
    char FileWord[256];
    int i = 0;
    while (std::getline(MadLibFile, SingleWord, ' '))
    {
        std::size_t found = SingleWord.find("(");

        // User input words are defined by ()
        // Search the string line for a paraenthesis
        // If found, it is a word requiring user input
        // Remove paraentheses () and ask user for input
        if (found != std::string::npos)
        {
            // Search through the string character by character and create new string without ( or )
            std::string WordType = "";
            for (char character : SingleWord)
            {
                if (character != '(' && character != ')')
                {
                    WordType += character;
                }
            }

            // Ask user for input 
            std::cout << "Please input a " << WordType << " ";
            std::string UserInput;
            std::cin >> UserInput;
            UserInput += ' ';
            CurrMadLib.MadLibWords.push_back(UserInput);

        }
        // No paraenthesis found, add to MadLib story
        else {
            SingleWord += ' ';
            CurrMadLib.MadLibWords.push_back(SingleWord);
        }
        
    }

    // Print the story with the user input
    for (int i = 0; i < CurrMadLib.MadLibWords.size(); i++)
    {
        std::cout << CurrMadLib.MadLibWords[i];
    }


    /*
    for(int i = 0; i< PresetWords.size(); i++)
    {
        std::cout << PresetWords[i] << std::endl;

    }
    */

    return 0;
}
