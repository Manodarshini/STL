#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main() 
{
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string word;
    while (file >> word) 
    {
        // Remove any punctuation and convert the word to lowercase
        for (char& ch : word) 
        {
            ch = std::tolower(ch);
            if (!std::isalpha(ch))
            {
                ch = ' ';
            }
        }

        std::istringstream iss(word);
        while (iss >> word) 
        {
            if (!word.empty()) 
            {
                wordCount[word]++;
            }
        }
    }

    std::cout << "Word occurrence counts:" << std::endl;
    for (const auto& pair : wordCount) 
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
