#include <iostream>
#include <vector>

class Solution {
public:
    int shortestDistance(std::vector<std::string>& wordsDict, std::string word1, std::string word2) {
        int minDist = wordsDict.size();
        int word1Index = -1;
        int word2Index = -1;
        
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                word1Index = i;
            }
            if (wordsDict[i] == word2) {
                word2Index = i;
            }
            if (word1Index != -1 && word2Index != -1) {
                minDist = std::min(minDist, std::abs(word1Index - word2Index) );
            }
        }
        return minDist;
    }
};

// n = word number
// Time: O(n) 
// Space: O(1)