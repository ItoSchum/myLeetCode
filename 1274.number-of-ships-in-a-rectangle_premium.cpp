/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */
#include <vector>

class Solution {
public:
    int countShips(Sea sea, std::vector<int> topRight, std::vector<int> bottomLeft) {
       return stepCountShips(sea, topRight, bottomLeft);
    }

private:
    int stepCountShips(Sea sea, std::vector<int> topRight, std::vector<int> bottomLeft) {
        if (topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1]) { 
            return 0; 
        }
        if (sea.hasShips(topRight, bottomLeft) == false) { 
            return 0; 
        }
        if (topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1]) { 
            return 1; 
        }
        
        int totalShips = 0;
        std::vector<int> center = { 
            (topRight[0] + bottomLeft[0]) / 2, 
            (topRight[1] + bottomLeft[1]) / 2 };
            
        totalShips = stepCountShips(sea, center, bottomLeft)
            + stepCountShips(sea, { center[0], topRight[1] }, { bottomLeft[0], center[1]+1 })
            + stepCountShips(sea, { topRight[0], center[1] }, { center[0]+1, bottomLeft[1] })
            + stepCountShips(sea, topRight, { center[0]+1, center[1]+1 });
        
        return totalShips;
    }
};
    
// Divide and Conquer
// Time: O( 4^n )
// Space: O(1)