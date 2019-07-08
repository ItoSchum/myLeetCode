class Solution:
	def strStr(self, haystack: str, needle: str) -> int:
	
		len_haystack = len(haystack)
		len_needle = len(needle)

		if len_needle == 0:
			return 0
		elif len_haystack < len_needle:
			return -1
		else:
			for i in range(0, len_haystack - len_needle + 1):
				if haystack[i:i + len_needle] == needle:
					return i
		return -1
