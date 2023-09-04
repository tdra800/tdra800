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

void GetWord(std::string DesiredWord, std::string InputWord, std::vector<std::string> MadLibWords)
{

    std::cout << "Enter a " << DesiredWord << " " << std::endl;
    std::cin >> InputWord;
    MadLibWords.push_back(InputWord);
}

int main()
{

    class MadLib
    {
    public:
        std::vector<std::string> MadLibWords;
        std::vector<std::string> PresetWords{"Hello", "World", "Its", "Good", "To", "Be", "Here"};
        std::string InputWord;

    };

    MadLib CurrMadLib;



    // Add value for loop to run
    for (int i = 0; i < 0; i++)
    {
        std::cout << "Enter a word " << std::endl;
        std::cin >> CurrMadLib.InputWord;

        CurrMadLib.MadLibWords.push_back(CurrMadLib.InputWord);
    }

    std::cout << std::endl;

    /*
    for(int i = 0; i< PresetWords.size(); i++)
    {
        std::cout << PresetWords[i] << std::endl;

    }
    */

    return 0;
}
