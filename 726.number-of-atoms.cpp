/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 *
 * https://leetcode.com/problems/number-of-atoms/description/
 *
 * algorithms
 * Hard (51.07%)
 * Likes:    795
 * Dislikes: 197
 * Total Accepted:    39.2K
 * Total Submissions: 76.2K
 * Testcase Example:  '"H2O"'
 *
 * Given a string formula representing a chemical formula, return the count of
 * each atom.
 * 
 * The atomic element always starts with an uppercase character, then zero or
 * more lowercase letters, representing the name.
 * 
 * One or more digits representing that element's count may follow if the count
 * is greater than 1. If the count is 1, no digits will follow.
 * 
 * 
 * For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
 * 
 * 
 * Two formulas are concatenated together to produce another formula.
 * 
 * 
 * For example, "H2O2He3Mg4" is also a formula.
 * 
 * 
 * A formula placed in parentheses, and a count (optionally added) is also a
 * formula.
 * 
 * 
 * For example, "(H2O2)" and "(H2O2)3" are formulas.
 * 
 * 
 * Return the count of all elements as a string in the following form: the
 * first name (in sorted order), followed by its count (if that count is more
 * than 1), followed by the second name (in sorted order), followed by its
 * count (if that count is more than 1), and so on.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: formula = "H2O"
 * Output: "H2O"
 * Explanation: The count of elements are {'H': 2, 'O': 1}.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: formula = "Mg(OH)2"
 * Output: "H2MgO2"
 * Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: formula = "K4(ON(SO3)2)2"
 * Output: "K4N2O14S4"
 * Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: formula = "Be32"
 * Output: "Be32"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= formula.length <= 1000
 * formula consists of English letters, digits, '(', and ')'.
 * formula is always valid.
 * All the values in the output will fit in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <map>

class Solution {
public:
    std::string countOfAtoms(std::string formula) {
        int currPos = 0;
        std::map<std::string, int> elementToFreq = stepCountOfAtoms(formula, currPos);
        std::string results;
        std::map<std::string, int>::iterator itr;
        for (itr = elementToFreq.begin(); itr != elementToFreq.end(); ++itr) {
            if (itr->second > 1) {
                results.append(itr->first + std::to_string(itr->second) );
            } else {
                results.append(itr->first);   
            }
        }
        return results;
    }
    
    std::map<std::string, int> stepCountOfAtoms(const std::string& formula, int& currPos) {
        std::map<std::string, int> elementToFreq;
        // If reached the end of the formula, return empty map
        if (currPos >= formula.size() ) {
            return elementToFreq;
        }
        
        // Save the elements in the current level
        while ( currPos < formula.size() && formula[currPos] != ')' ) {
            // If next char is a opening bracket, recursively call itself
            if ( formula[currPos] == '(' ) {
                // skip the opening bracket
                currPos += 1;
                for (auto const& pair: stepCountOfAtoms(formula, currPos) ) {
                    elementToFreq[pair.first] += pair.second; 
                }
            } else {
                // If next char is a letter, save the entire element string
                std::string currElement = "";
                currElement += formula[currPos++];
                while (currPos < formula.size() && std::islower(formula[currPos]) ) {
                    currElement += formula[currPos++];
                }
                // If next char is a number, save the number
                std::string repeatTime = "";
                while (currPos < formula.size() && std::isdigit(formula[currPos]) ) {
                    repeatTime += formula[currPos++];
                }
                // Add appearing times, default 1 time
                elementToFreq[currElement] += (repeatTime.size() == 0) ? 1 : std::stoi(repeatTime);
            } 
        }

        // If next char is a closing bracket
        if (currPos < formula.size() && formula[currPos] == ')') {
            // skip the closing bracket
            currPos += 1;
            std::string multiplyTime = "";
            while (currPos < formula.size() && std::isdigit(formula[currPos]) ) {
                multiplyTime += formula[currPos++];
            }
            int multiplyTimeVal = (multiplyTime.size() == 0) ? 1 : std::stoi(multiplyTime);
            std::map<std::string, int>::iterator itr;
            for (itr = elementToFreq.begin(); itr != elementToFreq.end(); ++itr) {
                itr->second *= multiplyTimeVal;
            }
        }
        return elementToFreq;
    }
};
// @lc code=end

// n = string length
// Time: O(n^2)
// Space: O(n)

