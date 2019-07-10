class Solution:
	def isPalindrome(self, x: int) -> bool:
		
		half_reversed_x = 0

		if x < 0 or (x % 10 == 0 and x != 0):
			return False
		else:
			while x > half_reversed_x:
				half_reversed_x = half_reversed_x * 10 + x % 10
				x //= 10
			
		return x == half_reversed_x or x == half_reversed_x // 10

# Runtime: 76 ms, faster than 64.78% of Python3 online submissions for Palindrome Number.
# Memory Usage: 13.3 MB, less than 31.25% of Python3 online submissions for Palindrome Number.

# TC: O(log10(n)), n = x
# SC: O(1)