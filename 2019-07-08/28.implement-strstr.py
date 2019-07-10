class Solution:
	def strStr(self, haystack: str, needle: str) -> int:
	
		haystack_len = len(haystack)
		needle_len = len(needle)

		if needle_len == 0:
			return 0
		elif haystack_len < needle_len or haystack_len == 0:
			return -1
		else:
			for i in range(0, haystack_len - needle_len + 1):
				if haystack[i:i + needle_len] == needle:
					return i
		return -1


# Runtime: 32 ms, faster than 92.33% of Python3 online submissions for Implement strStr().
# Memory Usage: 13.4 MB, less than 34.17% of Python3 online submissions for Implement strStr().

# TC: O(m - n), m = haystack_len, n = needle_len
# SC: O(1)



# Alternative Solution

# class Solution:
	# def strStr(self, haystack: str, needle: str) -> int:
		# index = haystack.find(needle)
		# return index

# Runtime: 36 ms, faster than 78.16% of Python3 online submissions for Implement strStr().
# Memory Usage: 13.3 MB, less than 68.00% of Python3 online submissions for Implement strStr().

