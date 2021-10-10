/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (44.49%)
 * Likes:    2763
 * Dislikes: 77
 * Total Accepted:    175.5K
 * Total Submissions: 380.5K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are
 * non-overlapping.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals
 * non-overlapping.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        std::sort(intervals.begin(), intervals.end(), compareEndPoint);
        
        int currEnd = intervals[0][1];
        int count = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= currEnd) {
                currEnd = intervals[i][1];
                count++;
            }
        }
        return intervals.size() - count;
    }
    
    static bool compareEndPoint(const std::vector<int>& left, const std::vector<int>& right) {
        if (left[1] < right[1]) {
            return true;
        }
        return false;
    }
};
// @lc code=end

// n = interval number
// Time: O( nlog(n) )
// Space: O(1)
