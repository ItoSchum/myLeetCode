/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator/description/
 *
 * algorithms
 * Medium (56.31%)
 * Likes:    2507
 * Dislikes: 902
 * Total Accepted:    241.6K
 * Total Submissions: 425.9K
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * You are given a nested list of integers nestedList. Each element is either
 * an integer or a list whose elements may also be integers or other lists.
 * Implement an iterator to flatten it.
 * 
 * Implement the NestedIterator class:
 * 
 * 
 * NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with
 * the nested list nestedList.
 * int next() Returns the next integer in the nested list.
 * boolean hasNext() Returns true if there are still some integers in the
 * nested list and false otherwise.
 * 
 * 
 * Your code will be tested with the following pseudocode:
 * 
 * 
 * initialize iterator with nestedList
 * res = []
 * while iterator.hasNext()
 * ⁠   append iterator.next() to the end of res
 * return res
 * 
 * 
 * If res matches the expected flattened list, then your code will be judged as
 * correct.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nestedList = [[1,1],2,[1,1]]
 * Output: [1,1,2,1,1]
 * Explanation: By calling next repeatedly until hasNext returns false, the
 * order of elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nestedList = [1,[4,[6]]]
 * Output: [1,4,6]
 * Explanation: By calling next repeatedly until hasNext returns false, the
 * order of elements returned by next should be: [1,4,6].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nestedList.length <= 500
 * The values of the integers in the nested list is in the range [-10^6,
 * 10^6].
 * 
 * 
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <iostream>
#include <vector>
#include <iterator>

class NestedIterator {
public:
    NestedIterator(std::vector<NestedInteger> &nestedList) {
        std::vector<NestedInteger>::iterator nest_itr;
        for (nest_itr = nestedList.begin(); nest_itr != nestedList.end(); ++nest_itr) {
            traverse(nest_itr, flatElements);
        }
        _itr = flatElements.begin();
    }
    
    int next() {
        _itr++;
        return *(_itr);
    }
    
    bool hasNext() {
        return (std::next(_itr) != flatElements.end());
    }

    void traverse(const std::vector<NestedInteger>::iterator nest_itr, std::vector<int> &flatElements) {
        if (nest_itr->isInteger() == true) {
            flatElements.push_back(nest_itr->getInteger() );
            return;
        }
        std::vector<NestedInteger>::iterator sub_itr;
        for (sub_itr = nest_itr->getList().begin(); sub_itr != nest_itr->getList().end(); ++sub_itr) {
            traverse(sub_itr, flatElements);
        }
    }

private:
    std::vector<int>::iterator _itr;
    std::vector<int> flatElements = std::vector<int>({0});
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

// n = node number
// Time: O(n)
// Space: O(n)
