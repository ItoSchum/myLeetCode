/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 *
 * https://leetcode.com/problems/robot-bounded-in-circle/description/
 *
 * algorithms
 * Medium (54.94%)
 * Likes:    1810
 * Dislikes: 458
 * Total Accepted:    126.3K
 * Total Submissions: 231.3K
 * Testcase Example:  '"GGLLGG"'
 *
 * On an infinite plane, a robot initially stands at (0, 0) and faces north.
 * The robot can receive one of three instructions:
 * 
 * 
 * "G": go straight 1 unit;
 * "L": turn 90 degrees to the left;
 * "R": turn 90 degrees to the right.
 * 
 * 
 * The robot performs the instructions given in order, and repeats them
 * forever.
 * 
 * Return true if and only if there exists a circle in the plane such that the
 * robot never leaves the circle.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: instructions = "GGLLGG"
 * Output: true
 * Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and
 * then returns to (0,0).
 * When repeating these instructions, the robot remains in the circle of radius
 * 2 centered at the origin.
 * 
 * Example 2:
 * 
 * 
 * Input: instructions = "GG"
 * Output: false
 * Explanation: The robot moves north indefinitely.
 * 
 * Example 3:
 * 
 * 
 * Input: instructions = "GL"
 * Output: true
 * Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) ->
 * (0, 0) -> ...
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= instructions.length <= 100
 * instructions[i] is 'G', 'L' or, 'R'.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
// #include <unordered_map>

class Solution {
public:
    bool isRobotBounded(std::string instructions) {
        int currDirectIndex = 0;
        std::vector<int> currCoord = {0, 0};
        for (int i = 0; i < instructions.size(); ++i) {
            if (instructions[i] == 'G') {
                stepForward(currCoord, currDirectIndex);
            }
            if (instructions[i] == 'L') {
                turnLeft(currDirectIndex);
            }
            if (instructions[i] == 'R') {
                turnRight(currDirectIndex);
            }
        }
        return (currCoord[0] == 0 && currCoord[1] == 0) || currDirectIndex != 0;
    }

    void turnLeft(int& currDirectIndex) {
        currDirectIndex = (currDirectIndex - 1 + 4) % 4;
    } 

    void turnRight(int& currDirectIndex) {
        currDirectIndex = (currDirectIndex + 1) % 4;
    }

    void stepForward(std::vector<int>& currCoord, const int& currDirectIndex) {
        currCoord[0] += DIRECTOINS[currDirectIndex][0];
        currCoord[1] += DIRECTOINS[currDirectIndex][1];
    }

private:
    const std::vector<std::vector<int> > DIRECTOINS { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
};
// @lc code=end

