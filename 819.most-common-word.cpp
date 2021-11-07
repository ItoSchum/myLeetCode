/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 *
 * https://leetcode.com/problems/most-common-word/description/
 *
 * algorithms
 * Easy (45.44%)
 * Likes:    1123
 * Dislikes: 2346
 * Total Accepted:    259.1K
 * Total Submissions: 571.8K
 * Testcase Example:  '"Bob hit a ball, the hit BALL flew far after it was hit."\n["hit"]'
 *
 * Given a string paragraph and a string array of the banned words banned,
 * return the most frequent word that is not banned. It is guaranteed there is
 * at least one word that is not banned, and that the answer is unique.
 * 
 * The words in paragraph are case-insensitive and the answer should be
 * returned in lowercase.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was
 * hit.", banned = ["hit"]
 * Output: "ball"
 * Explanation: 
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent
 * non-banned word in the paragraph. 
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"), 
 * and that "hit" isn't the answer even though it occurs more because it is
 * banned.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: paragraph = "a.", banned = []
 * Output: "a"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= paragraph.length <= 1000
 * paragraph consists of English letters, space ' ', or one of the symbols:
 * "!?',;.".
 * 0 <= banned.length <= 100
 * 1 <= banned[i].length <= 10
 * banned[i] consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
        std::vector<std::string> splitWords = splitIntoWords(paragraph);
        std::unordered_map<std::string, int> wordFreq;
        for (std::string word : splitWords) {
            if (std::find(banned.begin(), banned.end(), word) == banned.end()) { 
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                wordFreq[word] += 1; 
            }
        }
        
        int maxFreq = 0;
        std::string maxFreqWord;
        for (const auto& pair : wordFreq) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
                maxFreqWord = pair.first;
            }
        }
        return maxFreqWord;
    }
    
    std::vector<std::string> splitIntoWords(std::string& inputString) {
        std::vector<std::string> wordVector;
        std::stringstream stringStream(inputString);
        std::string line;
        while(std::getline(stringStream, line))  {
            std::size_t prev = 0, pos;
            while ((pos = line.find_first_of(" ,.'\";!?", prev)) != std::string::npos) {
                if (pos > prev) { 
                    wordVector.push_back(line.substr(prev, pos - prev)); 
                }
                prev = pos + 1;
            }
            if (prev < line.length()) { 
                wordVector.push_back(line.substr(prev, std::string::npos)); 
            }
        }
        return wordVector;
    }

};
// @lc code=end

