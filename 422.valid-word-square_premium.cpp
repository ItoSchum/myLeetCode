#include <iostream>
#include <vector>

class Solution {
public:
    bool validWordSquare(std::vector<std::string>& words) {
        // Find out the size of the longest string
        int maxSize = 0;
        for (unsigned int row = 0; row < words.size(); ++row) {
            maxSize = std::max((int)words[row].size(), maxSize);
        }
        // Error checking, if inconsistent size in row and column
        if (maxSize != words.size() ) { return false; }
        
        // Fill all empty cell with ''\0'
        for (unsigned int row = 0; row < words.size(); ++row) {
            while (words[row].size() < maxSize) { words[row].push_back('\0'); }
        }
        
        // Compare cells
        for (unsigned int row = 0; row < words.size(); ++row) {
            for (unsigned int col = 0; col < row + 1; ++col) {
                if (words[row][col] != words[col][row]) { return false; }
            }
        }
        // Otherwise
        return true;
    }
};

// n = edge length of the square, aka words.size() (if valid input)
// Time: O(n^2)
// Space: O(1)