/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 *
 * https://leetcode.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (78.75%)
 * Likes:    2363
 * Dislikes: 99
 * Total Accepted:    153.9K
 * Total Submissions: 194.8K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1,
 * find all possible paths from node 0 to node n - 1 and return them in any
 * order.
 * 
 * The graph is given as follows: graph[i] is a list of all nodes you can visit
 * from node i (i.e., there is a directed edge from node i to node
 * graph[i][j]).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: graph = [[1,2],[3],[3],[]]
 * Output: [[0,1,3],[0,2,3]]
 * Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
 * Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: graph = [[1],[]]
 * Output: [[0,1]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: graph = [[1,2,3],[2],[3],[]]
 * Output: [[0,1,2,3],[0,2,3],[0,3]]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: graph = [[1,3],[2],[3],[]]
 * Output: [[0,1,2,3],[0,3]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == graph.length
 * 2 <= n <= 15
 * 0 <= graph[i][j] < n
 * graph[i][j] != i (i.e., there will be no self-loops).
 * All the elements of graph[i] are unique.
 * The input graph is guaranteed to be a DAG.
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> allPaths = std::vector<std::vector<int> >();
    
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph) {
        std::vector<int> singlePath = std::vector<int>();
        // Start from node 0
        traverse(graph, 0, singlePath);
        return allPaths;
    }

    void traverse(std::vector<std::vector<int>>& graph, int s, std::vector<int>& singlePath) {
        // Push back current node
        singlePath.push_back(s);

        // End of the path
        if (s == graph.size() - 1) {
            allPaths.push_back(singlePath);
            singlePath.pop_back();
            return;
        }
        // Traverse all neighbors
        for (int i = 0; i < graph[s].size(); ++i) {
            traverse(graph, graph[s][i], singlePath);
        }
        // Pop back current node
        singlePath.pop_back();
    }
};
// @lc code=end

// n = node number
// Time: O(2^log2(n)) = O(n)
// Space: O(n)

