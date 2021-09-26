/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <vector>

class Solution {
public:
    int depthSumInverse(std::vector<NestedInteger>& nestedList) {
        _maxDepth = getMaxDepth(nestedList, 1);
        stepDepthSumInverse(nestedList, 1);
        return _sumWithWeight;
    }

    void stepDepthSumInverse(std::vector<NestedInteger>& nestedList, int currDepth) {
        if (nestedList.size() == 0) {
            return;
        }
        for (int i = 0; i < nestedList.size(); ++i) {
            if (nestedList[i].isInteger() ) {
                _sumWithWeight += nestedList[i].getInteger() * (_maxDepth + 1 - currDepth);
                // std::cout << nestedList << " " << currDepth << std::endl;
            } else {
                stepDepthSumInverse(nestedList[i].getList(), currDepth + 1);
            }
        }
    }

    int getMaxDepth(std::vector<NestedInteger>& nestedList, int currDepth) {
        int maxDepth = currDepth;
        for (int i = 0; i < nestedList.size(); ++i) {
            if (!nestedList[i].isInteger()) {
                maxDepth = std::max(maxDepth ,getMaxDepth(nestedList[i].getList(), currDepth + 1) );
            }
        }
        return maxDepth;
    }

private:
    int _sumWithWeight = 0;
    int _maxDepth = 0;
};

// Runtime: 4 ms, faster than 47.45% of C++ online submissions for Nested List Weight Sum II.
// Memory Usage: 8.8 MB, less than 95.88% of C++ online submissions for Nested List Weight Sum II.

// n = element number
// Time: O(n)
// Space: O(n)