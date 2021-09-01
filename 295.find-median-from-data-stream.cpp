/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (48.12%)
 * Likes:    5192
 * Dislikes: 92
 * Total Accepted:    359.6K
 * Total Submissions: 732.1K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * The median is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value and the median is the mean of the
 * two middle values.
 * 
 * 
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Implement the MedianFinder class:
 * 
 * 
 * MedianFinder() initializes the MedianFinder object.
 * void addNum(int num) adds the integer num from the data stream to the data
 * structure.
 * double findMedian() returns the median of all elements so far. Answers
 * within 10^-5 of the actual answer will be accepted.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 * 
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -10^5 <= num <= 10^5
 * There will be at least one element in the data structure before calling
 * findMedian.
 * At most 5 * 10^4 calls will be made to addNum and findMedian.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are in the range [0, 100], how would
 * you optimize your solution?
 * If 99% of all integer numbers from the stream are in the range [0, 100], how
 * would you optimize your solution?
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <queue>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        // printStatus();
    }
    
    void addNum(int num) {
        if (largeNums.size() > smallNums.size()) {
            largeNums.push(num);
            smallNums.push(largeNums.top());
            largeNums.pop();
            std::cout << largeNums.top() << std::endl;
        } else {
            smallNums.push(num);
            largeNums.push(smallNums.top());
            smallNums.pop();
        }
    }
    
    double findMedian() {
        if (smallNums.size() > largeNums.size()) {
            return (double)smallNums.top();
        } else if (smallNums.size() < largeNums.size()) {
            return (double)largeNums.top();
        } else {
            return (double)(smallNums.top() + largeNums.top()) / 2.0;
        }
    }

private:
    std::priority_queue<int> smallNums;
    std::priority_queue<int, std::vector<int>, std::greater<int> > largeNums;

    void printStatus() {
        std::cout << "large : small = " << largeNums.size() << " : " << smallNums.size() << std::endl;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

// n = number amount
// Time: O(nlogn)
// Space: O(n)