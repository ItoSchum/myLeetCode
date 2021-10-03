/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 *
 * https://leetcode.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (55.06%)
 * Likes:    1344
 * Dislikes: 3307
 * Total Accepted:    243.4K
 * Total Submissions: 438.8K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]'
 *
 * You are given an array of logs. Each log is a space-delimited string of
 * words, where the first word is the identifier.
 * 
 * There are two types of logs:
 * 
 * 
 * Letter-logs: All words (except the identifier) consist of lowercase English
 * letters.
 * Digit-logs: All words (except the identifier) consist of digits.
 * 
 * 
 * Reorder these logs so that:
 * 
 * 
 * The letter-logs come before all digit-logs.
 * The letter-logs are sorted lexicographically by their contents. If their
 * contents are the same, then sort them lexicographically by their
 * identifiers.
 * The digit-logs maintain their relative ordering.
 * 
 * 
 * Return the final order of the logs.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit
 * dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5
 * 1","dig2 3 6"]
 * Explanation:
 * The letter-log contents are all different, so their ordering is "art can",
 * "art zero", "own kit dig".
 * The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act
 * zoo"]
 * Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4
 * 7"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * All the tokens of logs[i] are separated by a single space.
 * logs[i] is guaranteed to have an identifier and at least one word after the
 * identifier.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> reorderLogFiles(std::vector<std::string>& logs) {
        std::vector<std::string> sortedStrVec;
        std::vector<std::string> letterLogs;
        std::vector<std::string> digitLogs;

        for (int i = 0; i < logs.size(); ++i) {
            int secondWordStartIndex = logs[i].find(' ') + 1;
            if (std::isdigit(logs[i][secondWordStartIndex]) ) {
                digitLogs.push_back(logs[i]);
            } else {
                letterLogs.push_back(logs[i]);
            }
        }

        std::sort(letterLogs.begin(), letterLogs.end(), logSortComparator);
        for (int i = 0; i < letterLogs.size(); ++i) {
            sortedStrVec.push_back(letterLogs[i]);
        }
        for (int i = 0; i < digitLogs.size(); ++i) {
            sortedStrVec.push_back(digitLogs[i]);
        }
        return sortedStrVec;
    }

    static bool logSortComparator(const std::string& str1, const std::string& str2) {
        int secondWordStartIndex1 = str1.find(' ') + 1;
        int secondWordStartIndex2 = str2.find(' ') + 1;
        std::string substr1 = str1.substr(secondWordStartIndex1, str1.size() );
        std::string substr2 = str2.substr(secondWordStartIndex2, str2.size() );
        return substr1 <= substr2;
    }

private:
    std::vector<std::string> sortedStrVec;
};
// @lc code=end

// n = number of the letter log elements 
// m = number of the digit log elements
// Time: O( nlog2(n) )
// Space: O(n + m)