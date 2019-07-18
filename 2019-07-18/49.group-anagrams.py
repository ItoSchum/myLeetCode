from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        solution_collect = defaultdict(list)
        
        for string in strs:
            solution_collect[tuple(sorted(string))].append(string)
        
        return list(solution_collect.values())

# Runtime: 120 ms, faster than 49.86% of Python3 online submissions for Group Anagrams.
# Memory Usage: 16.8 MB, less than 35.79% of Python3 online submissions for Group Anagrams.

# TC: O(n), n = len(strs)
# SC: O(n * k), n = len(strs), k = max(len for len(string) in strs)