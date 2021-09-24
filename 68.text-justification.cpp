/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (31.00%)
 * Likes:    1307
 * Dislikes: 2346
 * Total Accepted:    197.2K
 * Total Submissions: 609.9K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of strings words and a width maxWidth, format the text such
 * that each line has exactly maxWidth characters and is fully (left and right)
 * justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line does not divide evenly between words, the
 * empty slots on the left will be assigned more spaces than the slots on the
 * right.
 * 
 * For the last line of text, it should be left-justified and no extra space is
 * inserted between words.
 * 
 * Note:
 * 
 * 
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["This", "is", "an", "example", "of", "text",
 * "justification."], maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth
 * = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be", because the last line must be left-justified instead of
 * fully-justified.
 * Note that the second line is also left-justified becase it contains only one
 * word.
 * 
 * Example 3:
 * 
 * 
 * Input: words =
 * ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 300
 * 1 <= words[i].length <= 20
 * words[i] consists of only English letters and symbols.
 * 1 <= maxWidth <= 100
 * words[i].length <= maxWidth
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> justifiedWords;
        std::vector<std::string> currLineWords;
        int currWidth = 0;
        std::string currLinePadded;

        for (int i = 0; i < words.size(); ++i) {
            // If exceeded the maxwidth
            if (checkNotExceedingMaxwidth(currWidth, words[i], maxWidth) == false) {
                paddingSingleLineEvenly(currLineWords, maxWidth, currLinePadded);
                justifiedWords.push_back(currLinePadded);
                currWidth = 0;
                currLinePadded = "";
                currLineWords.clear();
            }
            // If not, keep appending words to the current line
            if (currWidth > 0) { currWidth += 1; }
            currWidth += words[i].size();
            currLineWords.push_back(words[i]);

            if (i == words.size() - 1) {
                paddingSingleLineLeftJustified(currLineWords, maxWidth, currLinePadded);
                justifiedWords.push_back(currLinePadded);
            }
        }
        return justifiedWords;
    }

    bool checkNotExceedingMaxwidth(int currWidth, const std::string& nextWord, int maxWidth) {
        if (currWidth > 0) {
            return (currWidth + 1 + nextWord.size() <= maxWidth);
        } else {
            return (nextWord.size() <= maxWidth);
        }
    }

    void paddingSingleLineEvenly(
        const std::vector<std::string>& wordVec, const int& maxWidth, std::string& paddedLine) {
        // Only one word
        if (wordVec.size() == 1) {
            paddedLine = wordVec[0] + std::string(maxWidth - wordVec[0].size(), ' ');
            return;
        }
        // More than one words
        int spacingWidth = maxWidth;
        for (int i = 0; i < wordVec.size(); ++i) {
            spacingWidth -= wordVec[i].size();
        }
        int baseSpacingWidth = spacingWidth / (wordVec.size() - 1);
        int extraSpacingWidth = spacingWidth % (wordVec.size() - 1);
        paddedLine = wordVec[0];

        std::string baseSpacing = std::string(baseSpacingWidth, ' ');
        for (int i = 1; i < wordVec.size(); ++i) {
            if (extraSpacingWidth-- > 0) { paddedLine.append(" "); }
            paddedLine.append(baseSpacing);
            paddedLine.append(wordVec[i]);
        }
    }

    void paddingSingleLineLeftJustified(
        const std::vector<std::string>& wordVec, const int& maxWidth, std::string& paddedLine) {
        // Only one word
        if (wordVec.size() == 1) {
            paddedLine = wordVec[0] + std::string(maxWidth - wordVec[0].size(), ' ');
            return;
        }
        // More than one words
        int spacingWidth = maxWidth - wordVec[0].size();
        paddedLine = wordVec[0];
        for (int i = 1; i < wordVec.size(); ++i) {
            paddedLine.append(" ");
            paddedLine.append(wordVec[i]);
            spacingWidth -= (wordVec[i].size() + 1);
        }
        paddedLine.append(std::string(spacingWidth, ' ') );
    }
};
// @lc code=end

// n = words number
// Time: O(n)
// Space: O(n)
