#include <iostream>
#include <vector>

class Solution {
public:
    int wateringPlants(std::vector<int>& plants, int capacity) {
        int remainCap = capacity;
        int stepCount = 0;
        for (int i = 0; i < plants.size(); ++i) {
            if (remainCap < plants[i] && i > 0) {
                stepCount += calRefillStep(i - 1, remainCap, capacity);
            }
            remainCap -= plants[i];
            stepCount += 1;
        }
        // std::cout << std::endl;
        return stepCount;
    }
    
    int calRefillStep(int currIdx, int& remainCap, int capacity) {
        // std::cout << "Refill +" << (currIdx + 1) * 2 << std::endl;
        remainCap = capacity;
        return (currIdx + 1) * 2;
    }
};

int main() {
    Solution sol = Solution();
    std::vector<int> plants = {3,2,4,2,1};
    int step = sol.wateringPlants(plants, 6);
    std::cout << step << std::endl;
    return 0;
}