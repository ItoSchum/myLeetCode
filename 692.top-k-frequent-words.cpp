/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (53.49%)
 * Likes:    3695
 * Dislikes: 225
 * Total Accepted:    324.9K
 * Total Submissions: 603.3K
 * Testcase Example:  '["i","love","leetcode","i","love","coding"]\n2'
 *
 * Given an array of strings words and an integer k, return the k most frequent
 * strings.
 * 
 * Return the answer sorted by the frequency from highest to lowest. Sort the
 * words with the same frequency by their lexicographical order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["i","love","leetcode","i","love","coding"], k = 2
 * Output: ["i","love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words =
 * ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
 * Output: ["the","is","sunny","day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 500
 * 1 <= words[i] <= 10
 * words[i] consists of lowercase English letters.
 * k is in the range [1, The number of unique words[i]]
 * 
 * 
 * 
 * Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        // Rec freqency for each word 
        for (unsigned int i = 0; i < words.size(); ++i) {
            strToFreq[ words[i] ] += 1;
        }
        // Rec words by frequency
        std::unordered_map<std::string, int>::iterator itr;
        for (itr = strToFreq.begin(); itr != strToFreq.end(); ++itr) {
            freqToStrs[ itr->second ].push_back( itr->first );
        }
        // Extract words: tterate words by higher frequency
        std::vector<std::string> result;
        int count = 0;
        std::map<int, std::vector<std::string> >::reverse_iterator vecItr;
        for (vecItr = freqToStrs.rbegin(); vecItr != freqToStrs.rend() && count < k; ++vecItr) {
            // Sort string by alphabetical order
            std::sort(vecItr->second.begin(), vecItr->second.end() );
            int vecSize = vecItr->second.size();
            // If more words than needed, insert part of the words
            if ( count + vecSize > k) {
                int diff = count + vecSize - k;
                result.insert(result.end(), vecItr->second.begin(), vecItr->second.begin() + vecSize - diff);
                break;
            }
            // Otherwise, insert all words
            result.insert(result.end(), vecItr->second.begin(), vecItr->second.end() );
            count += vecSize;
        }
        return result;
    }

private:
    std::map<int, std::vector<std::string> > freqToStrs;
    std::unordered_map<std::string, int> strToFreq;
};

// n = word number
// Time: O( nlog(n) )
// Space: O(n)
// @lc code=end

