/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (45.04%)
 * Likes:    6462
 * Dislikes: 245
 * Total Accepted:    421.5K
 * Total Submissions: 932.4K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * You are given an array of integers nums, there is a sliding window of size k
 * which is moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window moves
 * right by one position.
 * 
 * Return the max sliding window.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation: 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,-1], k = 1
 * Output: [1,-1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [9,11], k = 2
 * Output: [11]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [4,-2], k = 2
 * Output: [4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <list>

class MonotonicQueue {
public:
    void push(int newVal) {
        // Remove all elements less than newVal (front to back)
        // Then insert the new value to the front
        while (!_queue.empty() && newVal > _queue.front()) {
            _queue.pop_front();
        }
        // ALTERNATIVE: Using iterator
        // std::list<int>::iterator itr = _queue.begin();
        // while (itr != _queue.end() && newVal > *itr) {
        //     itr = _queue.erase(itr);
        // }

        // insert newVal to the front
        _queue.push_front(newVal);
    }
    // Pop the corresponding val if it is the max
    void pop(int valToRemove) {
        if (_queue.back() == valToRemove) {
            _queue.pop_back();
        }
    }
    // return the last element which is the max
    int max() {
        return _queue.back();
    }

private:
    std::list<int> _queue;
};

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        // vector recording max int of each window
        std::vector<int> max_vec;
        // ALTERNATIVE: Using priority queue
        // std::priority_queue<std::pair<int,int> > val_seq_pq;
        
        // When nums is empty
        if (nums.empty() == true) { 
            return max_vec; 
        }
        
        // When window size k < size of nums
        if (nums.size() < k) {
            int currNum = nums[0];
            for (int i = 0; i < k; ++i) {
                if (nums[i] > currNum) { currNum = nums[i]; }
            }
            max_vec.push_back(currNum);
            return max_vec;
        }

        // ALTERNATIVE: Using priority queue
        // int offset = 0;
        // for (int i = k; i < nums.size(); ++i) {
        //     val_seq_pq.push( {nums[i], i} );
        //     while(val_seq_pq.top().second <= offset) {
        //         val_seq_pq.pop();
        //     }
        //     max_vec.push_back(val_seq_pq.top().first);
        //     offset++;
        // }

        MonotonicQueue monotonicQueue;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k - 1) {
                monotonicQueue.push(nums[i]);
            } else {
                monotonicQueue.push(nums[i]);
                max_vec.push_back(monotonicQueue.max());
                monotonicQueue.pop(nums[i - k + 1]);
            }
        }
        return max_vec;
    }
};

// @lc code=end

