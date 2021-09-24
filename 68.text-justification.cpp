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

#define SPACE " "

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> justifiedWords;
        std::vector<std::string> currLineWords;
        int currWidth = 0;

        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() + currWidth + 1 < maxWidth) {
                if (currWidth > 0) { currWidth += 1; }
                currWidth += words[i].size();
                currLineWords.push_back(words[i]);
            } else {
                justifiedWords.push_back(paddingSingleLine(currLineWords, maxWidth) );
                currWidth = 0;
                i--;
            }
        }
        return justifiedWords;
    }

    std::string paddingSingleLine(std::vector<std::string> wordVec, int maxWidth) {
        int wordLengthSum = 0;
        for (int i = 0; i < wordVec.size(); ++i) {
            wordLengthSum += wordVec[i].size();
        }
        int eachSpacingWidth = (maxWidth - wordLengthSum) / (wordVec.size() - 1);
        int lastSpacingWidth = maxWidth - eachSpacingWidth * (wordVec.size() - 1);
        std::string paddedLine = wordVec[0];
        for (int i = 1; i < wordVec.size(); ++i) {
            paddedLine.append(SPACE);
            paddedLine.append(wordVec[i]);
        }
        return paddedLine;
    }
};
// @lc code=end

