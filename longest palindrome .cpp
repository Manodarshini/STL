#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str) 
{
    return str == std::string(str.rbegin(), str.rend());
}

std::string findLongestPalindrome(const std::string& input) 
{
    std::string longestPalindrome;
    size_t maxLength = 0;

    for (size_t i = 0; i < input.length(); ++i) 
    {
        for (size_t j = i + 1; j <= input.length(); ++j) 
        {
            std::string subStr = input.substr(i, j - i);
            if (isPalindrome(subStr) && subStr.length() > maxLength)
            {
                longestPalindrome = subStr;
                maxLength = subStr.length();
            }
        }
    }

    return longestPalindrome;
}

int main() {
    std::string input;
    std::cout << "Enter the string: ";
    std::getline(std::cin, input); // Allowing spaces in input

    std::string longestPalindrome = findLongestPalindrome(input);

    if (longestPalindrome.empty())
    {
        std::cout << "No palindrome found." << std::endl;
    } else 
    {
        std::cout << "Longest palindrome: " << longestPalindrome << std::endl;
    }

    return 0;
}
