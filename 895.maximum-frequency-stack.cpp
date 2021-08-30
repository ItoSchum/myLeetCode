/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 *
 * https://leetcode.com/problems/maximum-frequency-stack/description/
 *
 * algorithms
 * Hard (63.56%)
 * Likes:    2114
 * Dislikes: 38
 * Total Accepted:    77.2K
 * Total Submissions: 120.9K
 * Testcase Example:  '["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"]\n' +
  '[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]'
 *
 * Design a stack-like data structure to push elements to the stack and pop the
 * most frequent element from the stack.
 * 
 * Implement the FreqStack class:
 * 
 * 
 * FreqStack() constructs an empty frequency stack.
 * void push(int val) pushes an integer val onto the top of the stack.
 * int pop() removes and returns the most frequent element in the
 * stack.
 * 
 * If there is a tie for the most frequent element, the element closest to the
 * stack's top is removed and returned.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop",
 * "pop", "pop"]
 * [[], [5], [7], [5], [7], [4], [5], [], [], [], []]
 * Output
 * [null, null, null, null, null, null, null, 5, 7, 5, 4]
 * 
 * Explanation
 * FreqStack freqStack = new FreqStack();
 * freqStack.push(5); // The stack is [5]
 * freqStack.push(7); // The stack is [5,7]
 * freqStack.push(5); // The stack is [5,7,5]
 * freqStack.push(7); // The stack is [5,7,5,7]
 * freqStack.push(4); // The stack is [5,7,5,7,4]
 * freqStack.push(5); // The stack is [5,7,5,7,4,5]
 * freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes
 * [5,7,5,7,4].
 * freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is
 * closest to the top. The stack becomes [5,7,5,4].
 * freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes
 * [5,7,4].
 * freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is
 * closest to the top. The stack becomes [5,7].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= val <= 10^9
 * At most 2 * 10^4 calls will be made to push and pop.
 * It is guaranteed that there will be at least one element in the stack before
 * calling pop.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <unordered_map>

class FreqStack {
public:
    FreqStack() {
        _maxFreq = 0;
    }
    
    void push(int val) {
        // If exist in the hashmap
        if (_valToFreq.find(val) != _valToFreq.end() ) {
            int freq = ++_valToFreq[val];
            _freqToVals[freq].push(val);
            updateMaxFreqAfterPush(freq);
            return;
        }
        // If not exist
        _valToFreq[val] = 1;
        _freqToVals[1].push(val);
        updateMaxFreqAfterPush(1);
    }
    
    int pop() {
        int topVal = _freqToVals[_maxFreq].top();
        _freqToVals[_maxFreq].pop();
        _valToFreq[topVal] -= 1;
        updateMaxFreqAfterPop();
        return topVal;
    }

    void updateMaxFreqAfterPush(int freq) {
        if (freq > _maxFreq) { _maxFreq = freq; }
    }

    void updateMaxFreqAfterPop() {
        while (_freqToVals[_maxFreq].size() == 0 && _maxFreq >= 1) {
            _maxFreq--;
        }
    }

private:
    int _maxFreq;
    std::unordered_map<int, int> _valToFreq;
    std::unordered_map<int, std::stack<int> > _freqToVals;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

// n = element number in the stack
// Time: O(1)
// Space: O(n)

