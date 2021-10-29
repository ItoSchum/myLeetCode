#include <iostream>
#include <vector>

class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
        // Check if no meetings
        if (intervals.size() == 0) {
            return true;
        }
        // Otherwise
        std::sort(intervals.begin(), intervals.end() );
        
        for (unsigned int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};

// n = interval size
// Time: O( nlog(n) )
// Space: O(1)