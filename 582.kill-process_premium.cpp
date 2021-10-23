#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> killProcess(std::vector<int>& pid, std::vector<int>& ppid, int kill) {
        // init parent to child process map
        for(int i = 0; i < ppid.size(); ++i) {
            int childPid = pid[i];
            int parentPid = ppid[i];
            parentToChildProc[parentPid].push_back(childPid);
        }
        
        // find all child processes
        killedProc.push_back(kill);
        findChildProcess(kill);
        return killedProc;
    }
    
    void findChildProcess(int kill) {
        if (parentToChildProc[kill].size() == 0) {
            return;
        }
        for (int pidToKill : parentToChildProc[kill]) {
            killedProc.push_back(pidToKill);
            findChildProcess(pidToKill);
        }
    }

private:
    std::unordered_map<int, std::vector<int> > parentToChildProc;
    std::vector<int> killedProc;
};

// n = process number
// Time: O(n)
// Space: O(n)