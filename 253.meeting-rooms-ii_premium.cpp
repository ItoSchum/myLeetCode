#include <iostream>
#include <vector>

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::vector<int> startTimes(intervals.size(), 0);
        std::vector<int> endTimes(intervals.size(), 0);
        
        // extract start and end times
        for (int i = 0; i < intervals.size(); ++i) {
            startTimes[i] = intervals[i][0];
            endTimes[i] = intervals[i][1];
        }
        std::sort(startTimes.begin(), startTimes.end() );
        std::sort(endTimes.begin(), endTimes.end() );
        
        // find the max count
        int inProgressCount = 0;
        int endedCount = 0;
        int roomCount = 0;
        
        while (inProgressCount < startTimes.size() ) {
            if (startTimes[inProgressCount] >= endTimes[endedCount]) {
                roomCount -= 1;
                endedCount += 1;
            }
            roomCount += 1;
            inProgressCount += 1;
        }
        return roomCount;
    }
};