/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (41.92%)
 * Likes:    9936
 * Dislikes: 440
 * Total Accepted:    1.1M
 * Total Submissions: 2.6M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<std::vector<int> > merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end() );
        std::vector<std::vector<int> > mergedIntervals;
        for (std::vector<int> interval : intervals) {
            if (mergedIntervals.empty() || interval[0] > mergedIntervals.back()[1]) {
                mergedIntervals.push_back(interval);
            } else {
                mergedIntervals.back()[1] = std::max(mergedIntervals.back()[1], interval[1]);  
            }
        }    
        return mergedIntervals;
    }
};
// @lc code=end

// n = interval number
// Time: O( nlog(n) )
// Space: O(n)
