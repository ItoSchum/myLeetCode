/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (65.20%)
 * Likes:    4939
 * Dislikes: 139
 * Total Accepted:    279.4K
 * Total Submissions: 424.8K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 * 
 * 
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        std::vector<int> warmerOffsets(temperatures.size());
        std::stack<int> candidateIndex;

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while(!candidateIndex.empty() && temperatures[candidateIndex.top()] <= temperatures[i]) {
                candidateIndex.pop();
            }
            warmerOffsets[i] = !candidateIndex.empty()? (candidateIndex.top() - i) : 0;
            candidateIndex.push(i);
        }
        return warmerOffsets;
    }
};
// @lc code=end

// n = temperature number
// Time: O(n)
// Space: O(n)
