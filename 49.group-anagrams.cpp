/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (60.38%)
 * Likes:    7045
 * Dislikes: 257
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string> > strToAnagrams;
        std::string sortedStr;
        for (std::string str : strs) {
            sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end() );
            strToAnagrams[sortedStr].push_back(str);
        }
        
        std::vector<std::vector<std::string> > results;
        std::unordered_map<std::string, std::vector<std::string> >::iterator itr;
        for (itr = strToAnagrams.begin(); itr != strToAnagrams.end(); ++itr) {
            results.push_back(itr->second);
        }
        return results;
    }
    
};
// @lc code=end

// n = string number, m = average string length
// Time: O( n * mlog(m) )
// Space: O(n * m)

