#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int connectSticks(std::vector<int>& sticks) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > len_queue;
        for (int i = 0; i < sticks.size(); ++i) {
            len_queue.push(sticks[i]);
        }
        int minCost = 0;
        int stick_1;
        int stick_2;
        while (len_queue.size() > 1) {
            stick_1 = len_queue.top();
            len_queue.pop();
            stick_2 = len_queue.top();
            len_queue.pop();
            len_queue.push(stick_1 + stick_2);
            minCost = minCost + stick_1 + stick_2;
        }
        return minCost;
    }
};