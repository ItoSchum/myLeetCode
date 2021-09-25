/*
 * @lc app=leetcode id=730 lang=cpp
 * 
 * [240] Shortest Word Distance II
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>

class WordDistance {
public:
    WordDistance(std::vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            wordToLocations[ wordsDict[i] ].push_back(i);
        }
    }
    
    int shortest(std::string word1, std::string word2) {
        int shortestDist = INT_MAX;
        std::vector<int> locations_1 = wordToLocations[word1];
        std::vector<int> locations_2 = wordToLocations[word2];
        // Brute Force
        // for (int i = 0; i < locations_1.size(); ++i) {
        //     for (int j = 0; j < locations_2.size(); ++j) {
        //         shortestDist = std::min(shortestDist, std::abs(locations_1[i] - locations_2[j]) );
        //     }
        // }

        // Alternative
        int loc1_index = 0;
        int loc2_index = 0;
        while (loc1_index < locations_1.size() && loc2_index < locations_2.size()) {
            shortestDist = std::min(shortestDist, std::abs(locations_1[loc1_index] - locations_2[loc2_index]) );
            if (locations_1[loc1_index] < locations_2[loc2_index]) {
                loc1_index++;
            } else {
                loc2_index++;
            }
        }

        return shortestDist;
    }

private:
    std::unordered_map<std::string, std::vector<int> > wordToLocations;  
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */

// @lc code=end

// Runtime: 24 ms, faster than 99.37% of C++ online submissions for Shortest Word Distance II.
// Memory Usage: 19.6 MB, less than 45.43% of C++ online submissions for Shortest Word Distance II.

// n = word number
// Time: O(n)
// Space: O(n)