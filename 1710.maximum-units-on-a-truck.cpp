/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 *
 * https://leetcode.com/problems/maximum-units-on-a-truck/description/
 *
 * algorithms
 * Easy (70.12%)
 * Likes:    974
 * Dislikes: 78
 * Total Accepted:    87.4K
 * Total Submissions: 120.9K
 * Testcase Example:  '[[1,3],[2,2],[3,1]]\n4'
 *
 * You are assigned to put some amount of boxes onto one truck. You are given a
 * 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi,
 * numberOfUnitsPerBoxi]:
 * 
 * 
 * numberOfBoxesi is the number of boxes of type i.
 * numberOfUnitsPerBoxi is the number of units in each box of the type i.
 * 
 * 
 * You are also given an integer truckSize, which is the maximum number of
 * boxes that can be put on the truck. You can choose any boxes to put on the
 * truck as long as the number of boxes does not exceed truckSize.
 * 
 * Return the maximum total number of units that can be put on the truck.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
 * Output: 8
 * Explanation: There are:
 * - 1 box of the first type that contains 3 units.
 * - 2 boxes of the second type that contain 2 units each.
 * - 3 boxes of the third type that contain 1 unit each.
 * You can take all the boxes of the first and second types, and one box of the
 * third type.
 * The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
 * Output: 91
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= boxTypes.length <= 1000
 * 1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
 * 1 <= truckSize <= 10^6
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), prioritized);
        
        #ifdef DEBUG
        for (auto boxType : boxTypes) {
            std::cout << boxType[0] << "," << boxType[1] << " ";
        }
        std::cout << std::endl;
        #endif

        int sizeSum = 0;
        int weightSum = 0;
        for (int i = 0; i < boxTypes.size(); ++i) {
            while (boxTypes[i][0] > 0) {
                sizeSum += 1;
                boxTypes[i][0] -= 1;
                weightSum += boxTypes[i][1];
                // std::cout << "+=" << boxTypes[i][1] << " ";
                if (sizeSum >= truckSize) { return weightSum; }
            }
        }
        return weightSum;
    }

private:
    static bool prioritized(const std::vector<int>& vec1, const std::vector<int>& vec2) {
        return vec1[1] > vec2[1];
    }
};
// @lc code=end

// n = size category number
// Time: O(nlogn)
// Space: O(1)