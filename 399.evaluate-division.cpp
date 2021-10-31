/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (55.04%)
 * Likes:    4186
 * Dislikes: 343
 * Total Accepted:    212K
 * Total Submissions: 379.2K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * You are given an array of variable pairs equations and an array of real
 * numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
 * equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
 * single variable.
 * 
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the
 * j^th query where you must find the answer for Cj / Dj = ?.
 * 
 * Return the answers to all queries. If a single answer cannot be determined,
 * return -1.0.
 * 
 * Note: The input is always valid. You may assume that evaluating the queries
 * will not result in division by zero and that there is no contradiction.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * Explanation: 
 * Given: a / b = 2.0, b / c = 3.0
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: equations = [["a","b"],["b","c"],["bc","cd"]], values =
 * [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * Output: [3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * Output: [0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    typedef std::unordered_map<std::string, std::unordered_map<std::string, double> > FromToEquation;
    
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, 
        std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        
        // Save equations to map
        for (unsigned i = 0; i < equations.size(); ++i) {
            fromToEquation[ equations[i][0] ][ equations[i][1] ] = values[i];
            fromToEquation[ equations[i][1] ][ equations[i][0] ] = 1.0 / values[i];
        }
        // Process the queries
        std::vector<double> results(queries.size(), -1.0);
        for (unsigned i = 0; i < queries.size(); ++i) {
            // if no such equation
            if (fromToEquation.count(queries[i][0]) == 0 || fromToEquation.count(queries[i][1]) == 0) {
                results[i] = -1.0;
            }
            // if same "from" and "to" item
            else if (queries[i][0] == queries[i][1]) {
                results[i] = 1.0;
            }
            // otherwise find out the equation
            else {
                std::unordered_set<std::string> visitedSet;
                results[i] = findEquation(queries[i][0], queries[i][1], 1, visitedSet);
            }
        }
        return results;
    }

    double findEquation(
        const std::string& currVar, const std::string& targetVar, 
        double ratio, std::unordered_set<std::string>& visitedSet) {
        
        double result = -1.0;
        visitedSet.insert(currVar);
        
        std::unordered_map<std::string, double> neighbors = fromToEquation[currVar];
        // If targetVar can be directly found
        if (neighbors.find(targetVar) != neighbors.end() ) {
            result = ratio * neighbors[targetVar];
        }
        // Otherwise, recursively searching
        else {
            for (std::pair<std::string, double> neighbor : neighbors) {
                std::string nextVar = neighbor.first;
                // Skip if already visited
                if (visitedSet.find(nextVar) != visitedSet.end() ) { continue; }
                // Recursively call itself
                result = findEquation(nextVar, targetVar, ratio * neighbor.second, visitedSet);
                // DEBUG
                // std::cout << nextVar << " " << targetVar << std::endl;
                // std::cout << result << std::endl;
                
                // Break the loop if found any path
                if (result != -1.0) { break; }
            }
        }
        visitedSet.erase(currVar);
        return result;
    }

private:
    FromToEquation fromToEquation;
};

// @lc code=end

// n = node (var) number, m = query number
// Time: O(n * m) 
// Space: O(n)