#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        for (int i = 0; i < username.size(); ++i) {
            usernameToTimeToWeb[ username[i] ][ timestamp[i] ] = website[i];
        }

        unordered_map<string, int> websiteComboToFreq;
        // Iterate records by username
        unordered_map<string, map<int, string> >::iterator recByUserItr;
        for (recByUserItr = usernameToTimeToWeb.begin(); recByUserItr != usernameToTimeToWeb.end(); recByUserItr++) {
            string websiteCombo;
            unordered_set<string> websiteComboSet; 
            // Iterate all record pairs 
            for (map<int, string>::iterator itr = recByUserItr->second.begin(); itr != recByUserItr->second.end(); itr++) {
                for (map<int, string>::iterator itr2 = next(itr); itr2 != recByUserItr->second.end(); itr2++) {
                    for (map<int, string>::iterator itr3 = next(itr2); itr3 != recByUserItr->second.end(); itr3++) {
                        // concat the website names and insert into freq map
                        websiteCombo = itr->second;
                        websiteCombo.append("+").append( itr2->second );
                        websiteCombo.append("+").append( itr3->second );
                        websiteComboSet.insert(websiteCombo);
                    }
                }
            }
            for (auto& websiteComboStr : websiteComboSet) {
                websiteComboToFreq[websiteComboStr]++;
            }
        }

        string maxCombo = websiteComboToFreq.begin()->first;
        int maxFreq = websiteComboToFreq.begin()->second;
        
        unordered_map<string, int>::iterator itr;
        for (itr = websiteComboToFreq.begin(); itr != websiteComboToFreq.end(); itr++) {
            if (itr->second > maxFreq) { 
                maxCombo = itr->first;
                maxFreq = itr->second;
            }
            if (itr->first < maxCombo && itr->second == maxFreq) {
                maxCombo = itr->first;
            }
        }

        int firstSeparator = maxCombo.find("+");
        int secondSeparator = maxCombo.find("+", firstSeparator + 1);
        return { maxCombo.substr(0, firstSeparator), 
            maxCombo.substr(firstSeparator + 1, secondSeparator - firstSeparator - 1), 
            maxCombo.substr(secondSeparator + 1) };
    }

private:
    unordered_map<string, map<int, string> > usernameToTimeToWeb;
};

// Runtime: 20 ms, faster than 98.88% of C++ online submissions for Analyze User Website Visit Pattern.
// Memory Usage: 16.1 MB, less than 98.88% of C++ online submissions for Analyze User Website Visit Pattern.

// n = record number
// Time: O(n^3)
// Space: O(n^3)