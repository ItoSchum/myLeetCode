class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char expectedSmallestChar = letters[0];
        for (int i = 0; i < letters.size(); ++i) {
            expectedSmallestChar = letters[i];
            if (letters[i] > target) {
                return expectedSmallestChar;
            }
        }
        return letters[0];
    }
};

// n = letter number
// Time: O(n)
// Space: O(1)