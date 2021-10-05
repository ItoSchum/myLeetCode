/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 *
 * https://leetcode.com/problems/search-suggestions-system/description/
 *
 * algorithms
 * Medium (65.52%)
 * Likes:    1577
 * Dislikes: 105
 * Total Accepted:    106.5K
 * Total Submissions: 162.1K
 * Testcase Example:  '["mobile","mouse","moneypot","monitor","mousepad"]\r\n"mouse"\r'
 *
 * Given an array of strings products and a string searchWord. We want to
 * design a system that suggests at most three product names from products
 * after each character of searchWord is typed. Suggested products should have
 * common prefix with the searchWord. If there are more than three products
 * with a common prefix return the three lexicographically minimums products.
 * 
 * Return list of lists of the suggested products after each character of
 * searchWord is typed. 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
 * searchWord = "mouse"
 * Output: [
 * ["mobile","moneypot","monitor"],
 * ["mobile","moneypot","monitor"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"]
 * ]
 * Explanation: products sorted lexicographically =
 * ["mobile","moneypot","monitor","mouse","mousepad"]
 * After typing m and mo all products match and we show user
 * ["mobile","moneypot","monitor"]
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: products = ["havana"], searchWord = "havana"
 * Output:
 * [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: products = ["bags","baggage","banner","box","cloths"], searchWord =
 * "bags"
 * Output:
 * [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: products = ["havana"], searchWord = "tatiana"
 * Output: [[],[],[],[],[],[],[]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= products.length <= 1000
 * There are no repeated elements in products.
 * 1 <= Σ products[i].length <= 2 * 10^4
 * All characters of products[i] are lower-case English letters.
 * 1 <= searchWord.length <= 1000
 * All characters of searchWord are lower-case English letters.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end() );
        
        vector<vector<string> > results;
        int startWordIndex = 0;
        int prevStartWordIndex = 0;
        string prefix = "";
        
        for (int i = 0; i < searchWord.size(); ++i) {
            prefix += searchWord[i];
            startWordIndex = lower_bound(products.begin() + prevStartWordIndex, products.end(), prefix) - products.begin();
            
            results.push_back({ });
            for (int j = 0; j < min(startWordIndex + 3, (int)products.size() ); ++j) {
                if (products[j].compare(0, prefix.size(), prefix) == 0 ) {
                    results.back().push_back(products[j]);
                }
            }
            prevStartWordIndex = startWordIndex;
        }
        return results;
    }
};
// @lc code=end

// n = number of candidate words, m = length of "searchWord"
// Time: O(nlog(2)n + mlog(2)n)
// Space: O(n * m)