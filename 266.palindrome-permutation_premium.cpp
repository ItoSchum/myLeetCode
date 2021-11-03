#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool canPermutePalindrome(std::string s) {
        std::unordered_map<char, int> charToFreq;
        
        // record frequency for all char
        for (unsigned int i = 0; i < s.size(); ++i) {
            charToFreq[ s[i] ] += 1;
        }
        // check if frequency all even or at most 1 odd
        int oddCount = 0;
        for (const auto& pair : charToFreq) {
            if (pair.second & 1 == 1) { oddCount += 1; }
            if (oddCount > 1) { return false; }
        }
        return true;
    }
};